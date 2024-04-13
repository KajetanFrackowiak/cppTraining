#pragma once

#include "iostream"

class Base {
public:
	Base();
	virtual ~Base();
};

class Delivered : public Base {
public:
	Delivered();
	~Delivered();
};

class AnotherClass : public Base {
public:
	AnotherClass();
	~AnotherClass();
};