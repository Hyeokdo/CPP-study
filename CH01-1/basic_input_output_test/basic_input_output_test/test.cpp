#include <iostream>

int main()
{
	//���� 1
	// 5���� ������ �Է¹޾� ���� ���

	int num1, num2, num3, num4, num5;

	std::cout << "1��° ���� �Է�: ";
	std::cin >> num1;
	std::cout << "2��° ���� �Է�: ";
	std::cin >> num2;
	std::cout << "3��° ���� �Է�: ";
	std::cin >> num3;
	std::cout << "4��° ���� �Է�: ";
	std::cin >> num4;
	std::cout << "5��° ���� �Է�: ";
	std::cin >> num5;

	int result = num1 + num2 + num3 + num4 + num5;

	std::cout << "�հ�: " << result << std::endl;

	//���� 2
	// �̸�, ��ȭ��ȣ�� ���ڿ��� ���·� �Է� �� ���

	char name[10];
	char phone[15];

	std::cout << "�̸� �Է�: ";
	std::cin >> name;
	std::cout << "��ȭ��ȣ �Է�: ";
	std::cin >> phone;

	std::cout << "������� �̸��� " << name << "��ȭ��ȣ�� " << phone << " �Դϴ�." << std::endl;

	//���� 3
	// ���ڸ� �Է¹޾� �� ������ �ܿ� �ش��ϴ� ������ �ۼ�

	int num;
	
	do {
		std::cout << "�������� ����� ���ڸ� �Է�(2~9): ";
		std::cin >> num;
	} while (num < 1 || num > 9);

	for (int i = 1; i < 10; i++) {
		std::cout << num << " * " << i << " = " << (num * i) << std::endl;
	}

	//���� 4
	//�⺻ �޿� 50���� + ��ǰ �Ǹ� �ݾ��� 12%�� ���� ����

	int product;
	double salary;

	while(1){
		std::cout << "�Ǹ� �ݾ� �Է�(���� ����, �Է��� �����ϰ� ������ -1�� �Է�): ";
		std::cin >> product;
		if (product == -1) {
			std::cout << "���α׷� ����";
			break;
		}
		salary = 50.0 + (double)product * 0.12;
		std::cout << "�̹� �� �޿�: " << salary << std::endl;
	}

	return 0;
}