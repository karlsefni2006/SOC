#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, target;
    cin >> n >> target;
    vector<int> input(n);
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    map<int, int> index;
    for (int i = 0; i < n; i++) {
        index[input[i]] = i + 1;  // store 1-based index
    }

    bool found = false;
    int i_ans = -1, j_ans = -1, k_ans = -1;

    for (int i = 0; i < n && !found; i++) {
        for (int j = i + 1; j < n; j++) {
            int sum = target - input[i] - input[j];
            auto x = index.find(sum);
            if (x != index.end()) {
                int k = x->second;
                if (k != i + 1 && k != j + 1) { // ensure all positions are distinct
                    i_ans = i + 1;
                    j_ans = j + 1;
                    k_ans = k;
                    found = true;
                    break;
                }
            }
        }
    }

    if (found) {
        cout << i_ans << " " << j_ans << " " << k_ans << "\n";
    } else {
        cout << "IMPOSSIBLE\n";
    }

    return 0;
}
