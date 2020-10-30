#include "octagon.hpp"

#include <cmath>
#include "vertex.hpp"

vertex octagon::center() const {
    double x = 0;
    double y = 0;
    for(int i = 0; i < 8; i++){
        x += Vertexs[i].x;
        y += Vertexs[i].y;
    }
    x /= 8;
    y /= 8;
    vertex p(x,y);
    return p;
}

void octagon::print(std::ostream& os) const {
    for(int i = 0; i < 8; i++){
        os << Vertexs[i] <<' ';
    }
    os << '\n'<< "Center: " << center() << " Area: "<< area() << '\n';
}

void octagon::printFile(std::ofstream& of) const {
    for(int i = 0; i < 8; i++){
        of << Vertexs[i] <<' ';
    }
    of << '\n';
}

double octagon::area() const{
    double Area = 0;
    for (int i = 0; i < 8; i++) {
        Area += (Vertexs[i].x) * (Vertexs[(i + 1) % 8].y) - (Vertexs[(i + 1) % 8].x)*(Vertexs[i].y);
    }
    Area *= 0.5;
    return abs(Area);
}

octagon::octagon(std::istream& is) {
    for(int i = 0; i < 8; i++){
        is >> Vertexs[i];
    }
}

octagon::octagon(std::ifstream& is) {
    for(int i = 0; i < 8; i++){
        is >> Vertexs[i];
    }
}