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
*/

#include <iostream>
using namespace std;

struct account {
	char name[10];		// name: user name
	int id, balance;	// id: 게좌번호, balance: 잔액
};
account user[10];		// user list
int user_num = 0;		// user number

int __init__();			// 초기 설정
void make_account();
void deposit();
void withdraw();
void print();

int main() {
	__init__();

	return 0;
}
int __init__() {
	int select;
	while (1) {
		if (user_num == 10)
			cout << "더 이상 계좌를 만들 수 없습니다.";
		cout << "------ menu ------" << endl << "1. 계좌 개설" << endl << "2. 입금" << endl << "3. 출금" << endl << "4. 계좌정보 전체 출력" << endl << "5. 프로그램 종료" << endl << "선택: ";
		cin >> select;
		if (select == 1) 
			make_account();
		if (select == 2)
				deposit();
		if (select == 3)
				withdraw();
		if (select == 4)
				print();
		if (select == 5) {
			cout << endl << endl << "[프로그램 종료]" << endl << endl << " 프로그램 종료" << endl;
			return 0;
		}		
	}
	return 0;
}
void make_account() {
	cout << endl <<"[계좌개설]" << endl << endl << "계좌 ID: ";
	cin >> user[user_num].id;
	cout << "이름: ";
	cin >> user[user_num].name; 
	cout << "입금액: ";
	cin >> user[user_num].balance;
	cout << endl;
	user_num++;
}
void deposit() {

	int money, account, i = 0;

	cout << endl << "[입금]" << endl << "계좌 ID: ";
	cin >> account;
	cout << "입금액: ";
	cin >> money;
	cout << endl;
	for (i; i < 10; i++) {
		if (account == ::user[i].id) {
			user[i].balance += money;
			break;
		}
	}
	if (i == 10)
		cout << "찾는 계좌가 존재하지 않습니다." << endl;
}
void withdraw(){
	int money, account, i = 0;

	cout << endl << "[출금]" << endl << "계좌 ID: ";
	cin >> account;
	cout << "출금액: ";
	cin >> money;
	for (i; i < 10; i++) {
		if (account == ::user[i].id) {
			if (user[i].balance < money) {
				cout << endl << "잔액이 부족합니다." << endl;
				break;
			}
			user[i].balance -= money;
			break;
		}
	}
	if (i == 10)
		cout << "찾는 계좌가 존재하지 않습니다." << endl;
}
void print() {
	cout << endl << "[계좌정보 전체 출력]" << endl << endl;

	for (int i = 0; i < 10; i++) {
		if (user[i].id == 0)
			break;
		cout << endl << "계좌 ID: " << user[i].id << endl << "이름: " << user[i].name << endl << "잔액: " << user[i].balance << endl << endl;
	}
}