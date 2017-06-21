# include <vector>
#ifndef Point_h
#define Point_h

using namespace std;
struct Point {
  double _x, _y;
};
#endif

#ifndef Line_h
#define Line_h
struct Line {
	double _slope, _yInt;
    double getYforX(double x);
    bool fitPoints(const std::vector<Point> &pts);
};

#endif
