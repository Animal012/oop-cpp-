#include "myvector.h"

void MyVector::resize() {
    int new_maxsize;
    if (size >= maxsize)
        new_maxsize = int(maxsize * 1.5);
    else if (size < maxsize / 2) {
        new_maxsize = int(maxsize / 1.5);
        if (new_maxsize < 1)
            new_maxsize = 1;
    }
    else
        return;
    char** new_pdata = new char*[new_maxsize];
    for (int i = 0; i < size; ++i) {
        new_pdata[i] = pdata[i];
    }
    delete[] pdata;
    pdata = new_pdata;
    maxsize = new_maxsize;
};

void MyVector::add_element(const char* el) {
    if (size >= maxsize) {
        resize();
    }
    pdata[size] = new char[strlen(el) + 1];
    strcpy(pdata[size], el);
    size++;
}

bool MyVector::delete_element(int i) {
    if (i < 0 || i >= size)
        return false;
    delete[] pdata[i];
    for (int j = i; j < size - 1; j++)
        pdata[j] = pdata[j + 1];
    size--;
    if (size < maxsize / 2 && maxsize > 1)
        resize();
    return true;
}

void MyVector::sort() {
    std::sort(pdata, pdata + size, [](const char* a, const char* b) { return strcmp(a, b) < 0; });
}

int MyVector::find(char* el) const {
    for (int i = 0; i < size; ++i) {
        if (strcmp(pdata[i], el) == 0) {
            return i;
        }
    }
    return -1;
};