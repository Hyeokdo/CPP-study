/*
* ���� 02-3
* struct ����
* typedef struct __point{
*	int xpos;
*	int ypos;
* }point;
* ������ �Լ��� �����Ͽ� �� ���� ���� ��� 
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
***** ���� *****
* �Լ��� ��ȯ���� reference�� ��� �Լ��� return�� �޴� ���� ���� reference �̾�� ��
* 35 line�� sum ������ ó������ pointer�� �����Ͽ� error�� �߻��Ͽ���
*/