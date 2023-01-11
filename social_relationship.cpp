#include "social_relationship.h"
#include <queue>

bool SocialRelationship::Person::isEmpty()
{
	return _name.empty();
}

std::string const& SocialRelationship::Person::getName() const
{
	return _name;
}

int const& SocialRelationship::Person::getId() const
{
	return _id;
}

SocialRelationship::SocialRelationship()
{
	for (size_t i = 0u; i < SIZE; ++i)
	{
		for (size_t j = 0u; j < SIZE; ++j)
		{
			matrix[i][j] = 0;
		}
	}
}


bool SocialRelationship::arrFiends(Person& const p1, Person const& p2)
{
	return matrix[p1.getId()][p2.getId()] == 1;
}


SocialRelationship::Person const* SocialRelationship::findByName(std::string const&& name)
{
	for (size_t i = 0u; i < array.size(); ++i)
	{
		if (!array[i].getName().compare(name))
			return &array[i];
	}
	return nullptr;
}


auto SocialRelationship::addPerson(std::string const&& name) -> bool
{
	if (findByName(std::forward<std::string const&&>(name)) || array.size() > 30)
		return false;

	array.push_back(Person(name, array.size()));
	return true;
}

auto SocialRelationship::delPerson(std::string const&& name) -> bool
{
	auto found = findByName(std::forward<std::string const&&>(name));

	if (found == nullptr)
		return false;

	for (size_t i = 0; i < array.size(); ++i)
	{
		matrix[i][found->getId()];
		matrix[found->getId()][i];
	}

	array[found->getId()] = Person("", -1);
	return true;
}

auto SocialRelationship::addFriendship(std::string const&& name1, std::string const&& name2) -> bool
{
	auto found1 = findByName(std::forward<std::string const&&>(name1));
	auto found2 = findByName(std::forward<std::string const&&>(name2));

	if (found1 && found2)
	{
		matrix[found1->getId()][found2->getId()] = 1;
		matrix[found2->getId()][found1->getId()] = 1;
		return true;
	}
	return false;
}

auto SocialRelationship::showPairsOfRelationships() -> void
{
	int points[SIZE];
	for (size_t i = 0u; i < SIZE; ++i)
		points[i] = -1;

	points[0] = 0;
	std::queue<int> que;
	que.push(0);

	while (!que.empty())
	{
		int currPoint = que.front();
		que.pop();

		for (size_t i = 0u; i < array.size(); ++i)
		{
			if (arrFiends(array[i], array[currPoint]) && points[i] == -1)
			{
				points[i] = points[currPoint] + 1;
				que.push(i);
			}
		}

	}

	for (size_t i = 0u; i < array.size(); ++i)
	{
		bool check = false;


		for (size_t j = i + 1; j < array.size(); ++j)
		{
			if (points[i] != -1 && points[j] != -1 && abs(points[j] - points[i]) < 4)
			{
				std::cout << array[i].getName() << " friends with "
					<< array[j].getName()<<std::endl;
			}
		}
	}



}