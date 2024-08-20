#include <iostream>
#include "polynom/polynom.h"

int interactive() {
    Term t1;
    Term t2(3);
    Term t3(-4, 5);
    Term t4(-3, 3);
    std::cout << "Term1: " << t1 << std::endl;
    std::cout << "Term2: " << t2 << std::endl;
    std::cout << "Term3: " << t3 << std::endl;
    std::cout << "Input the term with the same degree as the third term: ";
    std::cin >> t1;
    std::cout << "Term4: " << t1 << std::endl;
    std::cout << "Term3 + Term 4: " << t3 + t1 << std::endl;
    std::cout << "Term3 * Term 4: " << t3 * t1 << std::endl;
    Polynomial p1;
    Polynomial p2(3);
    Polynomial p3(t3);
    Polynomial p4(t4);
    std::cout << "Polynomial1: " << p1 << std::endl;
    std::cout << "Polynomial2: " << p2 << std::endl;
    std::cout << "Polynomial3: " << p3 << std::endl;
    std::cout << "Polynomial4: " << p4 << std::endl;
    std::cout << "Summary check: " << p3 + p2 + p4 << std::endl;
    std::cout << "Multiplication check 1: " << p2 * p3 * p4 << std::endl;
    p1 = p3 + p2 + p4;
    std::cout << "Multiplication check 2: " << p1 * p1 << std::endl;
    p1 *= p3;
    std::cout << "Multiplication check 3: " << p1 << std::endl;
    std::cin.ignore();
    Polynomial p5;
    std::cout << "Input the polynomial: ";
    std::cin >> p5;
    std::cout << "Polynomial5: " << p5 << std::endl;
    Polynomial p6;
    std::cout << "Input the polynomial once again: ";
    std::cin >> p6;
    std::cout << "Polynomial6: " << p6 << std::endl;
    std::cout << "Summary of your polynomial: " << p5 + p6 << std::endl;
    std::cout << "Multiplication of your polynomial: " << p5 * p6 << std::endl;
    return 0;
}

int demo() {
    Term t1;
    Term t2(3);
    Term t3(-4, 5);
    Term t4(-3, 5);
    std::cout << "Term1: " << t1 << std::endl;
    std::cout << "Term2: " << t2 << std::endl;
    std::cout << "Term3: " << t3 << std::endl;
    std::cout << "Term4: " << t4 << std::endl;
    std::cout << "Term3 + Term 4: " << t3 + t4 << std::endl;
    std::cout << "Term3 * Term 4: " << t3 * t4 << std::endl;
    Polynomial p1;
    Polynomial p2(3);
    Polynomial p3(t3);
    Polynomial p4(t4);
    std::cout << "Polynomial1: " << p1 << std::endl;
    std::cout << "Polynomial2: " << p2 << std::endl;
    std::cout << "Polynomial3: " << p3 << std::endl;
    std::cout << "Polynomial4: " << p4 << std::endl;
    std::cout << "Summary check: " << p3 + p2 + p4 << std::endl;
    std::cout << "Multiplication check 1: " << p2 * p3 * p4 << std::endl;
    p1 = p3 + p2 + p4;
    std::cout << "Multiplication check 2: " << p1 * p1 << std::endl;
    p1 *= p3;
    std::cout << "Multiplication check 3: " << p1 << std::endl;
    return 0;
}

int main(int argc, char* argv[]) {
    bool is_interactive = false;
    if ((argc == 2) && strcmp(argv[1], "i") == 0)
        is_interactive = true;
    if (is_interactive)
        return interactive();
    else
        return demo();
}