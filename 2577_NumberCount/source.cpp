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

	NumCount[Num % 10]++; // ù��° �ڸ� ���� �ֱ�

	do {
		Num = Num / 10;

		NumCount[Num % 10]++; // n + 1 ��° ����
	} 
	while ((Num / 10) != 0); // ������ (/) ���� �� 0�� ���ö�����.

	for (const int& Count : NumCount)
	{
		std::cout << Count << std::endl;
	}

	return 0;
}