#include<bits/stdc++.h>
using namespace std;

int findSteps(int V,vector<int>adj[]){
    vector<int>cnt(V+1,INT_MAX);
    vector<bool>visited(V+1,false);
    queue<int>q;
    q.push(1);
    visited[1]=true;
    cnt[1]=1;
    while(q.empty()==false){
        int node=q.front();
        q.pop();
        if(node==V){
            return cnt[node];
        }
        int n=adj[node].size();
        for(int i=0;i<n;i++){
            int neighbor=adj[node][i];
            if(visited[neighbor]==false){
                visited[neighbor]=true;
                cnt[neighbor]=1+cnt[node];
                q.push(neighbor);
            }
        }
    }
    return -1;
}
void solution(){
    int n;
    int m;
    cin >> n >> m;
    vector<int>adj[n+1];
    for(int i=0;i<m;i++){
        int u;
        int v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int ans=findSteps(n,adj);
    cout << ans << "\n";
}

int main(){
    solution();
    
}