#include <iostream>
#include <array>
#include <map>

int main(void)
{
	// 다섯 참가자
	// 서로 다른 사람 음식을 점수로 평가
	// 점수는 1 ~ 5점

	// 다른 사람이 평가한 점수의 합
	// 가장 많은 점수 얻은 사람이 우승

	// 얻은 평가 점수가 주어졌을 때, 우승자와 그의 점수 구하기

	//    입력
	// 총 다섯 개 줄에 각 참가자가 얻은 네 개의 평가 점수가 공백으로 구분
	// 첫번째부터 다섯번째 차례대로


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