#include "Serializer.hpp"

int main()
{
	Data data(12, 40.2, "daje");
	std::cout << data << std::endl;
	uintptr_t pointer = Serializer::serialize(&data);
	std::cout << pointer << std::endl;
	std::cout << *Serializer::deserialize(pointer) << std::endl;
}
