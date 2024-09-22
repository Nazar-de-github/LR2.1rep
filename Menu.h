#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include "MySTLLib.h"
#include "BasicClasses.h"
#include "Gift.h"
#include "HumanGift.h" 


template<typename Gift_t>
class Menu {
private:
	MyCont<std::string, Gift_t> container;

	void add_from_keyboard();
	void add_from_file();
	void show_for_type();
	void show_all();
	void show_vector();
	void delete_name();
	void delete_all();
	void show_sum_type();
	void show_sum_all();

	void Exit() { exit(0); }
	void Add();
	void show();
	void delete_menu();
	void show_sum();
	void sort_menu();
	void sort_by(std::string sortBy);
	void save();
	void load();
public:
	void main();
};

template<typename Gift_t>
void Menu<Gift_t>::add_from_keyboard()
{
	system("cls");
	std::string name;
	std::cout << "Enter the name: ";
	std::cin >> name;

	float price;
	std::cout << "Enter the price: ";
	std::cin >> price;
	while (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(LLONG_MAX, '\n');
		std::cout << "incorrect value. Enter float value : ";
		std::cin >> price;
	}

	std::string type;
	std::cout << "Enter the type: ";
	std::cin >> type;

	int day;
	std::cout << "Enter the day: ";
	std::cin >> day;
	while (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(LLONG_MAX, '\n');
		std::cout << "incorrect value. Enter int value : ";
		std::cin >> day;
	}
	int month;
	std::cout << "Enter the month: ";
	std::cin >> month;
	while (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(LLONG_MAX, '\n');
		std::cout << "incorrect value. Enter int value : ";
		std::cin >> month;
	}

	Gift_t temp(name, price, type, { day, month });
	container.Add(temp);

	system("cls");
	std::cout << "Successfully add new gift\n";
	Add();
}
template<typename Gift_t>
void Menu<Gift_t>::add_from_file()
{
	system("cls");
	std::string file_name;
	std::cout << "Enter name of file: ";
	std::cin.ignore(LLONG_MAX, '\n');
	std::getline(std::cin, file_name);

	std::ifstream file(file_name);
	if (!file)
	{
		system("cls");
		std::cout << "File named \" " << file_name << " \" is not found";
		Add();
	}
	file >> container;

	system("cls");
	std::cout << "Successfully add new gifts\n";
	Add();
}
template<typename Gift_t>
void Menu<Gift_t>::show_for_type()
{
	system("cls");
	std::string type;
	std::cout << "Enter category of gift: ";
	std::cin >> type;
	system("cls");

	container.show(type);
	std::cout << "\n\n=====================================================\n\nEnter '1' if you want return to 'show menu' and '0 to return to 'main menu': ";
	int choose;
	std::cin >> choose;
	while (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(LLONG_MAX, '\n');
		std::cout << "incorrect value. Enter int value : ";
		std::cin >> choose;
	}
	if (choose == 1)
	{
		system("cls");
		show();
	}
	else
	{
		system("cls");
		main();
	}
}
template<typename Gift_t>
void Menu<Gift_t>::show_all()
{
	system("cls");

	container.show_map();
	std::cout << "\n\n=====================================================\n\nEnter '1' if you want return to 'show menu' and '0 to return to 'main menu': ";
	int choose;
	std::cin >> choose;
	while (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(LLONG_MAX, '\n');
		std::cout << "incorrect value. Enter int value : ";
		std::cin >> choose;
	}
	if (choose == 1)
	{
		system("cls");
		show();
	}
	else
	{
		system("cls");
		main();
	}
}
template<typename Gift_t> // show sorted conteiner (if you sort them before)
void Menu<Gift_t>::show_vector()
{
	system("cls");

	container.show_vector();
	std::cout << "\n\n=====================================================\n\nEnter '1' if you want return to 'show menu' and '0 to return to 'main menu': ";
	int choose;
	std::cin >> choose;
	while (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(LLONG_MAX, '\n');
		std::cout << "incorrect value. Enter int value : ";
		std::cin >> choose;
	}
	if (choose == 1)
	{
		system("cls");
		show();
	}
	else
	{
		system("cls");
		main();
	}
}
template<typename Gift_t>
void Menu<Gift_t>::delete_name()
{
	system("cls");
	std::string name;
	std::cout << "Enter name of gift: ";
	std::cin >> name;

	system("cls");
	if (container.Delete(name))
		std::cout << "Successfully delete gift\n";
	else
		std::cout << "Gift was not found\n";
	delete_menu();
}
template<typename Gift_t>
void Menu<Gift_t>::delete_all()
{
	system("cls");
	bool choose;
	std::cout << "Really want to delete all gifts? Enter '1' if you want and '0' if dont: ";
	std::cin >> choose;
	while (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(LLONG_MAX, '\n');
		std::cout << "incorrect value. Enter int value : ";
		std::cin >> choose;
	}
	if (choose)
	{
		container.clear();
	}

	system("cls");
	std::cout << "Successfully delete all gifts\n";
	delete_menu();
}
template<typename Gift_t> // show summary price for type
void Menu<Gift_t>::show_sum_type()
{
	system("cls");
	std::string type;
	std::cout << "Enter type of gifts that you want to see summary: ";
	std::cin >> type;

	system("cls");
	std::cout << "Summary price: " << container.sum_of_all_price(type) << "\n";
	main();
}
template<typename Gift_t>
void Menu<Gift_t>::show_sum_all()
{
	system("cls");
	std::cout << "Summary price: " << container.sum_of_all_price() << "\n";
	main();
}
template<typename Gift_t> // show main menu
void Menu<Gift_t>::main()
{
	std::cout << std::endl;
	std::cout << "               ==========================MENU==========================             \n\n";
	std::cout << "                                     [1] Add new gift                               \n";
	std::cout << "                                     [2] Delete gift                                \n";
	std::cout << "                                     [3] Show gifts                                 \n";
	std::cout << "                                     [4] Show summary price                         \n";
	std::cout << "                                     [5] Sort                         \n";
	std::cout << "                                     [6] Save to file                               \n";
	std::cout << "                                     [7] Load from file                             \n";
	std::cout << "                                     [0] Exit                                       \n\n\n";
	std::cout << "                            Enter number (0-6) to choose option                     \n\n";
	std::cout << "               ========================================================             \n";

	int choose = -1;
	while (choose == -1)
	{
		std::cin >> choose;
		while (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(LLONG_MAX, '\n');
			std::cout << "incorrect value. Enter int value : ";
			std::cin >> choose;
		}
		switch (choose)
		{
		case 0:
			Exit();
		case 1:
			system("cls");
			Add();
			choose = -1;
			break;
		case 2:
			system("cls");
			delete_menu();
			choose = -1;
			break;
		case 3:
			system("cls");
			show();
			choose = -1;
			break;
		case 4:
			system("cls");
			show_sum();
			choose = -1;
			break;
		case 5:
			system("cls");
			sort_menu();
			choose = -1;
			break;
		case 6:
			system("cls");
			save();
			choose = -1;
			break;
		case 7:
			system("cls");
			load();
			choose = -1;
			break;
		default:
			choose = -1;
		}
	}
}
template<typename Gift_t> // Show menu for add gifts
void Menu<Gift_t>::Add()
{
	std::cout << std::endl;
	std::cout << "               ===================== Add new gift =====================             \n\n";
	std::cout << "                                     [1] From keyboard                               \n";
	std::cout << "                                     [2] From file                                \n";
	std::cout << "                                     [3] Return to MENU                                 \n";
	std::cout << "                                     [0] Exit                                       \n\n\n";
	std::cout << "                            Enter number (0-3) to choose option                     \n\n";
	std::cout << "               ========================================================             \n";

	int choose = -1;
	while (choose == -1)
	{
		std::cin >> choose;
		while (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(LLONG_MAX, '\n');
			std::cout << "incorrect value. Enter int value : ";
			std::cin >> choose;
		}
		switch (choose)
		{
		case 0:
			Exit();
		case 1:
			add_from_keyboard();
			choose = -1;
			break;
		case 2:
			add_from_file();
			choose = -1;
			break;
		case 3:
			system("cls");
			main();
			break;
		default:
			choose = -1;
		}
	}
}
template<typename Gift_t> //show menu to choose what you want to se from your container
void Menu<Gift_t>::show()
{
	std::cout << std::endl;
	std::cout << "               ========================= Show =========================             \n\n";
	std::cout << "                                     [1] By category                               \n";
	std::cout << "                                     [2] All                                \n";
	std::cout << "                                     [3] Sorted                                \n";
	std::cout << "                                     [4] Return to MENU                                 \n";
	std::cout << "                                     [0] Exit                                       \n\n\n";
	std::cout << "                            Enter number (0-3) to choose option                     \n\n";
	std::cout << "               ========================================================             \n";

	int choose = -1;
	while (choose == -1)
	{
		std::cin >> choose;
		while (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(LLONG_MAX, '\n');
			std::cout << "incorrect value. Enter int value : ";
			std::cin >> choose;
		}
		switch (choose)
		{
		case 0:
			Exit();
		case 1:
			show_for_type();
			choose = -1;
			break;
		case 2:
			show_all();
			choose = -1;
			break;
		case 3:
			show_vector();
			choose = -1;
			break;
		case 4:
			system("cls");
			main();
			break;
		default:
			choose = -1;
		}
	}
}
template<typename Gift_t>
void Menu<Gift_t>::delete_menu()
{
	std::cout << std::endl;
	std::cout << "               ========================= Delete =========================             \n\n";
	std::cout << "                                     [1] By name                               \n";
	std::cout << "                                     [2] All container                                \n";
	std::cout << "                                     [3] Return to MENU                                 \n";
	std::cout << "                                     [0] Exit                                       \n\n\n";
	std::cout << "                            Enter number (0-3) to choose option                     \n\n";
	std::cout << "               ========================================================             \n";

	int choose = -1;
	while (choose == -1)
	{
		std::cin >> choose;
		while (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(LLONG_MAX, '\n');
			std::cout << "incorrect value. Enter int value : ";
			std::cin >> choose;
		}
		switch (choose)
		{
		case 0:
			Exit();
		case 1:
			delete_name();
			choose = -1;
			break;
		case 2:
			delete_all();
			choose = -1;
			break;
		case 3:
			system("cls");
			main();
			break;
		default:
			choose = -1;
		}
	}
}
template<typename Gift_t> // show menu for choose sum that you want to see
void Menu<Gift_t>::show_sum()
{
	std::cout << std::endl;
	std::cout << "               ================== Show summary price ==================             \n\n";
	std::cout << "                                     [1] For type                               \n";
	std::cout << "                                     [2] For all container                                \n";
	std::cout << "                                     [3] Return to MENU                                 \n";
	std::cout << "                                     [0] Exit                                       \n\n\n";
	std::cout << "                            Enter number (0-3) to choose option                     \n\n";
	std::cout << "               ========================================================             \n";

	int choose = -1;
	while (choose == -1)
	{
		std::cin >> choose;
		while (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(LLONG_MAX, '\n');
			std::cout << "incorrect value. Enter int value : ";
			std::cin >> choose;
		}
		switch (choose)
		{
		case 0:
			Exit();
		case 1:
			show_sum_type();
			choose = -1;
			break;
		case 2:
			show_sum_all();
			choose = -1;
			break;
		case 3:
			system("cls");
			main();
			break;
		default:
			choose = -1;
		}
	}
}
template<typename Gift_t> // show menu to choose by what you want to sort container
void Menu<Gift_t>::sort_menu()
{
	std::cout << std::endl;
	std::cout << "               ========================== Sort ========================             \n\n";
	std::cout << "                                     [1] By price                               \n";
	std::cout << "                                     [2] By name                                \n";
	std::cout << "                                     [3] By category                                \n";
	std::cout << "                                     [4] By date                                \n";
	std::cout << "                                     [5] Return to MENU                                 \n";
	std::cout << "                                     [0] Exit                                       \n\n\n";
	std::cout << "                            Enter number (0-3) to choose option                     \n\n";
	std::cout << "               ========================================================             \n";

	int choose = -1;
	while (choose == -1)
	{
		std::cin >> choose;
		while (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(LLONG_MAX, '\n');
			std::cout << "incorrect value. Enter int value : ";
			std::cin >> choose;
		}
		switch (choose)
		{
		case 0:
			Exit();
		case 1:
			sort_by("price");
			choose = -1;
			break;
		case 2:
			sort_by("name");
			choose = -1;
			break;
		case 3:
			sort_by("category");
			choose = -1;
			break;
		case 4:
			sort_by("date");
			choose = -1;
			break;
		case 5:
			system("cls");
			main();
			break;
		default:
			choose = -1;
		}
	}
}
template<typename Gift_t>
void Menu<Gift_t>::sort_by(std::string sortBy)
{
	system("cls");
	bool choose;
	std::cout << "Enter '1' if you want to sort in ascending order and '0' if you want to sort in descending order: ";
	std::cin >> choose;
	while (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(LLONG_MAX, '\n');
		std::cout << "incorrect value. Enter int value : ";
		std::cin >> choose;
	}

	if (choose)
	{
		if (sortBy == "price")
		{
			container.Sort([](const Gift_t& a, const Gift_t& b) {return a.get_price() < b.get_price(); });
		}
		if (sortBy == "name")
		{
			container.Sort([](const Gift_t& a, const Gift_t& b) {return a.get_name() < b.get_name(); });
		}
		if (sortBy == "category")
		{
			container.Sort([](const Gift_t& a, const Gift_t& b) {return a.get_type() < b.get_type(); });
		}
		if (sortBy == "date")
		{
			container.Sort([](const Gift_t& a, const Gift_t& b) {return (a.get_date().month < b.get_date().month ||
				a.get_date().month == b.get_date().month && a.get_date().day < b.get_date().day); });
		}
	}
	else
	{
		if (sortBy == "price")
		{
			container.Sort([](const Gift_t& a, const Gift_t& b) {return a.get_price() > b.get_price(); });
		}
		if (sortBy == "name")
		{
			container.Sort([](const Gift_t& a, const Gift_t& b) {return a.get_name() > b.get_name(); });
		}
		if (sortBy == "category")
		{
			container.Sort([](const Gift_t& a, const Gift_t& b) {return a.get_type() > b.get_type(); });
		}
		if (sortBy == "date")
		{
			container.Sort([](const Gift_t& a, const Gift_t& b) {return (a.get_date().month > b.get_date().month ||
				a.get_date().month == b.get_date().month && a.get_date().day > b.get_date().day); });
		}
	}

	system("cls");
	if (container.empty())
		std::cout << "Container is empty\n";
	else
		std::cout << "Successfully Sorted\n";
	sort_menu();
}
template<typename Gift_t> // save this container gifts to file
void Menu<Gift_t>::save()
{
	system("cls");
	std::string name;
	std::cout << "Enter name of file: ";
	std::cin.ignore(LLONG_MAX, '\n');
	std::getline(std::cin, name);

	bool choose;
	std::cout << "Enter '1' to create new file (delete old if it exist) or '0' to append old file (if it doesnt exist it will created): ";
	std::cin >> choose;
	while (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(LLONG_MAX, '\n');
		std::cout << "incorrect value. Enter int value : ";
		std::cin >> choose;
	}

	std::ofstream file;
	if (choose)
		file.open(name, std::ios::out);
	else
		file.open(name, std::ios::app);
	file << container;
	file.close();
	system("cls");
	std::cout << "Container successfully saved to file ' " << name << "'";
	main();
}

template<typename Gift_t> // Load gifts from file to container
void Menu<Gift_t>::load()
{
	system("cls");
	std::string name;
	std::cout << "Enter name of file: ";
	std::cin.ignore(LLONG_MAX, '\n');
	std::getline(std::cin, name);

	std::cout << "uploading the file will clear the container. Enter '1' to upload and '0' to return to menu : ";
	bool choose;
	std::cin >> choose;
	while (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(LLONG_MAX, '\n');
		std::cout << "incorrect value. Enter int value : ";
		std::cin >> choose;
	}
	if (choose)
	{
		std::ifstream file(name, std::ios::in);
		if (!file.is_open())
		{
			system("cls");
			std::cout << "The file ' " << name << " ' doesnt exist";
			main();
			return;
		}
		container.clear();
		file >> container;
		file.close();
	}
	system("cls");
	std::cout << "The file ' " << name << " ' has been successfully copied to the container";
	main();
}