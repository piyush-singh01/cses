#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;
int32_t main()
{
    int n;cin>>n;
    int m;cin>>m;
 
    vector<int> a(n+1);
    for(int i = 1;i<=n;i++) {
        cin>>a[i];
    }
 
    vector<vector<int>> dp(n+1, vector<int>(m+2));
    for(int j = 1;j<=m;j++) { 
        if(a[1] == 0 || a[1] == j) {
            dp[1][j] = 1;
        }
    }
 
    for(int i = 2;i<=n;i++) {
        for(int j = 1;j<=m;j++) {
            if(a[i] == 0 || a[i] == j) {
                dp[i][j] = (0LL + dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1])%MOD;
            }
        }
    }
 
    int sum = 0;
    for(int j = 1;j<=m;j++) {
        (sum += dp[n][j])%=MOD;
    }
    cout<<sum;
}