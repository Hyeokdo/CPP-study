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
	std::cout << "ù ��° ���� �Է�: ";
	std::cin >> val1;

	int val2;
	std::cout << "�� ��° ���� �Է�: ";
	std::cin >> val2;

	int result = val1 + val2;
	std::cout << "���� ���: " << result << std::endl;

	// array input
	char name[10];
	int std_num;
	char univ[20];
	char depart[10];

	std::cout << "�б��� �Է��Ͻÿ�: ";
	std::cin >> univ;
	std::cout << "�а��� �Է��Ͻÿ�: ";
	std::cin >> depart;
	std::cout << "�й��� �Է��Ͻÿ�: ";
	std::cin >> std_num;
	std::cout << "�̸��� �Է��Ͻÿ�: ";
	std::cin >> name;

	std::cout << univ << ' ' << depart << ' ' << std_num << ' ' << name << "�Դϴ�." << std::endl;

	return 0;
}

/*
***** ���� *****
* C++�� ��� header file Ȯ���� ����
* std::cout << '��� ���';
* std::cout << '��� ���1' << '��� ���2' << '��� ���3'
* std::cout << std::endl;�� ��� �� �ٲ��� �ǹ�
* std::cin >> '�Է� ����'�� ��� keyboard�� �Է��� �Է� ������ ����
* std::cin >> '�Է� ���� 1' >> '�Է� ����2'�� ���·� ���ӵ� �Է� ����
* ���ڿ��� ��� char type array�� ���� ���� �� ����
* std::cin >> '�迭 �̸�'�� ���� ���ڿ� ����
*/