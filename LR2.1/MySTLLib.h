#pragma once
#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

template<typename Type_t, typename Gift_t>
class MyCont {
private:
	std::multimap<Type_t, Gift_t> map_of_gift;
	std::vector<Gift_t> vector_of_gift;
public:
	void Add(Gift_t gift);

	bool Delete(std::string name);

	void show(Type_t type);
	void show_vector();
	void show_map();

	bool empty() { return map_of_gift.empty(); }

	float sum_of_all_price();
	float sum_of_all_price(Type_t type);

	auto find(const std::string& name);

	void clear() { map_of_gift.clear(); }

	void Sort(bool(*pred)(const Gift_t&, const Gift_t&))
	{
		vector_of_gift.clear();
		for (const auto& iter : map_of_gift)
		{
			vector_of_gift.push_back(iter.second);
		}

		std::sort(vector_of_gift.begin(), vector_of_gift.end(), pred);
	}

	friend std::ostream& operator<<(std::ostream& s, const MyCont<Type_t, Gift_t>& obj)
	{
		if (obj.map_of_gift.empty())
		{
			std::cout << "Container is empty";
			return s;
		}
		
		for (auto iter : obj.map_of_gift)
		{
			s << iter.second << "\n";
		}
		return s;
	}

	friend std::ifstream& operator>>(std::ifstream& file, MyCont<Type_t, Gift_t>& obj)
	{
		Gift_t temp;
		while (file >> temp)
			obj.Add(temp);

		return file;
	}
};

template<typename Type_t, typename Gift_t>
void MyCont<Type_t, Gift_t>::Add(Gift_t gift)
{
	map_of_gift.emplace(gift.get_type(), gift);
}

template<typename Type_t, typename Gift_t>
bool MyCont<Type_t, Gift_t>::Delete(std::string name)
{
	auto iter = find(name);

	if (iter != map_of_gift.end())
	{
		map_of_gift.erase(iter);
		return true;
	}
	else
	{
		return false;
	}
}

template<typename Type_t, typename Gift_t>
void MyCont<Type_t, Gift_t>::show(Type_t type)
{
	if (map_of_gift.empty())
	{
		std::cout << "Container is empty";
		return;
	}


	for (auto iter = map_of_gift.cbegin(); iter != map_of_gift.cend(); ++iter)
	{
		if (iter->second.get_type() == type)
			std::cout << iter->second << std::endl;
	}
}

template<typename Type_t, typename Gift_t>
void MyCont<Type_t, Gift_t>::show_vector()
{
	if (vector_of_gift.empty())
	{
		std::cout << "Container is empty";
		return;
	}

	for (auto iter = vector_of_gift.cbegin(); iter != vector_of_gift.cend(); ++iter)
	{
		std::cout << *iter << std::endl;
	}
}

template<typename Type_t, typename Gift_t>
void MyCont<Type_t, Gift_t>::show_map()
{
	if (map_of_gift.empty())
	{
		std::cout << "Container is empty";
		return;
	}

	for (auto iter = map_of_gift.cbegin(); iter != map_of_gift.cend(); ++iter)
	{
		std::cout << iter->second << std::endl;
	}
}

template<typename Type_t, typename Gift_t>
float MyCont<Type_t, Gift_t>::sum_of_all_price()
{
	float sum = 0.f;
	for (auto& iter : map_of_gift)
	{
		sum += iter.second.get_price();
	}
	return sum;
}

template<typename Type_t, typename Gift_t>
float MyCont<Type_t, Gift_t>::sum_of_all_price(Type_t type)
{
	float sum = 0.f;
	for (auto& iter : map_of_gift)
	{
		if(iter.second.get_type() == type)
			sum += iter.second.get_price();
	}
	return sum;
}

template<typename Type_t, typename Gift_t>
auto MyCont<Type_t, Gift_t>::find(const std::string& name)
{
	auto iter = map_of_gift.begin();
	while (iter != map_of_gift.end())
	{
		if (iter->second.get_name() == name)
		{
			return iter;
		}
		++iter;
	}
	return map_of_gift.end();
}