#include<bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), vals;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        vals.push_back(a[i]);
    }

    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end()); 
    int m = vals.size();

    vector<vector<int>> dp(n, vector<int>(m, INF));

    
    for (int j = 0; j < m; j++) {
        dp[0][j] = abs(a[0] - vals[j]);
    }


    for (int i = 1; i < n; i++) {
        int min_so_far = INF;
        for (int j = 0; j < m; j++) {
            min_so_far = min(min_so_far, dp[i - 1][j]);
            dp[i][j] = min_so_far + abs(a[i] - vals[j]);
        }
    }

    int result = *min_element(dp[n - 1].begin(), dp[n - 1].end());
    cout << result << '\n';

    return 0;
}
