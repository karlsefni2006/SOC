#include <bits/stdc++.h>
using namespace std;

const int MAX = 2e5 + 5;

vector<int> adj[MAX];
bool visited[MAX];
int t, n;
int a[MAX];

void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) dfs(v);
    }
}

int main() {

    cin >> t;
    while (t--) {
        cin >> n;

        for (int i=1; i<= n;i++) {
            adj[i].clear();
            visited[i] = false;
        }

        for (int i=1; i<= n;i++) {
            cin >> a[i];
            adj[i].push_back(a[i]);
            adj[a[i]].push_back(i);
        }

        int min = 0;
        for (int i=1;i<=n;i++){
            if (!visited[i]) {
                dfs(i);
                min++; 
            }
        }

        vector<bool> visit(n+1,false);
        int max= 0;
        for (int i=1;i<=n;i++){
            if (!visit[i]) {
                int temp = i;
                while (!visit[temp]){
                    visit[temp] = true;
                    temp = a[temp];
                }
                max++; 
            }
        }

        cout << min << " " << max<< '\n';
    }

}
