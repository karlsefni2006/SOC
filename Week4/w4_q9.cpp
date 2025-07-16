#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int f(ll h, ll a, ll b) {
    if (h <= a) return 1;
    return (h - b - 1) / (a - b) + 1;
}

int main() {

    int t;
    cin >> t;
    while (t--) {
        int q;
        cin >> q;
        vector<int> ans;
        ll minH = 1, maxH = 1e18;

        while (q--) {
            int type;
            cin >> type;
            if (type == 1) {
                ll a, b, n;
                cin >> a >> b >> n;

                ll low, high;
                if (n == 1) {
                    low = 1;
                    high = a;
                } else {
                    low = (n - 2) * (a - b) + a + 1;
                    high = (n - 1) * (a - b) + a;
                }

                if (low > maxH || high < minH) {
                    ans.push_back(0);
                } else {
                    minH = max(minH, low);
                    maxH = min(maxH, high);
                    ans.push_back(1);
                }
            } else {
                ll a, b;
                cin >> a >> b;
                int n1 = f(minH, a, b);
                int n2 = f(maxH, a, b);
                if (n1 == n2)
                    ans.push_back(n1);
                else
                    ans.push_back(-1);
            }
        }

        for (int x : ans)
            cout << x << " ";
        cout << '\n';
    }

}
