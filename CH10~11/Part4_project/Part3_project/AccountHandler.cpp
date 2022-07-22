/*
* CPP-study/CH08/Part3_project/Part3_project/bank_account.cpp의 AccountHandler class 정의
*/

#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#include "AccountHandler.h"


using namespace std;

int AccountHandler::ShowMenu() {
	int choice;			// 번호 선택
	cout << endl << "----- Menu-----" << endl << "1. 계좌 개설" << endl << "2. 입금" << endl << "3. 출금" << endl << "4. 계좌정보 전체 출력" << endl << "5. 프로그램 종료" << endl << "선택: ";
	cin >> choice;
	return choice;
}
void AccountHandler::MakeAccount() {
	char name[10];
	int account = 0;
	int money;
	int choice, interest, level;
	Account** temp;

	// 계좌 종류 예외 처리
	while (1) {
		cout << endl << "[계좌종류선택]" << endl << endl << "1. 보통예금계좌 2. 신용신뢰계좌" << endl << "선택: ";
		cin >> choice;
		if (choice == 1 || choice == 2)
			break;
	}
	if (choice == 1)
		cout << endl << "[보통예금";
	if (choice == 2)
		cout << endl << "[신용신뢰";
	cout << "계좌 개설]" << endl << endl << "계좌 ID: ";
	cin >> account;

	// 계좌 ID 중복 체크
	//while (1) {
	//	if (account == (*(*member).array_return())->GetAccount()) {
	//		cout << "중복된 계좌 ID가 있습니다. 새로운 계좌 ID를 입력하시오." << endl << "계좌 ID: ";
	//		cin >> account;
	//	}
	//	if (account != (*(*member).array_return())->GetAccount())
	//		break;
	//}
	cout << "이름: ";
	cin >> name;
	cout << "입금액: ";
	cin >> money;
	cout << "이자율: ";
	cin >> interest;
	if (choice == 2) {
		cout << "신용등급(1toA, 2toB, 3toC): ";
		cin >> level;
		HighCreditAccount person(name, account, money, interest, level);
		person.Dep_With(0, money);
		//*member->array_return() = &person;
		temp = member->array_return();
		temp[i] = &person;
	}
	if (choice == 1) {
		NormalAccount person(name, account, money, interest);
		person.Dep_With(0, money);
		temp = member->array_return();
		temp[i] = &person;
	}
	i++;
}

void AccountHandler::Deposit() {
	int money;
	int account;
	cout << endl << "[입금]" << endl << endl << "게좌 ID: ";
	cin >> account;
	cout << "입금액: ";
	cin >> money;
	for (int j = 0; j < i; j++) {
		if (account == member[j].GetAccount()) {
			member[j].Dep_With(0, money);
			cout << "입금완료" << endl << endl;
			break;
		}
		else
			cout << "찾는 계좌가 없습니다" << endl << endl;
	}
}
void AccountHandler::Withhdraw() {
	int money;
	int account;
	cout << endl << "[출금]" << endl << endl << "게좌 ID: ";
	cin >> account;
	cout << "출금액: ";
	cin >> money;
	for (int j = 0; j < i; j++) {
		if (account == member[j].GetAccount()) {
			if (member[j].ShowMoney() < money) {
				cout << "잔액이 부족합니다." << endl;
				break;
			}
			else {
				member[j].Dep_With(1, money);
				cout << "출금완료" << endl << endl;
				break;
			}
		}
		else
			cout << "찾는 계좌가 없습니다" << endl << endl;
	}
}
void AccountHandler::ShowBalance() const {
	cout << endl << "[계좌정보 전체 출력]" << endl << endl;
	Account** temp;
	for (int j = 0; j < i; j++) {
		cout << j + 1 << "번 계좌" << endl;
		temp = member->array_return();
		(temp[i])->ShowInfo();
	}
}