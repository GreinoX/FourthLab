//TT
// Created by Thund on 27.02.2024.
//

#include "VirtualGeoFig.h"

Point::Point(std::pair<double, double> _xy) : x(_xy.first), y(_xy.second) {}

Point::Point(double _x, double _y): x(_x), y(_y) {}

Point::Point() : x(0), y(0) {}

Circle::Circle() : r(0) {}

Circle::Circle(std::pair<double, double> _xy, double _r) : a(_xy), r(_r) {}

Circle::~Circle(){
    r = 0;
    a = {0, 0};
}

double Circle::square() {
    double square = M_PI * pow(r,2);
    return square;
}

double Circle::perimeter() {
    double perimeter = M_PI * 2 * r;
    return perimeter;
}

void Circle::draw() {
    std::cout << "Circle: radius(" << r << "), center(" << a.x << ", " << a .y << ")";
}

void Circle::initFromDialog(){
    std::cout << "Input radius of circle: ";
    std::cin >> r;
    std::cout << "Input coordinates of the center as (x;y): ";
    std::cin >> a.x >> a.y;
}

unsigned int Circle::size() {
    return sizeof(*this);
}

const char* Circle::classname() {
    return class_name;
}

Parallelogram::Parallelogram() : a(0, 0), b(0, 0), c(0, 0), d(0, 0) {}

Parallelogram::Parallelogram(std::pair<double, double> _a, std::pair<double, double> _b, std::pair<double, double> _c, std::pair<double, double> _d){
    a = _a;
    b = _b;
    c = _c;
    d = _d;
    h = sqrt(pow((a.x - c.x), 2) + pow((a.y - c.y), 2));
}

double Parallelogram::square() {
    double osnovanie = sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
    double square = osnovanie * h;
    return square;
}

double Parallelogram::perimeter() {
    double first_side = sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
    double second_side = sqrt(pow((b.x - d.x), 2) + pow((b.y - d.y), 2));
    double third_side = sqrt(pow((d.x - c.x), 2) + pow((d.y - c.y), 2));
    double fourth_side = sqrt(pow((a.x - c.x), 2) + pow((a.y - c.y), 2));
    return first_side + second_side + third_side + fourth_side;
}

void Parallelogram::draw(){
    std::cout << "Parallelogram" << '\n';
    std::cout << "a(" << a.x << ',' << a.y << ") - b(" << b.x << ',' << b.y << ") c(" << c.x << ',' << c.y << ") d(" << d.x << ',' << d.y <<");";
}

void Parallelogram::initFromDialog() {
    std::cout << "Input coordinates for points:";
    std::vector<Point*> points = {&a, &b, &c, &d};
    for(auto point : points){
        std::cout << "(x,y):";
        std::cin >> point->x >> point->y;
    }
}

unsigned int Parallelogram::size(){
    return sizeof(*this);
}

const char* Parallelogram::classname() {
    return class_name;
}
