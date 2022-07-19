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
* CPP-study/CH06/friend_static_const/friend_static_const/part2_project.cpp의 내용에 Enitity class와 Control class 개념 추가
* Entity class Name: Account, Control class Name: AccountHander
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
	Account(Account& ref)
	{
		this->name = new char[strlen(ref.name)];
		strcpy(this->name, ref.name);
		this->account = ref.account;
		this->money = ref.money;
	}
	Account() {
		this->name = 0;
		this->account = 0;
		this->money = 0;
	}
	int GetAccount();
	void Dep_With(bool i, int money);
	void ShowInfo() const;
	int ShowMoney();
};


class AccountHandler : public Account {
private:
	Account* member = new Account[100];
	int i = 0;					// Account number
public:
	int ShowMenu();
	void MakeAccount();
	void Deposit();
	void Withhdraw();
	void ShowBalance() const ;
};


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
int AccountHandler :: ShowMenu() {
	int choice;			// 번호 선택
	cout << "----- Menu-----" << endl << "1. 계좌 개설" << endl << "2. 입금" << endl << "3. 출금" << endl << "4. 계좌정보 전체 출력" << endl << "5. 프로그램 종료" << endl << "선택: ";
	cin >> choice;
	return choice;
}
void AccountHandler::MakeAccount() {
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
	member[i] = person;
	i++;
}
void AccountHandler :: Deposit() {
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
			if (member[j].ShowMoney() < money)
				cout << "잔액이 부족합니다." << endl;
			else {
				member[j].Dep_With(1, money);
				cout << "출금완료" << endl << endl;
			}
		}
		else
			cout << "찾는 계좌가 없습니다" << endl << endl;
	}
}
void AccountHandler::ShowBalance() const{
	cout << endl << "[계좌정보 전체 출력]" << endl << endl;
	for (int j = 0; j < i; j++) {
		member[j].ShowInfo();
	}
}
int Account::GetAccount() {
	return this->account;
}
int Account::ShowMoney() {
	return this->money;
}
void Account::ShowInfo() const {
	cout << "이름: " << this->name << endl << "계좌 ID:" << this->account << endl << "잔액: " << this->money << endl << endl;
}
void Account::Dep_With(bool i, int money) {
	if (i == 0) {
		// 입금
		this->money += money;
	}
	if(i == 1){
		// 출금
		this->money -= money;
	}
}