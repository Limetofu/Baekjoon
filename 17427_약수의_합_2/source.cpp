#include <iostream>
#include <vector>

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	// 두 자연수 A와 B가 있을 때, A = BC를 만족하는 자연수 C를 A의 약수라고 한다. 
	// 예를 들어, 2의 약수는 1, 2가 있고, 24의 약수는 1, 2, 3, 4, 6, 8, 12, 24가 있다. 
	// 자연수 A의 약수의 합은 A의 모든 약수를 더한 값이고, f(A)로 표현한다. 
	// x보다 작거나 같은 모든 자연수 y의 f(y)값을 더한 값은 g(x)로 표현한다.

	// 자연수 N이 주어졌을 때, g(N)을 구해보자.
	

	// 입력
	int n;
	std::cin >> n;

	unsigned long long result{};

	// memoziation 사용해야할듯.
	// 거꾸로가 아니라, 처음부터.
	// ~번째 원소가, 몇 번 나왔는지만 체크!
	std::vector<int> memo(n + 1, 0);

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j * i <= n; ++j)
		{
			memo[i] += 1;
		}

		//// 1부터, i까지.
		// for (int j = 1; j <= i; ++j)
		// {


		//	if (i % j == 0) // 나누어 떨어짐. 따라서 지금의 j는 약수가 맞음.
		//	{
		//		if (j * j >= i) // 조건 추가
		//		{
		//			break;
		//		}
		//		result += j + (i / j);
		//	}
		//}
	}

	for (int i = 1; i <= n; ++i)
	{
		result += memo[i] * i;
	}

	std::cout << result;


	return 0;
}