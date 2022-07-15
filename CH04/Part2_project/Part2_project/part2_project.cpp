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
*/

#include <iostream>
#include <cstring>

using namespace std;

class Account {
private:
	char* name;			// ���̸�
	char* account;		// ���¹�ȣ
	int money;			// �ܾ�
public:
	// class initializer
	Account(char* name, char* account, int money)
	{
		this->name = new char[strlen(name)];
		this->account = new char[strlen(account)];
		strcpy(this->name, name);
		strcpy(this->name, name);
		this->money = money;
	}
	Account() {
		this->name = 0;
		this->account = 0;
		this->money = 0;
	}

	void MakeAccount();
	void Deposit();
	void Withhdraw();
	void ShowBalance();
};
int ShowMenu();

int main() {
	// object pointer array
	Account* member = new Account[100];
	int i = 0;			// member number
	while (1) {
		int choice = ShowMenu();
		
		switch (choice) {
		case 1:
			member[i].MakeAccount();
			i++;
			break;
		case 2:
			member->Deposit();
		case 3:
			member->Withhdraw();
		case 4:
		case 5:
			cout << endl << endl << "[���α׷� ����]" << endl << endl << " ���α׷� ����" << endl;
			return 0;
		}
	}

	return 0;
}
int ShowMenu() {
	int choice;			// ��ȣ ����
	cout << "---- - Menu-----" << endl << "1. ���� ����" << endl << "2. �Ա�" << endl << "3. ���" << endl << "4. �������� ��ü ���" << endl << "5. ���α׷� ����" << endl << "����: ";
	cin >> choice;
	return choice;
}
void Account::MakeAccount() {
	char* name = 0;
	char* account = 0;
	int money;
	cout << "[���°���]" << endl << "���� ID: ";
	cin >> account;
	cout << endl << "�̸�: ";
	cin >> name;
	cout << endl << "�Աݾ�: ";
	cin >> money;
	cout << endl;

	Account person(name, account, money);
}
void Account::Deposit() {
	int money;
	char* account = 0;
	cout << "[�Ա�]" << endl << "���� ID: ";
	cin >> account;
	cout << "�Աݾ�: " << endl;
	cin >> money;
	cout << endl << "�ԱݿϷ�" << endl;
	if (account == this->account)
		this->money += money;
}
void Account::Withhdraw() {
	int money;
	char* account = 0;
	cout << "[���]" << endl << "���� ID: ";
	cin >> account;
	cout << "��ݾ�: " << endl;
	cin >> money;
	cout << endl << "��ݿϷ�" << endl;
	if (account == this->account)
		this->money -= money;
}
void Account::ShowBalance() {
	
}
