#include <iostream>

void PrintSum(int a, int b, int c) {
	std::cout << a << " + " << b <<  " + " << c <<  " = " << (a + b + c) << std::endl;
}
int main() {
	int preValue = 0;
	PrintSum(++preValue, ++preValue, ++preValue);	
	std::cout << " PreValue: " << preValue << std::endl;
	
	int postValue = 0;
	PrintSum(postValue++, postValue++, postValue++);
	std::cout << "PostValue: " << postValue << std::endl;

	return 0;
}