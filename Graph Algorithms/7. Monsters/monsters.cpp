#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;
typedef array<int, 2> ar;

int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};
int dir[]= {'R', 'D', 'U', 'L'};
bool valid(int i, int j, int n, int m) {
    return i>=0 and j>=0 and i<n and j<m;
}
bool boundry(int i, int j, int n, int m) {
    return i == 0 || j == 0 || i == n - 1 || j == m - 1;
}
void pushSource(char ch, queue<ar> &q, vector<vector<char>> &grid, vector<vector<bool>> &visited) {
    int n = grid.size();
    int m = grid[0].size();
    for(int i = 0;i<n;i++) {
        for(int j = 0;j<m;j++) {
            if(grid[i][j] == ch) {
                q.push({i,j});
                visited[i][j] = true;
            }
        }
    }
}
int32_t main()
{
    int n,m;cin>>n>>m;
    vector<vector<char>> grid(n, vector<char>(m));

    ar src, dest;
    for(int i = 0;i<n;i++) {
        for(int j = 0;j<m;j++) {
            cin>>grid[i][j];

            if(grid[i][j] == 'A') {
                src = {i,j};
            }
        }
    }


    vector<vector<int>> parent(n, vector<int>(m, -1));
    vector<vector<int>> level(n, vector<int>(m));
    vector<vector<bool>> visited(n, vector<bool>(m));

    vector<vector<bool>> visited_monster(n, vector<bool>(m));
    vector<vector<int>> level_monsters(n, vector<int>(m));
    


    queue<ar> q;
    pushSource('M', q, grid, visited_monster);
    while(!q.empty()) {
        ar curr = q.front();
        q.pop();

        int node_x = curr[0];
        int node_y = curr[1];

        for(int i = 0;i<4;i++) {
            int child_x = node_x + dx[i];
            int child_y = node_y + dy[i];
            if(valid(child_x, child_y, n, m)) {
                if(!visited_monster[child_x][child_y]) {
                    if(grid[child_x][child_y] != '#') {
                        visited_monster[child_x][child_y] = true;
                        level_monsters[child_x][child_y] = level_monsters[node_x][node_y] + 1;
                        q.push({child_x, child_y});
                    }
                }
            }
        }
    }

    pushSource('A', q, grid, visited);
    while(!q.empty()) {
        ar curr = q.front();
        q.pop();

        int node_x = curr[0];
        int node_y = curr[1];

        for(int i = 0;i<4;i++) {
            int child_x = node_x + dx[i];
            int child_y = node_y + dy[i];

            if(valid(child_x, child_y, n, m)) {
                if(!visited[child_x][child_y]) {
                    if(grid[child_x][child_y] != '#' and (level[node_x][node_y] + 1 < level_monsters[child_x][child_y] or !visited_monster[child_x][child_y])) {
                        visited[child_x][child_y] = true;
                        level[child_x][child_y] = level[node_x][node_y] + 1;
                        parent[child_x][child_y] = i;
                        q.push({child_x, child_y});
                    }
                }
            }
        }
    }

    /**/
    bool ok = false;
    // 0'th row
    for(int j = 0;j<m;j++) {
        if(visited[0][j] and (level[0][j] < level_monsters[0][j] or !visited_monster[0][j])) {
            dest = {0,j};
            ok = true;
            break;
        }
    }

    //last row
    for(int j = 0;j<m and !ok;j++) {
        if(visited[n-1][j] and (level[n-1][j] < level_monsters[n-1][j] or !visited_monster[n-1][j])) {
            dest = {n-1,j};
            ok = true;
            break;
        }
    }

    // 0th col
    for(int i = 0;i<n and !ok;i++) {
        if(visited[i][0] and (level[i][0] < level_monsters[i][0] or !visited_monster[i][0])) {
            dest = {i,0};
            ok = true;
            break;
        }
    }

    //last col
    for(int i = 0;i<n and !ok;i++) {
        if(visited[i][m-1] and (level[i][m-1] < level_monsters[i][m-1] or !visited_monster[i][m-1])) {
            dest = {i,m-1};
            ok = true;
            break;
        }
    }

    if(!ok) {
        cout<<"NO";
        return 0;
    }

    /**/
    cout<<"YES\n";
    vector<char> p;

    ar curr = dest;
    while(curr != src) {
        int idx = parent[curr[0]][curr[1]];
        p.push_back(dir[idx]);
        int child_x = curr[0] - dx[idx];
        int child_y = curr[1] - dy[idx];
        curr = {child_x, child_y};
    }

    reverse(p.begin(), p.end());
    cout<<(int)p.size()<<"\n";
    for(char c:p) {
        cout<<c;
    }
}