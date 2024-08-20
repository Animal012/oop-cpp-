#include "classes.h"

int demo() {
    const int size = 12;
    Planet* arr = new Planet [size];
    const char* filename = "planet.txt";
    int n;
    cout << "Чтение базы данных" << endl;
    Planet::read_dbase(filename, arr, n);
    cout << "Запись элементов базы в файл" << endl;
    Planet::write_dbase(filename, arr, n);
    cout << "Добавление элемента в базу" << endl;
    add(arr, n);
    print_dbase(arr, n);
    cout << "Удаление элемента из базы" << endl;
    remove(arr, n);
    print_dbase(arr, n);
    cout << "Редактирование элемента из базы" << endl;
    edit(arr, n);
    print_dbase(arr, n);
    cout << "Сортировка базы" << endl;
    sort_db(arr, n);
    print_dbase(arr, n);
    return 0;
}

int interactive() {
    const int size = 12;
    Shop* arr = new Shop [size];
    const char* filename = "shop.txt";
    int n;
    while (true) {
        switch (Shop::menu()) {
            case 1:
                Shop::read_dbase(filename, arr, n);
                break;
            case 2:
                add(arr, n);
                break;
            case 3:
                remove(arr, n);
                break;
            case 4:
                edit(arr, n);
                break;
            case 5:
                print_dbase(arr, n);
                break;
            case 6:
                Shop::write_dbase(filename, arr, n);
                break;
            case 7:
                sort_db(arr, n);
                break;
            case 8:
                return 0;
            default:
                cout << "Недопустимый номер операции" << endl;
                break;
        }
    }
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