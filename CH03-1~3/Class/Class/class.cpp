/*
* ���� 03-1
* ����ü ���� �Լ� �����ϱ�
* xpos, ypos�� �����ϴ� point struct ����
* point struct ���� �Ʒ��� �Լ� ����
* void MovePos(int x, int y);		// ���� ��ǥ �̵�
* void AddPoint(Const Point &pos);	// ���� ��ǥ ����
* void ShowPosition();				// ������ x, y ��ǥ ���
*/

#include <iostream>

using namespace std;

struct point {

	int xpos, ypos;			// x, y ��ǥ

	void MovePos(int x, int y) {

		xpos += x;
		ypos += y;
	}

	void AddPoint(const point &pos) {

		xpos += pos.xpos;
		ypos += pos.ypos;
	}

	void ShowPosition() {
	
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}
};

int main() {

	point p1 = { 12, 4 };
	point p2 = { 20, 30 };

	p1.MovePos(-7, 10);
	p1.ShowPosition();

	p1.AddPoint(p2);
	p1.ShowPosition();

	return 0;
}