#include <iostream>

// ����
// swap �Լ��� ����� ���ڿ�

void swap(int* num1, int* num2);
void swap(char* ch1, char* ch2);
void swap(double* double1, double* double2);

int main() {
	
	int num1 = 20, num2 = 30;
	swap(&num1, &num2);

	char ch1 = 'A', ch2 = 'Z';
	swap(&ch1, &ch2);

	double dbl1 = 1.111, dbl2 = 5.555;
	swap(&dbl1, &dbl2);

	return 0;
}
void swap(int* num1, int* num2)
{
	std::cout << *num1 << ' ' << *num2 << std::endl;
}
void swap(char* ch1, char* ch2) {
	std::cout << *ch1 << ' ' << *ch2 << std::endl;
}
void swap(double* dbl1, double* dbl2) {
	std::cout << *dbl1 << ' ' << *dbl2 << std::endl;
}

/*
**** ���� *****
* C++�� ��� �Լ��� parameter�� �ٸ� ��� �ٸ� �Լ��� �ν��� ����
* �̰��� Function Overload��� �θ�
*/