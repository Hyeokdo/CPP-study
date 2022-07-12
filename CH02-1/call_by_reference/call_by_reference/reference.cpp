/*
* ���� 02-1 call by reference
* ���� 1
* ���ڷ� ���޵� int ������ ���� 1�� ����
* ���ڷ� ���޵� int ������ ��ȣ�� �ٲٴ� �Լ�
*
* ���� 2 
* void SwapByRef(int &ref1, int &ref2)�� �Լ�����
* SwapByRef(23, 45)�� ���·� ȣ�� �� ��� compile error�� �߻��ϴ� ������?
* 
* ���� 3
* pointer�� parameter�� �ϴ� �Լ��� �����
* �� ������ value�� �ٲ�� �Լ� ����
*/

#include <iostream>
using namespace std;

void int_plus_1(int* n);
void int_reverse(int* n);
void int_change(int* n1, int* n2);

int main() {

	//���� 1
	int a = 10, b = 10;

	int_plus_1(&a);
	int_reverse(&b);

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	//���� 3
	int_change(&a, &b);

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	return 0;
}
void int_plus_1(int* n) {
	*n += *n;
}
void int_reverse(int* n) {
	*n *= -1;
}
void int_change(int* n1, int* n2) {

	int temp = 0;
	
	temp = *n1;
	*n1 = *n2;
	*n2 = temp;

}
/*
***** ���� *****
* call by reference�� ��� parameter�� reference�� ����
* reference�� ���� �ش� ���� address�� ���� �� ������ value�� ����
*/