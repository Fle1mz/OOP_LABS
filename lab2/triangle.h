#ifndef TRIANGLE_H
#define TRIANGLE_H

struct Point {
    double x;
    double y;
};

enum PointLocation {
    INSIDE,
    OUTSIDE,
    ON_BOUNDARY,
    DEGENERATE_TRIANGLE
};

double crossProduct( Point a, Point b, Point c);

bool isDegenerate( Point a, Point b, Point c);

PointLocation checkPointLocation( Point p, Point a, Point b, Point c);

#endif

