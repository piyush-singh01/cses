#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;
int32_t main()
{
    int n;cin>>n;
    vector<int> a(n); for(int &i:a) cin>>i;
 
    sort(a.begin(), a.end());
    int median = 0;
    if(n&1) {
        median = a[n/2];
    } else {
        median = (a[n/2] + a[n/2-1])/2;
    }
    ll cost = 0;
    for(int i = 0;i<n;i++) {
        cost += abs(a[i] - median);
    }
    cout<<cost;
}
