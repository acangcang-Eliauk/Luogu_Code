#include<bits/stdc++.h>
using namespace std;
int x1,x2,Y1,y2,n;
char maps[1005][1005];
bool note[1005][1005];
int nextt[5][2] = {{114514,1919810},{-1,0},{0,-1},{1,0},{0,1}}; 
struct dot{
    int x,y,step;
};
int bfs(int x1,int Y1,int x2,int y2){
    queue<dot> q;
    dot first = {x1,Y1,0};
    q.push(first);
    while(q.size()){
        dot f = q.front();
        q.pop();
        for(int i = 1;i <= 4;i ++){
            dot next = {f.x + nextt[i][0],f.y + nextt[i][1],f.step + 1};
            if(next.x >= 1 && next.x <= n && next.y >= 1 && next.y <= n && maps[next.x][next.y] == '0' && !note[next.x][next.y]){
                if(next.x == x2 && next.y == y2)return next.step;
                note[next.x][next.y] = 1;
                q.push(next);
            }
        }
    }
}
int main(){
    cin>>n;
    for(int i = 1;i <= n;i ++)  
        for(int j = 1;j <= n;j ++)
            cin>>maps[i][j];
    cin>>x1>>Y1>>x2>>y2;
    cout<<bfs(x1,Y1,x2,y2);
    return 0;
}