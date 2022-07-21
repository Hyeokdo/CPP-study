/*
* CPP-study/CH08/Part3_project/Part3_project/bank_account.cpp�� Account class ����
*/

#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include <iostream>
#include <cstring>

class Account {
private:
	char* name;			// ���̸�
	int account;		// ���¹�ȣ
	int money;			// �ܾ�
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