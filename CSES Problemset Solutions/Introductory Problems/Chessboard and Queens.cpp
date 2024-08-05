#include<bits/stdc++.h>
using namespace std;
char a[8][8];
int vis[8][8];
long long ans=0;
void ok(int i,int j,int b) {
    for(int k=0; k<8; k++) {
        vis[i][k]+=b;
        vis[k][j]+=b;
    }
    int x=i,y=j;
    while(x<8 && y<8)
        vis[x++][y++]+=b;
    x=i,y=j;
    while(x<8 && y>=0)
        vis[x++][y--]+=b;
}
void sol(int i,int j,int cnt) {
    if(cnt==8) {
        ans++;
        return;
    }
    if(j==8)
        i++, j=0;
    if(i==8)
        return;
    sol(i,j+1,cnt);
    if(!vis[i][j]&&a[i][j]=='.') {
        ok(i,j,1);
        sol(i,j+1,cnt+1);
        ok(i,j,-1);
    }
}
int main() {
    std::ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    for(int i=0; i<8; i++)
        for(int j=0; j<8; j++)
            cin>>a[i][j];
    sol(0,0,0);
    cout<<ans;
    return 0;
}
