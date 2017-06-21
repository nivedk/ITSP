# include "line.h"
# include <iostream>
# include <vector>
using namespace std;

int main(){
	struct Point p, q;
	p._x = 2;
	p._y = 2;
	q._x = 3;
	q._y = 3;

	struct Line l;
	l._slope = 1;
	l._yInt = 0;
	vector<Point> v;
	v.push_back(p);
	v.push_back(q);
	vector<Point>* ptr = &v;

	//bool x = l.fitPoints(ptr);
	double y  = l.getYforX(5);


}
