#include <iostream>
#include <vector>

int main(void)
{
	// �� �� �Է�
	int A{};
	int B{};
	
	std::cin >> A >> B;

	int ReverseA{};
	int ReverseB{};

	ReverseA = (A / 100) + ((A / 10) % 10 * 10) + (A % 10 * 100);
	ReverseB = (B / 100) + ((B / 10) % 10 * 10) + (B % 10 * 100);

	std::cout << ((ReverseA < ReverseB) ? ReverseB : ReverseA);

	return 0;
}