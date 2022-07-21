/*
* CPP-study/CH08/Part3_project/Part3_project/bank_account.cpp�� NormalAccount class ����
*/
#ifndef __NORMALACCOUNT_H__
#define __NORMALACCOUNT_H__

#include "Account.h"

class NormalAccount : public Account {
private:
	int interest;			// ������
public:
	NormalAccount(char* name, int account, int money, int interest);
	virtual int GetAccount();
	virtual void ShowInfo() const;
	virtual int ShowMoney();
	virtual void Dep_With(bool i, int money);
};

#endif