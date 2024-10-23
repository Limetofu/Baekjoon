#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    // 최대 n은 10이므로 dp 배열 크기는 11로 설정
    vector<int> dp(11, 0);

    // 초기 값 설정
    dp[0] = 1;  // 0
    dp[1] = 1;  // 1
    dp[2] = 2;  // 2
    dp[3] = 4;  // 3

    // dp 배열 채우기 (4부터 10까지)
    for (int i = 4; i <= 10; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }

    for (int i = 0; i < T; ++i) {
        int n;
        cin >> n;
        cout << dp[n] << endl;  // n을 1, 2, 3의 합으로 나타내는 방법의 수 출력
    }

    return 0;
}
