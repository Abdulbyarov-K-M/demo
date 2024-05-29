#include <iostream>

using namespace std;

/**
 * @brief Проверяет, является ли число натуральным.
 * @param num Целое число для проверки.
 * @return true, если число является натуральным (больше нуля), в противном случае - false.
 */
bool isNatural(int num);

/**
 * @brief Проверяет, является ли число целым.
 * @param num Число типа float для проверки.
 * @return true, если число является целым, в противном случае - false.
 */
bool isInteger(float num);

/**
 * @brief Вычисляет среднее арифметическое двух целых чисел.
 * @param num1 Первое целое число для вычисления среднего.
 * @param num2 Второе целое число для вычисления среднего.
 * @return Среднее арифметическое чисел num1 и num2 в виде числа типа float.
 */
float calculateAverage(int num1, int num2);

/**
 * @brief Основная функция программы.
 * @return Возвращает целое число, указывающее на успешное завершение программы (0).
 */
int main()
{
    setlocale(LC_ALL, "Russian");
    int num1, num2;

    cout << "Введите первое натуральное число: ";
    cin >> num1;

    if (!isNatural(num1))
    {
        cout << "Ошибка: Введите натуральное число." << endl;
        return 1;
    }

    cout << "Введите второе натуральное число: ";
    cin >> num2;

    if (!isNatural(num2))
    {
        cout << "Ошибка: Введите натуральное число." << endl;
        return 1;
    }

    float average = calculateAverage(num1, num2);

    if (isInteger(average))
    {
        cout << "Среднее арифметическое чисел " << num1 << " и " << num2 << " является целым числом." << endl;
    }
    else
    {
        cout << "Среднее арифметическое чисел " << num1 << " и " << num2 << " не является целым числом." << endl;
    }

    return 0;
}

bool isNatural(int num)
{
    return num > 0;
}

bool isInteger(float num)
{
    int intPart = static_cast<int>(num);
    return num == intPart;
}


float calculateAverage(int num1, int num2)
{
    return (num1 + num2) / 2.0;
}
