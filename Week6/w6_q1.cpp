#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

vector<int> graph[MAXN];
int max_stamina[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    priority_queue<pair<int, int>> pq;

    for (int i = 0; i < k; ++i) {
        int p, h;
        cin >> p >> h;
        pq.push({h, p});
        max_stamina[p] = h;
    }

    while (!pq.empty()) {
        auto [stam, u] = pq.top();
        pq.pop();

        if (max_stamina[u] > stam) continue;  

        if (stam == 0) continue;

        for (int v : graph[u]) {
            if (max_stamina[v] < stam - 1) {
                max_stamina[v] = stam - 1;
                pq.push({stam - 1, v});
            }
        }
    }

    vector<int> guarded;
    for (int i = 1; i <= n; ++i) {
        if (max_stamina[i] > 0)
            guarded.push_back(i);
    }

    cout << guarded.size() << "\n";
    for (int v : guarded)
        cout << v << " ";
    cout << "\n";

}
