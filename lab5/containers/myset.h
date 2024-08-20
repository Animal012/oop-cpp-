#ifndef CONTAINERS_MYSET_H
#define CONTAINERS_MYSET_H

#include <iostream>
#include "myvector.h"

class MySet: public MyVector {
public:
    explicit MySet(const char *el = NULL): MyVector(el) {};
    friend std::ostream &operator<<(std::ostream &out, const MySet &s) {
        out << "{";
        for (int i = 0; i < s.size; i++) {
            out << s.pdata[i];
            if (i != s.size - 1)
                out << ", ";
        }
        out << "}";
        return out;
    };
    MySet &operator+=(const MySet &s) {
        for (int i = 0; i < s.size; i++) {
            add_element(s.pdata[i]);
        }
        return *this;
    };
    MySet &operator-=(const MySet &s) {
        for (int i = 0; i < s.size; i++) {
            delete_element(s.pdata[i]);
        }
        return *this;
    };
    MySet &operator*=(const MySet &s) {
        MySet tmp;
        for (int i = 0; i < size; i++) {
            if (s.is_element(pdata[i])) {
                tmp.add_element(pdata[i]);
            }
        }
        *this = tmp;
        return *this;
    };
    bool operator==(const MySet &s) {
        if (size != s.size) {
            return false;
        }
        for (int i = 0; i < size; i++) {
            if (strcmp(pdata[i], s.pdata[i]) != 0) {
                return false;
            }
        }
        return true;
    };
    friend MySet operator+(const MySet &s1, const MySet &s2) {
        MySet s3;
        s3 += s1;
        s3 += s2;
        return s3;
    };
    friend MySet operator-(const MySet &s1, const MySet &s2) {
        MySet s3;
        s3 += s1;
        s3 -= s2;
        return s3;
    };
    friend MySet operator*(const MySet &s1, const MySet &s2) {
        MySet s3;
        s3 += s1;
        s3 *= s2;
        return s3;
    };
    void add_element(char *el);
    void delete_element(char *el);
    bool is_element(char *el) const;
};

#endif //CONTAINERS_MYSET_H