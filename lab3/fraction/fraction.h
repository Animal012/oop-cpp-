#ifndef FRACTION_FRACTION_H
#define FRACTION_FRACTION_H
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>

class fraction {
private:
    float main;
    int num;
    int denum;
public:
    fraction();
    explicit fraction(int, int);
    explicit fraction(const char*);
    explicit fraction(double);
    static int parser(const char*, char);
    static char* substr(const char*, int, int);
    static void reduction(float&, int&, int&);
    static int NOD(int, int);
    fraction& operator = (const fraction&);
    fraction& operator += (const fraction&);
    fraction& operator += (double);
    fraction& operator += (int);
    friend fraction operator + (const fraction&, const fraction&);
    friend fraction operator + (double, const fraction &);
    friend fraction operator + (const fraction &, double);
    friend fraction operator + (int, const fraction &);
    friend fraction operator + (const fraction &, int );
    friend std::istream& operator >> (std::istream&, fraction&);
    friend std::ostream& operator << (std::ostream&, const fraction&);
};

#endif //FRACTION_FRACTION_H
