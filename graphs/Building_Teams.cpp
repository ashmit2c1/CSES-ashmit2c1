#include<bits/stdc++.h>
using namespace std;


bool checkFunction(int V,vector<int>adj[],vector<int>&teams){
    vector<int>color(V,-1);
    queue<int>q;
    for(int i=0;i<V;i++){
        if(color[i]==-1){
            color[i]=0;
            q.push(i);
            while(q.empty()==false){
                int node=q.front();
                q.pop();
                int n=adj[node].size();
                for(int j = 0; j<n ; j++){
                    int neighbor=adj[node][j];
                    if(color[neighbor]==-1){
                        color[neighbor]=1-color[node];
                        q.push(neighbor);
                    }
                    else{
                        if(color[neighbor]==color[node]){
                            return false;
                        }
                    }
                }
            }
        }
    }
    for(int i=0;i<V;i++){
        teams[i]=1+color[i];
    }
    return true;
}
void solution(){
    int n; // number of friends // nodes
    int m; // relations // edges 
    cin >> n >>m;
    vector<int>adj[n];
    for(int i=0;i<m;i++){
        int u;
        int v;
        cin >> u >> v;
        adj[u-1].push_back(v-1); // 0 based indexing 
        adj[v-1].push_back(u-1); // 0 based indexing 
    }
    // is it possible or not 
    vector<int>teams(n);
    bool ans = checkFunction(n,adj,teams);
    if(ans==true){
        for(int i=0;i<teams.size();i++){
            cout << teams[i] << " ";
        }
    }
    else{
        cout << "IMPOSSIBLE" << "\n";
    }
}

int main(){
    solution();
    
}