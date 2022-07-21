/*
* CPP-study/CH08/Part3_project/Part3_project/bank_account.cpp의 Account class 정의
*/

#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include <iostream>
#include <cstring>

class Account {
private:
	char* name;			// 고객이름
	int account;		// 계좌번호
	int money;			// 잔액
public:
	// class initializer
	Account(char* name, int account, int money);
	Account(Account& ref);
	Account();

	virtual int GetAccount();
	virtual void Dep_With(bool i, int money);
	virtual void ShowInfo() const;
	virtual int ShowMoney();
};

#endif