#include <iostream>
#include <vector>

int main(void)
{
	// �� N���� ������ �־����� ��, ���� v�� �� ������ ���ϱ�

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