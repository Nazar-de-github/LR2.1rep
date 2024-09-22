#pragma once
#include <iostream>
#include <iomanip>
#include <string>


struct Date {
	int day;
	int month;
};

class ForEvent {
protected:
	std::string type;
	Date date;

public:
	ForEvent() : type("unknown"), date{ 0, 0 } {}
	ForEvent(std::string t, Date d) : type(t), date(d) {}

	virtual void set_type(std::string t) = 0;
	virtual void set_date(Date d) = 0;

	virtual std::string get_type() const = 0;
	virtual Date get_date() const = 0;
};

class Item {
protected:
	std::string name;
	float price;

public:
	Item() : name("unknown"), price(0.f) {}
	Item(std::string n, float p) : name(n), price(p) {}

	virtual void set_name(std::string n) = 0;
	virtual void set_price(float p) = 0;

	virtual std::string get_name() const = 0;
	virtual float get_price() const = 0;
};

class Human {
protected:
	std::string name;
	float price;

public:
	Human() : name("unknown"), price(0.f) {}
	Human(std::string n, float p) : name(n), price(p) {}

	virtual void set_name(std::string n) = 0;
	virtual void set_price(float p) = 0;

	virtual std::string get_name() const = 0;
	virtual float get_price() const = 0;
};