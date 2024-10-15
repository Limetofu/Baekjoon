#include <iostream>
#include <map>

int main(void)
{
	// ������ ������ 10��.
	// �ڿ����� ũ��� 1000���� ���� 10�� ���
	// �׷� �ִ��� 990..

	std::map<int, int> Numbers{}; // �ڿ���, ��

	int sum{};

	int in{};
	for (int i = 0; i < 10; ++i)
	{
		std::cin >> in;
		if ((in % 10) != 0 and in > 1000) return 1;

		Numbers[in]++;
		sum += in;
	}

	int often{};
	int oftenVal{};
	for (auto iter = Numbers.begin(); iter != Numbers.end(); ++iter)
	{
		if (often < iter->second) // ����
		{
			often = iter->second;
			oftenVal = iter->first;
		}
	}

	std::cout << sum / 10 << std::endl; // ���
	std::cout << oftenVal << std::endl; // �ֺ�

	return 0;
}