#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	// 아홉 명의 난쟁이는 모두 자신이 "백설 공주와 일곱 난쟁이"의 주인공이라고 주장했다. 
	// 뛰어난 수학적 직관력을 가지고 있던 백설공주는, 
	// 다행스럽게도 일곱 난쟁이의 키의 합이 100이 됨을 기억해 냈다.

	// 아홉 난쟁이의 키가 주어졌을 때, 백설공주를 도와 일곱 난쟁이를 찾는 프로그램을 작성

	// 입력
	// 아홉 개의 줄에 걸쳐 난쟁이들의 키가 주어진다. 주어지는 키는 100을 넘지 않는 자연수이며, 
	// 아홉 난쟁이의 키는 모두 다르며, 가능한 정답이 여러 가지인 경우에는 아무거나 출력한다.

	// 출력
	// 일곱 난쟁이의 키를 오름차순으로 출력한다.일곱 난쟁이를 찾을 수 없는 경우는 없다.

	std::vector<int> height(9);

	for (int i = 0; i < 9; ++i)
	{
		int n;
		std::cin >> n;
		height[i] = n;
	}

	std::sort(height.begin(), height.end());

	// 숫자 7개를 더했을 때, 100이 될 때까지.
	// 들어가지 않을 숫자 두개를 정해야 함.
	for (int i = 0; i < 9; ++i)
	{
		int result{};

		for (int j = i + 1; j < 9; ++j)
		{
			// 나머지 숫자들을 모조리 더해야 함
			for (int k = 0; k < 9; ++k)
			{
				if (k != i && k != j)
				{
					result += height[k];
				}
			}

			if (result == 100)
			{
				for (int h = 0; h < 9; ++h)
				{
					if (h != i && h != j)
						std::cout << height[h] << std::endl;
				}
				return 0;
			}
			else
			{
				result = 0;
			}
		}
	}

	return 0;
}