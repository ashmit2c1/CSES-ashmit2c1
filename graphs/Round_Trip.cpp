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

bool checkForCycle(lint node, lint parent, vector<bool>& visited, vector<lint> adj[], vector<lint>& nodes, vector<lint>& parentV) {
    visited[node] = true;
    lint n = adj[node].size();
    forloop(0, n) {
        lint neighbor = adj[node][i];
        if(neighbor == parent) { 
            continue; 
        }
        if(visited[neighbor] == true) {
            nodes.push_back(neighbor);
            lint current = node;
            while(current != neighbor) {
                nodes.push_back(current);
                current = parentV[current];
            }
            nodes.push_back(neighbor);
            return true;
        }
        else {
            parentV[neighbor] = node;
            if(checkForCycle(neighbor, node, visited, adj, nodes, parentV) == true) { 
                return true; 
            }
        }
    }
    return false;
}

bool findFunction(lint V, vector<lint> adj[], vector<lint>& nodes) {
    vector<bool> visited(V, false);
    vector<lint> parentV(V, -1);
    forloop(0, V) {
        if(visited[i] == false) {
            if(checkForCycle(i, -1, visited, adj, nodes, parentV) == true) {
                return true;
            }
        }
    }
    return false;
}

void solution() {
    lint n;
    lint m;
    cin >> n >> m;
    vector<lint> adj[n];
    forloop(0, m) {
        lint u; 
        lint v;
        cin >> u >> v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }
    vector<lint> nodes;
    bool ans = findFunction(n, adj, nodes);
    if(ans == false) {
        print("IMPOSSIBLE")
    }
    else {
        print(nodes.size());
        forloop(0, nodes.size()) {
            cout << nodes[i]+1 << " ";
        }
        cout << "\n";
    }
}

int main() {
    solution();
}