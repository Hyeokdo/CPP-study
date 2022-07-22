/*
* CPP-study/CH08/Part3_project/Part3_project/bank_account.cppÀÇ Account class Á¤ÀÇ
*/

#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include <iostream>
#include <cstring>

class Account {
private:
	char* name;			// °í°´ÀÌ¸§
	int account;		// °èÁÂ¹øÈ£
	int money;			// ÀÜ¾×
public:
	// class initializer
	Account(char* name, int account, int money);
	Account(Account& ref);
	Account();
	Account& operator=(Account& ref);

	virtual int GetAccount();
	virtual void Dep_With(bool i, int money);
	virtual void ShowInfo() const;
	virtual int ShowMoney();
};

#endif