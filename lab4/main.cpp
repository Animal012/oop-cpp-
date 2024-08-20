#include <iostream>
#include "MyStack/MyStack.h"

void Multipliers(int n, MyStack<int> &stack) {
    int div = 2;
    while (n > 1) {
        while (n % div == 0) {
            stack.push(div);
            n = n / div;
        }
        div++;
    }
}

int main() {
    MyStack<int> stack;
    int n = 3960;
    Multipliers(n, stack);
    std::cout << n << " = ";
    for (int i = 0; !stack.empty(); i++) {
        if (i == 0)
            std::cout << stack.top_inf();
        else
            std::cout << " * " << stack.top_inf();
        stack.pop();
    }
    std::cout << std::endl;
    Multipliers(n, stack);
    std::cout << n << " = ";
    MyStack<int> stack_r;
    while (!stack.empty()) {
        stack_r.push(stack.top_inf());
        stack.pop();
    }
    for (int i = 0; !stack_r.empty(); i++) {
        if (i == 0)
            std::cout << stack_r.top_inf();
        else
            std::cout << " * " << stack_r.top_inf();
        stack_r.pop();
    }
    return 0;
}
