/*
* 문제 03-2
* 클래스의 정의
* 문제 1
* Calculator 클래스 정의
* 문제 2
* Printer 클래스 정의
* 기능: 문자열 저장, 문자열 출력
*/

#include <iostream>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

//문제 1
class calculator {

private:
	int count_add, count_min, count_div, count_mul;		// 연산횟수 저장
public:
	void init();
	int Add(int a, int b);
	int Min(int a, int b);
	int Div(int a, int b);
	int Mul(int a, int b);
	void ShowOpCount();
};

//문제 2
class printer {
private:
	char str[30];
public:
	void SetString(const char* a);
	void ShowString();
};


int main() {

	calculator cal;
	cal.init();

	cout << "10 + 10 = " << cal.Add(10, 10) << endl;
	cout << "10 - 10 = " << cal.Min(10, 10) << endl;
	cout << "10 * 10 = " << cal.Mul(10, 10) << endl;
	cout << "10 / 10 = " << cal.Div(10, 10) << endl;

	cal.ShowOpCount();

	printer prt;
	prt.SetString("Hello World!");
	prt.ShowString();

	return 0;
}

void calculator::init() {
	count_add = 0, count_min = 0, count_div = 0, count_mul = 0;
}
int calculator::Add(int a, int b) {
	int add = a + b;
	count_add++;
	return add;
}
int calculator::Min(int a, int b) {
	int min = a - b;
	count_min++;
	return min;
}
int calculator::Div(int a, int b) {
	int div = a / b;
	count_div++;
	return div;
}
int calculator::Mul(int a, int b) {
	int mul = a * b;
	count_mul++;
	return mul;
}
void calculator::ShowOpCount() {

	cout << "덧셈: " << count_add << " 뺄셈: " << count_min << " 곱셈: " << count_mul << " 나눗셈: " << count_div << endl;
}

void printer::SetString(const char* a) {
	strcpy_s(str, a);
}
void printer::ShowString() {
	cout << str << endl;
}