#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;
const ll INF = 1e18;
const ll NINF = -INF;
typedef array<ll, 2> ar;

template<typename T>
using pqmin = priority_queue<T, vector<T>, greater<T>>;
int32_t main()
{
    int n,m;cin>>n>>m;
    vector<vector<ar>> adj(n+1);
    for(int i = 0;i<m;i++) {
        int a,b;cin>>a>>b;
        ll w;cin>>w;
        adj[a].push_back({b,w});
    }

    int src = 1;
    vector<ar> dist(n+1, {INF, INF});
    vector<int> visited(n+1);
    dist[src][0] = 0;

    pqmin<ar> pq;
    pq.push({dist[src][0], src});

    while(!pq.empty()) {
        ar curr = pq.top();
        pq.pop();
        
        int fr = curr[1];
        ll dis = curr[0];

        /*Every vertex need to be visited at most twice to decide*/
        if(visited[fr] == 2) continue;
        visited[fr]++;
        
        for(ar child:adj[fr]) {
            int to = child[0];
            ll wt = child[1];

            if(dist[fr][0] != INF) {
                if(dist[to][0] > dist[fr][0] + wt) {
                    dist[to][0] = dist[fr][0] + wt;
                    pq.push({dist[to][0], to});
                }
                if(dist[to][1] > dist[fr][0] + wt/2) {
                    dist[to][1] = dist[fr][0] + wt/2;
                    pq.push({dist[to][1], to});
                }
            }
            if(dist[fr][1] != INF) {
                if(dist[to][1] > dist[fr][1] + wt) {
                    dist[to][1] = dist[fr][1] + wt;
                    pq.push({dist[to][1], to});
                }
            }
        }
    }
    cout<<min(dist[n][0], dist[n][1]);
}