#include <iostream>
#include <vector>

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	// �� �ڿ��� A�� B�� ���� ��, A = BC�� �����ϴ� �ڿ��� C�� A�� ������ �Ѵ�. 
	// ���� ���, 2�� ����� 1, 2�� �ְ�, 24�� ����� 1, 2, 3, 4, 6, 8, 12, 24�� �ִ�. 
	// �ڿ��� A�� ����� ���� A�� ��� ����� ���� ���̰�, f(A)�� ǥ���Ѵ�. 
	// x���� �۰ų� ���� ��� �ڿ��� y�� f(y)���� ���� ���� g(x)�� ǥ���Ѵ�.

	// �ڿ��� N�� �־����� ��, g(N)�� ���غ���.
	

	// �Է�
	int n;
	std::cin >> n;

	unsigned long long result{};

	// memoziation ����ؾ��ҵ�.
	// �Ųٷΰ� �ƴ϶�, ó������.
	// ~��° ���Ұ�, �� �� ���Դ����� üũ!
	std::vector<int> memo(n + 1, 0);

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j * i <= n; ++j)
		{
			memo[i] += 1;
		}

		//// 1����, i����.
		// for (int j = 1; j <= i; ++j)
		// {


		//	if (i % j == 0) // ������ ������. ���� ������ j�� ����� ����.
		//	{
		//		if (j * j >= i) // ���� �߰�
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