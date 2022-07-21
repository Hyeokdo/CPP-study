/*
* CPP-study/CH08/Part3_project/Part3_project/bank_account.cpp�� HighCreditAccount class ����
*/
#ifndef __HIGHCREDITACCOUNT_H__
#define __HIGHCREDITACCOUNT_H__

#include "NormalAccount.h"

class HighCreditAccount : public NormalAccount {
private:
	int plus_interest;		// �߰�������
public:
	HighCreditAccount(char* name, int account, int money, int interest, int plus_interest);
	virtual int GetAccount();
	virtual void ShowInfo() const;
	virtual int ShowMoney();
	virtual void Dep_With(bool i, int money);
};

#endif