#include <Windows.h>
#include <string>
#include <set>
#include <map>

#include "../RaceSimulatorDynamicLib/MyLibrary.h"

using std::endl;

int main()
{ 
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int race, distance;
	std::cout << "Добро пожаловать в гоночный симулятор!" << endl;
	std::cout << "1. Гонка для наземного транспорта" << endl;
	std::cout << "2. Гонка для воздушного транспорта" << endl;
	std::cout << "3. Гонка для наземного и воздушного транспорта" << endl;
	std::cout << "Выберите тип гонки: ";
	try
	{
		std::cin >> race;
		if (race < 1 || race > 3)
		{
			throw std::invalid_argument("Вы ввели некорректное значение!");
		}
	}
	catch (const std::invalid_argument& e) { std::cerr << "Error: " << e.what() << endl; return 1; }

	std::cout << "Укажите длину дистанции (должна быть положительна): ";
	try
	{
		std::cin >> distance;
		if (distance < 0) { throw std::invalid_argument("Дистанция должна быть положительной!"); }
	}
	catch (const std::invalid_argument& e) { std::cerr << "Error: " << e.what() << endl; return 1; }

	int registration;
	std::cout << "Должно быть зарегистрировано хотя бы 2 транспортных средства" << endl;
	std::cout << "1. Зарегистрировать транспорт" << endl;
	std::cout << "Выберите действие: ";
	try
	{
		std::cin >> registration;
		if (registration != 1)
		{
			throw std::invalid_argument("Вы ввели некорректное значение!");
		}
	}
	catch (const std::invalid_argument& e) { std::cerr << "Error: " << e.what() << endl; return 1; }

	std::map<int, std::string> names = {
	{1, "Ботинки-вездеходы"},
	{2, "Метла"},
	{3, "Верблюд"},
	{4, "Кентавр"},
	{5, "Орёл"},
	{6, "Верблюд-быстроход"},
	{7, "Ковёр-самолёт"}
	};

	int count = 0;
	int choose = -1;
	std::set<int> chosen;
	while (!(count == 2 && choose == 0))
	{
		if (race == 1)
		{
			std::cout << "Гонка для наземного транспорта. " << "Расстояние: " << distance << endl;
		}
		else if (race == 2)
		{
			std::cout << "Гонка для воздушного транспорта. " << "Расстояние: " << distance << endl;
		}
		else if (race == 3)
		{
			std::cout << "Гонка для наземного и воздушного транспорта. " << "Расстояние: " << distance
				<< endl;
		}

		bool first = true;
		if (choose != 0)
		{
			std::cout << "Зарегистрированные транспортные средства: ";
			for (int tran : chosen)
			{
				if (!first)
				{
					std::cout << ", ";
				}
				std::cout << names[tran];
				first = false;
			}
			std::cout << endl;
		}

		std::cout <<
			"1. Ботинки-вездеходы\n"
			"2. Метла\n"
			"3. Верблюд\n"
			"4. Кентавр\n"
			"5. Орёл\n"
			"6. Верблюд-быстроход\n"
			"7. Ковёр-самолёт\n"
			"0. Закончить регистрацию" << endl;

		std::cout << "Выберите транспорт или 0 для окончания процесса регистрации: ";
		try
		{
			std::cin >> choose;
			if (choose < 0 || choose > 7)
			{
				throw std::invalid_argument("Вы ввели некорректное значение!");
			}
		}
		catch (const std::invalid_argument& e) { std::cerr << "Error: " << e.what() << endl; return 1; }

		if(choose == 0)
		{
			if(count != 2)
			{
				std::cout << "Должно быть зарегистрировано хотя бы 2 транспортных средства!" << endl;
				continue;
			}
			else
			{
				break;
			}
		}

		if (chosen.count(choose))
		{
			std::cout << "Это транспортное средство уже зарегистрировано!" << endl;
		}
		else
		{
			if (race == 1)
			{
				switch (choose)
				{
				case 1:
					std::cout << "Ботинки-вездеходы успешно зарегистрированы!" << endl;
					count++;
					chosen.insert(choose);
					break;
				case 2:
					std::cout << "Попытка зарегистрировать неправильный тип транспортного средства!"
						<< endl;
					break;
				case 3:
					std::cout << "Верблюд успешно зарегистрирован!" << endl;
					count++;
					chosen.insert(choose);
					break;
				case 4:
					std::cout << "Кентавр успешно зарегистрирован!" << endl;
					count++;
					chosen.insert(choose);
					break;
				case 5:
					std::cout << "Попытка зарегистрировать неправильный тип транспортного средства!" << endl;
					break;
				case 6:
					std::cout << "Верблюд-быстроход успешно зарегистрирован!" << endl;
					count++;
					chosen.insert(choose);
					break;
				case 7:
					std::cout << "Попытка зарегистрировать неправильный тип транспортного средства!" << endl;
				}
			}
			else if (race == 2)
			{
				switch (choose)
				{
				case 1:
					std::cout << "Попытка зарегистрировать неправильный тип транспортного средства!"
						<< endl;
					break;
				case 2:
					std::cout << "Метла успешно зарегистрирована!" << endl;
					count++;
					chosen.insert(choose);
					break;
				case 3:
					std::cout << "Попытка зарегистрировать неправильный тип транспортного средства!"
						<< endl;
					break;
				case 4:
					std::cout << "Попытка зарегистрировать неправильный тип транспортного средства!"
						<< endl;
					break;
				case 5:
					std::cout << "Орёл успешно зарегистрирован!" << endl;
					count++;
					chosen.insert(choose);
					break;
				case 6:
					std::cout << "Попытка зарегистрировать неправильный тип транспортного средства!"
						<< endl;
					break;
				case 7:
					std::cout << "Ковёр-самолёт успешно зарегистрирован!" << endl;
					count++;
					chosen.insert(choose);
				}
			}
			else if (race == 3)
			{
				switch (choose)
				{
				case 1:
					std::cout << "Ботинки-вездеходы успешно зарегистрированы!" << endl;
					count++;
					chosen.insert(choose);
					break;
				case 2:
					std::cout << "Метла успешно зарегистрирована!" << endl;
					count++;
					chosen.insert(choose);
					break;
				case 3:
					std::cout << "Верблюд успешно зарегистрирован!" << endl;
					count++;
					chosen.insert(choose);
					break;
				case 4:
					std::cout << "Кентавр успешно зарегистрирован!" << endl;
					count++;
					chosen.insert(choose);
					break;
				case 5:
					std::cout << "Орёл успешно зарегистрирован!" << endl;
					count++;
					chosen.insert(choose);
					break;
				case 6:
					std::cout << "Верблюд-быстроход успешно зарегистрирован!" << endl;
					count++;
					chosen.insert(choose);
					break;
				case 7:
					std::cout << "Ковёр-самолёт успешно зарегистрирован!" << endl;
					count++;
					chosen.insert(choose);
				}
			}
		}
	}

	int pick;
	std::cout << "1. Зарегистрировать транспорт" << endl;
	std::cout << "2. Начать гонку" << endl;
	std::cout << "Выберите действие: ";
	try
	{
		std::cin >> pick;
		if (pick < 1 && pick > 2)
		{
			throw std::invalid_argument("Вы ввели некорректное значение!");
		}
	}
	catch (const std::invalid_argument& e) { std::cerr << "Error: " << e.what() << endl; return 1; }

	choose = -1;
	if (pick == 1)
	{
		while (choose != 0)
		{
			if (race == 1)
			{
				std::cout << "Гонка для наземного транспорта. " << "Расстояние: " << distance << endl;
			}
			else if (race == 2)
			{
				std::cout << "Гонка для воздушного транспорта. " << "Расстояние: " << distance << endl;
			}
			else if (race == 3)
			{
				std::cout << "Гонка для наземного и воздушного транспорта. " << "Расстояние: " << distance
					<< endl;
			}

			bool first = true;
			if (choose != 0)
			{
				std::cout << "Зарегистрированные транспортные средства: ";
				for (int tran : chosen)
				{
					if (!first)
					{
						std::cout << ", ";
					}
					std::cout << names[tran];
					first = false;
				}
				std::cout << endl;
			}

			std::cout <<
				"1. Ботинки-вездеходы\n"
				"2. Метла\n"
				"3. Верблюд\n"
				"4. Кентавр\n"
				"5. Орёл\n"
				"6. Верблюд-быстроход\n"
				"7. Ковёр-самолёт\n"
				"0. Закончить регистрацию" << endl;

			std::cout << "Выберите транспорт или 0 для окончания процесса регистрации: ";
			try
			{
				std::cin >> choose;
				if (choose < 0 || choose > 7)
				{
					throw std::invalid_argument("Вы ввели некорректное значение!");
				}
			}
			catch (const std::invalid_argument& e) { std::cerr << "Error: " << e.what() << endl; return 1; }

			if (chosen.count(choose))
			{
				std::cout << "Это транспортное средство уже зарегистрировано!" << endl;
			}
			else
			{
				if (race == 1)
				{
					switch (choose)
					{
					case 1:
						std::cout << "Ботинки-вездеходы успешно зарегистрированы!" << endl;
						count++;
						chosen.insert(choose);
						break;
					case 2:
						std::cout << "Попытка зарегистрировать неправильный тип транспортного средства!"
							<< endl;
						break;
					case 3:
						std::cout << "Верблюд успешно зарегистрирован!" << endl;
						count++;
						chosen.insert(choose);
						break;
					case 4:
						std::cout << "Кентавр успешно зарегистрирован!" << endl;
						count++;
						chosen.insert(choose);
						break;
					case 5:
						std::cout << "Попытка зарегистрировать неправильный тип транспортного средства!" << endl;
						break;
					case 6:
						std::cout << "Верблюд-быстроход успешно зарегистрирован!" << endl;
						count++;
						chosen.insert(choose);
						break;
					case 7:
						std::cout << "Попытка зарегистрировать неправильный тип транспортного средства!" << endl;
					}
				}
				else if (race == 2)
				{
					switch (choose)
					{
					case 1:
						std::cout << "Попытка зарегистрировать неправильный тип транспортного средства!"
							<< endl;
						break;
					case 2:
						std::cout << "Метла успешно зарегистрирована!" << endl;
						count++;
						chosen.insert(choose);
						break;
					case 3:
						std::cout << "Попытка зарегистрировать неправильный тип транспортного средства!"
							<< endl;
						break;
					case 4:
						std::cout << "Попытка зарегистрировать неправильный тип транспортного средства!"
							<< endl;
						break;
					case 5:
						std::cout << "Орёл успешно зарегистрирован!" << endl;
						count++;
						chosen.insert(choose);
						break;
					case 6:
						std::cout << "Попытка зарегистрировать неправильный тип транспортного средства!"
							<< endl;
						break;
					case 7:
						std::cout << "Ковёр-самолёт успешно зарегистрирован!" << endl;
						count++;
						chosen.insert(choose);
					}
				}
				else if (race == 3)
				{
					switch (choose)
					{
					case 1:
						std::cout << "Ботинки-вездеходы успешно зарегистрированы!" << endl;
						count++;
						chosen.insert(choose);
						break;
					case 2:
						std::cout << "Метла успешно зарегистрирована!" << endl;
						count++;
						chosen.insert(choose);
						break;
					case 3:
						std::cout << "Верблюд успешно зарегистрирован!" << endl;
						count++;
						chosen.insert(choose);
						break;
					case 4:
						std::cout << "Кентавр успешно зарегистрирован!" << endl;
						count++;
						chosen.insert(choose);
						break;
					case 5:
						std::cout << "Орёл успешно зарегистрирован!" << endl;
						count++;
						chosen.insert(choose);
						break;
					case 6:
						std::cout << "Верблюд-быстроход успешно зарегистрирован!" << endl;
						count++;
						chosen.insert(choose);
						break;
					case 7:
						std::cout << "Ковёр-самолёт успешно зарегистрирован!" << endl;
						count++;
						chosen.insert(choose);
					}
				}
			}
		}
	}
	else if (pick == 2)
	{
		std::multimap<int, int> results;
		for (int tran : chosen)
		{
			int time = 0;
			switch (tran)
			{
			case 1: time = countBootsResultTime(distance); break;
			case 2: time = countBroomResultTime(distance); break;
			case 3: time = countCamelResultTime(distance); break;
			case 4: time = countCentaurResultTime(distance); break;
			case 5: time = countEagleResultTime(distance); break;
			case 6:
			{
				auto result = countFastCamelResultTime(distance);
				if (std::holds_alternative<int>(result))
				{
					time = std::get<int>(result);
				}
				else if (std::holds_alternative<float>(result))
				{
					time = static_cast<int>(std::get<float>(result));
				}
				break;
			}
			case 7: time = countFlyingCarpetResultTime(distance); break;
			}
			results.insert({ time, tran });

		}
		std::cout << "Результаты гонки:" << endl;
		int place = 1;
		for (const auto& result : results)
		{
			std::cout << place++ << ". " << names[result.second] << ". " << "Время: " << result.first
				<< endl;

		}
	}

		return 0;
}