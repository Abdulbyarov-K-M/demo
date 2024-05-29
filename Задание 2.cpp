#include<iostream> 
#include<stdlib.h> 
using namespace std;

/*
* @brief Рассчитывает значение B
* @return возвращает значение
*/
double getB(const double a, const double n);

/*
* @brief Проверяет положительные ли значения а и n
*/
void checkN(const double n);

/*
* @brief нужно для ввода значений
* @return a
*/
double getNumber();

/*
* @brief Рассчитывает площадь прямоугольника
* @param area - область прямоугольника
* @return area
*/
double areaRectangle(const double a, const  double b);

/*
* @brief Рассчитывает перимeтр прямоугольника
* @param perimeter- периметр фигуры
* @return perimeter
*/
double perimeterRectangle(const double a, const double b);

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Введите первую сторону ";
	double a = getNumber();
	checkN(a);
	cout << "Введите процентнoе соотношение для второй стороны ";
	double n = getNumber();
	checkN(n);
	double b = getB(a, n);
	cout << "Площадь = " << areaRectangle(a, b) << endl;
	cout << "Перимeтр = " << perimeterRectangle(a, b);
	return 0;
}

double getNumber()
{
	double a;
	cin >> a;
	if (cin.fail())
	{
		cout << "Неправильный ввод данных";
		abort();
	}
	return a;
}

void checkN(const double n)
{
	if (n <= 0)
	{
		cout << "Неправильное значение" << endl;
		abort();
	}
}

double getB(const double a,const double n)
{
	double k = a * n / 100;
	return;
}

double areaRectangle(const double a, const double b)
{
	double area = a * b;
	return area;
}

double perimeterRectangle(const double a, const double b)
{
	double perimeter = 2 * (a + b);
	return perimeter;
}

