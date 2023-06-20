#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;
#define ENTER 1
#define EXIT -1
int32_t main()
{
    int n;cin>>n;
    set<pair<int, int>> s;
 
    for(int i = 0;i<n;i++) {
        int a,b;cin>>a>>b;
        s.insert({a, ENTER});
        s.insert({b, EXIT});
    }
 
    int sum = 0;
    int mx = 0;
    for(auto it:s) {
        sum += it.second;
        mx = max(mx, sum);
    }
    cout<<mx;
}