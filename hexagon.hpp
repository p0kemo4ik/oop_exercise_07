#ifndef _HEXAGON_H_
#define _HEXAGON_H_

#include "figure.hpp"

struct hexagon : figure {
private:
    vertex Vertexs[6];
public:
    vertex center() const override ;
    void print(std::ostream&) const  override ;
    void printFile(std::ofstream&) const override ;
    double area() const override ;
    hexagon() = default;
    hexagon(std::istream& is);
    hexagon(std::ifstream& is);
};

#endif //_HEXAGON_H_