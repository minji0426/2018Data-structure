#include <iostream>
#include <string>
using namespace std;

struct Node
{
	string name;
	int year;
	int price;

	Node*link;
};

Node* head() //공백리스트 생성하는 함수
{
	Node* head = NULL;
	return head;
}

void addNode(Node*&head, string name, int year, int price) // 노드를 tail에 추가하는 함수 
{
	Node *newNode = new Node;

	newNode->name = name;
	newNode->year = year;
	newNode->price = price;

	newNode->link = NULL;

	if (head == NULL)
	{
		head = newNode; // 헤드에 생성한 노드 연결
	}

	else
	{
		Node *temp = head;

		while (temp->link != NULL) {
			temp = temp->link;
		}
		temp->link = newNode; //마지막 노드일 경우 새로 생성한 노드 연결
	}
}

void deleteNode(Node*&head, string title) // 노드를 삭제하는 함수
{
	Node *pre = head;
	Node *old;

	if (head == NULL) return; // 현재 노드가 없을 경우
	if (head->link == NULL) //현재 노드가 한 개일 경우
	{
		free(head);
		head = NULL;
		return;
	}
	else
	{
		pre = head;
		while (pre->link->name != title) {
			pre = pre->link;
		}
		old = pre->link;
		pre->link = old->link;
		free(old);
	}
}

void print(Node *head)  // 노드를 순회하며 출력해주는 함수
{
	Node *temp = head;
	while (temp != NULL) {
		cout << temp->name << " " << temp->year << "년도 " << temp->price << "원" << endl;
		temp = temp->link;
	}
	if (temp == 0) cout << "end" << endl;
}

int main()
{
	Node *L = head();

	addNode(*&L, "c로 배우는 쉬운 자료구조", 2018, 2700);
	print(L);
	deleteNode(*&L, "c로 배우는 쉬운 자료구조");
	print(L);

	system("pause");
	return 0;
}