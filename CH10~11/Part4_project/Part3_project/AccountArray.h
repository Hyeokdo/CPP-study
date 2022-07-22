/*
* �迭�� index�� �ʰ��ϴ� ��츦 ����
*/

#ifndef __ACCOUNTARRAY_H__
#define __ACCOUNTARRAY_H__

#include "Account.h"

using namespace std;

class AccountArray: public Account {
private:
	Account** arr;
	int len_of_array;
public:
	AccountArray(int len);
	Account* operator[] (int len_over);
	Account*& operator[] (int len_over) const;
	Account* return_arr(int i, Account acc);
	Account** array_return();
};

#endif