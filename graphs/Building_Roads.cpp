#include<bits/stdc++.h>
using namespace std;


/// function for dfs 
void dfsFunction(int node,vector<bool>&visited,vector<int>adj[]){
    visited[node]=true;
    int n=adj[node].size();
    for(int i = 0; i<n ; i++){
        int neighbor=adj[node][i];
        if(visited[neighbor]==false){
            dfsFunction(neighbor,visited,adj);
        }
    }
}
int findComponents(int V,vector<int>adj[],vector<int>&nodes){
    vector<bool>visited(V+1,false);
    int cnt=0;
    for(int i = 1; i<V+1 ; i++){
        if(visited[i]==false){
            nodes.push_back(i);
            dfsFunction(i,visited,adj);
            cnt++;
        }
    }
    return cnt;
}
void solution(){
    int n; int m; // nodes // edges
    cin >> n >> m;
    vector<int>adj[n+1];
    for(int i=0;i<m;i++){
        int u;int v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // nodes aray
    vector<int>nodes;
    int ans=findComponents(n,adj,nodes);
    cout << ans-1 << "\n";
    for(int i = 0; i<nodes.size()-1; i++){
        cout << nodes[i] << " " << nodes[i+1] << "\n";
    }

}

int main(){
    solution();
    
}