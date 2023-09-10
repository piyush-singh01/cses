#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll dp[21][2][2][11];
ll recursion(int pos, bool already_smaller, int last_digit, bool still_leading_zero, vector<int> &number) {
    if(pos == (int)number.size()) {
        return dp[pos][already_smaller][still_leading_zero][last_digit] = 1LL;
    }

    if(dp[pos][already_smaller][still_leading_zero][last_digit] != -1) {
        return dp[pos][already_smaller][still_leading_zero][last_digit];
    }

    int limit = number[pos];
    if(already_smaller) {
        limit = 9;
    }

    ll res = 0;
    for (int digit = 0;digit <= limit; digit++) {
        bool smaller_now = already_smaller;
        bool leading_now = still_leading_zero;
        if(!already_smaller && digit < limit) smaller_now = true;
        if(still_leading_zero && digit > 0) leading_now = false;

        if(leading_now) {
            res += recursion(pos + 1, smaller_now, digit, leading_now, number);
        } else {
            if(digit != last_digit) {
                res += recursion(pos + 1, smaller_now, digit, leading_now, number);
            }
        }
    }
    return dp[pos][already_smaller][still_leading_zero][last_digit] = res;
}
ll solve(ll n) {
    vector<int> number;
    while(n) {
        number.push_back(n%10);
        n /= 10;
    }
    reverse(number.begin(), number.end());
    memset(dp, -1LL, sizeof(dp));
    return recursion(0, 0, 0, 10, number);
}
int32_t main() {
    ll a,b;cin>>a>>b;
    if(a == 0) {
        cout<<solve(b);
    } else {
        cout<<solve(b) - solve(a - 1);
    }
}
