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
*/

#include <iostream>
#include <cstring>

using namespace std;

class Account {
private:
	char* name;			// 고객이름
	char* account;		// 계좌번호
	int money;			// 잔액
public:
	// class initializer
	Account(char* name, char* account, int money)
	{
		this->name = new char[strlen(name)];
		this->account = new char[strlen(account)];
		strcpy(this->name, name);
		strcpy(this->name, name);
		this->money = money;
	}
	Account() {
		this->name = 0;
		this->account = 0;
		this->money = 0;
	}

	void MakeAccount();
	void Deposit();
	void Withhdraw();
	void ShowBalance();
};
int ShowMenu();

int main() {
	// object pointer array
	Account* member = new Account[100];
	int i = 0;			// member number
	while (1) {
		int choice = ShowMenu();
		
		switch (choice) {
		case 1:
			member[i].MakeAccount();
			i++;
			break;
		case 2:
			member->Deposit();
		case 3:
			member->Withhdraw();
		case 4:
		case 5:
			cout << endl << endl << "[프로그램 종료]" << endl << endl << " 프로그램 종료" << endl;
			return 0;
		}
	}

	return 0;
}
int ShowMenu() {
	int choice;			// 번호 선택
	cout << "---- - Menu-----" << endl << "1. 계좌 개설" << endl << "2. 입금" << endl << "3. 출금" << endl << "4. 계좌정보 전체 출력" << endl << "5. 프로그램 종료" << endl << "선택: ";
	cin >> choice;
	return choice;
}
void Account::MakeAccount() {
	char* name = 0;
	char* account = 0;
	int money;
	cout << "[계좌개설]" << endl << "계좌 ID: ";
	cin >> account;
	cout << endl << "이름: ";
	cin >> name;
	cout << endl << "입금액: ";
	cin >> money;
	cout << endl;

	Account person(name, account, money);
}
void Account::Deposit() {
	int money;
	char* account = 0;
	cout << "[입금]" << endl << "게좌 ID: ";
	cin >> account;
	cout << "입금액: " << endl;
	cin >> money;
	cout << endl << "입금완료" << endl;
	if (account == this->account)
		this->money += money;
}
void Account::Withhdraw() {
	int money;
	char* account = 0;
	cout << "[출금]" << endl << "게좌 ID: ";
	cin >> account;
	cout << "출금액: " << endl;
	cin >> money;
	cout << endl << "출금완료" << endl;
	if (account == this->account)
		this->money -= money;
}
void Account::ShowBalance() {
	
}
