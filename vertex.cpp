#include "vertex.hpp"

std::istream& operator >> (std::istream& is,vertex& p ) {
    return  is >> p.x >> p.y;
}

std::ostream& operator << (std::ostream& os,const vertex& p) {
    return os << p.x << ' ' << p.y;
}