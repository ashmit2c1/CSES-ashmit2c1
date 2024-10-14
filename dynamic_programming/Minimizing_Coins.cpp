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


// TOP DOWN CODE 
lint findCoinsTopDown(lint n,vector<lint>&arr,lint sum,vector<vector<lint>>&dp){
    if(sum==0){return 0;}
    if(sum<0 || n==0){return lintmax;}
    if(dp[n][sum]!=-1){return dp[n][sum];}

    lint toInclude=findCoinsTopDown(n,arr,sum-arr[n-1],dp);
    if(toInclude!=lintmax){
        toInclude++;
    }
    lint toNotInclude = findCoinsTopDown(n-1,arr,sum,dp);
    dp[n][sum]=min(toInclude,toNotInclude);
    return dp[n][sum];
}
lint findAnsTopDown(lint n,vector<lint>&arr,lint sum){
    vector<vector<lint>>dp(n+1,vector<lint>(sum+1,-1));
    lint ans=findCoinsTopDown(n,arr,sum,dp);
    if(ans==lintmax){return -1;}
    else{
        return ans;
    }
}
// RECURISVE CODE 
lint findCoins(lint n,vector<lint>& arr,lint sum){
    if(sum==0)return 0;
    if(sum<0||n==0)return lintmax;
        lint toInclude=findCoins(n,arr,sum-arr[n-1]);
    if(toInclude!=lintmax)
        toInclude++;
    lint toNotInclude=findCoins(n-1,arr,sum);
    return min(toInclude,toNotInclude);
}
lint findAns(lint n,vector<lint> arr,lint sum){
    lint ans=findAnsTopDown(n,arr,sum);
    if(ans==lintmax){return -1;}
    else{
        return ans;
    }
}
void solution(){
    lint n;
    cin >> n;
    lint sum;
    cin >> sum;
    vector<lint>arr;
    forloop(0,n){
        lint x;
        cin >> x;
        arr.push_back(x);
    }
    lint ans=findAns(n,arr,sum);
    print(ans)

}
int main(){

    solution();
}