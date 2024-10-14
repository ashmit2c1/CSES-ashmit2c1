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

// solving it using vector
vector<lint>solveFunction(vector<lint>&customers,vector<lint>&tickets){
    asort(tickets);
    vector<lint>ans;
    forloop(0,customers.size()){
        lint customerPrice=customers[i];
        auto it = upper_bound(tickets.begin(),tickets.end(),customerPrice);
        if(it==tickets.begin()){ans.push_back(-1);}
        else{
            ans.push_back(*--it);tickets.erase(it);
        }
    }
    return ans;
}



vector<lint> solveFunction(vector<lint>& customers, vector<lint>& tickets) {
    multiset<lint> st(tickets.begin(), tickets.end()); // Insert tickets into the multiset
    vector<lint> ans;
    
    forloop(0, customers.size()) {
        lint customerPrice = customers[i];
        auto it = st.upper_bound(customerPrice);
        if (it == st.begin()) { // No valid tickets
            ans.push_back(-1);
        } else {
            --it; 
            ans.push_back(*it);
            st.erase(it);
        }
    }
    
    return ans;
}
void solution(){
    lint n;lint m;
    cin >> n >> m;
    vector<lint>tickets;
    forloop(0,n){lint x;cin >> x;tickets.push_back(x);}
    vector<lint>customers;
    forloop(0,m){lint x;cin >> x;customers.push_back(x);}
    vector<lint>ans=solveFunction(customers,tickets);
    forloop(0,ans.size()){print(ans[i])}
}
int main(){

    solution();
}