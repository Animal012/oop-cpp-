#include "abstact.h"

///Class State///
void State::print() {
    State* ptr = begin;
    while (ptr != nullptr) {
        ptr->show();
        ptr = ptr->next;
    }
}

void State::add() {
    if (!begin) {
        begin = this;
        next = nullptr;
        return;
    }
    State* ptr = begin;
    while (ptr->next) {
        ptr = ptr->next;
    }
    ptr->next = this;
    next = nullptr;
}

///Class Kingdom///
void Kingdom::show() {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Capital: " << capital << std::endl;
    std::cout << "Population: " << population << std::endl;
    std::cout << "Ruler: " << ruler << std::endl;
}

void Kingdom::change_ruler(const std::string& ruler_) {
    ruler = ruler_;
}

///Class Republic///
void Republic::show(){
    std::cout << "Name: " << name << std::endl;
    std::cout << "Capital: " << capital << std::endl;
    std::cout << "Population: " << population << std::endl;
    std::cout << "Form of government: " << form_of_government << std::endl;
    std::cout << std::endl;
}

void Republic::change_form_of_government(const std::string& form_of_government_) {
    form_of_government = form_of_government_;
}

///Class Monarchy///
void Monarchy::show() {
    Kingdom::show();
    std::cout << "Form of monarchy: " << form_of_monarchy << std::endl;
    std::cout << std::endl;
}

void Monarchy::change_form_of_monarchy(const std::string& form_of_monarchy_) {
    form_of_monarchy = form_of_monarchy_;
}