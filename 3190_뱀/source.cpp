#include <iostream>
#include <vector>
#include <deque>
#include <array>
#include <map>

int RotateSnake(int current, char rot)
{
	switch (rot)
	{
	case 'L':
		if (current <= 0)
			return 3;
		else
			return current - 1;
		break;

	case 'R':
		if (current >= 3)
			return 0;
		else
			return current + 1;
		break;
	}
}

bool CanMoveSnake(int dir, int size)
{

}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);


	//'Dummy' 라는 도스게임이 있다.이 게임에는 뱀이 나와서 기어다니는데, 
	// 사과를 먹으면 뱀 길이가 늘어난다.
	// 뱀이 이리저리 기어다니다가 벽 또는 자기자신의 몸과 부딪히면 게임이 끝난다.

	//	게임은 NxN 정사각 보드위에서 진행되고, 몇몇 칸에는 사과가 놓여져 있다.
	// 보드의 상하좌우 끝에 벽이 있다.
	// 게임이 시작할때 뱀은 맨위 맨좌측에 위치하고 뱀의 길이는 1 이다.뱀은 처음에 오른쪽을 향한다.

	//	뱀은 매 초마다 이동을 하는데 다음과 같은 규칙을 따른다.

	//	먼저 뱀은 몸길이를 늘려 머리를 다음칸에 위치시킨다.
	//	만약 벽이나 자기자신의 몸과 부딪히면 게임이 끝난다.
	//	만약 이동한 칸에 사과가 있다면, 그 칸에 있던 사과가 없어지고 꼬리는 움직이지 않는다.
	//	만약 이동한 칸에 사과가 없다면, 몸길이를 줄여서 꼬리가 위치한 칸을 비워준다.
	// 즉, 몸길이는 변하지 않는다.
	//	사과의 위치와 뱀의 이동경로가 주어질 때 이 게임이 몇 초에 끝나는지 계산하라.



	// N x N 크기의 보드
	int N;
	std::cin >> N;

	// board 
	//  - 0 : 빈 상태
	//  - 1 : apple
	std::vector<std::vector<int>> board(N, std::vector<int>(N, 0));



	int cnt;
	std::cin >> cnt;

	// apple init
	// 
	for (int i = 0; i < cnt; ++i)
	{
		int l, c;
		std::cin >> l >> c;
		board[l - 1][c - 1] = 1; // 1, 1 => 0, 0
	}



	std::cin >> cnt;

	std::map<int, char> turn;
	for (int i = 0; i < cnt; ++i)
	{
		int x;
		char dir;
		std::cin >> x >> dir;
		turn[x] = dir;
	}

	// 상 하 좌 우
	// 3  1  2  0
	int current_dir{ 0 };

	// 뱀은 어떻게?
	// Deque 사용 - pop, push 둘 다 가능
	std::deque<std::array<int, 2>> snake;
	snake.push_back({ 0, 0 });

	int sec{};

	while (true)
	{
		// move snake
		// 1. turn하는 시간인지 검사
		auto it = turn.find(sec);
		if (it != turn.end()) // 찾았다면
		{
			// turn
			current_dir = RotateSnake(current_dir, it->second);
		}
		else // 못찾았다면
		{
			// turn하지 않음. 그대로 진행
		}

		// 1.5. 갈 수 있는지 검사
		if ()


		// 2. 지금 current_dir에 맞게 이동
		// overflow된다면?!
		// 먼저 갈 수 있는지 검사해야 할 듯
		switch (current_dir)
		{
		case 0: // right

			break;
		case 1: // down

			break;
		case 2: // left
			
			break;
		case 3: // up

			break;
		default: break;
		}

		
		
		// 벽에 걸리거나
		// 자기 자신의 몸에 걸리거나



		if ()
		{
			break;
		}


			sec++;
	}



	return 0;
}