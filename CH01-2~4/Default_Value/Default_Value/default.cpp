# include <iostream>

int BoxVolume(int length, int width, int height);
int BoxVolume(int length, int width);
int BoxVolume(int length);

int main() {
	// 문제 1
	// BoxVolume를 Default 지정 형태가 아닌 Overload 형태로 구현
	// int BoxVoulume(int length, int width = 1, int height = 1);의 형태

	std::cout << "[3, 3, 3] : " << BoxVolume(3, 3, 3) << std::endl;
	std::cout << "[5, 5, D] : " << BoxVolume(5, 5) << std::endl;
	std::cout << "[7, D, D] : " << BoxVolume(7) << std::endl;


	// 문제 2
	// int SimpleFunc(int a = 10)과 int SimplFunc(void)의 Overloading은 왜 문제가 있는가
	/*
	* int a = 10으로 parameter에 defualt value를 설정해주는 경우, parameter를 입력 하지 않을 경우와 void의 경우가 같은 경우로 인식됨
	* 따라서 문제의 두 함수에 대한 overloading은 문제가 발생함
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