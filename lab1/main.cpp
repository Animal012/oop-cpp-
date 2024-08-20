#include <iostream>
#include "mymath/mymath.h"
#include "sort/sort.h"

int main() {
    setlocale(LC_ALL, "Russian");
    std::cout << "Я умею суммировать! Зацени 1+1=";
    std::cout << mymath::sum(10, 32) << std::endl;
    std::cout << "Введите размер массива" << std::endl;
    int n;
    std::cin >> n;
    double *arr = new double [n];
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
    sort::bubble(arr, n);
    std::cout << "Отсортированный массив по возрастанию" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    return 0;
}
