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

lint r;
lint c;
lint row[4]={-1,1,0,0};
lint col[4]={0,0,-1,1};
bool isValid(lint i,lint j,vector<vector<char>>&matrix){
    if(i>=0&&i<r && j>=0 && j<c &&matrix[i][j]=='.'){
        return true;
    }
    return false;
}
lint findRooms(vector<vector<char>>&matrix){
    r=matrix.size();
    c=matrix[0].size();
    queue<pair<lint,lint>>q;
    lint cnt=0;
    forloop(0,r){
        secondfor(0,c){
            if(matrix[i][j]=='.'){
                cnt++;
                q.push(mp(i,j));
                matrix[i][j]='#';
                while(q.empty()==false){
                    lint x=q.front().first;
                    lint y=q.front().second;
                    q.pop();
                    for(int k=0;k<4;k++){
                        lint newX = x+row[k];
                        lint newY = y+col[k];
                        if(isValid(newX,newY,matrix)==true){
                            matrix[newX][newY]='#';
                            q.push(mp(newX,newY));
                        }
                    }
                }
            }
        }
    }
    return cnt;
}

void solution(){
    lint n;lint m;
    cin >> n >> m;
    vector<vector<char>>matrix(n,vector<char>(m));
    forloop(0,n){
        secondfor(0,m){
            cin >> matrix[i][j];
        }
    }
    lint ans=findRooms(matrix);
    print(ans)

}
int main(){

    solution();
}