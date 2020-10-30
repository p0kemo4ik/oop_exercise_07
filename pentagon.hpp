#ifndef _PENTAGON_H_
#define _PENTAGON_H_

#include "figure.hpp"

struct pentagon : figure {
private:
    vertex Vertexs[5];
public:
    vertex center() const override ;
    void print(std::ostream&) const  override ;
    void printFile(std::ofstream&) const override ;
    double area() const override ;
    pentagon() = default;
    pentagon(std::istream& is);
    pentagon(std::ifstream& is);
};

#endif //_PENTAGON_H_