///*INFO: A deep copy duplicates the object or variable being pointed to
//so that the destination (the object being assigned to) receives it’s own local copy.
//This way, the destination can do whatever it wants to it’s local copy
//and the object that was copied from will not be affected.*/
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
//	////implicit copy constructor for reference
//	//Toy(const Toy& other) : toyName(other.toyName), serialNumber(other.serialNumber)
//	//{
//	//	std::cout << "Copy constructor\n";
//	//}
//
//	////implicit copy assignment operator for reference
//	//Toy& operator=(const Toy& other)
//	//{
//	//	std::cout << "Copy assignment operator\n";
//	//	toyName = other.toyName;
//	//	serialNumber = other.serialNumber;
//	//	return *this;
//	//}
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
//	//explicit copy assignment operator
//	Toy& operator=(const Toy& other)
//	{
//		std::cout << "Copy assignment operator\n";
//		char* localToyName = new char[strlen(other.toyName) + 1]; /*if new char[...] throws due to memory exhaustion
//																	the original object is still in same state as before
//																	and none of the following lines will throw and be exception safe*/
//
//		strcpy(localToyName, other.toyName);
//		delete[] toyName;
//		toyName = localToyName;
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
//			Toy bat(super); //copy constructor, performs deep copy.
//			bat = super; //copy assignment operator
//			bat.display();
//		} //bat goes out of scope
//		super.display(); //Now, this won't crash
//	} //super goes out of scope
//
//	getchar();
//	return 0;
//}