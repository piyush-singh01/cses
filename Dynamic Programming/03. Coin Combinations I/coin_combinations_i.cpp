#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;
int32_t main()
{
    int n;cin>>n;
    int x;cin>>x;
    vector<int> coins(n);
    for(int &i:coins) {
        cin>>i;
    }

    vector<int> dp(x+1);
    dp[0] = 1;

    for(int i = 1;i<=x;i++) {
        for(int j:coins) {
            if(i - j >= 0){
                (dp[i] += dp[i-j]) %= MOD;
            }
        }
    }
    cout<<dp[x];
}