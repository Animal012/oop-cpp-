#ifndef SHOP_LIBRARY_H
#define SHOP_LIBRARY_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

class Shop {
private:
    char* name;
    int square;
    int numOfEmployees;
    int receipts;
public:
    Shop() {
        name = new char[5];
        strncpy(name, "null", 5);
        square = 0;
        numOfEmployees = 0;
        receipts = 0;}
    Shop(const Shop& rec) {
        this->name = new char [strlen(rec.name) + 1];
        strncpy(this->name, rec.name, strlen(rec.name) + 1);
        this->name = rec.name;
        this->square = rec.square;
        this->numOfEmployees = rec.numOfEmployees;
        this->receipts = rec.receipts;
    }
    int static menu();
    void static read_dbase(const char*, Shop*, int&);
    int static write_dbase(const char*, const Shop*, int);

    friend void print_dbase(Shop*, int);
    friend void sort_db(Shop*, int);
    friend void add(Shop*, int&);
    friend void remove(Shop*, int&);
    friend void edit(Shop*, int);
    friend void swaper(Shop*, int);

    friend std::ofstream& operator << (std::ofstream& out, const Shop& obj) {
        out << obj.name << " " << obj.square << " " << obj.numOfEmployees << " " << obj.receipts;
        return out;
    }
    friend std::istream& operator >> (std::istream& in, Shop& obj) {
        in >> obj.name >> obj.square >> obj.numOfEmployees >> obj.receipts;
        return in;
    }
    friend bool operator < (const Shop& obj1, const Shop& obj2) {
        return (obj1.numOfEmployees < obj2.numOfEmployees);
    }
    friend bool operator == (const Shop& obj1, const Shop& obj2) {
        return (obj1.numOfEmployees == obj2.numOfEmployees);
    }
    Shop& operator = (const Shop& obj) {
        if (this != &obj) {
            delete [] name;
            name = new char [strlen(obj.name) + 1];
            strncpy(name, obj.name, strlen(obj.name) + 1);
            square = obj.square;
            numOfEmployees = obj.numOfEmployees;
            receipts = obj.receipts;
        }
        return *this;
    }
    friend Shop* numOfEmployees_sort(Shop* arr, int n);
    ~Shop() {delete [] name;}
};

#endif
