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

template <typename T> static void swap(T& a, T& b) {
	T c = a;
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

void pointer_example() {
	int a, b;
	int* a_ptr, * b_ptr;
	a_ptr = &a;
	*a_ptr = 10;
	b_ptr = a_ptr;
	a_ptr = &b;
	*a_ptr = 20;
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "*a_ptr: " << *a_ptr << std::endl;
	std::cout << "*b_ptr: " << *b_ptr << std::endl;
}

void cast_example() {
	int* ptr = new int(69);
	char* ptr2 = reinterpret_cast<char*>(ptr);
	std::cout << *ptr << std::endl;
	std::cout << *ptr2 << std::endl;
	std::cout << ptr << std::endl;
	std::cout << ptr2 << std::endl;
}

void pointer_arithmetics() {
	int arr[4] = { 1,2,3,4 };
	int* a;
	int* pa;
	pa = arr;
	a = &arr[0];
	std::cout << *pa << " " << *a << std::endl;
	std::cout << *(pa + 1) << " " << *(a + 1) << std::endl;
	std::cout << *(pa + 2) << " " << *(a + 2) << std::endl;

	std::cout << pa << " " << a << std::endl;
	std::cout <<  ++pa << " " << a+1 << std::endl;
	std::cout << ++pa << " " << a+2 << std::endl;
}

void pointers_2d() {
	int arr[3][4] = {
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12}
	};

	int* a[3];
	for (int i = 0; i < 3; i++) {
		a[i] = arr[i];
	}

	int** b;
	b = a;

	std::cout << a[2][2] << " " << b[2][2] << std::endl;
	std::cout << **(a+1) << " " << **(b+1) << std::endl;
	std::cout << (*a + 1)[0] << " " << *(*b + 1) << std::endl;
	std::cout << (*(a + 1))[1] << " " << *(*(b + 1)+1) << std::endl;
}

namespace vehicles {

	class Vehicle {
	public:
		virtual void print() = 0;
	};

	class Car: public Vehicle {
	protected:
		static int count;
	public:
		std::string name;
		int price;

		static int tax;

		Car() {
			name = "default";
			price = -1;
			++count;
		}

		Car(std::string name, int price) {
			this->name = name;
			this->price = price;
			++count;
		}

		Car(const Car& c) {
			name = c.name;
			price = c.price;
			++count;
		}
		Car& operator ++() {
			price += 1000;
			return *this;
		}

	    Car operator ++(int) {
			Car new_car(*this);
			price+=1000;
			return new_car;
		}

		/*void operator ++(int) {
			price++;
		}*/

		bool operator == (const Car& other) {
			return other.name == name;
		}

		virtual void print() {
			std::cout << "Car " << name << " price: " << price + tax << std::endl;
		}

		void info() {
			std::cout << "This is a car" << std::endl;
		}

		void asign_tax(int tax) {
			Car::tax = tax;
		}

		friend static void reset_counter();

		~Car() {
			--count;
			std::cout << name << " crushed " << count << " cars remains" << std::endl;
		}
	};

	int Car::count = 0;
	int Car::tax = 0;
	static void reset_counter() {
		Car::count = 0;
	}

	class Bus : public virtual Car {

	public:
		int wheels;

		virtual void print() {
			std::cout << "Bus " << name << " price: " << price + tax << "; wheels: " << wheels << std::endl;
			std::cout << "Total cars: " << count << std::endl;
		}

		void info() {
			std::cout << "This is a bus" << std::endl;
		}
	};

	void inheritane_example() {
		Bus bus;
		bus.wheels = 8;
		bus.print();
	}

	class Electric {
	protected:
		int wattage;

	public:
		Electric() {
			wattage = 100;
		}

		~Electric() {
			std::cout << "Energy exhausted" << std::endl;
		}
	};



	class ElecticVehicle : public virtual Car, protected Electric {
	public:
		ElecticVehicle() {
			wattage = 1000;
			name = "CyberTrack";
			price = 1000000;
		}

		ElecticVehicle(int wattage) : Car("CyberTrack", 1300000) {
			this->wattage = wattage;
		}

		virtual void print() {
			std::cout << "Bus " << name << " price: " << price + tax << "; wattage: " << wattage << std::endl;
			std::cout << "Total cars: " << count << std::endl;
		}
	};

	

	class ElectroBus : protected Bus, private ElecticVehicle {
	public:
		ElectroBus() :
			Car("ElecroBus", 5000000), ElecticVehicle(2000) {
		}

		virtual void print() {
			std::cout << "Name: " << name << " Name from Bus: " << Bus::name << " Name from ElectricVehicle: " << ElecticVehicle::name << std::endl;
			std::cout << "Wattage: " << wattage << std::endl;
			std::cout << "Total vehicles: " << count << std::endl;
		}
	};
}

void class_example() {
	vehicles::Car lada("lada", 3000000);
	{
		vehicles::Car lada("lada", 3000000);
		vehicles::Car granta(lada);
		granta.name = "granta";
		granta.print();
		granta.asign_tax(10000);
	}
	lada.print();
	lada.asign_tax(20000);
	lada.print();
}

void multiple_inheritance() {
	vehicles::ElecticVehicle cyberTruck(2300);
	cyberTruck.print();
}

void diamond_problem() {
	vehicles::ElectroBus bus;
	bus.print();
}

void virtual_methods() {
	using namespace vehicles;
	Bus* bus = new Bus();
	bus->info();
	Car* car = bus;
	car->info();
	car->print();
}

void friend_example() {
	vehicles::Car car1;
	vehicles::Car car2(car1);
	car2.name = "kaliina";
	vehicles::reset_counter();
}

void operator_overload() {
	vehicles::Car car("buhanka", 50000);
	vehicles::Car old = car++;
	old.print();
	car.print();
	++car;
	car.print();
	bool isEqual = car == old;
	std::cout << isEqual << std::endl;

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
	// pointer_example();
	// cast_example();
	// pointer_arithmetics();
	// pointers_2d();
	// class_example();
	// inheritane_example();
	// multiple_inheritance();
	// diamond_problem();
	// virtual_methods();
	// friend_example();
	operator_overload();
} 