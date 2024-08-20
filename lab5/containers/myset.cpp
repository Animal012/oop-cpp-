#include "myset.h"

bool MySet::is_element(char *el) const {
    return (find(el) != -1);
}

void MySet::add_element(char *el) {
    if (!is_element(el)) {
        MyVector::add_element(el);
        sort();
    }
}

void MySet::delete_element(char *el) {
    int ind = find(el);
    if (ind != -1)
        MyVector::delete_element(ind);
}