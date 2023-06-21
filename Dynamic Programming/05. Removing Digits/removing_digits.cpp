#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;
const int INF = 2e9;

vector<int> getDigits(int n) {
    vector<int> res;
    while(n > 0) {
        res.push_back(n%10);
        n /= 10;
    }
    reverse(res.begin(), res.end());
    return res;
}

int32_t main()
{
    int n;cin>>n;
    vector<int> dp(n+1, INF);
    dp[0] = 0;

    for(int i = 1;i<=n;i++) {
        for(int digit:getDigits(i)) {
            dp[i] = min(dp[i], dp[i-digit] + 1);
        }
    } 
    cout<<dp[n];

}