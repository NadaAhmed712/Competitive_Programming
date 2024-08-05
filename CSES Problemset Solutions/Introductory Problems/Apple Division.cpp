#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e9+7;
ll n, a[20], sum;
ll sol(int i, ll t) {
    if(i==n)
        return abs(sum-(2*t));
    return min(sol(i+1,t),sol(i+1,t+a[i]));
}
int main() {
    std::ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>a[i], sum+=a[i];
    cout<<sol(0,0);
    return 0;
}
