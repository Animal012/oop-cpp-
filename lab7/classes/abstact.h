#ifndef CLASSES_ABSTACT_H
#define CLASSES_ABSTACT_H

#include <iostream>
#include <cstring>

class State {
protected:
    std::string name;
    std::string capital;
    int population;
    static State* begin;
    State* next;
public:
    State(const std::string& name, const std::string& capital, int population) {
        this->name = name;
        this->capital = capital;
        this->population = population;
        add();
    }
    virtual void show() = 0;
    static void print();
    void add();
    virtual ~State() {}
};

class Kingdom: public State {
protected:
    std::string ruler;
public:
    Kingdom(const std::string& name, const std::string& capital, int population, const std::string& ruler):
    State(name, capital, population) {
        this->ruler = ruler;
    }
    void show() override;
    void change_ruler(const std::string&);
};

class Republic : public State {
protected:
    std::string form_of_government;
public:
    Republic(const std::string& name, const std::string& capital, int population, const std::string& form_of_government):
    State(name, capital, population) {
        this->form_of_government = form_of_government;
    }
    void show() override;
    void change_form_of_government(const std::string&);
};

class Monarchy : public Kingdom {
protected:
    std::string form_of_monarchy;
public:
    Monarchy(const std::string& name, const std::string& capital, int population, const std::string& ruler, const std::string& form_of_monarchy):
    Kingdom(name, capital, population, ruler) {
        this->form_of_monarchy = form_of_monarchy;
    }
    void show() override;
    void change_form_of_monarchy(const std::string&);
};

#endif //CLASSES_ABSTACT_H