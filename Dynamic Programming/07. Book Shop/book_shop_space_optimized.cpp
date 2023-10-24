#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

// Space optimized
int32_t main()
{
    int n;cin>>n;
    int x;cin>>x;
    vector<int> dp(x+1);

    vector<int> prices(n);
    vector<int> pages(n);
    for(int i = 0;i<n;i++) 
        cin>>prices[i];
    
    for(int i = 0;i<n;i++) 
        cin>>pages[i];

    for(int i = 0;i<n;i++) {
        for(int j = x;j>=prices[i];j--) {
            dp[j] = max(dp[j], pages[i] + dp[j - prices[i]]);
        }
    }
    cout<<dp[x];
}
