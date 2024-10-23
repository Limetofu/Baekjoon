#include <iostream>
#include <vector>

int main()
{
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	// 2 x N 크기의 사각형을, 
	// 2x1, 1x2 크기의 사각형으로 채우는 경우의 수를 10007으로 나누고 출력.
	// DP Algorithm

	int N;
	std::cin >> N;

    std::vector<int> dp(N + 1);

    dp[1] = 1;
    if (N >= 2) {
        dp[2] = 2;
    }

    for (int i = 3; i <= N; ++i) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
    }

    std::cout << dp[N];

	return 0;
}