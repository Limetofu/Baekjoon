#include <iostream>
#include <vector>

//첫째 줄에 N과 K가 주어진다. (1 ≤ N ≤ 10, 1 ≤ K ≤ 100, 000, 000)
//
//둘째 줄부터 N개의 줄에 동전의 가치 Ai가 오름차순으로 주어진다. (1 ≤ Ai ≤ 1, 000, 000, A1 = 1, i ≥ 2인 경우에 Ai는 Ai - 1의 배수)



int main(void)
{
	short Ncount{}; // N 동전 종류 몇개있는지
	int K{ 0 }; // 목표 돈

	int ResultCount{}; // Result 코인 개수
	int Money{}; // 더해지고 있는 돈

	std::cin >> Ncount >> K;
	
	if (1 > Ncount or Ncount > 10) return 1;
	if (1 > K or K > 100000000) return 1;

	std::vector<int> N;
	
	for (int i = 0; i < Ncount; ++i)
	{
		int temp{};
		std::cin >> temp;

		if (1 > temp or temp > 100000000) return 1;

		N.emplace_back(temp);
	}


	// 목표치 돈 : 4800
	// N.back : 10000
	// 그러면, 

	while (true)
	{
		if ((K - Money) < N.back()) // 4800 - 4000 = 800 < 1000 넘어가기!
		{
			// 동전이 너무 큼
			// 다음으로 넘어가야 함
			N.pop_back();
		}
		else
		{
			// 목표치 돈이 더 큼! 
			// N.back()만큼 목표치 돈(Money) 더하기 
			Money += N.back();
			ResultCount++;

			if (Money == K)
			{
				break;
			}
		}
	}
	

	std::cout << ResultCount;

	return 0;
}