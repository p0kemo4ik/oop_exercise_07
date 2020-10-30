#include "hexagon.hpp"

#include <cmath>
#include "vertex.hpp"

vertex hexagon::center() const {
    double x = 0;
    double y = 0;
    for(int i = 0; i < 6; i++){
        x += Vertexs[i].x;
        y += Vertexs[i].y;
    }
    x /= 6;
    y /= 6;
    vertex p(x,y);
    return p;
}

void hexagon::print(std::ostream& os) const {
    for(int i = 0; i < 6; i++){
        os << Vertexs[i] <<' ';
    }
    os << '\n' << "Center:" << center() << " Area: " << area() << '\n';
}

void hexagon::printFile(std::ofstream& of) const {
    for(int i = 0; i < 6; i++){
        of << Vertexs[i]<<' ';
    }
    of << '\n';
}

double hexagon::area() const{
    double Area = 0;
    for (int i = 0; i < 6; i++) {
        Area += (Vertexs[i].x) * (Vertexs[(i + 1) % 6].y) - (Vertexs[(i + 1) % 6].x)*(Vertexs[i].y);
    }
    Area *= 0.5;
    return abs(Area);
}

hexagon::hexagon(std::istream& is) {
    for(int i = 0; i < 6; i++){
        is >> Vertexs[i];
    }
}

hexagon::hexagon(std::ifstream& is) {
    for(int i = 0; i < 6; i++){
        is >> Vertexs[i];
    }
}