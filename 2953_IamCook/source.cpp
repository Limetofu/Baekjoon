#include <iostream>
#include <array>
#include <map>

int main(void)
{
	// �ټ� ������
	// ���� �ٸ� ��� ������ ������ ��
	// ������ 1 ~ 5��

	// �ٸ� ����� ���� ������ ��
	// ���� ���� ���� ���� ����� ���

	// ���� �� ������ �־����� ��, ����ڿ� ���� ���� ���ϱ�

	//    �Է�
	// �� �ټ� �� �ٿ� �� �����ڰ� ���� �� ���� �� ������ �������� ����
	// ù��°���� �ټ���° ���ʴ��


	std::array<int, 4> score{};
	std::map<int, int> cooks{}; // Num, Score
	
	for (int i = 0; i < 5; ++i)
	{
		std::cin >> score[0] >> score[1] >> score[2] >> score[3];
		cooks[i] = score[0] + score[1] + score[2] + score[3];
	}

	int MaxScore{};
	int FirstCook{ 1 };
	for (const auto& c : cooks)
	{
		if (MaxScore < c.second)
		{
			MaxScore = c.second;
			FirstCook = c.first + 1;
		}
	}
	
	std::cout << FirstCook << " " << MaxScore;

	return 0;
}