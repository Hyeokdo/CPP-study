/*
* 문제 04-2
* point 클래스를 기반으로하여 원을 의미하는 Circle 클래스 정의
* circle 클래스는 원의 중심좌표와 반지름의 길이 출력
* ring 클래스 정의
*/
#include <iostream>

using namespace std;

// Point class 정의
class Point {
private:
	int xpos, ypos;			// Point(x, y) 선언	
public:
	// Point class initialize
	void init(int x, int y) {
		xpos = x;
		ypos = y;
	}
	// Show Point Information
	void ShowPointInfo() const {
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}
};
 // Circle class 정의
class Circle {
private:
	Point pnt;				// 원의 중심좌표
	int radius;				// 반지름
public:
	// Circle class initialize
	void init(int x, int y, int rad) {
		pnt.init(x, y);
		radius = rad;
	}
	// Show Circle Information
	void ShowCircleInfo() const {
		cout << "Circle Info..." << endl << "radius: " << radius << endl;
		pnt.ShowPointInfo();
	}
};
class Ring {
private:
	Circle inner, outter;	// Inner, Outter Circle	
public:
	// Ring class initialize
	void init(int x1, int y1, int rad1, int x2, int y2, int rad2) {
		inner.init(x1, y1, rad1);
		outter.init(x2, y2, rad2);
	}
	// Show Ring Information
	void ShowRingInfo() const {
		cout << "Inner ";
		inner.ShowCircleInfo();
		cout << "Outter ";
		outter.ShowCircleInfo();
	}
};

int main() {

	Ring ring;

	ring.init(1, 1, 4, 2, 2, 9);
	ring.ShowRingInfo();

	return 0;
}