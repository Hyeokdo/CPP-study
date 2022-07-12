#include <iostream>
using namespace std;

namespace first {
	void say_hello(void);
	void say_hi(void);
}
namespace second {
	void say_hello(void);
	void say_hi(void);
}

int main() {
	first::say_hello();
	second::say_hello();
	first::say_hi();
	second::say_hi();
}
void first::say_hello() {
	cout << "fisrt Hello" << endl;
}
void first::say_hi() {
	cout << "fist Hi" << endl;
}
void second::say_hello() {
	cout << "second Hi" << endl;
}
void second::say_hi() {
	cout << "second Hi" << endl;
}