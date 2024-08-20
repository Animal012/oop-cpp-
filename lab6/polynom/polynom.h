#ifndef POLYNOM_POLYNOM_H
#define POLYNOM_POLYNOM_H

#include <iostream>
#include <cstring>
#include <algorithm>

class Term {
private:
    int coefficient;
    int degree;
public:
    Term() {
        coefficient = 0;
        degree = 0;
    }
    explicit Term (int a) {
        coefficient = a;
        degree = 0;
    }
    Term(int a, int b) {
        coefficient = a;
        degree = b;
    }
    int getDegree() {
        return degree;
    }
    int getCoefficient() {
        return coefficient;
    }
    void setDegree(int a) {
        degree = a;
    }
    void setCoefficient(int a) {
        coefficient = a;
    }
    friend class Polynomial;
    friend Term operator+(const Term& v1, const Term& v2);
    friend Term operator*(const Term& v1, const Term& v2);
    friend std::ostream& operator<<(std::ostream& out, const Term& v);
    friend std::istream& operator>>(std::istream& in, Term& v);
};

class Polynomial {
private:
    Term* poly;
    int power;
    bool order_;
public:
    Polynomial() {
        power = 0;
        order_ = true;
        poly = new Term[1];
        poly[0] = Term();
    }
    explicit Polynomial(int a) {
        power = 0;
        order_ = true;
        poly = new Term[1];
        poly[0] = Term(a);
    }
    explicit Polynomial(Term a) {
        power = a.degree;
        order_ = true;
        poly = new Term[power + 1];
        poly[0] = Term(a.coefficient, a.degree);
        for(int i = 1; i <= power; i++)
            poly[i] = Term(0, power - i);
    }
    Polynomial(const Polynomial& other) {
        power = other.power;
        order_ = other.order_;
        poly = new Term[power + 1];
        for (int i = 0; i <= power; i++)
            poly[i] = other.poly[i];
    }
    Polynomial& operator=(const Polynomial& v);
    Polynomial& operator+=(const Polynomial& v);
    Polynomial& operator*=(const Polynomial& v);
    friend Polynomial operator*(const Polynomial& v1, const Polynomial& v2);
    friend Polynomial operator+(const Polynomial& v1, const Polynomial& v2);
    friend std::ostream& operator<<(std::ostream& out, const Polynomial& v);
    friend std::istream& operator>>(std::istream& in, Polynomial& v);
    ~Polynomial() {
        delete [] poly;
    }
};

#endif //POLYNOM_POLYNOM_H
