#include "fraction.h"

int N_DEC = 4;

void fraction::reduction(float& a, int& b, int& c){
    int sign;
    if (a >= 0)
        sign = 1;
    else
        sign = - 1;
    if (b < 0) {
        b = abs(b);
        sign = -1;
    }
    if (b > c){
        a = a + sign * (b / c);
        b = b % c;
    }
    int del = NOD(b,c);
    b = b / del;
    c = c / del;
}

int fraction::NOD(int a, int b) {
    while (a != 0 and b != 0){
        if (a > b)
            a %= b;
        else
            b %= a;
    }
    return (a + b);
}

int fraction::parser(const char* str, char symbol){
    for (int i = 0; i < strlen(str); i++){
        if (str[i] == symbol){
            return i;
        }
    }
    return -1;
}

char* fraction::substr(const char* str, int symbol1, int symbol2){
    char* arr = new char[symbol2 - symbol1+1];
    for (int i = symbol1; i < symbol2; i++){
        arr[i - symbol1] = str[i];
    }
    arr[symbol2 - symbol1]='\0';
    return arr;
}

////////////////////////////////

fraction::fraction(){
    this->main = 0;
    this->num = 0;
    this->denum = 1;
}

fraction::fraction(int x, int y) {
    this->main = 0.0f;
    if (x != 0 or y != 1) {
        this->num = x;
        this->denum = y;
        reduction(this->main, this->num, this->denum);
    }
    else {
        num = x;
        denum = y;
    }
}

fraction::fraction(const char* x){
    int sign;
    if (x[0] == '-'){
        sign = -1;
        x = substr(x,1,strlen(x));
    }
    else{
        sign = 1;
    }
    if (parser(x,' ') == -1){
        if (sign == -1)
            this->main = -0.0f;
        else
            this->main = 0;
        this->num = atoi(substr(x, 0,parser(x,'/')));
        this->denum = atoi(substr(x, parser(x, '/') + 1, strlen(x)));
    }
    else {
        int space = parser(x,' ');
        this->main = atoi(substr(x,0,space)) * sign;
        this->num = atoi(substr(x,space + 1, parser(x, '/')));
        this->denum = atoi(substr(x,parser(x, '/') + 1, strlen(x)));
    }
    reduction(main, num, denum);
}

fraction::fraction(double x){
    if (N_DEC == 0) {
        std::cout << "Введите погрешность: ";
        std::cin >> N_DEC;
    }
    this->main = int(x);
    this->num = abs((x - double(this->main))) * pow(10,N_DEC);
    this->denum = pow(10, N_DEC);
    reduction(this->main, this->num, this->denum);
}

////////////////////////////////

fraction &fraction::operator = (const fraction &other) {
    if (this != &other) {
        this->main = other.main;
        this->num = other.num;
        this->denum = other.denum;
    }
    return *this;
}

std::ostream& operator << (std::ostream& out, const fraction& obj){
    if (obj.main == 0.0f && std::signbit(obj.main))
        out << "-";
    if (obj.main != 0)
        out << obj.main << " ";
    if (obj.num != 0 or obj.main == 0)
        out << obj.num << "/" << obj.denum;
    return out;
}

std::istream& operator >> (std::istream& in, fraction& obj){
    std::string str1;
    std::getline(in, str1);
    char *str2 = new char(str1.length() + 1);
    strncpy(str2, str1.c_str(), str1.length() + 1);
    obj = fraction(str2);
    return in;
}

fraction operator + (const fraction& obj1, const fraction& obj2){
    fraction new_obj;
    int sign1 = 10;
    int sign2 = 10;
    if (obj1.main == 0.0f and std::signbit(obj1.main))
        sign1 = 0;
    if (obj2.main == 0.0f and std::signbit(obj2.main))
        sign2 = 0;
    if (sign1 != 0) {
        if (obj1.main >= 0)
            sign1 = 1;
        else
            sign1 = -1;}
    if (sign2 != 0) {
        if (obj2.main >= 0)
            sign2 = 1;
        else
            sign2 = -1;}
    int num1, num2;
    if (sign1 == 0)
        num1 = obj1.num * (-1);
    else
        num1 = sign1 * (abs(obj1.main) * obj1.denum + obj1.num);
    if (sign2 == 0)
        num2 = obj2.num * (-1);
    else
        num2 = sign2 * (abs(obj2.main) * obj2.denum + obj2.num);
    new_obj.num = num1 * obj2.denum + num2 * obj1.denum;
    new_obj.denum = obj1.denum * obj2.denum;
    int new_sign;
    if (new_obj.num >= 0)
        new_sign = 1;
    else
        new_sign = -1;
    new_obj.main = new_sign * (abs(new_obj.num) / new_obj.denum);
    new_obj.num = abs(new_obj.num) % new_obj.denum;
    fraction::reduction(new_obj.main, new_obj.num, new_obj.denum);
    return new_obj;
}

fraction& fraction::operator += (const fraction& obj){
    *this = (*this) + obj;
    return *this;
}

fraction& fraction::operator += (double dbl){
    fraction obj(dbl);
    *this = (*this) + obj;
    return *this;
}

fraction& fraction::operator += (int dbl){
    this->main += dbl;
    return *this;
}

fraction operator + (int number, const fraction& obj) {
    fraction new_obj = fraction(number, 1);
    return obj + new_obj;
}

fraction operator + (const fraction& obj, int number) {
    fraction new_obj = fraction(number, 1);
    return obj + new_obj;
}

fraction operator + (double number, const fraction& obj) {
    fraction result;
    fraction new_obj(number);
    result = obj + new_obj;
    return result;
}

fraction operator + (const fraction& obj, double number) {
    fraction result;
    fraction new_obj(number);
    result = obj + new_obj;
    return result;
}