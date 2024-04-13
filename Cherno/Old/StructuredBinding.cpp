#include "StructuredBinging.h"
#include <iostream>
#include <string>
#include <tuple>

std::tuple<std::string, int> CreatePerson() {
	return { "Kajetan", 22 };
}

int main() {
	//Using std::get
	auto person = CreatePerson();
	std::string& name_get = std::get<0>(person);
	int age_get = std::get<1>(person);
	std::cout << name_get << " " << age_get << std::endl;

	// Using std::tie (better way)
	std::string name_tie;
	int age_tie;
	std::tie(name_tie, age_tie) = CreatePerson();
	std::cout << name_tie << " " << age_tie << std::endl;

	// Using structured binding (the best way)
	auto [name_structured, age_structured] = CreatePerson();
	std::cout << name_structured << " " << age_structured << std::endl;


	// Array with structured binding
	int myArray[2] = { 42, 34 };
	auto [first, second] = myArray;
	std::cout << "Array made with structured binding: " << first << " " << second << std::endl;
}