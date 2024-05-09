#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e9+7;
int main() {
    std::ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll t, x, y;
    cin>>t;
    while(t--) {
        cin>>x>>y;
        if(y<=x) {
            if(x&1)
                cout<<(x-1)*(x-1)+y;
            else
                cout<<(x*x)-y+1;
        }
        else if(y&1)
            cout<<(y*y)-x+1;
        else
            cout<<(y-1)*(y-1)+x;
        cout<<'\n';
    }
    return 0;
}
