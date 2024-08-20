#ifndef PLANET_LIBRARY_H
#define PLANET_LIBRARY_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

class Planet {
private:
    char* name;
    int diameter;
    int habitability;
    int satellite;
public:
    Planet() {
        name = new char[5];
        strncpy(name, "null", 5);
        diameter = 0;
        habitability = 0;
        satellite = 0;}
    Planet(const Planet& rec) {
        this->name = new char [strlen(rec.name) + 1];
        strncpy(this->name, rec.name, strlen(rec.name) + 1);
        this->name = rec.name;
        this->diameter = rec.diameter;
        this->habitability = rec.habitability;
        this->satellite = rec.satellite;
    }
    //int static menu();
    void static read_dbase(const char*, Planet*, int&);
    int static write_dbase(const char*, const Planet*, int);

    friend void print_dbase(Planet*, int);
    friend void sort_db(Planet*, int);
    friend void add(Planet*, int&);
    friend void remove(Planet*, int&);
    friend void edit(Planet*, int);
    //friend void swaper(Planet*, int);

    friend std::ofstream& operator << (std::ofstream& out, const Planet& obj) {
        out << obj.name << " " << obj.diameter << " " << obj.habitability << " " << obj.satellite;
        return out;
    }
    friend std::istream& operator >> (std::istream& in, Planet& obj) {
        in >> obj.name >> obj.diameter >> obj.habitability >> obj.satellite;
        return in;
    }
    friend bool operator < (const Planet& obj1, const Planet& obj2) {
        return (obj1.habitability < obj2.habitability);
    }
    friend bool operator == (const Planet& obj1, const Planet& obj2) {
        return (obj1.habitability == obj2.habitability);
    }
    Planet& operator = (const Planet& obj) {
        if (this != &obj) {
            delete [] name;
            name = new char [strlen(obj.name) + 1];
            strncpy(name, obj.name, strlen(obj.name) + 1);
            diameter = obj.diameter;
            habitability = obj.habitability;
            satellite = obj.satellite;
        }
        return *this;
    }
    friend Planet* habitability_sort(Planet* arr, int n);
    ~Planet() {delete [] name;}
};

#endif //PLANET_LIBRARY_H
