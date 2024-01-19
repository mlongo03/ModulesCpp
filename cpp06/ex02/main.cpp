#include "Base.hpp"

int main()
{
	Base* toGuess = generate();
	identify(toGuess);
	identify(*toGuess);
	delete toGuess;
}
