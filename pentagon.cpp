#include "pentagon.hpp"

#include <cmath>
#include "vertex.hpp"

vertex pentagon::center() const {
    double x = 0;
    double y = 0;
    for(int i = 0; i < 5; i++){
        x += Vertexs[i].x;
        y += Vertexs[i].y;
    }
    x /= 5;
    y /= 5;
    vertex p(x,y);
    return p;
}

void pentagon::print(std::ostream& os) const {
    for(int i = 0; i < 5; i++){
        os << Vertexs[i] <<' ' ;
    }
    os << '\n' << "Center: "<< center() <<" Area: " << area() << '\n';
}

void pentagon::printFile(std::ofstream& of) const {
    for(int i = 0; i < 5; i++){
        of << Vertexs[i] << ' ';
    }
    of << '\n';
}

double pentagon::area() const{
    double Area = 0;
    for (int i = 0; i < 5; i++) {
        Area += (Vertexs[i].x) * (Vertexs[(i + 1) % 5].y) - (Vertexs[(i + 1) % 5].x)*(Vertexs[i].y);
    }
    Area *= 0.5;
    return abs(Area);
}

pentagon::pentagon(std::istream& is) {
    for(int i = 0; i < 5; i++){
        is >> Vertexs[i];
    }
}

pentagon::pentagon(std::ifstream& is) {
    for(int i = 0; i < 5; i++){
        is >> Vertexs[i];
    }
}