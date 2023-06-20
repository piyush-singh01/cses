#include<bits/stdc++.h>
using namespace std;
#define ll long long
/**/
class DS {
    vector<int> parent;
    vector<int> sz;
public:
    DS(int n) {
        parent.resize(n+1);
        sz.resize(n+1);
 
        for(int i = 1;i<=n;i++) {
            parent[i] = i;
            sz[i] = 1;
        }
    }
    int find(int u) {
        if(parent[u] == u) return u;
        return parent[u] = find(parent[u]);
    }
    void Union(int u, int v) {
        u = find(u);
        v = find(v);
 
        if(sz[u] < sz[v]) {
            swap(u,v);
        }
        parent[v] = u;
        sz[u] += sz[v];
    }
    int getSize(int u) {
        return sz[u];
    }
};
int32_t main()
{
    int n,m; cin>>n>>m;
    DS ds(n);
 
    int sz = 1;
    int components = n;
    for(int i = 0;i<m;i++) {
        int a,b;cin>>a>>b;
        a = ds.find(a);
        b = ds.find(b);
        if(a != b) {
            ds.Union(a, b);
            sz = max({sz, ds.getSize(a), ds.getSize(b)});
            components--;
        }
        cout<<components<<" "<<sz<<endl;
    }
}
