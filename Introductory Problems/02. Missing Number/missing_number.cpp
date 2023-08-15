#include<bits/stdc++.h>
using namespace std;
#define ll long long

int32_t main()
{
    int n;cin>>n;
    vector<int> a(n); for(int &i:a) cin>>i;
 
    ll sumN = ((ll)(n)*(n+1))/2;
    ll sum = 0;
    for(int i = 0;i<n;i++) {
        sum += a[i];
    }
    cout<<sumN - sum;
}