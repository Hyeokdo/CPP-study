#include <iostream>
using namespace std;

int main() {

	int a = 10;
	int& b = a;

	a++;
	b++;

	cout << a << endl;
	cout << b << endl;

	return 0;
}
/*
***** ���� *****
* inteeger a�� value�� 10�� �Ҵ�޾���
* reference &b�� ���� a�� ������
* b�� a�� ������ address�� ������ �ǹ���
* ���� a++�� b++�� ����� 12�� ��µǾ���
*/