#ifndef _FIGURE_H_
#define _FIGURE_H_

#include <iostream>
#include "vertex.hpp"
#include <fstream>

struct figure {
    virtual vertex center() const = 0;
    virtual void print(std::ostream&) const = 0 ;
    virtual void printFile(std::ofstream&) const = 0 ;
    virtual double area() const = 0;
    virtual ~figure() = default;
};

#endif //_FIGURE_H_