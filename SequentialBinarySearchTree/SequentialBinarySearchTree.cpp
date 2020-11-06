#include<iostream>
using namespace std;

void insert(int tree[]);
void del(int tree[]);
int search(int tree[], int num);
void height(int tree[]);

void insert(int tree[])
{
	int x;
	cout << "삽입 할 숫자 입력: ";
	cin >> x;

	int i = search(tree, x);

	if (i == -1) tree[1] = x;
	else if (tree[i] == x) {
		cout << "이미 있는 숫자입니다." << endl;
		return;
	}
	else tree[i] = x;
}

void del(int tree[])
{
	int x;
	cout << "삭제 할 숫자 입력: ";
	cin >> x;

	int i = search(tree, x);
	int L = 2 * i;
	int R = 2 * i + 1;

	if (tree[L] == -1 && tree[R] == -1) {
		cout << "삭제 된 노드가 단말노드입니다." << endl;
		tree[i] = -1;
	}

	else if (tree[L] == -1) {
		cout << "삭제 된 노드의 오른쪽에 자식노드 보유" << endl;
		tree[i] = tree[R];
		while (1) {
			if (tree[R * 2 + 1] == -1) {
				tree[R] = -1;
				break;
			}
			else {
				tree[R] = tree[R * 2 + 1];
				R = R * 2 + 1;
			}
		}
	}
	else if (tree[R] == -1) {
		cout << "삭제 된 노드의 왼쪽에 자식노드 보유" << endl;
		tree[i] = tree[L];
		while (1) {
			if (tree[L * 2] == -1) {
				tree[L] = -1;
				break;
			}
			else {
				tree[L] = tree[L * 2];
				L = L * 2;
			}
		}
	}
	else {
		cout << "삭제 된 노드가 자식노드 2개 보유" << endl;
		int j = i * 2 + 1;
		while (1) {
			if (tree[j * 2] == -1) { break; }
			j = j * 2;
		}
		tree[i] = tree[j];
		tree[j] = -1;
	}
}

int search(int tree[], int x)
{
	int i = 1;

	if (tree[1] == -1) return -1;

	while (true) {
		if (tree[i] == x) {
			return i;
		}
		else if (tree[i] > x) {
			i = i * 2;
			if (tree[i] == -1) return i;
		}
		else {
			i = i * 2 + 1;
			if (tree[i] == -1) return i;
		}
	}

	return -1;
}

void height(int tree[])
{
	int index = 0;
	int height = 0;

	for (int i = 1; i < 10000; i++) {
		if (tree[i] != -1) index = i;
	}

	while (index > 0) {
		index /= 2;
		height++;
	}

	cout << "트리의 높이: " << height - 1 << endl;
}

int main() {

	int tree[10000];

	for (int i = 1; i < 10000; i++) {
		tree[i] = -1;
	} // 배열을 -1로 초기화

	for (int i = 1; i < 12; i++) {
		insert(tree);
	}
	height(tree);

	del(tree);
	height(tree);

	del(tree);
	height(tree);

	del(tree);
	height(tree);

	del(tree);
	height(tree);

	system("pause");
	return 0;
}