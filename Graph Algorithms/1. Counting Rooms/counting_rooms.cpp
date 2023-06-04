#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;
int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};
bool valid(int i, int j, int n, int m) {
    return i>=0 and j>=0 and i<n and j<m;
}
void dfs(int node_x, int node_y, vector<vector<bool>> &visited, vector<vector<char>> &grid) {
    int n = grid.size();
    int m = grid[0].size();

    if(!valid(node_x, node_y, n, m)) return;
    if(grid[node_x][node_y] == '#') return;
    if(visited[node_x][node_y]) return;

    visited[node_x][node_y] = true;

    for(int i = 0;i<4;i++) {
        int child_x = node_x + dx[i];
        int child_y = node_y + dy[i];
        dfs(child_x, child_y, visited, grid);
    }
}
int32_t main()
{
    int n,m;cin>>n>>m;
    vector<vector<char>> grid(n, vector<char>(m));
    for(int i = 0;i<n;i++) {
        for(int j = 0;j<m;j++) {
            cin>>grid[i][j];
        }
    }

    vector<vector<bool>> visited(n, vector<bool>(m));
    int cnt = 0;
    for(int i = 0;i<n;i++) {
        for(int j = 0;j<m;j++) {
            if(!visited[i][j] && grid[i][j] == '.') {
                cnt++;
                dfs(i,j, visited, grid);
            }
        }
    }

    cout<<cnt;
}