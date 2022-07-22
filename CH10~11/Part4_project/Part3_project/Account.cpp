/*
* CPP-study/CH08/Part3_project/Part3_project/bank_account.cpp�� Account class ����
*/
#include "Account.h"

using namespace std;

// Account initializer
Account:: Account(char* name, int account, int money)
{
	this->name = new char[strlen(name)];
	strcpy(this->name, name);
	this->account = account;
	this->money = money;
}
Account::Account(Account& ref)
{
	this->name = new char[strlen(ref.name)];
	strcpy(this->name, ref.name);
	this->account = ref.account;
	this->money = ref.money;
}
Account::Account() {
	this->name = 0;
	this->account = 0;
	this->money = 0;
}

// Account Method
Account& Account::operator=(Account& ref) {
	this->name = ref.name;
	this->account = ref.account;
	this->money = ref.money;
	return *this;
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
	if (i == 1) {
		// ���
		this->money -= money;
	}
}