#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

typedef array<ll, 2> ar;
typedef array<ll, 3> arr;
template<class T>
using pqmin = priority_queue<T, vector<T>, greater<T>>;

int32_t main()
{
    int n, m;cin>>n>>m;
    vector<vector<ar>> adj(n+1);
    for(int i = 0;i<m;i++) {
        int a,b;cin>>a>>b;
        ll w;cin>>w;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }

    pqmin<arr> pq;
    vector<bool> visited(n+1);

    int count = 0;
    ll cost = 0;
    pq.push({0, 1, -1});
    while(!pq.empty()) {
        arr curr = pq.top();
        pq.pop();

        ll wt = curr[0];
        int fr = curr[1];
        int par = curr[2];
        
        if(visited[fr]) continue;
        visited[fr] = true;
        
        count++;
        cost += wt;
        for(ar child:adj[fr]) {
            int to = child[0];
            ll wt = child[1];
            if(!visited[to]) {
                pq.push({wt, to, fr});
            }
        }
    }
    if(count < n) {
        cout<<"IMPOSSIBLE";
    } else {
        cout<<cost;
    }
}
