#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;
int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};
int dir[]= {'R', 'D', 'U', 'L'};
typedef array<int, 2> ar;
bool valid(int i, int j, int n, int m) {
    return i>=0 and j>=0 and i<n and j<m;
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
            } else if(grid[i][j] == 'B') {
                dest = {i,j};
            }
        }
    }

    /**/
    vector<vector<bool>> visited(n, vector<bool>(m));
    vector<vector<int>> direction(n, vector<int>(m, 9));
    
    queue<ar> q;
    q.push(src);
    visited[src[0]][src[1]] = true;

    while(!q.empty()) {
        ar curr = q.front();
        q.pop();
        if(curr == dest) {
            break;
        } 

        int node_x = curr[0];
        int node_y = curr[1];
        for(int i = 0;i<4;i++) {
            int child_x = node_x + dx[i];
            int child_y = node_y + dy[i];
            if(valid(child_x, child_y, n, m)) {
                if(grid[child_x][child_y] != '#') {
                    if(!visited[child_x][child_y]) {
                        visited[child_x][child_y] = true;
                        direction[child_x][child_y] = i;
                        q.push({child_x, child_y});
                    }
                }
            }
        }
    }
    /**/

    if(!visited[dest[0]][dest[1]]) {
        cout<<"NO";
        return 0;
    }

    /**/
    vector<char> p;
    ar curr = dest;
    while(curr != src) {
        int movement = direction[curr[0]][curr[1]];
        ar parent = {curr[0] - dx[movement], curr[1] - dy[movement]};
        curr = parent;
        p.push_back(dir[movement]);
    }
    /**/
    reverse(p.begin(), p.end());
    cout<<"YES\n";
    cout<<(int)p.size()<<"\n";
    for(char c:p) {
        cout<<c;
    }
}