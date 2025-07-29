#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

vector<int> adj[MAXN];
vector<int> topo;
bool visited[MAXN];
int dp[MAXN];  

void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v])
            dfs(v);
    }
    topo.push_back(u); 
}

int main() {

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    for (int i = 1; i <= n; ++i) {
        if (!visited[i])
            dfs(i);
    }
    reverse(topo.begin(), topo.end());

    for (int u : topo) {
        for (int v : adj[u]) {
            dp[v] = max(dp[v], dp[u] + 1);
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, dp[i]);
    }

    cout << ans << '\n';

}
