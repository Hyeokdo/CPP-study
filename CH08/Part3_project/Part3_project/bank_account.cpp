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
* CPP-study/CH08/Part3_project/Part3_project/bank_account.cpp의 내용에 class inheritance 추가
* Account의 유도클래스 NormalAccount, HighCreditAccount 생성
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
	virtual int GetAccount();
	virtual void Dep_With(bool i, int money);
	virtual void ShowInfo() const;
	virtual int ShowMoney();
};

class NormalAccount : public Account {
private:
	int interest;			// 이자율
public:
	NormalAccount(char* name, int account, int money, int interest)
		:Account(name, account, money), interest(interest){}
	virtual int GetAccount();
	virtual void ShowInfo() const;
	virtual int ShowMoney();
	virtual void Dep_With(bool i, int money);
};

class HighCreditAccount : public NormalAccount {
private:
	int plus_interest;		// 추가이자율
public:
	HighCreditAccount(char* name, int account, int money, int interest, int plus_interest)
		:NormalAccount(name, account, money, interest), plus_interest(plus_interest){}
	virtual int GetAccount();
	virtual void ShowInfo() const;
	virtual int ShowMoney();
	virtual void Dep_With(bool i, int money);
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

// AccounterHandler Method
int AccountHandler :: ShowMenu() {
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
	
	// 계좌 종류 예외 처리
	while(1) {
		cout << endl << "[게좌종류선택]" << endl << endl << "1. 보통예금계좌 2. 신용신뢰계좌" << endl << "선택: ";
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
	while (1) {
		if (account == member->GetAccount()) {
			cout << "중복된 계좌 ID가 있습니다. 새로운 계좌 ID를 입력하시오." << endl << "계좌 ID: ";
			cin >> account;
		}
		if (account != member->GetAccount())
			break;
	}
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
		member[i] = person;
	}
	if(choice == 1){
		NormalAccount person(name, account, money, interest);
		person.Dep_With(0, money);
		member[i] = person;
	}
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
void AccountHandler::ShowBalance() const{
	cout << endl << "[계좌정보 전체 출력]" << endl << endl;
	for (int j = 0; j < i; j++) {
		cout << j + 1 << "번 계좌" << endl;
		member[j].ShowInfo();
	}
}

// Account Method
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

// NormalAccount Method
int NormalAccount::GetAccount() {
	return Account::GetAccount();
}
int NormalAccount::ShowMoney() {
	return Account::ShowMoney();
}
void NormalAccount::ShowInfo() const {
	Account::ShowInfo();
	cout << "이자율: " << this->interest << endl;;
}
void NormalAccount::Dep_With(bool i, int money) {
	Account::Dep_With(0, money * this->interest / 100);
}

// HighCreditAccount Method
int HighCreditAccount::GetAccount() {
	return Account::GetAccount();
}
int HighCreditAccount::ShowMoney() {
	return Account::ShowMoney();
}
void HighCreditAccount::ShowInfo() const {
	NormalAccount::ShowInfo();
	cout << "신용등급: " << this->plus_interest << endl;
}
void HighCreditAccount::Dep_With(bool i, int money) {
	int plus_interest;
	if (this->plus_interest == 1)
		plus_interest = 7;
	if (this->plus_interest == 2)
		plus_interest = 4;
	if (this->plus_interest == 3)
		plus_interest = 2;
	NormalAccount::Dep_With(0, money);
	Account::Dep_With(0, money * plus_interest / 100);
}