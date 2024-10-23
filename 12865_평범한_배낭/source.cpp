#include <iostream>
#include <vector>

int knapsack(int N, int W, std::vector<int>& weights, std::vector<int>& values)
{
	//  - 1��° ���Ҹ� �˻��ϱ� ������, �� ĭ ũ�� �����α�
	std::vector<std::vector<int>> dp(N + 1, std::vector<int>(W + 1, 0));

	for (int i = 1; i <= N; ++i)
	{
		for (int w = 1; w <= W; ++w)
		{
			// �賶�� ���� �� ���� ��
			if (weights[i - 1] <= w)
			{
				dp[i][w] = std::max(dp[i - 1][w], // ���� ���� ��
					dp[i - 1][w - weights[i - 1]] + values[i - 1]); // �־��� ��
			}

			// ���� ���� ��
			else
			{
				dp[i][w] = dp[i - 1][w]; // ������, �״��
			}
		}
	}

	return dp[N][W];
}


int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	// �� ������ ���� ����� �賶�� ���� �����̴�.

	/// �� �� �ĸ� ������ �θ��� �ް� �Ǵ� �ؼ��� ������ ������ �Ѵ�.
	// ������� ������ �����ϸ� �ִ��� ���� ���� �����̱� ������, 
	// ������ �ٴ� �賶 ���� �ִ��� ��ġ �ְ� �η��� �Ѵ�.

	// �ؼ��� ���࿡ �ʿ��ϴٰ� �����ϴ� N���� ������ �ִ�.
	// �� ������ ���� W�� ��ġ V�� �����µ�, �ش� ������ �賶�� �־ ���� �ؼ��� V��ŭ ��� �� �ִ�.
	// ���� �౺�� �غ� ���� ���� �ؼ��� �ִ� K��ŭ�� ���Ը��� ���� �� �ִ� �賶�� ��� �ٴ� �� �ִ�.
	// �ؼ��� �ִ��� ��ſ� ������ �ϱ� ���� �賶�� ���� �� �ִ� ���ǵ��� ��ġ�� �ִ��� �˷�����.

	// �Է�
	// ù �ٿ� ��ǰ�� �� N(1 �� N �� 100)�� �ؼ��� ��ƿ �� �ִ� ���� K(1 �� K �� 100,000)�� �־�����. 
	// �� ��° �ٺ��� N���� �ٿ� ���� �� ������ ���� W(1 �� W �� 100,000)�� 
	// �ش� ������ ��ġ V(0 �� V �� 1,000)�� �־�����.
	//    �Է����� �־����� ��� ���� �����̴�.

	// ���
	// �� �ٿ� �賶�� ���� �� �ִ� ���ǵ��� ��ġ���� �ִ��� ���

	// 0-1 ���� �˰����ε�



	// �Է�
	int N, max_weight;
	std::cin >> N >> max_weight;

	std::vector<int> weights(N);
	std::vector<int> values(N);
	

	for (int i = 0; i < N; ++i)
	{
		std::cin >> weights[i] >> values[i];
	}

	std::vector<std::vector<int>> dp(N, std::vector<int>(max_weight, 0));

	std::cout << knapsack(N, max_weight, weights, values);


	return 0;
}