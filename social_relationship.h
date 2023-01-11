#pragma once

#include <vector>
#include <string>
#include <iostream>

#define SIZE 30

class SocialRelationship
{
private:
	struct Person
	{

		Person(std::string const& name, int id) :
			_name(name), _id(id)
		{}

		Person() = default;

		auto isEmpty() -> bool;

		auto getName() const -> std::string const&;

		auto getId() const -> int const&;

	private:
		std::string _name;
		int         _id;
	};


	bool arrFiends(Person& const p1, Person const& p2);

	Person const* findByName(std::string const&& name);
	
	int matrix[SIZE][SIZE];
	std::vector<Person> array;

public:
	SocialRelationship();

	auto addPerson(std::string const&& name) -> bool;

	auto delPerson(std::string const&& name) -> bool;

	auto addFriendship(std::string const&& name1, std::string const&& name2) -> bool;

	auto showPairsOfRelationships() -> void;


	~SocialRelationship() = default;
};