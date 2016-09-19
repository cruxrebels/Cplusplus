/*RULE: Classes that declare custom destructors, copy/move constructors or copy/move assignment operators 
should deal exclusively with ownership. Other classes should not declare custom destructors, 
copy/move constructors or copy/move assignment operators.*/
/*INFO: When a base class is intended for polymorphic use, its destructor 
may have to be declared public and virtual. This blocks implicit moves (and deprecates implicit copies), 
and so the special member functions have to be declared as defaulted.
However, this can be avoided using std::shared_ptr. shared pointers invoke 
the derived class destructor even after casting to std::shared_ptr<Base>.*/
#include <iostream>
#include <string>

class Toy
{
public:
	virtual ~Toy()
	{
		std::cout << "Resource managed destructor of Toy " << this << "\n";
	}
};

class Kid : public Toy
{
private:
	char* toyName;

public:
	Kid(const char* name)
	{
		std::cout << "Resource managed parameterised constructor\n";
		toyName = new char[strlen(name) + 1];
		strcpy(toyName, name);
	}

	virtual void display()
	{
		std::cout << "toyName: " << toyName << " Address: " << &toyName << "\n";
	}

	//move constructor
	/*Kid(Kid&& other) : toyName(other.toyName)
	{
		std::cout << "Move constructor\n";
		other.toyName = nullptr;
	}*/

	virtual ~Kid()
	{
		std::cout << "Resource managed destructor of Kid " << this << "\n";
		delete[] toyName;
	}
};

int main()
{
	Kid *pKid = new Kid("Superman");
	pKid->display();
	Toy *pToy = pKid;
	/*Kid newKid(std::move(*pKid));
	newKid.display();*/
	delete pToy;

	getchar();
	return 0;
}