#include <iostream>
#include <vector>

int GetMaxCandy(std::vector<std::vector<char>>);

int main()
{
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	// ����̴� ����� ���� "������ (Bomboni)" ������ ����ߴ�.
	// 
	// ���� ó���� N��Nũ�⿡ ������ ä�� ���´�. ������ ���� ��� ���� ���� ���� �ִ�.
	// ����̴� ������ ���� �ٸ� ������ �� ĭ�� ����. 
	// �� ���� �� ĭ�� ����ִ� ������ ���� ��ȯ�Ѵ�. 
	// ����, ��� ���� ������ �̷���� �ִ� ���� �� ���� �κ�(�� �Ǵ� ��)�� �� ���� 
	// �� ������ ��� �Դ´�.
	// 
	// ������ ä���� ���°� �־����� ��, 
	// ����̰� ���� �� �ִ� ������ �ִ� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.


	// �Է�
	// ù° �ٿ� ������ ũ�� N�� �־�����. (3 �� N �� 50)
	// ���� N�� �ٿ��� ���忡 ä���� �ִ� ������ ������ �־�����.
	// �������� C, �Ķ����� P, �ʷϻ��� Z, ������� Y�� �־�����.
	// ������ ���� �ٸ� ������ �� ĭ�� �����ϴ� �Է¸� �־�����.

	// ���
	// ù° �ٿ� ����̰� ���� �� �ִ� ������ �ִ� ������ ���


    int n;
    std::cin >> n;
    std::vector<std::vector<char>> matrix(n);
	
    for (int i = 0; i < n; ++i) {
        std::vector<char> row;
        for (int j = 0; j < n; ++j) {
            char ch;
            std::cin >> ch;  // �� ���ھ� �Է�
            row.push_back(ch);
        }
        matrix[i] = row;
    }

	int max_count{1};

	// ���� �ٲ� �� ������, �ٲ㺸��.
	// �ٲٸ�, max_count, GetCount max()�� ��
	
	for (int i = 0; i < n - 1; ++i)
	{
		// �Ʒ�, ����
		// �̹� ���� �ٲ� ������ ������, �� �� �Ѿ��?
		// �� ���� �Ѿ �� ������, �ϳ��� �Ѿ��...
		// �� -> ��, ���� �Ʒ��� �Ѿ�µ�, 
		// ������, ���� ���ҳ����� �ȹٲ�� �ҵ�.
		// is_valid �Լ��� ���� �˻��ص� ������..
		// ���ڶ��� �˻��ϸ� �Ǵϱ� n-1������ �ϸ� �ɵ�?

		for (int j = 0; j < n - 1; ++j)
		{
			// �ٸ� ���ڶ��, �ٲ� �� ����.
			if (matrix[i][j] != matrix[i][j + 1]) // ������ ���ҿ� ��
			{
				std::swap(matrix[i][j], matrix[i][j + 1]);
				max_count = std::max(GetMaxCandy(matrix), max_count);
				std::swap(matrix[i][j], matrix[i][j + 1]);
			}

			if (matrix[i][j] != matrix[i + 1][j]) // �Ʒ��� ���ҿ� ��
			{
				std::swap(matrix[i][j], matrix[i + 1][j]);
				max_count = std::max(GetMaxCandy(matrix), max_count);
				std::swap(matrix[i][j], matrix[i + 1][j]);
			}
		}
		// i = 15
		// j = 10

		// ������ ���� n-1��°��.. ���� �Ʒ��� �˻��ؾ� ��
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

// �ִ�� ���� �� �ִ� ĵ�� �� ���ϱ�
int GetMaxCandy(std::vector<std::vector<char>> matrix)
{
	int count{};
	int max_count{1};
	char current_candy{};

	int n = matrix.size();

	// �� �ϳ�, �� �ϳ�����
	// �ϳ��ϳ� ���鼭, ���ο� �� ������ 
	// max_count => 1, char ���� �缳��

	// �� -> ���������� �˻�
	for (int i = 0; i < n; ++i)
	{
		count = current_candy = 0;

		for (int j = 0; j < n; ++j)
		{
			// ���ο� �� ����
			if (current_candy != matrix[i][j])
			{
				// count�� 1�� �ٲٱ� ���� max_count �ٲ��
				max_count = std::max(count, max_count); // ���� 2�� �� ��� ���� ū��.
				count = 1;
				current_candy = matrix[i][j];
			}

			// ���� �� ����
			else
			{
				count++;
				max_count = std::max(count, max_count);
			}
		}
	}


	// �� -> �Ʒ������� �˻�
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