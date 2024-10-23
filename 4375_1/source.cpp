#include <iostream>

int main(void)
{
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	// 2�� 5�� ������ �������� �ʴ� ���� n(1 �� n �� 10000)�� �־����� ��, 
	// �� �ڸ����� ��� 1�θ� �̷���� n�� ����� ã�� ���α׷��� �ۼ��Ͻÿ�.

	int n;
	
	while (true) {
		std::cin >> n;
		if (std::cin.eof()) break; // EOF ���ǽ����� ����

		int num{ 1 };
		int count{1};

		while (true)
		{
			if (num % n == 0)
			{
				std::cout << count << std::endl;
				break;
			}

			num = num * 10 + 1;
			num %= n; // ������ ���ܵΰ� ���
			count++;
		}
	}


	return 0;
}