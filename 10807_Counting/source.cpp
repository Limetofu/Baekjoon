#include <iostream>
#include <vector>

int main(void)
{
	// 총 N개의 정수가 주어졌을 때, 정수 v가 몇 개인지 구하기

	int N, v, count = 0;

	std::cin >> N;

	std::vector<int> numbers(N);
	for (int i = 0; i < N; ++i) {
		std::cin >> numbers[i];
	}

	std::cin >> v;

	for (const int& n : numbers)
	{
		if (n == v) count++;
	}

	std::cout << count << std::endl;

	return 0;
}