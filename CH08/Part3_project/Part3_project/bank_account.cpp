/*
***** ������Ʈ ���� *****
***** ��� *****
* ��� 1. ���°���
* ��� 2. �Ա�
* ��� 3. ���
* ��� 4. ��ü �� �ܾ���ȸ
***** ���� *****
* ���¹�ȣ�� �ߺ����� ����
* �Ա� �� ��ݾ��� 0���� ŭ
* ���� ���������� ���¹�ȣ, ���̸�, �ܾ� �̷��Ը� ����
* ���¹�ȣ�� ������ ����
***** ��� *****
* CPP-study/CH08/Part3_project/Part3_project/bank_account.cpp�� ���뿡 class inheritance �߰�
* Account�� ����Ŭ���� NormalAccount, HighCreditAccount ����
*/

#include <iostream>
#include <cstring>

using namespace std;

class Account {
private:
	char* name;			// ���̸�
	int account;		// ���¹�ȣ
	int money;			// �ܾ�
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
	int interest;			// ������
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
	int plus_interest;		// �߰�������
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
			cout << endl << endl << "[���α׷� ����]" << endl << endl << " ���α׷� ����" << endl;
			break;
		}
	}
	return 0;
}

// AccounterHandler Method
int AccountHandler :: ShowMenu() {
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
	
	// ���� ���� ���� ó��
	while(1) {
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
	while (1) {
		if (account == member->GetAccount()) {
			cout << "�ߺ��� ���� ID�� �ֽ��ϴ�. ���ο� ���� ID�� �Է��Ͻÿ�." << endl << "���� ID: ";
			cin >> account;
		}
		if (account != member->GetAccount())
			break;
	}
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
void AccountHandler::ShowBalance() const{
	cout << endl << "[�������� ��ü ���]" << endl << endl;
	for (int j = 0; j < i; j++) {
		cout << j + 1 << "�� ����" << endl;
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
	cout << "�̸�: " << this->name << endl << "���� ID:" << this->account << endl << "�ܾ�: " << this->money << endl << endl;
}
void Account::Dep_With(bool i, int money) {
	if (i == 0) {
		// �Ա�
		this->money += money;
	}
	if(i == 1){
		// ���
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
	cout << "������: " << this->interest << endl;;
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
	cout << "�ſ���: " << this->plus_interest << endl;
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