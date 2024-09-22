#include <iostream>
#include <iomanip>
#include <string>
#include "Menu.h"

int main()
{
	int choose = 0;
	std::cout << "Enter '1' if you want records \"Alive Gift\" and '0' to records \"Dead Gift\": ";
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
		Menu<GiftHuman> menu;
		menu.main();
	}
	else
	{
		Menu<Gift> menu;
		menu.main();
	}
	return 0;
}