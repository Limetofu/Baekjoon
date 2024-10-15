#include <iostream>
#include <map>

int main(void)
{
	// 숫자의 개수는 10개.
	// 자연수의 크기는 1000보다 작은 10의 배수
	// 그럼 최댓값은 990..

	std::map<int, int> Numbers{}; // 자연수, 빈도

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
		if (often < iter->second) // 갱신
		{
			often = iter->second;
			oftenVal = iter->first;
		}
	}

	std::cout << sum / 10 << std::endl; // 평균
	std::cout << oftenVal << std::endl; // 최빈값

	return 0;
}