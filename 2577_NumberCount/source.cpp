#include <iostream>
#include <array>

int main(void)
{
	long int Num{};

	int A{}, B{}, C{};

	std::cin >> A;
	std::cin >> B;
	std::cin >> C;

	Num = A * B * C;

	int Remain{};
	std::array<int, 10> NumCount{};

	NumCount[Num % 10]++; // 첫번째 자리 숫자 넣기

	do {
		Num = Num / 10;

		NumCount[Num % 10]++; // n + 1 번째 숫자
	} 
	while ((Num / 10) != 0); // 나누기 (/) 했을 때 0이 나올때까지.

	for (const int& Count : NumCount)
	{
		std::cout << Count << std::endl;
	}

	return 0;
}