#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e7 + 1;
vector<int> spf(MAX);

void sieve() {
    for (int i = 2; i < MAX; i++) {
        if (spf[i] == 0) {
            for (int j = i; j < MAX; j += i) {
                if (spf[j] == 0) spf[j] = i;
            }
        }
    }
}

int main() {

    sieve(); 

    int n;
    cin >> n;
    vector<int> first(n), second(n);

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;

        int original = x;
        set<int> primes;

        while (x > 1) {
            int p = spf[x];
            primes.insert(p);
            while (x % p == 0) x /= p;
        }

        if (primes.size() < 2) {
            first[i] = -1;
            second[i] = -1;
        } else {

            auto it = primes.begin();
            int p1 = *it;
            int p2 = *(++it);
            int d1 = 1;
            while (original % (d1 * p1) == 0) d1 *= p1;

            int d2 = original / d1;

            if (__gcd(d1 + d2, original) == 1) {
                first[i] = d1;
                second[i] = d2;
            } else {
                first[i] = -1;
                second[i] = -1;
            }
        }
    }

    for (int x : first) cout << x << " ";
    cout << "\n";
    for (int x : second) cout << x << " ";
    cout << "\n";

}
