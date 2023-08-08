#include<bits/stdc++.h>
#include <utility>
using namespace std;
int n,m,a,b,ans[505][505];
int nextt[5][2] = {{114514,1919810},{-1,0},{0,-1},{1,0},{0,1}};
bool note[505][505] = {0};
queue<pair<int,int>> q;
void bfs(){
    while(q.size()){
        pair<int,int> f = q.front();
        q.pop();
        for(int i = 1;i <= 4;i ++){
            pair<int,int> next = f;
            next.first += nextt[i][0];
            next.second += nextt[i][1];
            if(next.first >= 1 && next.first <= n && next.second >= 1 && next.second <= m && !note[next.first][next.second]){
                ans[next.first][next.second] = ans[f.first][f.second] + 1;
                note[next.first][next.second] = 1;
                q.push(next);
            }
        }
    }
}
int main(){
    cin>>n>>m>>a>>b;
    while(a --){
        int x,y;
        cin>>x>>y;
        q.push(make_pair(x,y));
        note[x][y] = 1;
    }
    bfs();
    while(b --){
        int x,y;
        cin>>x>>y;
        cout<<ans[x][y]<<endl;
    }
    return 0;
}