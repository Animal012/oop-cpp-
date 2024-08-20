#ifndef CONTAINERS_MYVECTOR_H
#define CONTAINERS_MYVECTOR_H

#include <iostream>
#include <cstring>
#include <algorithm>

const int MAX_SIZE = 5;

class MyVector {
public:
    explicit MyVector(const char *el = NULL, int maxsz = MAX_SIZE) {
        maxsize = maxsz;
        size = 0;
        pdata = new char* [maxsize];
        for (int i = 0; i < maxsize; i++)
            pdata[i] = NULL;
        if (el != NULL)
            add_element(el);
    };
    MyVector(const MyVector &v) {
        maxsize = v.maxsize;
        size = v.size;
        pdata = new char* [maxsize];
        for (int i = 0; i < size; ++i) {
            pdata[i] = new char[strlen(v.pdata[i]) + 1];
            strcpy(pdata[i], v.pdata[i]);
        }
    };
    ~MyVector() {
        for (int i = 0; i < size; ++i) {
            delete[] pdata[i];
        }
        delete[] pdata;
    };
    void add_element(const char *el);
    bool delete_element(int i);
    char *operator[](int i) {
        if (i < 0 || i >= size) {
            return nullptr;
        }
        return pdata[i];
    };
    void sort();
    int Size() const { return size; }
    int Maxsize() const { return maxsize; }
    int find(char *el) const;
    MyVector &operator=(const MyVector &v) {
        if (this != &v) {
            for (int i = 0; i < size; ++i) {
                delete[] pdata[i];
            }
            delete[] pdata;
            maxsize = v.maxsize;
            size = v.size;
            pdata = new char* [maxsize];
            for (int i = 0; i < size; ++i) {
                pdata[i] = new char[strlen(v.pdata[i]) + 1];
                strcpy(pdata[i], v.pdata[i]);
            }
        }
        return *this;
    };
    friend std::ostream &operator<<(std::ostream &out, const MyVector &v) {
        for (int i = 0; i < v.size; i++) {
            out << v.pdata[i] << " ";
        }
        return out;
    };

protected:
    int maxsize;
    int size;
    char **pdata;
private:
    void resize();
};


#endif //CONTAINERS_MYVECTOR_H
