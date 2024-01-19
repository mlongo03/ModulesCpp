#include "Base.hpp"
#include <iostream>

Base::~Base()
{
}

A::A()
{
	std::cout << "A constructor called" << std::endl;
}

A::~A()
{
	std::cout << "A destructor called" << std::endl;
}

B::B()
{
	std::cout << "B constructor called" << std::endl;
}

B::~B()
{
	std::cout << "B destructor called" << std::endl;
}

C::C()
{
	std::cout << "C constructor called" << std::endl;
}

C::~C()
{
	std::cout << "C destructor called" << std::endl;
}


Base * generate(void)
{
	std::srand(static_cast<unsigned>(std::time(nullptr)));
	int randomValue = std::rand() % 3;
	switch (randomValue)
	{
		case 0:
			return new A();
			break;
		case 1:
			return new B();
			break;
		case 2:
			return new C();
			break;
	}
	return 0;
}

void identify(Base* p)
{
	if (dynamic_cast<const A*>(p)) {
		std::cout << "is type A" << std::endl;
	} else if (dynamic_cast<const B*>(p)) {
		std::cout << "is type B" << std::endl;
	} else if (dynamic_cast<const C*>(p)) {
		std::cout << "is type C" << std::endl;
	}
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<const A&>(p);
		std::cout << "is type A" << std::endl;
	}
	catch(const std::bad_cast& e)
	{
		try
		{
			(void)dynamic_cast<const B&>(p);
			std::cout << "is type B" << std::endl;
		}
		catch(const std::bad_cast& e)
		{
			std::cout << "is type C" << std::endl;
		}
	}

}
