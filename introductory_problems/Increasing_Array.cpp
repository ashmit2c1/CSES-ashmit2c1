#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define forloop(x,y) for(int i=x;i<y;i++)
#define secondfor(x,y) for(int j=x;j<y;j++)
#define print(x) cout << x << "\n";

void solution(){
    ll n;cin>>n;vector<ll>arr;
    forloop(0,n){ll x;cin >> x;arr.push_back(x);}
    ll diff=0;
    forloop(1,n){
        if(arr[i]<arr[i-1]){
            diff+=(arr[i-1]-arr[i]);
            arr[i]=arr[i-1]; // important to change the element to next
        }
    }
    print(diff);

}
int main(){

    solution();
}