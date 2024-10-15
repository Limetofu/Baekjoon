#include <iostream>
#include <vector>

int main(void)
{
	// 1을 한 번, 2를 두 번, 3을 세 번, 
	// 이런 식으로 1 2 2 3 3 3 4 4 4 4 5 .. 이러한 수열을 만들고 
	// 어느 일정한 구간을 주면 그 구간의 합

	// 첫째 줄에 구간의 시작과 끝을 나타내는 정수 A, B(1 ≤ A ≤ B ≤ 1,000)가 주어진다. 
	// 즉, 수열에서 A번째 숫자부터 B번째 숫자까지 합을 구하면 된다.

	int start{}, end{};
	std::cin >> start >> end;

	std::vector<int> Numbers{};

	int count{};

	for (int i = 1; i < 1000 or count < end + 1; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			Numbers.emplace_back(i);
			count++;
		}
	}
	
	int result{};
	for (int i = start; i <= end; ++i)
	{
		result += Numbers[i - 1];
	}

	std::cout << result;

	return 0;
}