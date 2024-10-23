#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	// 양수 A가 N의 진짜 약수가 되려면, N이 A의 배수이고, A가 1과 N이 아니어야 한다. 
	// 어떤 수 N의 진짜 약수가 모두 주어질 때, N을 구하는 프로그램을 작성하시오.

	// 첫째 줄에 N의 진짜 약수의 개수가 주어진다.
	// 이 개수는 50보다 작거나 같은 자연수이다.
	// 둘째 줄에는 N의 진짜 약수가 주어진다. 
	// 1, 000, 000보다 작거나 같고, 2보다 크거나 같은 자연수이고, 중복되지 않는다.


	// 입력
	int NumCount;
	std::cin >> NumCount;

	std::vector<int> Measures(NumCount);
	for (int i = 0; i < NumCount; ++i)
	{
		int n;
		std::cin >> n;
		Measures[i] = n;
	}

	std::sort(Measures.begin(), Measures.end());

	// 약수의 개수가 홀수인 경우 -> 제곱수. 
	// 그런데 1, N은 포함 안되니까
	if (NumCount % 2 != 0) 
	{
		std::cout << Measures[NumCount / 2] * Measures[NumCount / 2];
	}
	else
	{
		std::cout << Measures.front() * Measures.back();
	}

	return 0;
}