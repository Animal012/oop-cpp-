#include "polynom.h"

//Class Term//
Term operator+(const Term& v1, const Term& v2) {
    if (v1.degree != v2.degree) {
        std::cout << "Cannot summarize terms with different degrees" << std::endl;
        return Term();
    }
    return Term(v1.coefficient + v2.coefficient, v1.degree);
}

Term operator*(const Term& v1, const Term& v2) {
    int coefficient_ = v1.coefficient * v2.coefficient;
    int degree_ = v1.degree + v2.degree;
    return Term(coefficient_, degree_);
}

std::ostream& operator<<(std::ostream& out, const Term& v) {
    if (v.coefficient == 0) {
        out << "0";
        return out;
    }
    if (v.coefficient == -1)
        out << "-";
    else if (v.coefficient != 1)
        out << v.coefficient;
    if (v.degree == 0 && (v.coefficient == -1 || v.coefficient == 1))
        out << "1";
    else if (v.degree == 0 && v.coefficient != -1 && v.coefficient != 1)
        return out;
    else if (v.degree != 1)
        out << "x^" << v.degree;
    else
        out << "x";
    return out;
}

std::istream& operator>>(std::istream& in, Term& v) {
    std::string input;
    in >> input;
    int x = input.find('x');
    if (x == std::string::npos) {
        v.coefficient = stoi(input);
        v.degree = 0;
        return in;
    }
    if (input.substr(0, x) == "-")
        v.coefficient = -1;
    else if (input.substr(0, x) == "")
        v.coefficient = 1;
    else
        v.coefficient = stoi(input.substr(0, x));
    if (input.substr(x) == "x")
        v.degree = 1;
    else
        v.degree = stoi(input.substr(x + 2));
    return in;
}

//Class Polynomial//
Polynomial& Polynomial::operator=(const Polynomial& v) {
    if (this != &v) {
        delete [] poly;
        power = 0;
        order_ = v.order_;
        poly = new Term[v.power + 1];
        power = v.power;
        for (int i = 0; i <= power; i++)
            poly[i] = v.poly[i];
    }
    return *this;
}

Polynomial operator*(const Polynomial& v1, const Polynomial& v2) {
    Term a(0, v1.power + v2.power);
    Polynomial v3(a);
    if (v1.power < v2.power) {
        for (int i = 0; i <= v2.power; i++) {
            for (int j = 0; j <= v1.power; j++)
                v3.poly[i + j] = v3.poly[i + j] + (v2.poly[i] * v1.poly[j]);
        }
    }
    else {
        for (int i = 0; i <= v1.power; i++) {
            for (int j = 0; j <= v2.power; j++)
                v3.poly[i + j] = v3.poly[i + j] + (v1.poly[i] * v2.poly[j]);
        }
    }
    return v3;
}

Polynomial operator+(const Polynomial& v1, const Polynomial& v2) {
    Term a(0, std::max(v1.power, v2.power));
    Polynomial v3(a);
    int f = abs(v1.power - v2.power);
    if(v1.power < v2.power) {
        for (int i = 0; i <= v2.power; i++)
            v3.poly[i] = v3.poly[i] + v2.poly[i];
        for (int i = 0; i <= v1.power; i++)
            v3.poly[f + i] = v3.poly[f + i] + v1.poly[i];
    }
    else {
        for (int i = 0; i <= v1.power; i++)
            v3.poly[i] = v3.poly[i] + v1.poly[i];
        for (int i = 0; i <= v2.power; i++)
            v3.poly[f + i] = v3.poly[f + i] + v2.poly[i];
    }
    return v3;
}

Polynomial& Polynomial::operator+=(const Polynomial& v) {
    *this = *this + v;
    return *this;
}

Polynomial& Polynomial::operator*=(const Polynomial& v) {
    *this = *this * v;
    return *this;
}

std::ostream& operator<<(std::ostream& out, const Polynomial& v) {
    if (v.power == 0 && v.poly[0].getCoefficient() == 0) {
        out << "0";
        return out;
    }
    else if (v.power == 0 && v.poly[0].getCoefficient() != 0) {
        out << v.poly[0].getCoefficient();
        return out;
    }
    /*if (v.poly[0].getCoefficient() != 0)
        out << v.poly[0];*/
    out << v.poly[0];
    for (int i = 1; i <= v.power; i++) {
        if (v.poly[i].getCoefficient() == 0)
            continue;
        if (v.poly[i].getCoefficient() < -1 && v.poly[i].getDegree() == 0)
            out << " - " << -v.poly[i].getCoefficient();
        else if (v.poly[i].getCoefficient() < -1 && v.poly[i].getDegree() != 0)
            out << " - " << -v.poly[i].getCoefficient() << "x^" << v.poly[i].getDegree();
        else if (v.poly[i].getCoefficient() == -1 && v.poly[i].getDegree() == 0)
            out << " - 1";
        else if (v.poly[i].getCoefficient() == -1 && v.poly[i].getDegree() != 0)
            out << " - " << "x^" << v.poly[i].getDegree();
        else
            out << " + " << v.poly[i];
    }
    return out;
}

std::istream& operator>>(std::istream& in, Polynomial& v) {
    std::string input;
    in.clear();
    getline(in, input);
    input.erase(remove(input.begin(), input.end(), ' '), input.end());
    input.erase(remove(input.begin(), input.end(), ')'), input.end());
    input.erase(remove(input.begin(), input.end(), '('), input.end());
    for (int i = 0; i < input.length() - 1; i++){
        if (input[i] == '+' && input[i + 1] == '+') input.erase(i + 1, 1);
        if (input[i]== '+' && input[i + 1] == '-') input.erase(i, 1);
        if (input[i]== '-' && input[i + 1]== '+') input.erase(i + 1, 1);
        if (input[i]== '-' && input[i + 1]== '-') input.replace(i,2,"+");
    }
    if (input == "")
        return in;
    if (input[0] == '+')
        input = input.substr(1, input.length());
    int start = 0;
    int pos = input.find_first_of("+-", start + 1);
    int len_temp_mas = std::count(input.begin(), input.end(), '+') + std::count(input.begin(), input.end(), '-') + 1;
    Term* temp_mas = new Term [len_temp_mas];
    std::string temp;
    int i = 0;
    int x;
    while (pos != std::string::npos) {
        temp = input.substr(start, pos - start);
        x = temp.find('x');
        Term t;
        if (x == std::string::npos) {
            t.setCoefficient(std::stoi(temp));
            t.setDegree(0);
        }
        else {
            if (temp.substr(0, x) == "-")
                t.setCoefficient(-1);
            else if (temp.substr(0, x) == "" || temp.substr(0, x) == "+")
                t.setCoefficient(1);
            else
                t.setCoefficient(stoi(temp.substr(0, x)));
            if (temp.substr(x) == "x")
                t.setDegree(1);
            else
                t.setDegree(stoi(temp.substr(x + 2)));
        }
        temp_mas[i] = t;
        i++;
        start = pos;
        pos = input.find_first_of("+-", start + 1);
    }
    temp = input.substr(start, input.length());
    x = temp.find('x');
    Term t;
    if (x == std::string::npos) {
        t.setCoefficient(std::stoi(temp));
        t.setDegree(0);
    }
    else {
        if (temp.substr(0, x) == "-")
            t.setCoefficient(-1);
        else if (temp.substr(0, x) == "" || temp.substr(0, x) == "+")
            t.setCoefficient(1);
        else
            t.setCoefficient(stoi(temp.substr(0, x)));
        if (temp.substr(x) == "x")
            t.setDegree(1);
        else
            t.setDegree(stoi(temp.substr(x + 2)));
    }
    temp_mas[i] = t;
    int new_power = temp_mas[0].getDegree();
    for (int j = 1; j < len_temp_mas; j++) {
        if (temp_mas[j].getDegree() > new_power)
            new_power = temp_mas[j].getDegree();
    }
    Term t1(0, new_power);
    Polynomial v1 (t1);
    for (int j = 0; j < len_temp_mas; j++) {
        Polynomial v2 (temp_mas[j]);
        v1 = v1 + v2;
    }
    v = v1;
    delete [] temp_mas;
    return in;
}