
#include<bits/stdc++.h>
using namespace std;
 
const int maxH = 21;
 
// bose of node 'k' levels above
int lift(int node, int k, vector<vector<int>> &up) {
    int ans = node;
    for(int j = maxH - 1;j>=0;j--) {
        if((k>>j)&1) {
            ans = up[ans][j];
        }
        if(ans == 0) {
            return 0;
        }
    }
    return ans;
}
 
int32_t main() {
    int n,q;cin>>n>>q;
    vector<vector<int>> up(n+1, vector<int>(maxH));
 
    for (int node = 2;node<=n;node++) {
        int boss; cin>>boss;
        up[node][0] = boss;
    }
 
    for(int j = 1;j<maxH;j++) {
        for(int node = 1;node<=n;node++) {
            up[node][j] = up[up[node][j-1]][j-1];
        }
    }
    while(q--) {
        int node;cin>>node;
        int k;cin>>k;
        int res = lift(node, k, up);
        if (res == 0) {
            cout<<-1;
        } else {
            cout<<res;
        }
        cout<<"\n";
    }
}
