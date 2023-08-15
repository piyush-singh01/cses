#include<bits/stdc++.h>
using namespace std;
#define ll long long

int32_t main()
{
    int n;cin>>n;
    vector<int> a(n);for(int &i:a) cin>>i;
 
    int prev = a[0];
    ll moves = 0;
    for(int i = 1;i<n;i++) {
        if(a[i] < prev) {
            moves += prev - a[i];
        } else {
            prev = a[i];
        }
    }
    cout<<moves;
}