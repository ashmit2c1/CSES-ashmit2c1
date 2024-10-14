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

lint r,c;
lint row[4]={-1,1,0,0};
lint col[4]={0,0,-1,1};
char direction[4]={'U','D','L','R'};

bool isValid(int i,int j,vector<vector<char>>&matrix){
    return (i>=0 && i<r && j>=0 && j<c && matrix[i][j]!='#');
}

pair<int,string>findStepString(vector<vector<char>>&matrix,lint startX,lint startY,lint endX,lint endY){
    vector<vector<bool>>visited(r,vector<bool>(c,false));
    vector<vector<char>>parentDir(r,vector<char>(c));
    queue<pair<lint,lint>>q;
    q.push(mp(startX,startY));
    visited[startX][startY]=true;
    bool flag = false;
    // while ke inside 
    while(!q.empty()){
        lint x=q.front().first;
        lint y=q.front().second;
        q.pop();
        if(x==endX && y==endY){
        flag = true;
        lint x1 = endX; lint y1 = endY;
        string path="";
        while(!(x1==startX && y1==startY)){
            path+=parentDir[x1][y1];
            forloop(0,4){
                if(direction[i]==parentDir[x1][y1]){
                    x1-=row[i];
                    y1-=col[i];
                    break;
                }
            }
        }
        reverse(path.begin(),path.end());
        return {path.size(), path};
        }
        forloop(0,4){
            lint newX=x+row[i];
            lint newY=y+col[i];
            if(isValid(newX,newY,matrix) && !visited[newX][newY]){
                visited[newX][newY]=true;
                parentDir[newX][newY]=direction[i];
                q.push(mp(newX,newY));
            }
        }
    }
//  here 
    /*if(flag==true) {
        lint x = endX; lint y = endY;
        string path="";
        while(!(x==startX && y==startY)){
            path+=parentDir[x][y];
            forloop(0,4){
                if(direction[i]==parentDir[x][y]){
                    x-=row[i];
                    y-=col[i];
                    break;
                }
            }
        }
        reverse(path.begin(),path.end());
        return {path.size(), path};
    }*/

    
    return {-1,""};
}

void solution(){
    cin>>r>>c;
    vector<vector<char>>matrix(r,vector<char>(c));
    lint startX,startY,endX,endY;
    forloop(0,r){
        secondfor(0,c){
            cin>>matrix[i][j];
            if(matrix[i][j]=='A'){
                startX=i;
                startY=j;
            }
            if(matrix[i][j]=='B'){
                endX=i;
                endY=j;
            }
        }
    }
    pair<int,string>ans=findStepString(matrix,startX,startY,endX,endY);
    if(ans.first!=-1){
        print("YES")
        print(ans.first)
        print(ans.second)
    }
    else{
        print("NO")
    }
}

int main(){
    solution();
}