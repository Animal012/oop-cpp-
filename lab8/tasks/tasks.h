#ifndef TASKS_TASKS_H
#define TASKS_TASKS_H

#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <random>
#include <algorithm>

void task1();
void task2();
void task3();
void task4();
void task5();
void task6();
void task7();
void task8();
void task9();

class Complex {
private:
    double real;
    double imaginary;
public:
    Complex(double r, double i){
        real = r;
        imaginary = i;
    }
    double get_real() const{
        return real;}
    double get_imaginary() const{
        return imaginary;}
};

class Rectangle {
private:
    double a;
    double b;
public:
    Rectangle(){
        a = 0; b = 0;
    }
    Rectangle(double a, double b){
        this->a = a;
        this->b = b;
    }
    double get_area() const{
        return a * b;}

    bool operator<(const Rectangle& other) const {
        return get_area() < other.get_area();
    }

    bool operator==(const Rectangle& other) const {
        return get_area() == other.get_area();
    }

    friend std::ostream& operator<<(std::ostream& out, const Rectangle& rect) {
        out << rect.a << " x " << rect.b;
        return out;
    }
};

#endif //TASKS_TASKS_H
