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


	//'Dummy' ��� ���������� �ִ�.�� ���ӿ��� ���� ���ͼ� ���ٴϴµ�, 
	// ����� ������ �� ���̰� �þ��.
	// ���� �̸����� ���ٴϴٰ� �� �Ǵ� �ڱ��ڽ��� ���� �ε����� ������ ������.

	//	������ NxN ���簢 ���������� ����ǰ�, ��� ĭ���� ����� ������ �ִ�.
	// ������ �����¿� ���� ���� �ִ�.
	// ������ �����Ҷ� ���� ���� �������� ��ġ�ϰ� ���� ���̴� 1 �̴�.���� ó���� �������� ���Ѵ�.

	//	���� �� �ʸ��� �̵��� �ϴµ� ������ ���� ��Ģ�� ������.

	//	���� ���� �����̸� �÷� �Ӹ��� ����ĭ�� ��ġ��Ų��.
	//	���� ���̳� �ڱ��ڽ��� ���� �ε����� ������ ������.
	//	���� �̵��� ĭ�� ����� �ִٸ�, �� ĭ�� �ִ� ����� �������� ������ �������� �ʴ´�.
	//	���� �̵��� ĭ�� ����� ���ٸ�, �����̸� �ٿ��� ������ ��ġ�� ĭ�� ����ش�.
	// ��, �����̴� ������ �ʴ´�.
	//	����� ��ġ�� ���� �̵���ΰ� �־��� �� �� ������ �� �ʿ� �������� ����϶�.



	// N x N ũ���� ����
	int N;
	std::cin >> N;

	// board 
	//  - 0 : �� ����
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

	// �� �� �� ��
	// 3  1  2  0
	int current_dir{ 0 };

	// ���� ���?
	// Deque ��� - pop, push �� �� ����
	std::deque<std::array<int, 2>> snake;
	snake.push_back({ 0, 0 });

	int sec{};

	while (true)
	{
		// move snake
		// 1. turn�ϴ� �ð����� �˻�
		auto it = turn.find(sec);
		if (it != turn.end()) // ã�Ҵٸ�
		{
			// turn
			current_dir = RotateSnake(current_dir, it->second);
		}
		else // ��ã�Ҵٸ�
		{
			// turn���� ����. �״�� ����
		}

		// 1.5. �� �� �ִ��� �˻�
		if ()


		// 2. ���� current_dir�� �°� �̵�
		// overflow�ȴٸ�?!
		// ���� �� �� �ִ��� �˻��ؾ� �� ��
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

		
		
		// ���� �ɸ��ų�
		// �ڱ� �ڽ��� ���� �ɸ��ų�



		if ()
		{
			break;
		}


			sec++;
	}



	return 0;
}