/*
* CPP-study/CH09/Part3_project/Part3_project에 operator overloading 적용
*/

#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#include "AccountHandler.h"

using namespace std;

int main() {
	AccountHandler account;
	while (1) {
		int choice = account.ShowMenu();
		if (choice == 1) {
			account.MakeAccount();
		}
		if (choice == 2)
			account.Deposit();
		if (choice == 3)
			account.Withhdraw();
		if (choice == 4)
			account.ShowBalance();
		if (choice == 5) {
			cout << endl << endl << "[프로그램 종료]" << endl << endl << " 프로그램 종료" << endl;
			break;
		}
	}
	return 0;
}

