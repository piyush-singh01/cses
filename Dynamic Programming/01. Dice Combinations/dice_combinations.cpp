#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;
int32_t main()
{
    int n;cin>>n;
    vector<int> dp(n+1);
    vector<int> dice{1,2,3,4,5,6};
    dp[0] = 1;

    for(int i = 1;i<=n;i++) {
        for(int j:dice) {
            if(i - j >= 0){
                (dp[i] += dp[i-j]) %= MOD;
            }
        }
    }
    cout<<dp[n];
}