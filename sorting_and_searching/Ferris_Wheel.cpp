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
lint solveFunction(lint x, vector<lint>& arr) {
    asort(arr);
    lint i = 0;
    lint j = arr.size() - 1;
    lint cnt = 0;
    while (i <= j) {
        lint weight = arr[i] + arr[j];
        if (weight > x) {
            j--;
            cnt++;
        } else {
            i++;
            j--;
            cnt++;
        }
    }
    return cnt;
}
void solution(){
    lint n;lint x;
    cin >> n >> x;
    vector<lint>arr;
    forloop(0,n){
        lint x;cin >> x;arr.push_back(x);
    }
    lint ans=solveFunction(x,arr);
    print(ans)

}
int main(){

    solution();
}