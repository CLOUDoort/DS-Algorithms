/*
- <M:N>이 되는 해는 LCM(M, N)번째 해이다.
*/

#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a%b);
}

int lcm(int a, int b) {
    return a/gcd(a,b)*b;
}

int solve(int m, int n, int x, int y) {
    if(x == m) x = 0;
    if(y == n) y = 0;
    int l = lcm(m, n);
    for(int i = x; i <= l; i+=m) {
        if(i == 0) continue;
        if(i % n == y) return i;
    }
    return -1;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--) {
        int m, n, x, y;
        cin >> m >> n >> x >> y;
        cout << solve(m, n, x, y) << '\n';
    }
}