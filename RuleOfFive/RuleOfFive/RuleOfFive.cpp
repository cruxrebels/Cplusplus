///*INFO: Because the presence of a user-defined destructor, copy-constructor, or copy-assignment operator 
//prevents implicit definition of the move constructor and the move assignment operator, 
//any class for which move semantics are desirable, has to declare all five special member functions.*/
//#include <iostream>
//#include <string>
//
//class Toy
//{
//public:
//	//resource managed parameterised constructor
//	Toy(const char* name, int sn)
//	{
//		std::cout << "Resource managed parameterised constructor\n";
//		toyName = new char[strlen(name) + 1];
//		strcpy(toyName, name);
//		serialNumber = sn;
//	}
//
//	//explicit copy constructor
//	Toy(const Toy& other)
//	{
//		std::cout << "Copy constructor\n";
//		serialNumber = other.serialNumber; //because serialNumber is not a ptr we can shallow copy it
//		if (other.toyName) //if other.toyName is non-null
//		{
//			toyName = new char[strlen(other.toyName) + 1];
//			strcpy(toyName, other.toyName);
//		}
//		else
//			toyName = nullptr;
//	}
//
//	//robust copy assignment operator (more exception safe & reused code)
//	Toy& operator=(const Toy& other)
//	{
//		std::cout << "Copy assignment operator\n";
//		Toy temp(other); //reuse copy constructor
//		*this = std::move(temp); //reuse move assignment 
//		return *this;
//	}
//
//	//move constructor
//	Toy(Toy&& other) : toyName(other.toyName), serialNumber(other.serialNumber)
//	{
//		std::cout << "Move constructor\n";
//		other.toyName = nullptr;
//	}
//
//	//move assignment operator
//	Toy& operator=(Toy&& other)
//	{
//		std::cout << "Move assignment operator\n";
//		delete[] toyName;
//		serialNumber = other.serialNumber;
//		toyName = other.toyName;
//		other.toyName = nullptr;
//		return *this;
//	}
//
//	//resource managed destructor
//	~Toy()
//	{
//		std::cout << "Resource managed destructor of " << this << "\n";
//		delete[] toyName;
//	}
//
//	void display()
//	{
//		std::cout << "toyName: " << toyName << " Address: " << &toyName << "\n";
//		std::cout << "serialNumber: " << serialNumber << " Address: " << &serialNumber << "\n";
//	}
//private:
//	char* toyName;
//	int serialNumber;
//};
//
//int main()
//{
//	{
//		Toy super("Superman", 1);
//		{
//			Toy bat(super); //copy constructor
//			bat = super; //copy assignment operator
//			bat.display();
//		} //bat goes out of scope
//		super.display(); //Now, this won't crash
//	} //super goes out of scope
//
//	{
//		Toy batman("Batman", 0);
//		batman.display();
//		Toy flash(std::move(batman)); //move 
//		flash.display();
//	} //flash goes out of scope
//
//	getchar();
//	return 0;
//}