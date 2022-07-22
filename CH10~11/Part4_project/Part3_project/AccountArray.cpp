
#include "Account.h"
#include "AccountArray.h"

AccountArray::AccountArray(int len) {
	len_of_array = len;
	arr = new Account*[len];
}
Account* AccountArray::operator[] (int len_over) {
	if (len_over < 0 || len_over > len_of_array) {
		cout << "indexÀÇ ¹üÀ§¸¦ ¹þ¾î³µ½À´Ï´Ù." << endl;
		exit(1);
	}
	return arr[len_over];
}
Account*& AccountArray::operator[] (int len_over) const {
	if (len_over < 0 || len_over > len_of_array) {
		cout << "indexÀÇ ¹üÀ§¸¦ ¹þ¾î³µ½À´Ï´Ù." << endl;
		exit(1);
	}
	return arr[len_over];
}
Account* AccountArray::return_arr(int i, Account acc) {
	*arr[i] = acc;
	return arr[i];
}
Account** AccountArray::array_return(){
	return this->arr;
}

