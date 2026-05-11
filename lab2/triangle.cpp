#include "triangle.h"
#include <cmath>

const double EPSILON = 1e-9;

double crossProduct(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

bool isDegenerate(Point a, Point b, Point c) {
    return std::abs(crossProduct(a, b, c)) < EPSILON;
}

PointLocation checkPointLocation(Point p, Point a, Point b, Point c) {
    if (isDegenerate(a, b, c)) {
        return DEGENERATE_TRIANGLE;
    }

    double cp1 = crossProduct(a, b, p);
    double cp2 = crossProduct(b, c, p);
    double cp3 = crossProduct(c, a, p);

    bool has_neg = (cp1 < -EPSILON) || (cp2 < -EPSILON) || (cp3 < -EPSILON);
    bool has_pos = (cp1 > EPSILON) || (cp2 > EPSILON) || (cp3 > EPSILON);
    bool has_zero = (std::abs(cp1) <= EPSILON) || 
                    (std::abs(cp2) <= EPSILON) || 
                    (std::abs(cp3) <= EPSILON);

    if (has_neg && has_pos) {
        return OUTSIDE;
    } else if (has_zero) {
        return ON_BOUNDARY;
    } else {
        return INSIDE;
    }
}