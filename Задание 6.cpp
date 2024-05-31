#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

/**
 * @brief оператор выбоа способа заполнения массива
 * @param RANDOM = 0 автоматическое заполнение
 * @param MANUALLY =1 ручное заполнение
 */
enum SELECT { RANDOM = 0, MANUALLY = 1 };

/**
 * @brief проверяет размер массива
 * @param n - размер массива
 */
void checkN(const int n);

/**
 * @brief считывает размер массива
 * @return размер массива в беззнаковом типе данных
 */
size_t getSize();

/**
 * @brief считывает значение типа int
 * @return считанное значение целочисленное
 */
int getNumber();

/**
 * @brief вывод массива на экран
 * @param arr - массив
 * @param n - размер массива
 */
void printArray(const int* arr, const int n);

/**
 * @brief заполнение массива автоматически случайнвми числами в заданном диапазоне
 * @param arr - массив
 * @param n - размер массива
 * @param min - минимальное значение диапазона значений элементов массива
 * @param max - максимальное значение диапазона значений элементов массива
 */
void fillArrayRandom(int* arr, const int n, const int min, const int max);

/**
 * @brief проверяет диапазон
 * @param min - минимальное значение диапазона значений элементов массива
 * @param max - максимальное значение диапазона значений элементов массива
 */
void checkRange(const int min, const int max);

/**
 * @brief находит сумму элементов массива, имеющих нечетное значение.
 * @param arr Массив целых чисел.
 * @param n Размер массива.
 * @return Сумма элементов массива с нечетными значениями.
 */
int findSumOfOddValues(int arr[], int n);

/**
 * @brief заменяет второй элемент массива на максимальный среди отрицательных.
 * Если в массиве нет отрицательных чисел, второй элемент остается без изменений.
 * @param arr Массив целых чисел.
 * @param n Размер массива.
 */
void replaceSecondWithMaxNegative(const int arr[],const int n);

/**
 * @brief  выводит индексы элементов массива, значения которых больше заданного числа A.
 * @param arr Массив целых чисел.
 * @param n Размер массива.
 * @param a Заданное число a.
 */
void printIndexesGreaterThana(const int arr[],const  int n, const  int a);

/**
 * @brief заполнение массива вручную
 * @param arr - массив
 * @param n - размер массива
 * @param min - минимальное значение диапазона значений элементов массива
 * @param max - максимальное значение диапазона значений элементов массива
 */
void fillArray(int* arr, const int n, const int min, const int max);

/**
* @brief точка входа в программу
* @return 0 - если программма выполнена корректно, инече -1
*/
int main() {
    setlocale(LC_ALL, "Russian");
    int n = getSize();
    int* arr = new int[n];

    cout << "Введите минимальное и максимальное значение диапазона: ";
    int minValue = getNumber();
    int maxValue = getNumber();
    checkRange(minValue, maxValue);

    cout << "Введите выбор для заполнения массива: " << endl
        << RANDOM << " Для случайного заполнения" << endl
        << MANUALLY << " Для ручного заполнения" << endl;

    int choice = getNumber();
    switch ((SELECT)choice) {
    case RANDOM:
        fillArrayRandom(arr, n, minValue, maxValue);
        break;
    case MANUALLY:
        fillArray(arr, n, minValue, maxValue);
        break;
    default:
        cout << "Ваш выбор неверен" << endl;
        return -1;
    }

    cout << "Элементы массива:" << endl;
    printArray(arr, n);

    cout << "Сумма нечётных элементов: " << findSumOfOddValues(arr, n) << endl;

    int a;
    cout << "Введите значение a: ";
    a = getNumber();
    printIndexesGreaterThana(arr, n, a);

    replaceSecondWithMaxNegative(arr, n);

    delete[] arr; // Освобождаем память массива
    return 0;
}

void checkN(const int n) {
    if (n <= 0) {
        cout << "Неправильный размер массива" << endl;
        abort();
    }
}

size_t getSize() {
    cout << "Введите размер массива: ";
    int n;
    cin >> n;
    checkN(n);
    return (size_t)n;
}

int getNumber() {
    int number;
    cin >> number;
    if (cin.fail()) {
        cout << "Неправильный ввод данных";
        abort();
    }
    return number;
}

void printArray(const int* arr, const int n) {
    for (size_t i = 0; i < n; i++) {
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }
}

void fillArrayRandom(int* arr, const int n, const int min, const int max) {
    srand(time(0));
    for (size_t i = 0; i < n; i++) {
        arr[i] = rand() % (max - min + 1) + min;
    }
}

void checkRange(const int min, const int max) {
    if (min > max) {
        cout << "Введен неправильный диапазон" << endl;
        abort();
    }
}

int findSumOfOddValues(int arr[], int n) {
    int sum = 0;
    for (size_t = 0; i < n; ++i) {
        if (arr[i] % 2 != 0) {
            sum += arr[i];
        }
    }
    return sum;
}

void replaceSecondWithMaxNegative(int arr[], int n) {
    int maxNegative = INT_MIN; // Инициализируем максимальное отрицательное значение
    int maxNegativeIndex = -1;

    for (size_t = 0; i < n; ++i) {
        if (arr[i] < 0 && arr[i] > maxNegative) {
            maxNegative = arr[i];
            maxNegativeIndex = i;
        }
    }

    if (maxNegativeIndex != -1) {
        arr[1] = maxNegative;
    }
}

void printIndexesGreaterThana(int arr[], int n, int a) {
    for (size_t = 0; i < n; ++i) {
        if (arr[i] > a) {
            cout << "Индекс " << i << ": " << arr[i] << endl;
        }
    }
}

void fillArray(int* arr, const int n, const int min, const int max) {
    for (size_t i = 0; i < n; i++) {
        cout << "Введите значение для arr[" << i << "]: ";
        arr[i] = getNumber();

        if (arr[i] < min || arr[i] > max) {
            cout << "Значение вне диапазона" << endl;
            i--;
        }
    }
}

