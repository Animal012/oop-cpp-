#include "sort.h"

namespace sort {
    void bubble(double *a, int n) {
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n - i; j++) {
                if (a[j] > a[j + 1])
                    std::swap(a[j], a[j + 1]);
            }
        }
    }
}