#include<bits/stdc++.h>
using namespace std;
int n;
string ans;
bool is_prime(int n){
    if(n < 2)return 0;
    for(int i = 2;i <= n / i;i ++)
        if(n % i == 0)return 0;
    return 1;
}
void dfs(int x){
    if(x > n){
        cout<<ans<<endl;
        return;
    }
    for(int i = 1;i <= 9;i ++)
        if(is_prime(stoi(ans + char(i + '0') ))){
            string last_ans = ans;
            ans = ans + char(i + '0');
            dfs(x + 1);
            ans = last_ans;
        }
}
int main(){
    cin>>n;
    dfs(1);
    return 0;
}