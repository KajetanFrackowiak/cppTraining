#include "Casting.h"
#include "iostream"

Base::Base() {}
Base::~Base() {}
Delivered::Delivered() {}
Delivered::~Delivered() {}
AnotherClass::AnotherClass() {}
AnotherClass::~AnotherClass() {}
int main() {
	int a = 5;
	double value = (double)a;
		
	double s = static_cast<double>(a) + 5.3;

	Delivered* delivered = new Delivered();
	Base* base = delivered;
	
	Delivered* ac = dynamic_cast<Delivered*>(base);
}