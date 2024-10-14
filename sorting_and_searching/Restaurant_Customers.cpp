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

lint solveFunction(lint n){
    vector<lint>arrival(n);
    vector<lint>departure(n);
    forloop(0,n){
        cin >> arrival[i] >> departure[i];
    }
    asort(arrival);
    asort(departure);
    lint i=0;lint j=0;
    lint currentCustomers=0;
    lint maxCustomers=0;
    while(i<n && j<n){
        if( arrival[i]<departure[j]){
            currentCustomers++;
            maxCustomers=max(maxCustomers,currentCustomers);
            i++;
        }
        else{
            j++;
            currentCustomers--;
        }
    }
    return maxCustomers;
}
void solution(){
    lint n;cin >> n;
    lint ans=solveFunction(n);
    print(ans)

}
int main(){

    solution();
}