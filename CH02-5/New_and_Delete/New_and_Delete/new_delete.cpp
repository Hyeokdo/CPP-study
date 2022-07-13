/*
* 문제 02-3
* struct 선언
* typedef struct __point{
*	int xpos;
*	int ypos;
* }point;
* 다음의 함수를 선언하여 두 점의 합을 계산 
* Point& PntAdder(const Point &p1, const Point &p2);
*/

#include <iostream>

using namespace std;

typedef struct __point {
	int xpos;
	int ypos;
}point;


point& PntAdder(const point& p1, const point& p2);

int main() {

	point* point1 = new point;
	point* point2 = new point;

	point1->xpos = 1;
	point1->ypos = 1;	// point1(1, 1)

	point2->xpos = 2;
	point2->ypos = 2;	// point2(2, 2)

	point &sum = PntAdder(*point1, *point2);

	cout << sum.xpos << sum.ypos << endl;

	return 0;
}
point& PntAdder(const point& p1, const point& p2) {
	point* sum_of_point = new point;

	sum_of_point->xpos = p1.xpos + p2.xpos;
	sum_of_point->ypos = p1.ypos + p2.ypos;

	return *sum_of_point;

}
/*
***** 정리 *****
* 함수의 반환형이 reference일 경우 함수의 return을 받는 변수 또한 reference 이어야 함
* 35 line의 sum 변수를 처음에는 pointer로 선언하여 error가 발생하였음
*/