#include "Serializer.hpp"

int main()
{
    Data d;

	d.id = 25;
	d.name = "Vera";
	d.value = 13.75;

    Data* originalPtr = &d;
    uintptr_t raw = Serializer::serialize(originalPtr);
    Data* recoveredPtr = Serializer::deserialize(raw);

    std::cout << "Original pointer: " << originalPtr << "\n";
    std::cout << "Serialized raw value: " << raw << "\n";
    std::cout << "Recovered pointer: " << recoveredPtr << "\n";

    if (originalPtr == recoveredPtr)
    {
        std::cout << "SUCCESS: The recovered pointer is the same as the original pointer.\n";
    }
    else
    {
        std::cout << "FAILURE: The pointers do not match.\n";
    }

    // Opcional: mostrar datos para verificar que se accede bien
    std::cout << "Recovered Data: index = " << recoveredPtr->id
              << ", name = " << recoveredPtr->name
              << ", value = " << recoveredPtr->value << "\n";

    return 0;
}