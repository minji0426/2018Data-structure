#include <iostream>
#include <string>
using namespace std;

struct Stack
{
	string name;
	int level;
	double grade;

	Stack *link;

};

Stack *top;

int IsEmpty()
{
	if (top == NULL) return 1;
	else return 0;
}

void Push(string name, int level, double grade)
{
	Stack *temp = new Stack;

	temp->name = name;
	temp->level = level;
	temp->grade = grade;

	temp->link = top; //temp의 링크를 현재 top으로 설정
	top = temp; //스택의 맨 앞은 now로 설정
}

void Pop() {
	Stack *temp = top;

	if (IsEmpty()) return;
	else {
		top = temp->link;
		free(temp);
	}
}

void createStack() {
	top = NULL;
}

void printMaxScore() {
	double Max = 0.0;
	Stack *temp = top;

	if (top == NULL) return;

	while (top != NULL) {
		if (temp->grade > Max) Max = temp->grade;
		temp = temp->link;
	}

	temp = top;
	while (top != NULL) {
		if (temp->grade == Max) cout << temp->name << " " << temp->level << " " << temp->grade << endl;
		temp = temp->link;
	}
}

int main()
{
	string name;
	int level;
	int grade;

	createStack();

	cout << "입력을 끝내려면 end 를 입력하세요" << endl;

	while (true) {
		cin >> name >> level >> grade;

		if (name == "end") break;

		Push(name, level, grade);
	}

	printMaxScore();

	system("pause");
	return 0;
}