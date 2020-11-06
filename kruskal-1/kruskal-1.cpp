#include<iostream>
using namespace std;

const int SIZE = 100;

void weight(int A[][SIZE], int Vertex);
void Kruskal(int A[][SIZE], int Vertex);
void print_Kruskal(int A[][SIZE], int Vertex);

int main() {
	int A[SIZE][SIZE];

	int Vertex;
	cout << "Vertex의 개수 입력" << endl;
	cin >> Vertex;
	weight(A, Vertex);
	Kruskal(A, Vertex);
	print_Kruskal(A, Vertex);

	system("pause");
	return 0;
}

void weight(int A[][SIZE], int Vertex) {
	int print = -2;
	for (int i = 0; i < Vertex; i++) {
		print++;
		for (int j = Vertex - 1; j > print; j--) {
			if (i != j) {
				cout << "[" << i << "," << j << "] 가중치 입력: ";
				cin >> A[i][j];
				A[j][i] = A[i][j];
			}
			else if (i == j) { A[i][j] = 0; }
		}
	}
}

void Kruskal(int A[][SIZE], int Vertex) {
	while (true) {
		int check_edge = 0;
		for (int i = 0; i < Vertex; i++) {
			for (int j = 0; j < Vertex; j++) {
				if (A[i][j] != 0) { check_edge++; }
			}
		}
		if (check_edge == ((Vertex - 1) * 2)) { break; }

		int Max_weight = 0, Max_i = 0, Max_j = 0;
		for (int i = 0; i < Vertex; i++) {
			for (int j = 0; j < Vertex; j++) {
				if (Max_weight < A[i][j]) {
					Max_weight = A[i][j];
					Max_i = i;
					Max_j = j;
				}
			}
		}

		int edge_num1 = Vertex;
		int edge_num2 = Vertex;
		for (int j = 0; j < Vertex; j++) {
			if (A[Max_i][j] == 0) {
				edge_num1--;
			}
			if (A[Max_j][j] == 0) {
				edge_num2--;
			}
		}
		if (edge_num1 == 1 || edge_num2 == 1) {
			A[Max_i][Max_j] = -A[Max_i][Max_j];
			A[Max_j][Max_i] = -A[Max_j][Max_i];
		}
		else {
			A[Max_i][Max_j] = 0;
			A[Max_j][Max_i] = 0;
		}
	}

	for (int i = 0; i < Vertex; i++) {
		for (int j = 0; j < Vertex; j++) {
			if (A[i][j] < 0) { A[i][j] = -A[i][j]; }
		}
	}
}

void print_Kruskal(int A[][SIZE], int Vertex) {
	int sum = 0;
	cout << endl;
	cout << "크루스칼 알고리즘 결과" << endl;
	int print = -2;
	for (int i = 0; i < Vertex - 1; i++) {
		print++;
		for (int j = Vertex - 1; j>print; j--) {
			if (A[i][j] != 0) {
				cout << "[" << i << "," << j << "] " << A[i][j] << endl;
				sum += A[i][j];
			}
		}
	}
	cout << "총 weight값: " << sum << endl;
}