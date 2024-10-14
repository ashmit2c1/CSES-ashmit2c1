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

lint solveFunction(vector<lint>arr1,vector<lint>arr2,lint k){
    asort(arr1);asort(arr2);
    lint i=0;lint j=0;lint cnt=0;
    while(i<arr1.size() && j<arr2.size()){
        lint maxSize=arr1[i]+k;
        lint minSize=arr1[i]-k;
        lint avail=arr2[j];
        if(arr2[j]<=maxSize && arr2[j]>=minSize){cnt++;i++;j++;}
        else if(avail<minSize){j++;}
        else if(avail>maxSize){i++;}
    }
    return cnt;
}
void solution(){
    lint n;lint m;lint k;cin >> n >> m >> k;
    vector<lint>arr1;
    forloop(0,n){lint x;cin >> x;arr1.push_back(x);}
    vector<lint>arr2;
    forloop(0,m){lint x;cin >> x;arr2.push_back(x);}
    lint ans=solveFunction(arr1,arr2,k);
    print(ans)

}
int main(){

    solution();
}