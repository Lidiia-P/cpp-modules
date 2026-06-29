#include "Point.hpp"

static Fixed area(Point const point, Point const lineStart, Point const lineEnd);

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed d1 = area(point, a, b);
	Fixed d2 = area(point, b, c);
	Fixed d3 = area(point, c, a);

	if (d1 == Fixed(0) || d2 == Fixed(0) || d3 == Fixed(0))
		return (false);
	if (d1 < Fixed(0) || d2 < Fixed(0) || d3 < Fixed(0))
		return (false);
	if (d1 > Fixed(0) || d2 > Fixed(0) || d3 > Fixed(0))
		return (true);
	return (false);
}

// If I walk from point A to point B, is point P on my left (positive number), on my right (negative), or exactly in front of me (zero)?
// Cross product in 2D: v1.x * v2.y - v2.x * v1.y
// where v1 is from point to lineEnd
// and v2 is from lineStart to lineEnd
static Fixed area(Point const point, Point const lineStart, Point const lineEnd) {
	return ((point.getX() - lineEnd.getX()) * (lineStart.getY() - lineEnd.getY())
			- (lineStart.getX() - lineEnd.getX()) * (point.getY() - lineEnd.getY()));
}