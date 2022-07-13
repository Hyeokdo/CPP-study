/*
* 문제 03-1
* 구조체 내에 함수 정의하기
* xpos, ypos를 포함하는 point struct 정의
* point struct 내에 아래의 함수 선언
* void MovePos(int x, int y);		// 점의 좌표 이동
* void AddPoint(Const Point &pos);	// 정의 좌표 증가
* void ShowPosition();				// 현재의 x, y 좌표 출력
*/

#include <iostream>

using namespace std;

struct point {

	int xpos, ypos;			// x, y 좌표

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