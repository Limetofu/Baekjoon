#include <iostream>

int main(void)
{
	int PeopleCount{};
	int MaxCount{};

	for (int i = 0; i < 10; ++i)
	{
		int out, in;
		std::cin >> out >> in;

		PeopleCount -= out;
		PeopleCount += in;

		if (PeopleCount > MaxCount)
		{
			MaxCount = PeopleCount;
		}
	}

	std::cout << MaxCount;

	return 0;
}