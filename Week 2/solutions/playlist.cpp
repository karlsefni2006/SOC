#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);  

    int n;
    cin >> n;
    vector<int> input(n);
    for (int i = 0; i < n; i++) cin >> input[i];

    set<int> seen;
    int max_size = 0, left = 0;

    for (int right = 0; right < n; right++) {
        while (seen.find(input[right]) != seen.end()) {
            seen.erase(input[left]);
            left++;
        }
        seen.insert(input[right]);
        max_size = max(max_size,int(seen.size()));
    }

    cout << max_size << '\n';
}
