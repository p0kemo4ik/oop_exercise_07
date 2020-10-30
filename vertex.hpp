#ifndef _VERTEX_H_
#define _VERTEX_H_

#include <iostream>

struct vertex {
    double x, y;
    vertex (double a, double b) {x = a, y = b;};
    vertex() = default;
};

std::istream& operator >> (std::istream& is,vertex& p );
std::ostream& operator << (std::ostream& os,const vertex& p);

#endif // _VERTEX_H