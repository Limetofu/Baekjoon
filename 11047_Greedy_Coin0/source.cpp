#include <iostream>
#include <vector>

//ù° �ٿ� N�� K�� �־�����. (1 �� N �� 10, 1 �� K �� 100, 000, 000)
//
//��° �ٺ��� N���� �ٿ� ������ ��ġ Ai�� ������������ �־�����. (1 �� Ai �� 1, 000, 000, A1 = 1, i �� 2�� ��쿡 Ai�� Ai - 1�� ���)



int main(void)
{
	short Ncount{}; // N ���� ���� ��ִ���
	int K{ 0 }; // ��ǥ ��

	int ResultCount{}; // Result ���� ����
	int Money{}; // �������� �ִ� ��

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


	// ��ǥġ �� : 4800
	// N.back : 10000
	// �׷���, 

	while (true)
	{
		if ((K - Money) < N.back()) // 4800 - 4000 = 800 < 1000 �Ѿ��!
		{
			// ������ �ʹ� ŭ
			// �������� �Ѿ�� ��
			N.pop_back();
		}
		else
		{
			// ��ǥġ ���� �� ŭ! 
			// N.back()��ŭ ��ǥġ ��(Money) ���ϱ� 
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