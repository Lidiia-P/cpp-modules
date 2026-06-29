#include "Point.hpp"

// int main() {
// 	Point a(1, 1);
// 	Point b(10, 1);
// 	Point c(1, 10);

// 	Point in(2, 2);
// 	Point out(10, 10);
// 	Point edge(5, 1);
// 	Point vertex(1, 1);

// 	std::cout << "Inside:  " << bsp(a, b, c, in) << std::endl;
// 	std::cout << "Outside: " << bsp(a, b, c, out) << std::endl;
// 	std::cout << "Edge:    " << bsp(a, b, c, edge) << std::endl;
// 	std::cout << "Vertex:  " << bsp(a, b, c, vertex) << std::endl;

// 	return 0;
// }

#include <iostream>
#include "Point.hpp"

// Forward declaration of bsp (assuming bsp.cpp)
bool bsp(Point const a, Point const b, Point const c, Point const point);

int main() {
	// Triangle vertices
	Point a(0, 0);
	Point b(10, 0);
	Point c(0, 10);

	// Test points
	Point inside(2, 2);
	Point outside(10, 10);
	Point edge(5, 0);
	Point vertex(0, 0);

	std::cout << "Testing point (2,2) inside triangle: " << bsp(a, b, c, inside) << std::endl;   // Expected 1
	std::cout << "Testing point (10,10) outside triangle: " << bsp(a, b, c, outside) << std::endl; // Expected 0
	std::cout << "Testing point (5,0) on edge: " << bsp(a, b, c, edge) << std::endl; // Expected 0
	std::cout << "Testing point (0,0) on vertex: " << bsp(a, b, c, vertex) << std::endl; // Expected 0

	// Extra tests
	Point nearEdge(1, 0.1f);
	std::cout << "Testing point (1,0.1) near edge: " << bsp(a, b, c, nearEdge) << std::endl; // Expected 1

	return 0;
}

