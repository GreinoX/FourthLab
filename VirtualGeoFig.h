//
// Created by Thund on 27.02.2024.
//

#ifndef FOURTHLAB_VIRTUALGEOFIG_H
#define FOURTHLAB_VIRTUALGEOFIG_H
#include <iostream>
#include <cmath>
#include <vector>

class Point{
public:

    double x;
    double y;

    Point();

    Point(std::pair<double, double> _xy);

    Point(double _x, double _y);
};

class IGeoFig{
public:
    virtual double square() = 0;

    virtual double perimeter() = 0;
};


class IPrintable{
public:
    virtual void draw() = 0;
};

class IDialogInitiable{
public:
    virtual void initFromDialog() = 0;
};

class IPhyssObject{
public:
    virtual double mass() = 0;

    virtual bool operator == (const IPhyssObject& obj) const = 0;

    virtual bool operator < (const IPhyssObject& obj) const = 0;
};

class BaseCObject{
public:
    virtual const char * classname() = 0;

    virtual unsigned int size() = 0;
};

class Figure: public IGeoFig, public IPrintable, public IDialogInitiable, public BaseCObject {};


class Circle : public Figure{
private:
    const char* class_name = "Circle";
    Point a;
    double r;
public:
    Circle();

    ~Circle();

    Circle(std::pair<double, double> _xy, double _r);

    double square() override;

    double perimeter() override;

    void draw() override;

    void initFromDialog() override;

    unsigned int size() override;

    const char * classname() override;
};

class Parallelogram : public Figure{
private:
    const char* class_name = "Parallelogram";
    Point a, b, c, d;
    double h;
public:
    Parallelogram();

    Parallelogram(std::pair<double, double> _a, std::pair<double, double> _b, std::pair<double, double> _c, std::pair<double, double> _d);

    double square();

    double perimeter();

    void draw() override;

    void initFromDialog();

    unsigned int size();

    const char* classname();
};

#endif //FOURTHLAB_VIRTUALGEOFIG_H
