#include "social_relationship.h"
#include <iostream>

int main()
{
	SocialRelationship sr;
	sr.addPerson("Oleg");
	sr.addPerson("Nick");
	sr.addPerson("Nasty");
	sr.addPerson("Ivan");
	sr.addPerson("Jen");

	sr.addFriendship("Oleg", "Nick");
	sr.addFriendship("Nick", "Nasty");
	sr.addFriendship("Nasty", "Ivan");
	sr.addFriendship("Ivan", "Jen");

	sr.showPairsOfRelationships();
	
	return 0;
}