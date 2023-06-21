#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;
const int INF = 2e9;
int32_t main()
{
    int n;cin>>n;
    int x;cin>>x;
    vector<int> coins(n);
    for(int &c:coins) {
        cin>>c;
    }

    vector<int> dp(x+1, INF);
    dp[0] = 0;

    for(int i = 1;i<=x;i++) {
        for(int j:coins) {
            if(i - j >= 0){
                dp[i] = min(dp[i], dp[i-j] + 1);
            }
        }
    }
    
    if(dp[x] == INF) {
        cout<<-1;
    } else {
        cout<<dp[x];
    }
}