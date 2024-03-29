// parametric search
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int a[10005], n, k;

bool solve(ll x) {
    ll cur = 0;
    for(int i = 0; i < k; i++) cur += a[i]/x;
    return cur >= n;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> k >> n;
    for(int i = 0; i < k; i++) cin >> a[i];
    ll st = 1, en = 0x7fffffff;
    while(st < en) {
        ll mid = (st+en+1)/2;
        if(solve(mid)) st = mid;
        else en = mid-1;
    }
    cout << st;
}