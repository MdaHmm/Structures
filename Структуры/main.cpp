#include <iostream>
#include <string>

// Кодировка UTF-8
// Структура - это описание множества, состоящего из одной или более переменных, возможно имеющих различные типы,
// объединенных под одним именем. Является производным пользовательским типом данных, используемым для создания объектов.

struct dateData {
	int day = 1;
	int month = 1;
	int year = 1970;
};
struct personData {
	std::string name = "Безымянный";
	dateData birthday; // объект структуры, в качестве поля другой структуры
	std::string job = "нет";
	int salary = 0;
};
void show_person(const personData& PD) {
	std::cout << "Имя:       " << PD.name << std::endl;
	std::cout << "ДР:        " << PD.birthday.day << "." << PD.birthday.month << "." << PD.birthday.year << std::endl;
	std::cout << "Работа:    " << PD.job << std::endl;
	std::cout << "Зарплатка: " << PD.salary << std::endl;
}
personData input_person() {
	personData tmp;
	std::cout << "Введите имя -> ";
	std::cin.ignore();
	std::getline(std::cin, tmp.name);
	std::cout << "Введите день рождения -> ";
	std::cin >> tmp.birthday.day;
	std::cout << "Введите месяц рождения -> ";
	std::cin >> tmp.birthday.month;
	std::cout << "Введите год рождения -> ";
	std::cin >> tmp.birthday.year;
	std::cin.ignore();
	std::cout << "Введите работу -> ";
	std::getline(std::cin, tmp.job);
	std::cout << "Введите уровень зарплаты -> ";
	std::cin >> tmp.salary;
	return tmp;
}
struct coinKeeper {
	std::string name = "Безымянный";
	int age = 0;
	int coins_number = 0;
	int* coins = nullptr;
};
void show_coinKeeper(const coinKeeper& CK) {
	std::cout << "Имя:     " << CK.name << std::endl;
	std::cout << "Возраст: " << CK.age << std::endl;
	std::cout << "Монеты: ";
	for (int i{}; i < CK.coins_number; i++)
		std::cout << CK.coins[i] << ", ";
	std::cout << "\b\b \n";
}
inline int year_of_birth(const coinKeeper& CK, int year){
	return (year - CK.age);
}
int cash(const coinKeeper& CK) {
	int sum = 0;
	for (int i{}; i < CK.coins_number; i++)
		sum += CK.coins[i];
	return sum;
}



int main() {
	setlocale(LC_ALL, "Russian");
	int n;

	// Структура person
	/*
	struct person { // структура, явл. описанием объектов
		std::string name; // поле структуры, явл. строковой переменной
		int age;		  // поле структуры, явл. целочисленной переменной
		std::string gender;
		std::string job;
		int salary;
	} p1, p2{"Петька", 19, "муж.", "Солдат", 50000}; // создание объектов структуры, один из которых мгновенно инициализирован

	// обращение к полям объекта структуры 
	p1.name = "Василий Иваныч";
	p1.age = 26;
	p1.gender = "муж.";
	p1.job = "Комдив";
	p1.salary = 80000;

	std::cout << "Имя: " << p1.name << std::endl;
	std::cout << "Возраст: " << p1.age << std::endl;
	std::cout << "Пол: " << p1.gender << std::endl;
	std::cout << "Работа: " << p1.job << std::endl;
	std::cout << "Зарплата: " << p1.salary << std::endl;

	std::cout << "--------------------\n";

	std::cout << "Имя: " << p2.name << std::endl;
	std::cout << "Возраст: " << p2.age << std::endl;
	std::cout << "Пол: " << p2.gender << std::endl;
	std::cout << "Работа: " << p2.job << std::endl;
	std::cout << "Зарплата: " << p2.salary << std::endl;

	person p3{ // альтернативный вариант создания объекта
		"Анка",
		20,
		"жен.",
		"Пулеметчица",
		50000
	};

	person p4 = p3; // прямое присваивание полям объекта р4 значений объекта р3

	std::cout << "--------------------\n";

	std::cout << "Имя: " << p4.name << std::endl;
	std::cout << "Возраст: " << p4.age << std::endl;
	std::cout << "Пол: " << p4.gender << std::endl;
	std::cout << "Работа: " << p4.job << std::endl;
	std::cout << "Зарплата: " << p4.salary << std::endl;
	*/

	// Структура date
	/*
	struct date {
		unsigned int day = 1;
		unsigned int month = 1;
		unsigned int year = 1970;
		std::string note = "Пусто."; // значение по умолчанию
	};

	date bd{ 1, 5, 2010 };
	std::cout << bd.day << "." << bd.month << "." << bd.year << " - " << bd.note << std::endl;
	// вывод: 1.5.2010 - Пусто.
	*/

	// Две структуры
	/*
	personData pd{
		"Майк Вазовски",
		{29,7,1998},
		"Пугатель",
		95000
	};

	show_person(pd);
	

	personData* pointer = &pd;
	std::cout << pointer->name << std::endl;
	std::cout << pointer->birthday.day << std::endl;

	personData pd2 = input_person();
	show_person(pd2);
	*/

	// Задача 1. Объект с монетами

	std::cout << "Задача 1.\nОбъект:\n";
	coinKeeper keeper{
		"Петян",
		10,
		7,
		new int[7] {1, 10, 5, 2, 2, 5, 10}
	};
	show_coinKeeper(keeper);
	std::cout << "Год рождения: " << year_of_birth(keeper, 2023) << std::endl;
	std::cout << "Общие сбережения: " << cash(keeper) << std::endl;



	delete[] keeper.coins;

	return 0;
}