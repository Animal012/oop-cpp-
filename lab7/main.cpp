#include "classes/abstact.h"

State* State::begin = nullptr;

int main(int argc, char *argv[]) {
    Republic Russia("Russian Federation", "Moscow", 146485340, "Unitary semi-presidential constitutional republic");
    Monarchy Spain("Spain", "Madrid", 46754783, "Felipe VI", "Parliamentary monarchy");
    Kingdom UK("United Kingdom", "London", 68207116, "Elizabeth II");
    State::print();
    std::cout << std::endl;
    std::cout << "However, there have been some changes in these countries..." << std::endl;
    std::cout << std::endl;
    Russia.change_form_of_government("Presidential republic");
    Spain.change_form_of_monarchy("Absolute monarchy");
    UK.change_ruler("Karl III");
    State::print();
    std::cout << std::endl;
    std::cout << "P.S. These changes in countries are an invention of the author, expect for the change of the British monarch, of course(" << std::endl;
    return 0;
}