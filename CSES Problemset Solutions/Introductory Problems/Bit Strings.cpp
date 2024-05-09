#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e9+7;
int main() {
    std::ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll n, ans=1;
    cin >> n;
    for(int i=1; i<=n; i++)
        ans*=2, ans%=mod;
    cout<<ans;
    return 0;
}
