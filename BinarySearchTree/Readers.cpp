#include "Readers.h"

void ClearStream(std::istream& stream) {
	stream.clear();
	stream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

std::size_t ReadSizeT()
{
	int result;
	std::cin >> result;

	while (!std::cin.good() || result < 0) {
		std::cout << "Your input is of wrong type, please enter a positive number" << std::endl;
		ClearStream(std::cin);
		std::cin >> result;
	}

	return result;
}
