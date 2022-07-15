/*
* 문제 04-3
* 성명, 회사이름, 전화번호, 직급의 정보를 포함하는 NameCard class 정의
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
			cout << "사원" << endl;
			break;
		case SENIOR:
			cout << "주임" << endl;
			break;
		case ASSIST:
			cout << "대리 " << endl;
			break;
		case MANAGER:
			cout << "과장" << endl;
			break;
	}
}
void NameCard::ShowNameCardInfo() {
	cout << "이름: " << name << endl << "회사: " << company << endl << "전화번호: " << phone << endl << "직급: ";
	COMP_POS::ShowPosition(position);
	cout << endl << endl;
}
/*
***** 정리 *****
* Visual Studio 2017 버전 이상의 경우 표준 문접을 엄격히 사용하도록 되어있음
* permissive- 모드로 기본 설정 되어있음
* 따라서 char*가 아닌 string 사용 권장
* 37, 38, 39 line에서 error 발생
*** 해결방법 ***
* 프로젝트 -> 속성 -> C/C++ -> 언어 -> 준수 모드(예(permissive-)) -> 아니요 설정 변경
*/