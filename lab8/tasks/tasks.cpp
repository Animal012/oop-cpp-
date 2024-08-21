#include "tasks.h"

void task1() {
    std::string text;
    std::cout << "Input the word: ";
    text = "sfajdhf@hhhkjhk@hjhhhk@yghjk@";
    std::cout << text << std::endl;
    int count = 0;
    for (char c: text) {
        if (c == '@')
            count++;
    }
    std::cout << "Symbol '@' occurs " << count << " times" << std::endl;
}

void task2() {
    std::string name;
    std::cout << "Input the surname, name and patronymic: ";
    name = "Зеленский Владимир Александрович";
    std::cout << name << std::endl;
    int last_space = name.find_first_of(' ');
    std::string surname = name.substr(0, last_space);
    int first_space = name.find_first_of(' ', last_space + 1);
    std::string initial1 = name.substr(last_space + 1, 2) + ".";
    std::string initial2 = name.substr(first_space + 1, 2) + ".";
    std::string result = surname + " " + initial1 + initial2;
    std::cout << "Transform string: " << result << std::endl;
}

void task3() {
    std::ifstream input_file("/Users/semec/variant-50-user-146/lab8/input.txt");
    if (!input_file.is_open())
        std::cerr << "Error of file opening" << std::endl;
    else {
        std::ofstream output_file("output.txt");
        std::string line;
        while (std::getline(input_file, line))
            output_file << " - " << line << std::endl;
        input_file.close();
        output_file.close();
        std::cout << "File was successfully written" << std::endl;
    }
}

///Task 4 - begin///
void doubleVector(std::vector<int>& vec) {
    for (int i = 0; i < vec.size(); i++)
        vec[i] *= 2;
}

void printVector(const std::vector<int>& vec) {
    for (int i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";
    std::cout << std::endl;
}

void task4() {
    std::srand(std::time(nullptr));
    std::vector<int> vec;
    for (int i = 0; i < 5; i++)
        vec.push_back(std::rand() % 101);
    std::cout << "Vector: ";
    printVector(vec);
    doubleVector(vec);
    std::cout << "Double vector: ";
    printVector(vec);
    vec.erase(vec.begin() + 2);
    std::cout << "Vector without 2-element: ";
    printVector(vec);
}
///Task 4 - end///

void task5() {
    std::vector<Complex> v = {Complex(-1.2, 6.3), Complex(4.0, 0.7), Complex(7.2, 0.8),
                         Complex(5.3, 3.0), Complex(-4.9, 6.6), Complex(-9.3, 0.2)};
    std::cout << "Complex numbers:" << std::endl;
    for (int i = 0; i < v.size(); i++)
        std::cout << v[i].get_real() << " + i * " << v[i].get_imaginary() << std::endl;
    double sum_real = 0;
    double sum_imaginary = 0;
    for (int i = 0; i < v.size(); i++) {
        sum_real += v[i].get_real();
        sum_imaginary += v[i].get_imaginary();
    }
    Complex sum(sum_real, sum_imaginary);
    std::cout << "Sum: " << sum.get_real() << " + i * " << sum.get_imaginary() << std::endl;
}

void task6() {
    std::cout << "Task6 is the same as task4" << std::endl;
    task4();
}

///Task 7 - begin///
void printList(const std::list<Rectangle>& lst) {
    for (Rectangle x: lst)
        std::cout << x << std::endl;
}

void task7() {
    std::list<Rectangle> rectangles = {
            Rectangle(1.2, 6.3),
            Rectangle(4.0, 0.7),
            Rectangle(7.2, 0.8),
            Rectangle(5.3, 3.0),
            Rectangle(4.9, 6.6),
            Rectangle(9.3, 0.2)
    };
    std::cout << "List of rectangles:" << std::endl;
    printList(rectangles);
    auto max_el = max_element(rectangles.begin(), rectangles.end());
    std::cout << "Rectangle with max area: " << *max_el << std::endl;
}
///Task 7 - end

void task8() {
    std::map<std::string, int> my_map;
    my_map.insert(std::make_pair("one", 100));
    my_map.insert(std::make_pair("two", 200));
    my_map.insert(std::make_pair("three", 300));
    my_map.insert(std::make_pair("four", 400));
    my_map.insert(std::make_pair("five", 500));
    my_map.insert(std::make_pair("six", 600));
    std::cout << "Initial map:" << std::endl;
    std::map<std::string, int>::iterator it;
    for (it = my_map.begin(); it != my_map.end(); ++it)
        std::cout << it->first << ": " << it->second << std::endl;
    my_map.erase("five");
    my_map.erase("six");
    std::cout << "Final map:" << std::endl;
    for (it = my_map.begin(); it != my_map.end(); ++it)
        std::cout << it->first << ": " << it->second << std::endl;
}

///Task 9 - begin///
void printMap(const std::map<std::string, std::string>& phonebook) {
    std::cout << "Phonebook:" << std::endl;
    std::map<std::string, std::string>::iterator it;
    for (const auto& entry : phonebook)
        std::cout << entry.first << " - " << entry.second << std::endl;
}

void task9() {
    std::map<std::string, std::string> phonebook;
    std::string name, phone;
    phonebook["Scam"] = "88005553535";
    phonebook["Sberbank"] = "900";
    phonebook["Emergency"] = "112";
    printMap(phonebook);
    name = "Sberbank";
    auto it = phonebook.find(name);
    std::cout << "Removing " << it->first << " - " << it->second << " from the phonebook.\n";
    phonebook.erase(it);
    printMap(phonebook);
}
///Task 9 - end///