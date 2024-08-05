#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e9+7;
int main() {
    std::ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll t, a, b;
    cin>>t;
    while (t--) {
        cin>>a>>b;
        if((a+b)%3==0&&min(a,b)>=(a+b)/3)
            cout <<"YES\n";
        else
            cout <<"NO\n";
    }
    return 0;
}
