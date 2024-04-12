#include <iostream>

// Function to get a reference to a static integer variable
int& GetValue() {
    static int value = 10; // Static local variable initialized to 10
    return value; // Returns a reference to the static variable
}

// Function to print a string (passed by lvalue reference)
void PrintName(std::string& name) {
    std::cout << "[lvalue] with assignment to fullName using firstName and LastName: " << name << std::endl;
}

// Function to print a string (passed by const lvalue reference)
void PrintNameV2(const std::string& name) {
    std::cout << "[lvalue] with assignment to firstName and lastName: " << name << std::endl;
}

// Function to print a string (passed by rvalue reference)
void PrintNameV3(std::string&& name) {
    std::cout << "[rvalue] with assignment to firstName and lastName: " << name << std::endl;
}

int main() {
    // Example of using GetValue() function to retrieve and modify a static variable
    int i = GetValue(); // Retrieve the value from GetValue() and assign it to i
    GetValue() = 5; // Modify the value returned by GetValue() to 5

    // Example of string concatenation and variable assignment
    std::string firstName = "Kajetan";
    std::string lastName = "Frackowiak";
    std::string fullName = firstName + lastName; // Concatenate firstName and lastName to form fullName

    // Function calls to demonstrate different parameter passing modes
    PrintName(fullName); // Pass fullName (lvalue) to PrintName function
    // PrintName(firstName + lastName);  // This line won't compile because it attempts to pass an rvalue
    PrintNameV2(firstName + lastName); // Pass the result of firstName + lastName (rvalue) to PrintNameV2
    PrintNameV3(firstName + lastName); // Pass the result of firstName + lastName (rvalue) to PrintNameV3

    return 0;
}
