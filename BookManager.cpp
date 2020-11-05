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

Node* head() //���鸮��Ʈ �����ϴ� �Լ�
{
	Node* head = NULL;
	return head;
}

void addNode(Node*&head, string name, int year, int price) // ��带 tail�� �߰��ϴ� �Լ� 
{
	Node *newNode = new Node;

	newNode->name = name;
	newNode->year = year;
	newNode->price = price;

	newNode->link = NULL;

	if (head == NULL)
	{
		head = newNode; // ��忡 ������ ��� ����
	}

	else
	{
		Node *temp = head;

		while (temp->link != NULL) {
			temp = temp->link;
		}
		temp->link = newNode; //������ ����� ��� ���� ������ ��� ����
	}
}

void deleteNode(Node*&head, string title) // ��带 �����ϴ� �Լ�
{
	Node *pre = head;
	Node *old;

	if (head == NULL) return; // ���� ��尡 ���� ���
	if (head->link == NULL) //���� ��尡 �� ���� ���
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

void print(Node *head)  // ��带 ��ȸ�ϸ� ������ִ� �Լ�
{
	Node *temp = head;
	while (temp != NULL) {
		cout << temp->name << " " << temp->year << "�⵵ " << temp->price << "��" << endl;
		temp = temp->link;
	}
	if (temp == 0) cout << "end" << endl;
}

int main()
{
	Node *L = head();

	addNode(*&L, "c�� ���� ���� �ڷᱸ��", 2018, 2700);
	print(L);
	deleteNode(*&L, "c�� ���� ���� �ڷᱸ��");
	print(L);

	system("pause");
	return 0;
}