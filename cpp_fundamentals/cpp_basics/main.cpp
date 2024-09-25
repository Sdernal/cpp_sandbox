#include <iostream>

void size_of_types() {
	std::cout << "Size of int: " << sizeof(int) << " bytes" << std::endl;
	std::cout << "Size of Double: " << sizeof(double) << " bytes" << std::endl;
}

void pointer_size() {
	double b[] = { 1,2,3 };
	double* a = b;
	std::cout << "Size of b: " << sizeof(b) << " bytes" << std::endl;
	std::cout << "Size of a: " << sizeof(a) << " bytes" << std::endl;
	std::cout << "*a, *(a+1), *(a+2): " << *a << " " << *(a + 1) << " " << *(a + 2) << std::endl;
}

void summator() {
	int a, b;
	std::cout << "Enter two numbers:" << std::endl;
	std::cin >> a;
	std::cin >> b;
	std::cout << a << " + " << b << " = " << a + b << std::endl;
}
void main() {
	std::cout << "Hello World!" << std::endl;
	size_of_types();
	pointer_size();
	summator();
} 