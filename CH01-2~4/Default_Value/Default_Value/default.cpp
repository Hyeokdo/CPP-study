# include <iostream>

int BoxVolume(int length, int width, int height);
int BoxVolume(int length, int width);
int BoxVolume(int length);

int main() {
	// ���� 1
	// BoxVolume�� Default ���� ���°� �ƴ� Overload ���·� ����
	// int BoxVoulume(int length, int width = 1, int height = 1);�� ����

	std::cout << "[3, 3, 3] : " << BoxVolume(3, 3, 3) << std::endl;
	std::cout << "[5, 5, D] : " << BoxVolume(5, 5) << std::endl;
	std::cout << "[7, D, D] : " << BoxVolume(7) << std::endl;


	// ���� 2
	// int SimpleFunc(int a = 10)�� int SimplFunc(void)�� Overloading�� �� ������ �ִ°�
	/*
	* int a = 10���� parameter�� defualt value�� �������ִ� ���, parameter�� �Է� ���� ���� ���� void�� ��찡 ���� ���� �νĵ�
	* ���� ������ �� �Լ��� ���� overloading�� ������ �߻���
	*/

	return 0;
}
int BoxVolume(int length, int width, int height) {
	return length * width * height;
}
int BoxVolume(int length, int width) {
	return length * width;
}
int BoxVolume(int length) {
	return length;
}