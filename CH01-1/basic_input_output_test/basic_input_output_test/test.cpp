#include <iostream>

int main()
{
	//문제 1
	// 5개의 정수를 입력받아 합을 출력

	int num1, num2, num3, num4, num5;

	std::cout << "1번째 정수 입력: ";
	std::cin >> num1;
	std::cout << "2번째 정수 입력: ";
	std::cin >> num2;
	std::cout << "3번째 정수 입력: ";
	std::cin >> num3;
	std::cout << "4번째 정수 입력: ";
	std::cin >> num4;
	std::cout << "5번째 정수 입력: ";
	std::cin >> num5;

	int result = num1 + num2 + num3 + num4 + num5;

	std::cout << "합계: " << result << std::endl;

	//문제 2
	// 이름, 전화번호를 문자열의 형태로 입력 후 출력

	char name[10];
	char phone[15];

	std::cout << "이름 입력: ";
	std::cin >> name;
	std::cout << "전화번호 입력: ";
	std::cin >> phone;

	std::cout << "사용자의 이름은 " << name << "전화번호는 " << phone << " 입니다." << std::endl;

	//문제 3
	// 숫자를 입력받아 그 숫자의 단에 해당하는 구구단 작성

	int num;
	
	do {
		std::cout << "구구단을 출력할 숫자를 입력(2~9): ";
		std::cin >> num;
	} while (num < 1 || num > 9);

	for (int i = 1; i < 10; i++) {
		std::cout << num << " * " << i << " = " << (num * i) << std::endl;
	}

	//문제 4
	//기본 급여 50만원 + 물품 판매 금액의 12%의 돈을 지금

	int product;
	double salary;

	while(1){
		std::cout << "판매 금액 입력(만원 단위, 입력을 종료하고 싶으면 -1을 입력): ";
		std::cin >> product;
		if (product == -1) {
			std::cout << "프로그램 종료";
			break;
		}
		salary = 50.0 + (double)product * 0.12;
		std::cout << "이번 달 급여: " << salary << std::endl;
	}

	return 0;
}