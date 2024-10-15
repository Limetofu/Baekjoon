#include <iostream>
#include <vector>

int main(void)
{
	// 1�� �� ��, 2�� �� ��, 3�� �� ��, 
	// �̷� ������ 1 2 2 3 3 3 4 4 4 4 5 .. �̷��� ������ ����� 
	// ��� ������ ������ �ָ� �� ������ ��

	// ù° �ٿ� ������ ���۰� ���� ��Ÿ���� ���� A, B(1 �� A �� B �� 1,000)�� �־�����. 
	// ��, �������� A��° ���ں��� B��° ���ڱ��� ���� ���ϸ� �ȴ�.

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