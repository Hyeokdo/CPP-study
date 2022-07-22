/*
* CPP-study/CH08/Part3_project/Part3_project/bank_account.cpp의 NormalAccount class 정의
*/
#include "Account.h"
#include "NormalAccount.h"
#include <iostream>

using namespace std;

// NormalAccount initializer
NormalAccount::NormalAccount(char* name, int account, int money, int interest)
	:Account(name, account, money), interest(interest) {}

// NormalAccount Method
int NormalAccount::GetAccount() {
	return Account::GetAccount();
}
int NormalAccount::ShowMoney() {
	return Account::ShowMoney();
}
void NormalAccount::ShowInfo() const {
	Account::ShowInfo();
	cout << "이자율: " << this->interest << endl;;
}
void NormalAccount::Dep_With(bool i, int money) {
	Account::Dep_With(0, money * this->interest / 100);
}
