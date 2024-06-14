#include <iostream>
#include <limits>
using namespace std;

/**
 * @brief оператор выбоа способа заполнения массива
 * @param RANDOM 0 автоматическое заполнение
 * @param MANUALLY 1 ручное заполнение
 */
enum SELECT { RANDOM = 0, MANUALLY = 1 };

/**
* @brief Заполняет массив случаными числами
* @param arr указатель на массив
* @param n количество строк
* @param m количество столбцов
*/
void randFill(int** arr, const int n, const int m, const int max, const int min);

/**
* @brief Заполняет массив вручную
* @param arr указатель на массив
* @param n количество строк
* @param m количество столбцов
*/
void manualFill(int** arr, const int n, const int m, const int max, const int min);

/**
* @brief Заменяет все элементы первых трех столбцов на их квадраты
* @param arr указатель на массив
* @param n количество строк
* @param m количество столбцов
*/
void replaceMaxInRows(int** arr, const int n, const int m);

/**
* @brief Вставляет после каждой нечетной строки первую строку
* @param arr указатель на массив
* @param n количество строк
* @param m количество столбцов
*/
void insertEvenRow(int** arr, const int n, const int m, int** newArr);

/**
* @brief Выводит матрицу
* @param arr указатель на массив
* @param n количество строк
* @param m количество столбцов
*/
void printMatrix(int** arr, const int n, const int m);

/**
* @brief Выделяет память под массив
* @param arr указатель на массив
* @param n количество строк
* @param m количество столбцов
*/
int** AllocateMemoryMatrix(const int n, const int m);

/**
* @brief Очищает выделенную память под массив
* @param arr указатель на массив
* @param n количество строк
*/
void DeleteMemoryMatrix(int** arr, const int n);

/**
* @brief Считывает число типа int с проверкой
* @return возвращает считанный объект
*/
int getValue();

/**
* @brief Проверка на неотрицательное число
* @param value число для проверки
*/
void checkPositive(const int value);

/**
* @brief Копирует массив из шаблона
* @param arr указатель на массив - шаблон
* @param n количество строк
* @param m количество столбцов
* @return возвращает скопированный массив
*/
int** copyArray(int** arr, const int n, const int m);

/**
* @brief точка входа в программу
* @return 0 - если программма выполнена корректно, инече -1
*/
int main() 
{
    setlocale(LC_ALL, "Russian");
    cout << "Введите количество строк" << endl;
    int n = getValue();
    checkPositive(n);

    cout << "Введите количество столбцов" << endl;
    int m = getValue();
    checkPositive(m);

    cout << "Введите выбор для заполнения массива: " << endl
        << RANDOM << " Для случайного заполнения" << endl
        << MANUALLY << " Для ручного заполнения" << endl;
    int mode = getValue();
    cout << "MIN:" << endl;
    int min = getValue();
    cout << "MAX:" << endl;
    int max = getValue();

    int** arr=AllocateMemoryMatrix(n, m);

    switch (mode) {
    case RANDOM:
        randFill(arr, n, m, max, min);
        break;
    case MANUALLY:
        manualFill(arr, n, m, max, min);
        break;
    default:
        cout << "Некорректный режим заполнения!" << endl;
        DeleteMemoryMatrix(arr, n);
        return 1;
    }

    cout << "Элементы массива:" << endl;
    printMatrix(arr, n, m);
    cout << "1) Заменить максимальный по модулю элемент каждой строки на противоположный по знаку." << endl;
    int** first_task_arr = copyArray(arr, n, m);
    replaceMaxInRows(first_task_arr, n, m);
    printMatrix(first_task_arr, n, m);
    DeleteMemoryMatrix(first_task_arr, n);
    cout << "2) Вставить после каждой четной строки первую строку." << endl;
    int second_rows = n;
    for (size_t j = 0; j < n; j++)
    {
        if (j % 2 == 1)
        {
            second_rows++;
        }
    }
    int** second_task_arr = AllocateMemoryMatrix(second_rows, m);
    insertEvenRow(arr, n, m, second_task_arr);
    printMatrix(second_task_arr, second_rows, m);
    DeleteMemoryMatrix(second_task_arr, second_rows);
    DeleteMemoryMatrix(arr, n);
    return 0;
}

void randFill(int** arr, const int n, const int m, const int max, const int min) 
{
    srand(static_cast<unsigned int>(time(0))); // Инициализация генератора случайных чисел
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            arr[i][j] = rand() % (max - min + 1) + min;
        }
    }
}

void manualFill(int** arr, const int n, const int m,const int max, const int min) 
{
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            cout << " [" << i << "][" << j << "]=";
            cin >> arr[i][j];
            if (arr[i][j] > max || arr[i][j] < min || cin.fail()) {
                cin.clear();
                cout << "Непрвильное число" << endl;
                j--;
            }
        }
    }
}

void replaceMaxInRows(int** arr, const int n, const int m) 
{
    for (size_t i = 0; i < n; i++)
    {
        int max_abs = abs(arr[i][0]);
        int max_index = 0;
        for (size_t j = 0; j < m; j++)
        {
            if (abs(arr[i][j]) > max_abs)
            {
                max_abs = abs(arr[i][j]);
                max_index = j;
            }
        }
        arr[i][max_index] = -1 * arr[i][max_index];
    }
}

void insertEvenRow(int** arr, const int n, const int m, int** newArr) 
{
    int rowIndex = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (i % 2 == 1) {
            for (size_t j = 0; j < m; j++) 
            {
                newArr[rowIndex][j] = arr[i][j];
            }
            rowIndex++;
            for (size_t j = 0; j < m; j++) 
            {
                newArr[rowIndex][j] = arr[0][j];
            }
            rowIndex++;
        }
        else {
            for (size_t j = 0; j < m; j++) 
            {
                newArr[rowIndex][j] = arr[i][j];
            }
            rowIndex++;
        }
    }
}

void printMatrix(int** arr, const int n, const int m) 
{
    for (size_t i = 0; i < n; i++) 
    {
        for (size_t j = 0; j < m; j++) 
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int** AllocateMemoryMatrix(const int n, const int m)
{
    int** arr = new int*[n];
    for (size_t i = 0; i < n; i++) 
    {
        arr[i] = new int[m];
    }
    return arr;
}

void DeleteMemoryMatrix(int** arr, const int n) 
{
    for (size_t i = 0; i < n; i++) 
    {
        delete[] arr[i];
    }
    delete[] arr;
}

int getValue() 
{
    int value;
    while (!(cin >> value)) 
    {
        cout << "Ошибка ввода, попробуйте еще раз: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return value;
}

void checkPositive(const int value) 
{
    if (value <= 0) 
    {
        cout << "Значение должно быть положительным!" << endl;
        abort();
    }
}

int** copyArray(int** arr, const int n, const int m) 
{
    int** newArr = AllocateMemoryMatrix(n, m);
    for (size_t i = 0; i < n; i++) 
    {
        for (size_t j = 0; j < m; j++) 
        {
            newArr[i][j] = arr[i][j];
        }
    }
    return newArr;
}