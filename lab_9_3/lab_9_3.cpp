#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

struct Goods
{
	char name[100];
	char shop[100];
	double price;
	double amount;
	char measurement[20];
};

void Create(Goods* p, int N);
void Print(Goods* p, const int N);
void SearchShop(Goods* p, const int N, string store);
bool SearchPrice(Goods* p, const int N, double min, double max);
void Sort(Goods* p, const int N);

int main()
{
	SetConsoleCP(1251); // встановлення сторінки win-cp1251 в потік вводу
	SetConsoleOutputCP(1251); // встановлення сторінки win-cp1251 в потік виводу
	int N;
	cout << "Введіть загальну кількість товарів: "; cin >> N;
	Goods* p = new Goods[N]; // створення посилання на об'єкт типу Goods
	Create(p, N);
	char ch;
	string store;
	do
	{
		cout << endl;
		cout << "Зробіть вибір:" << endl;
		cout << "[1] - редагувати введенні данні" << endl;
		cout << "[2] - вивести всі товари на екран;" << endl;
		cout << "[3] - провести пошук по магазинам;" << endl;
		cout << "[4] - провести пошук по цінам;" << endl;
		cout << "[5] - провести сортування;" << endl << endl;

		cout << "[0] - завершення роботи." << endl << endl;
		cout << "Ваш вибір: "; cin >> ch;
		switch (ch)
		{
		case '0':
			break;
		case '1':
			cout << "Введіть загальну кількість товарів: "; cin >> N;
			Create(p, N);
			break;
		case '2':
			Print(p, N);
			break;
		case '3':
			cout << endl;
			cout << "Будь ласка, введіть назву магазину, в якому буде проведений пошук: "; cin >> store;
			SearchShop(p, N, store);
			break;
		case '4':
			double min, max;
			cout << endl;
			cout << "Введіть мінімальну ціну товару(UAH): "; cin.sync(); cin >> min;
			cout << endl;
			cout << "Введіть максимальну ціну товару(UAH): "; cin.sync(); cin >> max;
			cout << endl;
			SearchPrice(p, N, min, max);
			break;
		case '5':
			Sort(p, N);
			cout << "Сортування успішно проведено" << endl;
			break;
		default:
			cout << "Помилка вводу! ";
		}
	} while (ch != '0');
	return 0;
}

void Create(Goods* p, int N) // створення файлу з введених рядків
{
	for (int i = 0; i < N; i++) {
		cout << endl;
		cout << "Товар № " << i + 1 << ":" << endl;
		cout << "назва товару: "; cin >> p[i].name;
		cout << "магазин: "; cin >> p[i].shop;
		cout << "ціна(UAH): "; cin >> p[i].price;
		cout << "кількість: "; cin >> p[i].amount;
		cout << "од. вимірювання: "; cin >> p[i].measurement;
		cout << endl;
	}
	cout << endl;
}

void Print(Goods* p, const int N) // виведення файлу на екран
{
	cout << "========================================================================="
		<< endl;
	cout << "|  №  |  Товар  |  Магазин  |  Ціна  |  Кількість  |  Од. вимірювання  |"
		<< endl;
	cout << "-------------------------------------------------------------------------"
		<< endl;
	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(2) << right << i + 1 << "  ";
		cout << "|   " << setw(6) << left << p[i].name
			<< "|   " << setw(6) << left << p[i].shop << "  "
			<< "|   " << setw(5) << left << p[i].price
			<< setw(4) << "|     " << setw(6) << left << p[i].amount << "  "
			<< setw(6) << "|       " << setw(12) << left << p[i].measurement << "|";
		cout << endl;
	}
	cout << "========================================================================= "
		<< endl;
	cout << endl;
}


void SearchShop(Goods* p, const int N, string store)
{
	cout << endl;
	int k = 0;
	cout << endl;
	cout << "========================================================================="
		<< endl;
	cout << "|  №  |  Товар  |  Магазин  |  Ціна  |  Кількість  |  Од. вимірювання  |"
		<< endl;
	cout << "-------------------------------------------------------------------------"
		<< endl;
	for (int i = 0; i < N; i++)
	{
		if (p[i].shop == store) {
			cout << "| " << setw(2) << right << i + 1 << "  ";
			cout << "|   " << setw(6) << left << p[i].name
				<< "|   " << setw(6) << left << p[i].shop << "  "
				<< "|   " << setw(5) << left << p[i].price
				<< setw(4) << "|     " << setw(6) << left << p[i].amount << "  "
				<< setw(6) << "|       " << setw(12) << left << p[i].measurement << "|";
			cout << endl;
			k = 1;
		}
	}
	if (k == 0) {
		cout << "Нажаль, цей магазин не було знайдено. Будь ласка, перевірте правильність вводу." << endl;
	}
	cout << "========================================================================= "
		<< endl;
	cout << endl;
}

bool SearchPrice(Goods* p, const int N, double min, double max)
{
	cout << endl;
	int k = 0;
	cout << "========================================================================="
		<< endl;
	cout << "|  №  |  Товар  |  Магазин  |  Ціна  |  Кількість  |  Од. вимірювання  |"
		<< endl;
	cout << "-------------------------------------------------------------------------"
		<< endl;
	for (int i = 0; i < N; i++)
	{
		if (p[i].price >= min && p[i].price <= max) {
			cout << "| " << setw(2) << right << i + 1 << "  ";
			cout << "|   " << setw(6) << left << p[i].name
				<< "|   " << setw(6) << left << p[i].shop << "  "
				<< "|   " << setw(5) << left << p[i].price
				<< setw(4) << "|     " << setw(6) << left << p[i].amount << "  "
				<< setw(6) << "|       " << setw(12) << left << p[i].measurement << "|";
			cout << endl;
			k = 1;
		}
	}
	if (k == 0) {
		cout << "Схоже, в цій ціновій категорії нічого не було знайдено. Будь ласка, введіть іншу цінову категорію і повторіть пошук." << endl;
		return false;
	}
	cout << "========================================================================= "
		<< endl;
	cout << endl;
	return true;
}
void Sort(Goods* p, const int N)
{
	Goods tmp;
	for (int i0 = 0; i0 < N - 1; i0++) {
		for (int i1 = 0; i1 < N - i0 - 1; i1++) {
			if ((p[i1].shop > p[i1].shop)
				||
				(p[i1].shop == p[i1].shop &&
					p[i1].price > p[i1 + 1].price))
			{
				tmp = p[i1];
				p[i1] = p[i1 + 1];
				p[i1 + 1] = tmp;
			}
		}
	}
}