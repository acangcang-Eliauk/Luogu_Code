#include<bits/stdc++.h>
using namespace std;
int n,m,nextt[8][2] = {{1,0},{0,1},{-1,0},{0,-1},{-1,-1},{1,-1},{-1,1},{1,1}},sum;
char maps[105][105];
void bfs(int x,int y){
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));
    maps[x][y] = '.';
    while(q.size()){
        pair<int,int> f = q.front();
        q.pop();
        for(int i = 0;i < 8;i ++){
            pair<int,int> next = f;
            next.first += nextt[i][0];
            next.second += nextt[i][1];
            if(next.first >= 1 && next.first <= n && next.second >= 1 && next.second <= m && maps[next.first][next.second] == 'W'){
                maps[next.first][next.second] = '.';
                q.push(next);
            }
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i = 1;i <= n;i ++)
        for(int j = 1;j <= m;j ++)
            cin>>maps[i][j];
    for(int i = 1;i <= n;i ++)
        for(int j = 1;j <= m;j ++)
            if(maps[i][j] == 'W'){
                bfs(i,j);
                sum ++;
            }
    cout<<sum;
    return 0;
}