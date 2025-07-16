#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    stack<int> sub;
    sub.push(-1); 
    int MAX = 0, count = 0;

    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '(') {
            sub.push(i);
        } else {
            sub.pop();
            if (!sub.empty()) {
                int temp = i - sub.top();
                if (temp > MAX) {
                    MAX = temp;
                    count = 1;
                } else if (temp == MAX) {
                    count++;
                }
            } else {
                sub.push(i); 
            }
        }
    }

    if (MAX == 0)
        cout << "0 1";
    else
        cout << MAX << " " << count;

}
