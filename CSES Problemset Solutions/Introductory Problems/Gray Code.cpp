#include<bits/stdc++.h>
using namespace std;
int vis[(1<<16)], n;
vector<int>v;
void sol(int num, int lst) {
    if(v.size()==(1<<n))
        return;
    for(int j=0; j<n; j++) {
        if(!(num&(1<<j))&&!vis[num+(1<<j)]) {
            vis[num+(1<<j)]=1;
            v.push_back(num+(1<<j));
            sol(num+(1<<j),j);
        }
        else if((num&(1<<j))&&!vis[num-(1<<j)]) {
            vis[num-(1<<j)]=1;
            v.push_back(num-(1<<j));
            sol(num-(1<<j),j);
        }
    }
}
int main() {
    std::ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n;
    v.push_back(0), vis[0]=1;
    sol(0,-1);
    for(auto it:v) {
        bitset<16>bt=it;
        for(int i=0; i<n; i++)
            cout<<bt[i];
        cout<<'\n';
    }
    return 0;
}
