#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	// ��� A�� N�� ��¥ ����� �Ƿ���, N�� A�� ����̰�, A�� 1�� N�� �ƴϾ�� �Ѵ�. 
	// � �� N�� ��¥ ����� ��� �־��� ��, N�� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

	// ù° �ٿ� N�� ��¥ ����� ������ �־�����.
	// �� ������ 50���� �۰ų� ���� �ڿ����̴�.
	// ��° �ٿ��� N�� ��¥ ����� �־�����. 
	// 1, 000, 000���� �۰ų� ����, 2���� ũ�ų� ���� �ڿ����̰�, �ߺ����� �ʴ´�.


	// �Է�
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

	// ����� ������ Ȧ���� ��� -> ������. 
	// �׷��� 1, N�� ���� �ȵǴϱ�
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