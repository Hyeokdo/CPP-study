/*
* CPP-study/CH08/Part3_project/Part3_project/bank_account.cpp¿« AccountHandler class ¡§¿«
*/

#ifndef __ACCOUNTHANDLER_H__
#define __ACCOUNTHANDLER_H__

#include "Account.h"

class AccountHandler : public Account {
private:
	Account* member = new Account[100];
	int i = 0;					// Account number
public:
	int ShowMenu();
	void MakeAccount();
	void Deposit();
	void Withhdraw();
	void ShowBalance() const;
};
#endif