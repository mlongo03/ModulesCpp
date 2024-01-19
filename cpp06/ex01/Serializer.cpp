#include "Serializer.hpp"

Serializer::Serializer()
{
}

Serializer::~Serializer()
{
}

Serializer::Serializer(const Serializer &toCopy)
{
	*this = toCopy;
}

Serializer& Serializer::operator=(const Serializer &toCopy)
{
	if (this == &toCopy)
		return (*this);
	return (*this);
}
uintptr_t Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}
