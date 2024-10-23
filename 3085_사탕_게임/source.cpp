#include <iostream>
#include <vector>

int GetMaxCandy(std::vector<std::vector<char>>);

int main()
{
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	// 상근이는 어렸을 적에 "봄보니 (Bomboni)" 게임을 즐겨했다.
	// 
	// 가장 처음에 N×N크기에 사탕을 채워 놓는다. 사탕의 색은 모두 같지 않을 수도 있다.
	// 상근이는 사탕의 색이 다른 인접한 두 칸을 고른다. 
	// 그 다음 고른 칸에 들어있는 사탕을 서로 교환한다. 
	// 이제, 모두 같은 색으로 이루어져 있는 가장 긴 연속 부분(행 또는 열)을 고른 다음 
	// 그 사탕을 모두 먹는다.
	// 
	// 사탕이 채워진 상태가 주어졌을 때, 
	// 상근이가 먹을 수 있는 사탕의 최대 개수를 구하는 프로그램을 작성하시오.


	// 입력
	// 첫째 줄에 보드의 크기 N이 주어진다. (3 ≤ N ≤ 50)
	// 다음 N개 줄에는 보드에 채워져 있는 사탕의 색상이 주어진다.
	// 빨간색은 C, 파란색은 P, 초록색은 Z, 노란색은 Y로 주어진다.
	// 사탕의 색이 다른 인접한 두 칸이 존재하는 입력만 주어진다.

	// 출력
	// 첫째 줄에 상근이가 먹을 수 있는 사탕의 최대 개수를 출력


    int n;
    std::cin >> n;
    std::vector<std::vector<char>> matrix(n);
	
    for (int i = 0; i < n; ++i) {
        std::vector<char> row;
        for (int j = 0; j < n; ++j) {
            char ch;
            std::cin >> ch;  // 한 글자씩 입력
            row.push_back(ch);
        }
        matrix[i] = row;
    }

	int max_count{1};

	// 서로 바꿀 수 있으면, 바꿔보기.
	// 바꾸면, max_count, GetCount max()로 비교
	
	for (int i = 0; i < n - 1; ++i)
	{
		// 아래, 우측
		// 이미 서로 바꾼 경험이 있으면, 두 개 넘어가기?
		// 두 개를 넘어갈 수 없으면, 하나만 넘어가기...
		// 좌 -> 우, 이후 아래로 넘어가는데, 
		// 오른쪽, 위쪽 원소끼리는 안바꿔야 할듯.
		// is_valid 함수를 만들어서 검사해도 되지만..
		// 끝자락만 검사하면 되니까 n-1까지만 하면 될듯?

		for (int j = 0; j < n - 1; ++j)
		{
			// 다른 글자라면, 바꿀 수 있음.
			if (matrix[i][j] != matrix[i][j + 1]) // 오른쪽 원소와 비교
			{
				std::swap(matrix[i][j], matrix[i][j + 1]);
				max_count = std::max(GetMaxCandy(matrix), max_count);
				std::swap(matrix[i][j], matrix[i][j + 1]);
			}

			if (matrix[i][j] != matrix[i + 1][j]) // 아래쪽 원소와 비교
			{
				std::swap(matrix[i][j], matrix[i + 1][j]);
				max_count = std::max(GetMaxCandy(matrix), max_count);
				std::swap(matrix[i][j], matrix[i + 1][j]);
			}
		}
		// i = 15
		// j = 10

		// 마지막 원소 n-1번째꺼.. 따로 아래쪽 검사해야 함
		if (matrix[i][n - 1] != matrix[i + 1][n - 1])
		{
			std::swap(matrix[i][n - 1], matrix[i + 1][n - 1]);
			max_count = std::max(GetMaxCandy(matrix), max_count);
			std::swap(matrix[i][n - 1], matrix[i + 1][n - 1]);
		}
	}

	std::cout << max_count;

    return 0;
}

// 최대로 먹을 수 있는 캔디 수 구하기
int GetMaxCandy(std::vector<std::vector<char>> matrix)
{
	int count{};
	int max_count{1};
	char current_candy{};

	int n = matrix.size();

	// 행 하나, 열 하나에서
	// 하나하나 돌면서, 새로운 게 나오면 
	// max_count => 1, char 글자 재설정

	// 행 -> 오른쪽으로 검사
	for (int i = 0; i < n; ++i)
	{
		count = current_candy = 0;

		for (int j = 0; j < n; ++j)
		{
			// 새로운 색 나옴
			if (current_candy != matrix[i][j])
			{
				// count를 1로 바꾸기 전에 max_count 바꿔야
				max_count = std::max(count, max_count); // 현재 2개 중 어떤게 제일 큰지.
				count = 1;
				current_candy = matrix[i][j];
			}

			// 같은 색 나옴
			else
			{
				count++;
				max_count = std::max(count, max_count);
			}
		}
	}


	// 열 -> 아래쪽으로 검사
	for (int i = 0; i < n; ++i)
	{
		count = current_candy = 0;

		for (int j = 0; j < n; ++j)
		{
			if (current_candy != matrix[j][i])
			{
				max_count = std::max(count, max_count);
				count = 1;
				current_candy = matrix[j][i];
			}

			else
			{
				count++;
				max_count = std::max(count, max_count);
			}
		}
	}

	return max_count;
}