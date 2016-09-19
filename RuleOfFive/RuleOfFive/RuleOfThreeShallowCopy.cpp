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
//	//implicit copy constructor
//	Toy(const Toy& other) : toyName(other.toyName), serialNumber(other.serialNumber)
//	{
//		std::cout << "Copy constructor\n";
//	}
//
//	//implicit copy assignment operator
//	Toy& operator=(const Toy& other)
//	{
//		std::cout << "Copy assignment operator\n";
//		toyName = other.toyName;
//		serialNumber = other.serialNumber;
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
//	//std::string toyName;
//	char* toyName;
//	int serialNumber;
//};
//
//int main()
//{
//	{
//		Toy super("Superman", 1);
//		{
//			Toy bat(super); /*copy constructor, performs memberwise copy, but in case of class managed resource
//							copying the toyName member merely copies a pointer,
//							not the character array it points to.*/
//			bat = super; //copy assignment operator
//			bat.display();
//		} //bat goes out of scope
//		super.display(); //THIS WILL CRASH: because of dangling ptr since bat is destroyed
//	} //super goes out of scope
//	
//	getchar();
//	return 0;
//}