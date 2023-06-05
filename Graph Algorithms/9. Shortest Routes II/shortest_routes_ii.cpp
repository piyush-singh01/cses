#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;
const ll INF = 1e18;
typedef array<ll, 2> ar;

int32_t main()
{
    int n,m,q;cin>>n>>m>>q;
    vector<vector<ll>> matrix(n, vector<ll>(n, INF));

    for(int i = 0;i<n;i++) {
        matrix[i][i] = 0;
    }

    for(int i = 0;i<m;i++) {
        int a,b;cin>>a>>b;
        a--;b--;

        ll w;cin>>w;
        matrix[a][b] = min(matrix[a][b], w);
        matrix[b][a] = min(matrix[b][a], w);
    }


    for(int k = 0;k<n;k++) {
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<n;j++) {
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
    }

    while(q--) {
        int x,y;cin>>x>>y;
        x--;y--;
        ll dist = matrix[x][y];

        if(dist == INF) cout<<-1<<endl;
        else cout<<dist<<endl;
    }
}