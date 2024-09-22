#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include "BasicClasses.h"

class Gift : public Item, public ForEvent {
private:

public:
	Gift() : Item(), ForEvent() {}
	Gift(std::string gift_name, float gift_price, std::string event_type, Date event_date)
		: Item(gift_name, gift_price), ForEvent(event_type, event_date) {}
	Gift(std::string gift_name, float gift_price, std::string event_type)
		: Item(gift_name, gift_price), ForEvent() {}

	virtual void set_name(std::string gift_name) { name = gift_name; }
	virtual void set_price(float gift_price) { price = gift_price; }
	virtual void set_type(std::string gift_type) { type = gift_type; }
	virtual void set_date(Date d) { date = d; }

	virtual Date get_date() const { return date; }
	virtual std::string get_name()const { return name; }
	float get_price()const { return price; }
	virtual std::string get_type()const { return type; }


	friend std::ostream& operator<<(std::ostream& s, Gift gift);
	friend std::ifstream& operator>>(std::ifstream& s, Gift& gift);

	~Gift() = default;
};

std::ostream& operator<<(std::ostream& s, Gift gift) {
	s << gift.get_name() << "\t" << gift.get_price() << "\t" << gift.get_type() << "\t" << std::setw(2) << std::setfill('0') << gift.get_date().day << "/" << std::setw(2) << std::setfill('0') << gift.get_date().month;
	return s;
}

std::ifstream& operator>>(std::ifstream& s, Gift& gift) {
	std::string name;
	float price;
	std::string type;
	Date event_date;

	std::string temp, temp2;
	if (s >> name >> price >> type >> temp)
	{
		temp2.assign(temp, 0, 2);
		event_date.day = std::stoi(temp2);
		temp2.assign(temp, 3, 5);
		event_date.month = std::stoi(temp2);

		gift.set_name(name);
		gift.set_price(price);
		gift.set_type(type);
		gift.set_date(event_date);
	}
	else
	{
		std::cerr << "Empty file";
	}

	return s;
}