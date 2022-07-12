# include <iostream>

int main() 
{
	// output
	int num = 20;
	std::cout << "Hello World!" << std::endl;
	std::cout << "Hello " << "World!" << std::endl;
	std::cout << num << ' ' << 'A';
	std::cout << ' ' << 3.14 << std::endl;

	// input
	int val1;
	std::cout << "첫 번째 숫자 입력: ";
	std::cin >> val1;

	int val2;
	std::cout << "두 번째 숫자 입력: ";
	std::cin >> val2;

	int result = val1 + val2;
	std::cout << "덧셈 결과: " << result << std::endl;

	// array input
	char name[10];
	int std_num;
	char univ[20];
	char depart[10];

	std::cout << "학교를 입력하시오: ";
	std::cin >> univ;
	std::cout << "학과를 입력하시오: ";
	std::cin >> depart;
	std::cout << "학번을 입력하시오: ";
	std::cin >> std_num;
	std::cout << "이름을 입력하시오: ";
	std::cin >> name;

	std::cout << univ << ' ' << depart << ' ' << std_num << ' ' << name << "입니다." << std::endl;

	return 0;
}

/*
***** 정리 *****
* C++의 경우 header file 확장자 생략
* std::cout << '출력 대상';
* std::cout << '출력 대상1' << '출력 대상2' << '출력 대상3'
* std::cout << std::endl;의 경우 줄 바꿈을 의미
* std::cin >> '입력 변수'의 경우 keyboard의 입력을 입력 변수에 저장
* std::cin >> '입력 변수 1' >> '입력 변수2'의 형태로 연속된 입력 가능
* 문자열의 경우 char type array를 통해 받을 수 있음
* std::cin >> '배열 이름'을 통해 문자열 저장
*/