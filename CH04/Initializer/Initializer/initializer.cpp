/*
* ���� 04-3
* ����, ȸ���̸�, ��ȭ��ȣ, ������ ������ �����ϴ� NameCard class ����
*/
#include <iostream>
#include <cstring>

using namespace std;

namespace COMP_POS {
	enum {
		CLERK, SENIOR, ASSIST, MANAGER
	};
	void ShowPosition(int pos);
};
class NameCard {
private:
	char* name;
	char* company;
	char* phone;
	int position;
public:
	NameCard(char * _name, char * _company, char * _phone, int pos)
		: position(pos)
	{
		name = new char[strlen(_name) + 1];
		company = new char[strlen(_company) + 1];
		phone = new char[strlen(_phone) + 1];
		strcpy(name, _name);
		strcpy(company, _company);
		strcpy(phone, _phone);
	}
	void ShowNameCardInfo();
};

int main() {
	NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
	NameCard manSENIOR("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
	NameCard manAssist("kim", "SoGoodComp", "010-5555-6666", COMP_POS::ASSIST);
	manClerk.ShowNameCardInfo();
	manSENIOR.ShowNameCardInfo();
	manAssist.ShowNameCardInfo();

	return 0;
}
void COMP_POS::ShowPosition(int pos)  {
	switch (pos) {
		case CLERK:
			cout << "���" << endl;
			break;
		case SENIOR:
			cout << "����" << endl;
			break;
		case ASSIST:
			cout << "�븮 " << endl;
			break;
		case MANAGER:
			cout << "����" << endl;
			break;
	}
}
void NameCard::ShowNameCardInfo() {
	cout << "�̸�: " << name << endl << "ȸ��: " << company << endl << "��ȭ��ȣ: " << phone << endl << "����: ";
	COMP_POS::ShowPosition(position);
	cout << endl << endl;
}
/*
***** ���� *****
* Visual Studio 2017 ���� �̻��� ��� ǥ�� ������ ������ ����ϵ��� �Ǿ�����
* permissive- ���� �⺻ ���� �Ǿ�����
* ���� char*�� �ƴ� string ��� ����
* 37, 38, 39 line���� error �߻�
*** �ذ��� ***
* ������Ʈ -> �Ӽ� -> C/C++ -> ��� -> �ؼ� ���(��(permissive-)) -> �ƴϿ� ���� ����
*/