/*
***** ������Ʈ ���� *****
***** ��� ***** 
* ��� 1. ���°���
* ��� 2. �Ա�
* ��� 3. ���
* ��� 4. ��ü �� �ܾ���ȸ
***** ���� *****
* ���¹�ȣ�� �ߺ����� ����
* �Ա� �� ��ݾ��� 0���� ŭ
* ���� ���������� ���¹�ȣ, ���̸�, �ܾ� �̷��Ը� ����
* ���¹�ȣ�� ������ ����
*/

#include <iostream>
using namespace std;

struct account {
	char name[10];		// name: user name
	int id, balance;	// id: ���¹�ȣ, balance: �ܾ�
};
account user[10];		// user list
int user_num = 0;		// user number

int __init__();			// �ʱ� ����
void make_account();
void deposit();
void withdraw();
void print();

int main() {
	__init__();

	return 0;
}
int __init__() {
	int select;
	while (1) {
		if (user_num == 10)
			cout << "�� �̻� ���¸� ���� �� �����ϴ�.";
		cout << "------ menu ------" << endl << "1. ���� ����" << endl << "2. �Ա�" << endl << "3. ���" << endl << "4. �������� ��ü ���" << endl << "5. ���α׷� ����" << endl << "����: ";
		cin >> select;
		if (select == 1) 
			make_account();
		if (select == 2)
				deposit();
		if (select == 3)
				withdraw();
		if (select == 4)
				print();
		if (select == 5) {
			cout << endl << endl << "[���α׷� ����]" << endl << endl << " ���α׷� ����" << endl;
			return 0;
		}		
	}
	return 0;
}
void make_account() {
	cout << endl <<"[���°���]" << endl << endl << "���� ID: ";
	cin >> user[user_num].id;
	cout << "�̸�: ";
	cin >> user[user_num].name; 
	cout << "�Աݾ�: ";
	cin >> user[user_num].balance;
	cout << endl;
	user_num++;
}
void deposit() {

	int money, account, i = 0;

	cout << endl << "[�Ա�]" << endl << "���� ID: ";
	cin >> account;
	cout << "�Աݾ�: ";
	cin >> money;
	cout << endl;
	for (i; i < 10; i++) {
		if (account == ::user[i].id) {
			user[i].balance += money;
			break;
		}
	}
	if (i == 10)
		cout << "ã�� ���°� �������� �ʽ��ϴ�." << endl;
}
void withdraw(){
	int money, account, i = 0;

	cout << endl << "[���]" << endl << "���� ID: ";
	cin >> account;
	cout << "��ݾ�: ";
	cin >> money;
	for (i; i < 10; i++) {
		if (account == ::user[i].id) {
			if (user[i].balance < money) {
				cout << endl << "�ܾ��� �����մϴ�." << endl;
				break;
			}
			user[i].balance -= money;
			break;
		}
	}
	if (i == 10)
		cout << "ã�� ���°� �������� �ʽ��ϴ�." << endl;
}
void print() {
	cout << endl << "[�������� ��ü ���]" << endl << endl;

	for (int i = 0; i < 10; i++) {
		if (user[i].id == 0)
			break;
		cout << endl << "���� ID: " << user[i].id << endl << "�̸�: " << user[i].name << endl << "�ܾ�: " << user[i].balance << endl << endl;
	}
}