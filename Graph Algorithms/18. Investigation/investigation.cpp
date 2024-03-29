#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int MOD = 1e9+7;
const ll INF = 1e18;
typedef array<ll, 2> ar;
template<class T>
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

    vector<ll> dist(n+1, INF);
    vector<ll> num(n+1);
    vector<ll> min_flights(n+1, INF);
    vector<ll> max_flights(n+1, 0);
    dist[1] = 0;
    num[1] = 1;
    min_flights[1] = 0;
    max_flights[1] = 0;

    pqmin<ar> pq;
    pq.push({dist[1], 1});
    while(!pq.empty()) {
        ar curr = pq.top();
        pq.pop();

        ll dis = curr[0];
        int fr = curr[1];

        if(dis < dist[fr]) continue;
        for(ar child:adj[fr]) {
            int to = child[0];
            ll wt = child[1];

            if(dis + wt < dist[to]) {
                dist[to] = dis + wt;
                num[to] = num[fr];
                pq.push({dist[to], to});
                min_flights[to] = min_flights[fr] + 1;
                max_flights[to] = max_flights[fr] + 1;
            } else if(dis + wt == dist[to]) {
                (num[to] += num[fr])%=MOD;
                min_flights[to] = min(min_flights[to], min_flights[fr] + 1);
                max_flights[to] = max(max_flights[to], max_flights[fr] + 1);
            }
        }
    }

    cout<<dist[n]<<" "<<num[n]<<" "<<min_flights[n]<<" "<<max_flights[n];
}
