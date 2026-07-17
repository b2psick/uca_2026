#include <bits/stdc++.h>

using namespace std;

void evenSum(int n) {
    int start = 2;
    int prev = 0;

    cout << start << " ";

    while(start * 4 + prev < n) {
        int ans = start * 4 + prev;
        cout << ans << " ";
        prev = start;
        start = ans;
    }
}

int main() {

    int n;

    cin >> n;

    evenSum(n);

    return 0;
}