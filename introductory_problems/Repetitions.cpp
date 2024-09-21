#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define forloop(x,y) for(int i=x;i<y;i++)
#define secondfor(x,y) for(int j=x;j<y;j++)
#define print(x) cout << x << "\n";

void solution(){
    string s; cin>>s;
    ll n=s.size();ll cnt=1;ll maxCnt=1;
    forloop(1,n){
        if(s[i]==s[i-1]){cnt++;maxCnt=max(cnt,maxCnt);}
        else{cnt=1;}
    }
    print(maxCnt);
}
int main(){

    solution();
}