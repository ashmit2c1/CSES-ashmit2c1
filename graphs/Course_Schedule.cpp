#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define forloop(x,y) for(ll i=x;i<y;i++)
#define secondfor(x,y) for(ll j=x;j<y;j++)
#define print(x) cout << x << "\n";
bool check(int V,vector<int>adj[],vector<int>&ans){
    vector<int>inDegree(V,0);
    forloop(0,V){
        int n=adj[i].size();
        secondfor(0,n){
            int node=adj[i][j];
            inDegree[node]++;
        }
    }
    queue<int>q;
    forloop(0,V){
        if(inDegree[i]==0){q.push(i);}
    }
    while(q.empty()==false){
        int node=q.front();q.pop();ans.push_back(node);
        int n=adj[node].size();
        forloop(0,n){
            int neighbor=adj[node][i];
            inDegree[neighbor]--;
            if(inDegree[neighbor]==0){
                q.push(neighbor);
            }
        }
    }
    int cnt=ans.size();
    if(cnt!=V){return true;}
    else{return false;}
}
void solution(){
    int n;int m;
    cin >> n >> m;
    vector<int>adj[n];
    forloop(0,m){
        int u;int v;
        cin >> u >> v;
        adj[u-1].push_back(v-1);
    }
    vector<int>ans;
    bool answer = check(n,adj,ans);
    if(answer==true){cout << "IMPOSSIBLE" << "\n";}
    else{;
        forloop(0,ans.size()){
            cout << ans[i]+1 << " ";
        }
    }

}

int main(){
    solution();
}