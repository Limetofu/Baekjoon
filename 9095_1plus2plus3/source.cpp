#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    // �ִ� n�� 10�̹Ƿ� dp �迭 ũ��� 11�� ����
    vector<int> dp(11, 0);

    // �ʱ� �� ����
    dp[0] = 1;  // 0
    dp[1] = 1;  // 1
    dp[2] = 2;  // 2
    dp[3] = 4;  // 3

    // dp �迭 ä��� (4���� 10����)
    for (int i = 4; i <= 10; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }

    for (int i = 0; i < T; ++i) {
        int n;
        cin >> n;
        cout << dp[n] << endl;  // n�� 1, 2, 3�� ������ ��Ÿ���� ����� �� ���
    }

    return 0;
}
