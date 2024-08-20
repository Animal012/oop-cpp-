#include "library.h"

void Planet::read_dbase(const char* filename, Planet* arr, int& n){
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

void print_dbase(Planet *arr, int n){
    cout << " База Данных " << endl;
    for (int i = 0; i < n; i++)
        cout << setw(3) << i + 1 << ". " << arr[i].name << setw(20 - strlen(arr[i].name) + 6)
             << arr[i].diameter << setw(10) << arr[i].habitability << setw(10) << arr[i].satellite << endl;
}

/*int Planet::menu() {
    cout << " ============== ГЛАВНОЕ МЕНЮ ========================\n";
    cout << "1 - чтение базы из файла" << endl;
    cout << "2 - добавление планеты" << endl;
    cout << "3 - удаление планеты" << endl;
    cout << "4 - редактирование планеты" << endl;
    cout << "5 - вывод базы на экран" << endl;
    cout << "6 - вывод базы в файл" << endl;
    cout << "7 - сортировка базы" << endl;
    cout << "8 - выход" << endl;
    cout << "Для выбора операции введите цифру от 1 до 8" << endl;
    int resp = 0;
    cin >> resp;
    return resp;
}*/

int Planet::write_dbase(const char* filename, const Planet *arr, int n) {
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

void add(Planet* arr, int& n) {
    cout << "Введите имя новой планеты: ";
    char buf[100] = "Jupiter";
    cout << "Jupiter" << endl;
    //cin >> buf;
    strcpy(arr[n].name, buf);
    cout << "Введите диаметр планеты: ";
    arr[n].diameter = 142796;
    cout << "142796" << endl;
    //cin >> arr[n].diameter;
    cout << "Введите наличие жизни: ";
    arr[n].habitability = 0;
    cout << "0" << endl;
    //cin >> arr[n].habitability;
    cout << "Введите количество спутников: ";
    arr[n].satellite = 26;
    cout << "26" << endl;
    //cin >> arr[n].satellite;
    n++;
}

void remove(Planet* arr, int& n) {
    cout << "Введите порядковый номер планеты, которую нужно удалить: ";
    cout << "1" << endl;
    int choise = 0;
    //cin >> choise;
    //choise--;
    for (int j = choise; j < n; j++){
        arr[j] = arr[j + 1];
    }
    n--;
    /*if ((choise >= 0) and (choise < n)){
        for (int j = choise; j < n; j++){
            arr[j] = arr[j + 1];
        }
        n--;
    }
    else{
        cout << "Неправильный ввод!" << endl;
    }*/
}

void edit(Planet* arr, int n) {
    cout << "Введите порядковый номер планеты для редактирования: ";
    cout << "3" << endl;
    int choise = 2;
    //cin >> choise;
    //choise--;
    cout << "Что вы хотите отредактировать?\n1)Название\n2)Диаметр\n3)Наличие жизни\n4)Количество спутников" << endl;
    cout << "4" << endl;
    cout << "Введите новые данные: ";
    cout << "16" << endl;
    arr[choise].satellite = 16;
    /*if ((choise >= 0) and (choise < n)) {
        cout << "Что вы хотите отредактировать?\n1)Название\n2)Диаметр\n3)Наличие жизни\n4)Количество спутников" << endl;
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
                arr[choise].diameter = newd;
            else if (ans == 3)
                arr[choise].habitability = newd;
            else
                arr[choise].satellite = newd;
        }
        else{
            cout << "Неправильный ввод" << endl;
        }
    }
    else {
        cout << "Неправильный ввод" << endl;
    }*/
}

Planet* habitability_sort(Planet* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        Planet* pointer = &arr[i];
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < *pointer)
                pointer = &arr[j];
        }
        swap(arr[i].name, pointer->name);
        swap(arr[i].diameter, pointer->diameter);
        swap(arr[i].habitability, pointer->habitability);
        swap(arr[i].satellite, pointer->satellite);
    }
}

/*void swaper(Planet* arr, int j) {
    swap(arr[j].name, arr[j + 1].name);
    swap(arr[j].diameter, arr[j + 1].diameter);
    swap(arr[j].habitability, arr[j + 1].habitability);
    swap(arr[j].satellite, arr[j + 1].satellite);
}*/

void sort_db(Planet* arr, int n) {
    cout << "По какому критерию выполнить сортировку?" << endl;
    cout << "1 - По названию планеты (от А до Я)" << endl;
    cout << "2 - По размеру (от меньшего к большему)" << endl;
    cout << "3 - По наличию жизни (необитаемые - обитаемые)" << endl;
    cout << "4 - По количеству спутников (от меньшего к большему)" << endl;
    /*int ans = 0;
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
                    if (arr[j].diameter > arr[j + 1].diameter)
                        swaper(arr, j);
                }
            }
            break;
        case 3:
            habitability_sort(arr, n);
            break;
        case 4:
            for (int i = 1; i < n; i++) {
                for (int j = 0; j < n - i; j++) {
                    if (arr[j].satellite > arr[j + 1].satellite)
                        swaper(arr, j);
                }
            }
            break;
        default:
            cout << "Неправильный ввод" << endl;
            break;
    }*/
    cout << "Сортировка по наличию жизни (необитаемые - обитаемые)" << endl;
    habitability_sort(arr, n);
}