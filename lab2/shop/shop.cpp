#include "shop.h"

void Shop::read_dbase(const char* filename, Shop* arr, int& n){
    ifstream fin(filename, ios::in);
    if (!fin) {
        cout << "Heт файла " << filename << endl;
    }
    fin >> n;
    if (n > 12) {
        cout << "Переполнение БД. n= " << n << endl;
    }
    for (int i = 0; i < n; i++)
        fin >> arr[i];

    fin.close();
}

void print_dbase(Shop *arr, int n){
    cout << " База Данных " << endl;
    for (int i = 0; i < n; i++)
        cout << setw(3) << i + 1 << ". " << arr[i].name << setw(20 - strlen(arr[i].name) + 6)
             << arr[i].square << setw(10) << arr[i].numOfEmployees << setw(10) << arr[i].receipts << endl;
}

int Shop::menu() {
    cout << " ============== ГЛАВНОЕ МЕНЮ ========================\n";
    cout << "1 - чтение базы из файла" << endl;
    cout << "2 - добавление магазина" << endl;
    cout << "3 - удаление магазина" << endl;
    cout << "4 - редактирование магазина" << endl;
    cout << "5 - вывод базы на экран" << endl;
    cout << "6 - вывод базы в файл" << endl;
    cout << "7 - сортировка базы" << endl;
    cout << "8 - выход" << endl;
    cout << "Для выбора операции введите цифру от 1 до 8" << endl;
    int resp = 0;
    cin >> resp;
    return resp;
}

int Shop::write_dbase(const char* filename, const Shop *arr, int n) {
    ofstream fout(filename, ios::out);
    if (!fout) {
        cout << "Ошибка открытия файла" << endl;
        return 1;
    }
    fout << n << endl;
    for (int i = 0; i < n; i++)
        fout << arr[i] << endl;

    fout.close();
    return 0;
}

void add(Shop* arr, int& n) {
    cout << "Введите имя нового магазина:" << endl;
    char buf[100];
    cin >> buf;
    strcpy(arr[n].name, buf);
    cout << "Введите площадь магазина:" << endl;
    cin >> arr[n].square;
    cout << "Введите количество сотрудников:" << endl;
    cin >> arr[n].numOfEmployees;
    cout << "Введите выручку данного магазина:" << endl;
    cin >> arr[n].receipts;
    n++;
}

void remove(Shop* arr, int& n) {
    cout << "Введите порядковый номер магазина, который нужно удалить: ";
    int choise = 0;
    cin >> choise;
    choise--;
    if ((choise >= 0) and (choise < n)){
        for (int j = choise; j < n; j++){
            arr[j] = arr[j + 1];
        }
        n--;
    }
    else{
        cout << "Неправильный ввод!" << endl;
    }
}

void edit(Shop* arr, int n) {
    cout << "Введите порядковый номер магазина для редактирования: ";
    int choise = 0;
    cin >> choise;
    choise--;
    if ((choise >= 0) and (choise < n)) {
        cout << "Что вы хотите отредактировать?\n1)Название\n2)Площадь\n3)Количество сотрудников\n4)Выручка" << endl;
        int ans = 0;
        cin >> ans;
        cout << "Введите новые данные: ";
        if (ans == 1){
            char buf[100];
            cin >> buf;
            strcpy(arr[choise].name, buf);
        }
        else if ((ans >= 2) and (ans <= 4)){
            int newd = 0;
            cin >> newd;
            if (ans == 2)
                arr[choise].square = newd;
            else if (ans == 3)
                arr[choise].numOfEmployees = newd;
            else
                arr[choise].receipts = newd;
        }
        else{
            cout << "Неправильный ввод" << endl;
        }
    }
    else {
        cout << "Неправильный ввод" << endl;
    }
}

Shop* numOfEmployees_sort(Shop* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        Shop* pointer = &arr[i];
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < *pointer)
                pointer = &arr[j];
        }
        swap(arr[i].name, pointer->name);
        swap(arr[i].square, pointer->square);
        swap(arr[i].numOfEmployees, pointer->numOfEmployees);
        swap(arr[i].receipts, pointer->receipts);
    }
}

void swaper(Shop* arr, int j) {
    swap(arr[j].name, arr[j + 1].name);
    swap(arr[j].square, arr[j + 1].square);
    swap(arr[j].numOfEmployees, arr[j + 1].numOfEmployees);
    swap(arr[j].receipts, arr[j + 1].receipts);
}

void sort_db(Shop* arr, int n) {
    cout << "По какому критерию выполнить сортировку?" << endl;
    cout << "1 - По названию магазина (от А до Я)" << endl;
    cout << "2 - По площади (от меньшего к большему)" << endl;
    cout << "3 - По количеству сторудников (от меньшего к большему)" << endl;
    cout << "4 - По выручке (от меньшего к большему)" << endl;
    int ans = 0;
    cin >> ans;
    switch (ans){
        case 1:
            for (int i = 1; i < n; i++) {
                for (int j = 0; j < n - i; j++) {
                    if (*arr[j].name > *arr[j + 1].name)
                        swaper(arr, j);
                }
            }
            break;
        case 2:
            for (int i = 1; i < n; i++) {
                for (int j = 0; j < n - i; j++) {
                    if (arr[j].square > arr[j + 1].square)
                        swaper(arr, j);
                }
            }
            break;
        case 3:
            numOfEmployees_sort(arr, n);
            break;
        case 4:
            for (int i = 1; i < n; i++) {
                for (int j = 0; j < n - i; j++) {
                    if (arr[j].receipts > arr[j + 1].receipts)
                        swaper(arr, j);
                }
            }
            break;
        default:
            cout << "Неправильный ввод" << endl;
            break;
    }
}