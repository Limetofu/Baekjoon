#include <iostream>

int main(void)
{
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	// 2와 5로 나누어 떨어지지 않는 정수 n(1 ≤ n ≤ 10000)가 주어졌을 때, 
	// 각 자릿수가 모두 1로만 이루어진 n의 배수를 찾는 프로그램을 작성하시오.

	int n;
	
	while (true) {
		std::cin >> n;
		if (std::cin.eof()) break; // EOF 조건식으로 변경

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
			num %= n; // 오차만 남겨두고 계산
			count++;
		}
	}


	return 0;
}