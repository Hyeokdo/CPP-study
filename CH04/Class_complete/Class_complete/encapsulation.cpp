/*
* ���� 04-2
* point Ŭ������ ��������Ͽ� ���� �ǹ��ϴ� Circle Ŭ���� ����
* circle Ŭ������ ���� �߽���ǥ�� �������� ���� ���
* ring Ŭ���� ����
*/
#include <iostream>

using namespace std;

// Point class ����
class Point {
private:
	int xpos, ypos;			// Point(x, y) ����	
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
 // Circle class ����
class Circle {
private:
	Point pnt;				// ���� �߽���ǥ
	int radius;				// ������
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