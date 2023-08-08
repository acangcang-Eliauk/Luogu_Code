#include<bits/stdc++.h>
using namespace std;
int a[10][10];
bool note1[10][9],note2[10][9],note3[10][9];
void dfs(int now){
    if(now > 81){
        for(int i = 1;i <= 9;i ++){
            for(int j = 1;j <= 9;j ++)
                cout<<a[i][j]<<" ";
            puts("");
        }
        return;
    }
    int x = (now - 1) / 9 + 1;
    int y = (now - 1) % 9 + 1;
    int block = (x - 1) / 3 * 3 + (y - 1) / 3 + 1;
    for(int i = 1;i <= 9;i ++)
        if(!note1[x][i] && !note2[y][i] && !note3[block][i] && !a[x][y]){
            note1[x][i] = note2[y][i] = note3[block][i] = 1;
            a[x][y] = i;
            dfs(now + 1);
            note1[x][i] = note2[y][i] = note3[block][i] = 0;
            a[x][y] = 0;
        }
}
int main(){
    for(int i = 1;i <= 9;i ++){
        for(int j = 1;j <= 9;j ++){
            int block = (i - 1) / 3 * 3 + (j - 1) / 3 + 1;
            cin>>a[i][j];
            if(a[i][j])note1[i][a[i][j]] = note2[j][a[i][j]] = note3[block][a[i][j]] = 1;
        }
    }
    dfs(1);
    return 0;
}