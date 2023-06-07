#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

#define COMPLETE 2 //visited and popped out of stack
#define PARTIAL 1  //visited and in currently in stack

bool dfs(int node, stack<int> &st, vector<int> &visited, vector<vector<int>> &adj) {
    visited[node] = PARTIAL;
    st.push(node);
    for(int child:adj[node]) {
        if(!visited[child]) {
            if(dfs(child, st, visited, adj)) {
                return true;
            }
        } else if(visited[child] == PARTIAL) {  //if still in source chain
            st.push(child);
            return true;
        }
    }
    visited[node] = COMPLETE;
    st.pop();
    return false;
}
void printStack(stack<int> &st) {
    vector<int> p;

    int curr = st.top();
    p.push_back(curr);
    st.pop();

    while(st.top() != curr) {
        int val = st.top();
        st.pop();
        p.push_back(val);
    }

    p.push_back(st.top());

    reverse(p.begin(), p.end());
    cout<<p.size()<<"\n";
    for(int i:p) {
        cout<<i<<" ";
    }
}
int32_t main()
{
    int n,m;cin>>n>>m;
    vector<vector<int>> adj(n+1);
    for(int i = 0;i<m;i++) {
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
    }

    vector<int> visited(n+1);
    stack<int> st;

    for(int i = 1;i<=n;i++) {
        if(!visited[i]) {
            if(dfs(i, st, visited, adj)) {
                printStack(st);
                return 0;
            }
        }
    }
    cout<<"IMPOSSIBLE";
}   