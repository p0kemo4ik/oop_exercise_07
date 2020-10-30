#ifndef _OCTAGON_H_
#define _OCTAGON_H_

#include "figure.hpp"

struct octagon : figure {
private:
    vertex Vertexs[8];
public:
    vertex center() const override ;
    void print(std::ostream&) const  override ;
    void printFile(std::ofstream&) const override ;
    double area() const override ;
    octagon() = default;
    octagon(std::istream& is);
    octagon(std::ifstream& is);
};

#endif //_OCTAGON_H_