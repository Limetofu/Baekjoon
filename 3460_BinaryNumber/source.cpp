#include <iostream>
#include <vector>

int main() {
    int T;  // �׽�Ʈ ���̽��� ����
    std::cin >> T;

    while (T--) {
        int n;
        std::cin >> n;

        std::vector<int> positions;
        int position = 0;

        while (n > 0) {
            if (n & 1) {
                positions.push_back(position); // ���� ��Ʈ�� 1�̸� ��ġ ����
            }
            n >>= 1; // n�� ���������� 1 ��Ʈ �̵� (���� ��Ʈ �˻�)
            position++;
        }

        for (size_t i = 0; i < positions.size(); ++i) {
            if (i > 0) std::cout << " ";
            std::cout << positions[i];
        }
        std::cout << std::endl;
    }

    return 0;
}
