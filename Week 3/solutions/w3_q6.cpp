#include <bits/stdc++.h>
using namespace std;

long long f(int ind, int w, vector<int> &wt, vector<int> &val, vector<vector<int>> &dp) {
    if (ind == 0) {
        if (wt[0] <= w) return dp[0][w] = val[0];
        return dp[0][w] = 0;
    }

    if (dp[ind][w] != -1) return dp[ind][w];

    int notTake = f(ind - 1, w, wt, val, dp);
    int Take = INT_MIN;
    if (wt[ind] <= w)
        Take = val[ind] + f(ind - 1, w - wt[ind], wt, val, dp);

    return dp[ind][w] = max(Take, notTake);
}

int main() {
    int n, w;
    cin >> n >> w;

    vector<int> wt(n), val(n);
    for (int i = 0; i < n; i++) {
        cin >> wt[i] >> val[i];
    }

    vector<vector<int>> dp(n, vector<int>(w + 1, -1));

    cout << f(n - 1, w, wt, val, dp) << endl;

    return 0;
}
