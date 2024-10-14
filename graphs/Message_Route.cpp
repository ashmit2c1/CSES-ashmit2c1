#include<bits/stdc++.h>
using namespace std;
#define lint long long
#define forloop(x,y) for(int i=x;i<y;i++)
#define secondfor(x,y) for(int j=x;j<y;j++)
#define print(x) cout << x << "\n";
#define output(arr) for(int i=0;i<arr.size();i++){cout<<arr[i]<<" ";}
#define asort(v) sort(v.begin(), v.end())
#define dsort(v) sort(v.begin(), v.end(), greater<int>())
#define intmax INT_MAX
#define intmin INT_MIN
#define lintmax LLONG_MAX
#define lintmin LLONG_MIN
#define mp(x,y) make_pair(x,y)


lint findAns(lint V, vector<lint> adj[],vector<lint>&nodes) {
    vector<bool> visited(V+1, false);
    vector<lint> distance(V+1, lintmax);
    vector<lint>parent(V+1,-1);
    queue<lint> q;
    q.push(1);
    visited[1] = true;
    distance[1] = 1;

    while (!q.empty()) {
        lint node = q.front();
        q.pop();
        if (node == V) {
            lint current=V;
            while(current!=-1){
                nodes.push_back(current);
                current=parent[current];
            }
            reverse(nodes.begin(),nodes.end());
            return distance[node];
        }
        for (lint neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                parent[neighbor]=node;
                distance[neighbor] = distance[node] + 1;
                q.push(neighbor);
            }
        }
    }

    return -1; 
}

void solution(){
        lint n, m;
        cin >> n >> m;
        vector<lint> adj[n+1];
        forloop(0, m) {
            lint u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<lint>nodes;
        lint ans = findAns(n, adj,nodes);
        if (ans == -1) {
            print("IMPOSSIBLE");
        } else {
            print(ans);
            output(nodes)
        }

}
int main(){

    solution();
}
