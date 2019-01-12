#include<iostream>
using namespace std;

int all(int n) {
    if(n <= 1) return n;
    return all(n - 1) + all(n - 2);
}

int dp(int n) {
    int dp[1000] = {0, 1};

    for(int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i -2];
    }

    return dp[n];
}

int main() {
    int n;
    cin >> n;

    cout << all(n) << endl;
    cout << dp(n) << endl;
    return 0;
}