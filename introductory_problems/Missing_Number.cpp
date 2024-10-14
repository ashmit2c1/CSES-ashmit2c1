#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define forloop(x,y) for(int i=x;i<y;i++)
#define secondfor(x,y) for(int j=x;j<y;j++)
#define print(x) cout << x << "\n";

void solution(){
    ll n;cin >> n;
    vector<ll>arr;
    forloop(0,n-1){ll x;cin >> x;arr.push_back(x);}
    ll sum=0;ll arrSum=0;
    forloop(1,n+1){sum+=i;}
    forloop(0,n-1){arrSum+=arr[i];}
    print(sum-arrSum);

}
int main(){

    solution();
}