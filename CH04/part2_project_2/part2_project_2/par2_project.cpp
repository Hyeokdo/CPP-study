/*
***** 프로젝트 설명 *****
***** 기능 *****
* 기능 1. 계좌개설
* 기능 2. 입금
* 기능 3. 출금
* 기능 4. 전체 고객 잔액조회
***** 가정 *****
* 계좌번호는 중복되지 않음
* 입금 및 출금액은 0보다 큼
* 고객의 계좌정보는 계좌번호, 고객이름, 잔액 이렇게만 저장
* 계좌번호는 정수의 형태
***** 비고 *****
* CPP-study/CH01-6/CH1_project의 내용에 class 추가하여 구현
* 2022.07.14에 작성했던 part2_project의 경우 원하는 기능을 구현하지 못하였음.
*/

#include <iostream>
#include <cstring>

using namespace std;

class Account {
private:
	char* name;			// 고객이름
	int account;		// 계좌번호
	int money;			// 잔액
public:
	// class initializer
	Account(char* name, int account, int money)
	{
		this->name = new char[strlen(name)];
		strcpy(this->name, name);
		this->account = account;
		this->money = money;
	}
	Account() {
		this->name = 0;
		this->account = 0;
		this->money = 0;
	}
	void Deposit();
	void Withhdraw();
	void ShowBalance();
};
int ShowMenu();
Account MakeAccount();
int i = 0;			// member number
Account* member = new Account[100];		// object pointer array

int main() {
	while (1) {
		int choice = ShowMenu();
		if (choice == 1) {
			member[i] = MakeAccount();
			i++;
		}
		if(choice == 2)
			member->Deposit();
		if(choice == 3)
			member->Withhdraw();
		if (choice == 4)
			member->ShowBalance();
		if (choice == 5) {
			cout << endl << endl << "[프로그램 종료]" << endl << endl << " 프로그램 종료" << endl;
			break;
		}
	}
	return 0;
}
int ShowMenu() {
	int choice;			// 번호 선택
	cout << "----- Menu-----" << endl << "1. 계좌 개설" << endl << "2. 입금" << endl << "3. 출금" << endl << "4. 계좌정보 전체 출력" << endl << "5. 프로그램 종료" << endl << "선택: ";
	cin >> choice;
	return choice;
}
Account MakeAccount() {
	char name[10];
	int account = 0;
	int money;
	cout << endl << "[계좌개설]" << endl << endl << "계좌 ID: ";
	cin >> account;
	cout << "이름: ";
	cin >> name;
	cout << "입금액: ";
	cin >> money;
	cout << endl;
	
	Account person(name, account, money);

	return person;
}
void Account::Deposit() {
	int money;
	int account;
	cout << endl << "[입금]" << endl << endl << "게좌 ID: ";
	cin >> account;
	cout << "입금액: ";
	cin >> money;
	if (account == this->account) {
		this->money += money;
		cout << "입금완료" << endl << endl;
	}
	else
		cout << "찾는 계좌가 없습니다" << endl << endl;
}
void Account::Withhdraw() {
	int money;
	int account;
	cout << endl << "[출금]" << endl << endl << "게좌 ID: ";
	cin >> account;
	cout << "출금액: ";
	cin >> money;
	if (account == this->account) {
		this->money -= money;
		cout << "출금완료" << endl << endl;
	}
	else
		cout << "찾는 계좌가 없습니다" << endl << endl;
}
void Account::ShowBalance() {
	cout << endl << "[계좌정보 전체 출력]" << endl << endl;
	for (int j = 0; j < i; j++) {
		cout << "이름: " << member[j].name << endl << "계좌 ID:" << member[j].account << endl << "잔액: " << member[j].money << endl << endl;
	}
}