/*
* CPP-study/CH08/Part3_project/Part3_project/bank_account.cpp�� AccountHandler class ����
*/

#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#include "AccountHandler.h"


using namespace std;

int AccountHandler::ShowMenu() {
	int choice;			// ��ȣ ����
	cout << endl << "----- Menu-----" << endl << "1. ���� ����" << endl << "2. �Ա�" << endl << "3. ���" << endl << "4. �������� ��ü ���" << endl << "5. ���α׷� ����" << endl << "����: ";
	cin >> choice;
	return choice;
}
void AccountHandler::MakeAccount() {
	char name[10];
	int account = 0;
	int money;
	int choice, interest, level;
	Account** temp;

	// ���� ���� ���� ó��
	while (1) {
		cout << endl << "[������������]" << endl << endl << "1. ���뿹�ݰ��� 2. �ſ�ŷڰ���" << endl << "����: ";
		cin >> choice;
		if (choice == 1 || choice == 2)
			break;
	}
	if (choice == 1)
		cout << endl << "[���뿹��";
	if (choice == 2)
		cout << endl << "[�ſ�ŷ�";
	cout << "���� ����]" << endl << endl << "���� ID: ";
	cin >> account;

	// ���� ID �ߺ� üũ
	//while (1) {
	//	if (account == (*(*member).array_return())->GetAccount()) {
	//		cout << "�ߺ��� ���� ID�� �ֽ��ϴ�. ���ο� ���� ID�� �Է��Ͻÿ�." << endl << "���� ID: ";
	//		cin >> account;
	//	}
	//	if (account != (*(*member).array_return())->GetAccount())
	//		break;
	//}
	cout << "�̸�: ";
	cin >> name;
	cout << "�Աݾ�: ";
	cin >> money;
	cout << "������: ";
	cin >> interest;
	if (choice == 2) {
		cout << "�ſ���(1toA, 2toB, 3toC): ";
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
	cout << endl << "[�Ա�]" << endl << endl << "���� ID: ";
	cin >> account;
	cout << "�Աݾ�: ";
	cin >> money;
	for (int j = 0; j < i; j++) {
		if (account == member[j].GetAccount()) {
			member[j].Dep_With(0, money);
			cout << "�ԱݿϷ�" << endl << endl;
			break;
		}
		else
			cout << "ã�� ���°� �����ϴ�" << endl << endl;
	}
}
void AccountHandler::Withhdraw() {
	int money;
	int account;
	cout << endl << "[���]" << endl << endl << "���� ID: ";
	cin >> account;
	cout << "��ݾ�: ";
	cin >> money;
	for (int j = 0; j < i; j++) {
		if (account == member[j].GetAccount()) {
			if (member[j].ShowMoney() < money) {
				cout << "�ܾ��� �����մϴ�." << endl;
				break;
			}
			else {
				member[j].Dep_With(1, money);
				cout << "��ݿϷ�" << endl << endl;
				break;
			}
		}
		else
			cout << "ã�� ���°� �����ϴ�" << endl << endl;
	}
}
void AccountHandler::ShowBalance() const {
	cout << endl << "[�������� ��ü ���]" << endl << endl;
	Account** temp;
	for (int j = 0; j < i; j++) {
		cout << j + 1 << "�� ����" << endl;
		temp = member->array_return();
		(temp[i])->ShowInfo();
	}
}