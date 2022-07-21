/*
* CPP-study/CH08/Part3_project/Part3_project/bank_account.cpp의 HighCreditAccount class 정의
*/
#include <iostream>
#include "HighCreditAccount.h"

using namespace std;

// HighCreditAccount initializer
HighCreditAccount::HighCreditAccount(char* name, int account, int money, int interest, int plus_interest)
	:NormalAccount(name, account, money, interest), plus_interest(plus_interest) {}

// HighCreditAccount Method
int HighCreditAccount::GetAccount() {
	return Account::GetAccount();
}
int HighCreditAccount::ShowMoney() {
	return Account::ShowMoney();
}
void HighCreditAccount::ShowInfo() const {
	NormalAccount::ShowInfo();
	cout << "신용등급: " << this->plus_interest << endl;
}
void HighCreditAccount::Dep_With(bool i, int money) {
	int plus_interest = 0;
	if (this->plus_interest == 1)
		plus_interest = 7;
	if (this->plus_interest == 2)
		plus_interest = 4;
	if (this->plus_interest == 3)
		plus_interest = 2;
	NormalAccount::Dep_With(0, money);
	Account::Dep_With(0, money * plus_interest / 100);
}