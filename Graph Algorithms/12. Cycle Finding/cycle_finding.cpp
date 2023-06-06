#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;
const ll INF = 1e18;
typedef array<ll, 3> arr;
int32_t main()
{
    int n,m;cin>>n>>m;
    vector<arr> edges;
    for(int i = 0;i<m;i++) {
        int a,b;cin>>a>>b;
        ll w;cin>>w;
        edges.push_back({a,b,w});
    }

    // find sssp from a dummy node '0' with 0 distance from all nodes
    // since we only need to find negetive cycles
    // n-1 iterations to store all relaxants
    vector<ll> dist(n+1, 0);
    vector<int> parent(n+1, -1);
    for(int i = 0;i<n-1;i++) {
        for(int j = 0;j<m;j++) {
            int fr = edges[j][0];
            int to = edges[j][1];
            ll wt = edges[j][2];

            if(dist[to] > dist[fr] + wt) {
                dist[to] = dist[fr] + wt;
                parent[to] = fr;
            }
        }
    }

    //check with n'th iteration if there is a change
    int change = -1;
    for(int j = 0;j<m;j++) {
        int fr = edges[j][0];
        int to = edges[j][1];
        ll wt = edges[j][2];
        if(dist[to] > dist[fr] + wt) {
            change = to;
            break;
        }
    }

    if(change == -1) {
        cout<<"NO";
        return 0;
    }

    //go back n-1 steps(worse case in a straight line graph) to ensure we are in a cycle
    for(int i = 0;i<n-1;i++) {
        change = parent[change];
    }

    //retrieve the cycle from this point
    vector<int> p;
    p.push_back(change);
    
    int src = change;
    int dest = parent[change];
    
    for(int curr = dest;curr != src;curr = parent[curr]) {
        p.push_back(curr);
    }
    p.push_back(src);

    reverse(p.begin(), p.end());
    cout<<"YES\n";
    for(int i:p) {
        cout<<i<<" ";
    }
}