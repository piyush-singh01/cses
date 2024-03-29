
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;
 
typedef array<ll, 2> ar;
typedef array<ll, 3> arr;
 
class DS {
    vector<int> parent;
    vector<int> sz;
public:
    DS(int n) {
        parent.resize(n+1, -1);
        sz.resize(n+1, -1);
        for(int i = 0;i<=n;i++) {
            make(i);
        }
    }
    void make(int u) {
        parent[u] = u;
        sz[u] = 1;
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
 
    int getSize(int n) {
        return sz[find(n)];
    }
};
int32_t main()
{
    int n, m;cin>>n>>m;
    vector<arr> edges;
    for(int i = 0;i<m;i++) {
        int a,b;cin>>a>>b;
        ll w;cin>>w;
        edges.push_back({w,a,b});
    }
 
    sort(edges.begin(), edges.end());
    ll sum = 0;
    DS ds(n);
    for(int i = 0;i<m;i++) {
        ll w = edges[i][0];
        int a = edges[i][1];
        int b = edges[i][2];
 
        if(ds.find(a) != ds.find(b)) {
            sum += w;
            ds.Union(a,b);
        }
    }
    int mx = 0;
    for(int i = 1;i<=n;i++) {
        mx = max(mx, ds.getSize(i));
    }
    if(mx < n) {
        cout<<"IMPOSSIBLE";
    } else {
        cout<<sum;
    }
}
