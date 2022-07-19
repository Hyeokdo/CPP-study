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
* CPP-study/CH06/friend_static_const/friend_static_const/part2_project.cpp�� ���뿡 Enitity class�� Control class ���� �߰�
* Entity class Name: Account, Control class Name: AccountHander
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
	Account(Account& ref)
	{
		this->name = new char[strlen(ref.name)];
		strcpy(this->name, ref.name);
		this->account = ref.account;
		this->money = ref.money;
	}
	Account() {
		this->name = 0;
		this->account = 0;
		this->money = 0;
	}
	int GetAccount();
	void Dep_With(bool i, int money);
	void ShowInfo() const;
	int ShowMoney();
};


class AccountHandler : public Account {
private:
	Account* member = new Account[100];
	int i = 0;					// Account number
public:
	int ShowMenu();
	void MakeAccount();
	void Deposit();
	void Withhdraw();
	void ShowBalance() const ;
};


int main() {
	AccountHandler account;
	while (1) {
		int choice = account.ShowMenu();
		if (choice == 1) {
			account.MakeAccount();
		}
		if (choice == 2)
			account.Deposit();
		if (choice == 3)
			account.Withhdraw();
		if (choice == 4)
			account.ShowBalance();
		if (choice == 5) {
			cout << endl << endl << "[���α׷� ����]" << endl << endl << " ���α׷� ����" << endl;
			break;
		}
	}
	return 0;
}
int AccountHandler :: ShowMenu() {
	int choice;			// ��ȣ ����
	cout << "----- Menu-----" << endl << "1. ���� ����" << endl << "2. �Ա�" << endl << "3. ���" << endl << "4. �������� ��ü ���" << endl << "5. ���α׷� ����" << endl << "����: ";
	cin >> choice;
	return choice;
}
void AccountHandler::MakeAccount() {
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
	member[i] = person;
	i++;
}
void AccountHandler :: Deposit() {
	int money;
	int account;
	cout << endl << "[�Ա�]" << endl << endl << "���� ID: ";
	cin >> account;
	cout << "�Աݾ�: ";
	cin >> money;
	for (int j = 0; j < i; j++) {
		if (account == member[j].GetAccount()) {
			member[j].Dep_With(0, money);
			cout << "�ԱݿϷ�" << endl << endl;
		}
		else
			cout << "ã�� ���°� �����ϴ�" << endl << endl;
	}
}
void AccountHandler::Withhdraw() {
	int money;
	int account;
	cout << endl << "[���]" << endl << endl << "���� ID: ";
	cin >> account;
	cout << "��ݾ�: ";
	cin >> money;
	for (int j = 0; j < i; j++) {
		if (account == member[j].GetAccount()) {
			if (member[j].ShowMoney() < money)
				cout << "�ܾ��� �����մϴ�." << endl;
			else {
				member[j].Dep_With(1, money);
				cout << "��ݿϷ�" << endl << endl;
			}
		}
		else
			cout << "ã�� ���°� �����ϴ�" << endl << endl;
	}
}
void AccountHandler::ShowBalance() const{
	cout << endl << "[�������� ��ü ���]" << endl << endl;
	for (int j = 0; j < i; j++) {
		member[j].ShowInfo();
	}
}
int Account::GetAccount() {
	return this->account;
}
int Account::ShowMoney() {
	return this->money;
}
void Account::ShowInfo() const {
	cout << "�̸�: " << this->name << endl << "���� ID:" << this->account << endl << "�ܾ�: " << this->money << endl << endl;
}
void Account::Dep_With(bool i, int money) {
	if (i == 0) {
		// �Ա�
		this->money += money;
	}
	if(i == 1){
		// ���
		this->money -= money;
	}
}