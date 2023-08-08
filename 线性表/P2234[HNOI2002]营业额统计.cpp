#include<bits/stdc++.h>
using namespace std;
int n,a[32768];
long long sum = 0;
int main(){
    cin>>n;
    for(int i = 1;i <= n;i ++)
        cin>>a[i];
    sum = a[1];
    for(int i = n;i >= 2;i --){
        int minn = 2147483647;
        for(int j = 1;j < i;j ++)
            minn = min(minn,abs(a[j] - a[i]));
        sum += minn;
    }
    cout<<sum;
    return 0;
}