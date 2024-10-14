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

// BOTTOM UP CODE 
lint findAnsBottomUp(lint n){
    vector<lint>dp(n+1);
    dp[0]=1;
    forloop(1,n+1){
        secondfor(1,7){
            if(i-j>=0)
            dp[i] = (dp[i] + dp[i-j])%1000000007;
        }
    }
    return dp[n];
}
// TOP DOWN CODE  
lint findCombinationsTopDown(lint n,vector<lint>&dp){
    if(n<0){return 0;}
    if(n==0){return 1;}
    if(dp[n]!=-1){return dp[n];}
    lint cnt=0;
    forloop(1,7){
        cnt+=findCombinationsTopDown(n-i,dp);
    }
    dp[n]=cnt;
    return dp[n];
}
lint findAnsTopDown(lint n){
    vector<lint>dp(n+1,-1);
    return findCombinationsTopDown(n,dp);
}
// RECURSIVE CODE 
lint findCombinations(lint n){
    if(n==0){return 1;}
    if(n<0){return 0;}
    lint cnt=0;
    forloop(1,7){
        cnt+=findCombinations(n-i);
    }
    return cnt;
}

lint findAns(lint n){
    return findCombinations(n);
}

void solution(){
    lint n;
    cin >> n;
    lint ans=findAnsTopDown(n);
    print(ans)

}
int main(){

    solution();
}