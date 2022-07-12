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
***** 정리 *****
* inteeger a는 value로 10을 할당받았음
* reference &b는 변수 a를 참조함
* b와 a는 동일한 address의 변수를 의미함
* 따라서 a++와 b++시 결과는 12로 출력되었음
*/