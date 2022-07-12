/*
* 문제 02-1 call by reference
* 문제 1
* 인자로 전달된 int 변수의 값을 1씩 증가
* 인자로 전달된 int 변수의 부호를 바꾸는 함수
*
* 문제 2 
* void SwapByRef(int &ref1, int &ref2)의 함수에서
* SwapByRef(23, 45)의 형태로 호출 할 경우 compile error가 발생하는 이유는?
* 
* 문제 3
* pointer을 parameter로 하는 함수를 만들어
* 두 변수의 value가 바뀌도록 함수 정의
*/

#include <iostream>
using namespace std;

void int_plus_1(int* n);
void int_reverse(int* n);
void int_change(int* n1, int* n2);

int main() {

	//문제 1
	int a = 10, b = 10;

	int_plus_1(&a);
	int_reverse(&b);

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	//문제 3
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
***** 정리 *****
* call by reference의 경우 parameter로 reference를 받음
* reference를 통해 해당 변수 address를 참조 해 변수의 value를 변경
*/