#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int n, m;
vector<vector<int>> g;
vector<int> num;
vector<int> inDegree;

void top_sort_dp() {
    queue<int> q;
    vector<int> topo;

    for (int i = 1; i <= n; ++i) {
        if (inDegree[i] == 0)
            q.push(i);
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topo.push_back(u);
        for (int v : g[u]) {
            inDegree[v]--;
            if (inDegree[v] == 0)
                q.push(v);
        }
    }

    num[1] = 1; 
    for (int u : topo) {
        for (int v : g[u]) {
            num[v] = (num[v] + num[u]) % MOD;
        }
    }
}

int main() {
    cin >> n >> m;
    g.resize(n + 1);
    num.assign(n + 1, 0);
    inDegree.assign(n + 1, 0);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        inDegree[v]++;
    }

    top_sort_dp();
    cout << num[n] << "\n";
}
