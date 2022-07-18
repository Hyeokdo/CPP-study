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
***** ��� *****
* CPP-study/CH01-6/CH1_project�� ���뿡 class �߰��Ͽ� ����
* 2022.07.14�� �ۼ��ߴ� part2_project�� ��� ���ϴ� ����� �������� ���Ͽ���.
*/

#include <iostream>
#include <cstring>

using namespace std;

class Account {
private:
	char* name;			// ���̸�
	int account;		// ���¹�ȣ
	int money;			// �ܾ�
public:
	// class initializer
	Account(char* name, int account, int money)
	{
		this->name = new char[strlen(name)];
		strcpy(this->name, name);
		this->account = account;
		this->money = money;
	}
	Account() {
		this->name = 0;
		this->account = 0;
		this->money = 0;
	}
	void Deposit();
	void Withhdraw();
	void ShowBalance();
};
int ShowMenu();
Account MakeAccount();
int i = 0;			// member number
Account* member = new Account[100];		// object pointer array

int main() {
	while (1) {
		int choice = ShowMenu();
		if (choice == 1) {
			member[i] = MakeAccount();
			i++;
		}
		if(choice == 2)
			member->Deposit();
		if(choice == 3)
			member->Withhdraw();
		if (choice == 4)
			member->ShowBalance();
		if (choice == 5) {
			cout << endl << endl << "[���α׷� ����]" << endl << endl << " ���α׷� ����" << endl;
			break;
		}
	}
	return 0;
}
int ShowMenu() {
	int choice;			// ��ȣ ����
	cout << "----- Menu-----" << endl << "1. ���� ����" << endl << "2. �Ա�" << endl << "3. ���" << endl << "4. �������� ��ü ���" << endl << "5. ���α׷� ����" << endl << "����: ";
	cin >> choice;
	return choice;
}
Account MakeAccount() {
	char name[10];
	int account = 0;
	int money;
	cout << endl << "[���°���]" << endl << endl << "���� ID: ";
	cin >> account;
	cout << "�̸�: ";
	cin >> name;
	cout << "�Աݾ�: ";
	cin >> money;
	cout << endl;
	
	Account person(name, account, money);

	return person;
}
void Account::Deposit() {
	int money;
	int account;
	cout << endl << "[�Ա�]" << endl << endl << "���� ID: ";
	cin >> account;
	cout << "�Աݾ�: ";
	cin >> money;
	if (account == this->account) {
		this->money += money;
		cout << "�ԱݿϷ�" << endl << endl;
	}
	else
		cout << "ã�� ���°� �����ϴ�" << endl << endl;
}
void Account::Withhdraw() {
	int money;
	int account;
	cout << endl << "[���]" << endl << endl << "���� ID: ";
	cin >> account;
	cout << "��ݾ�: ";
	cin >> money;
	if (account == this->account) {
		this->money -= money;
		cout << "��ݿϷ�" << endl << endl;
	}
	else
		cout << "ã�� ���°� �����ϴ�" << endl << endl;
}
void Account::ShowBalance() {
	cout << endl << "[�������� ��ü ���]" << endl << endl;
	for (int j = 0; j < i; j++) {
		cout << "�̸�: " << member[j].name << endl << "���� ID:" << member[j].account << endl << "�ܾ�: " << member[j].money << endl << endl;
	}
}