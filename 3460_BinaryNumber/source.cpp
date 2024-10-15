#include <iostream>
#include <vector>

int main() {
    int T;  // 테스트 케이스의 개수
    std::cin >> T;

    while (T--) {
        int n;
        std::cin >> n;

        std::vector<int> positions;
        int position = 0;

        while (n > 0) {
            if (n & 1) {
                positions.push_back(position); // 현재 비트가 1이면 위치 저장
            }
            n >>= 1; // n을 오른쪽으로 1 비트 이동 (다음 비트 검사)
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
