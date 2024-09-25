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

static void swap(int& a, int& b) {
	int c = a;
	a = b;
	b = c;
}

void swap_example() {
	int a, b;
	std::cout << "Enter two numbers:" << std::endl;
	std::cin >> a;
	std::cin >> b;
	swap(a, b);
	std::cout << "a = " << a << " b = " << b << std::endl;
}

void loop() {
	int n;
	std::cout << "Enter a number..." << std::endl;
	std::cin >> n;

	int sum = 0;
	for (int i = 1; i <= n; ++i) {		
		sum += i;
	}
	std::cout << "The sum from 1 to " << n << " is " << sum << std::endl;
}

void array_sum() {
	int a[] = { 1,2,3,4,5 };
	int len = sizeof(a) / sizeof(*a);
	std::cout << "array length: " << len << std::endl;
	int sum = 0;
	for (int i = 0; i < len; ++i) {
		sum += a[i];
	}
	std::cout << "array sum: " << sum << std::endl;
}



void train_example() {	
	int train[3] = { 10,11 };
	train[2] = 12;	
	std::cout << "\nElements in Train are\n";
	std::cout << "Elements 1: " << train[0];
	std::cout << "\nElements 2: " << *(train+1);
	std::cout << "\nElements 3: " << train[2];
}

void linear_search() {
	int size;
	std::cout << "Input array size: " << std::endl;
	std::cin >> size;
	int* arr = (int*)malloc(size*sizeof(int));
	std::cout << "Input array elements: " << std::endl;
	for (int i = 0; i < size; ++i) {
		std::cin >> *(arr + i);
	}
	for (int i = 0; i < size; ++i) {
		std::cout << * (arr + i) << " ";
	}
	std::cout << std::endl;
	std::cout << "Input target element: " << std::endl;
	int target;
	std::cin >> target;
	int pos = -1;
	for (int i = 0; i < size; i++) {
		if (arr[i] == target) {
			pos = i;
			break;
		}
	}
	std::cout << "Target position is: " << pos << std::endl;
}

int binary_search(int* arr, int l, int r, int target) {
	if (l == r) {
		return -1;
	}	
	int m = (r + l) / 2;
	if (arr[m] == target) {
		return m;
	} 
	else if (target > arr[m]) {
		return binary_search(arr, m + 1, r, target);
	}
	else if (target < arr[m]) {
		return binary_search(arr, l, m, target);
	}
	else {
		return -1;
	}
}

void search_example() {
	int a[] = { 1,2,3,5,6 };
	std::cout << "Array to search in: { 1,2,3,5,6 }" << std::endl;
	for (int i = 0; i <= 7; i++) {
		std::cout << "Position of " << i << " is " << binary_search(a, 0, sizeof(a) / sizeof(*a), i) << std::endl;
	}
}


void reverse_string(std::string& str) {
	char tmp;
	int n = str.size() - 1;
	for (int i = 0; i < n / 2; ++i) {
		tmp = str[i];
		str[i] = str[n - i];
		str[n - i] = tmp;
	}
}

void string_example() {
	std::cout << "Input a string: " << std::endl;
	std::string a;
	std::cin >> a;
	reverse_string(a);
	std::cout << a << std::endl;
}

void main() {
	// std::cout << "Hello World!" << std::endl;
	// size_of_types();
	// pointer_size();
	// summator();
	// loop();
	// swap_example();
	// train_example();
	// array_sum();
	// linear_search();
	// search_example();
	// string_example();
} 