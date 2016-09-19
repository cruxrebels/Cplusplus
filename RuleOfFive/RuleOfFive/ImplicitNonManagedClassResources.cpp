///*
//Concepts order: ImplicitNonManagedClassResources -> RuleOfThreeShallowCopy -> RuleOfThreeDeepCopy -> RuleOfFive
//*/
//#include <iostream>
//#include <string>
//
//class Toy
//{
//public:
//	//parameterised constructor
//	Toy(const std::string& toyName, int serialNumber) : toyName(toyName), serialNumber(serialNumber)
//	{
//		std::cout << "Parameterised constructor\n";
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
//	//implicit destructor
//	~Toy()
//	{
//		std::cout << "Destructor of " << this << "\n";
//	}
//
//	void display()
//	{
//		std::cout << "toyName: " << toyName << " Address: " << &toyName << "\n";
//		std::cout << "serialNumber: " << serialNumber << " Address: " << &serialNumber << "\n";
//	}
//private:
//	std::string toyName;
//	int serialNumber;
//};
//
//int main()
//{
//	{
//		Toy super("Superman", 1);
//		Toy bat(super); //copy constructor, performs memberwise copy, which is what we want here
//		bat = super; //copy assignment operator
//		super.display();
//		bat.display();
//	} 
//
//	getchar();
//	return 0;
//}