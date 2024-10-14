#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define forloop(x,y) for(int i=x;i<y;i++)
#define secondfor(x,y) for(int j=x;j<y;j++)
#define print(x) cout << x << "\n";

void solution(){
    ll n;cin >> n;
    cout << n << " ";
    while(n!=1){
        if(n%2==0){n/=2;cout << n << " ";}
        
        else{n=n*3+1;cout << n << " ";}
    }

}
int main(){

    solution();
}