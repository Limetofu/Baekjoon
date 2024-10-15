#include <iostream>
#include <vector>

int main(void)
{
	// 총 N개의 정수가 주어졌을 때, 최대 최소 구하기

	int N{}, minNum{ 1000000 }, maxNum{-1000000};
	std::cin >> N;

	std::vector<int> numbers(N);

	for (int i = 0; i < N; ++i) {
		std::cin >> numbers[i];
	}

	for (int i = 0; i < N; ++i)
	{
		if (minNum > numbers[i]) minNum = numbers[i];
		if (maxNum < numbers[i]) maxNum = numbers[i];
	}

	std::cout << minNum << " " << maxNum;

	return 0;
}