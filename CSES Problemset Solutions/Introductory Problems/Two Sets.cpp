#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e9+7;
int main() {
    std::ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll n, sum1=0, sum2=0;
    vector<int>v, vv;
    cin>>n;
    if((n*(n+1)/2)&1)
        cout<<"NO\n";
    else {
        cout<<"YES\n";
        for(int i=n; i>=1; i--) {
            if(sum1<sum2)
                v.push_back(i), sum1+=i;
            else
                vv.push_back(i), sum2+=i;
        }
        cout<<v.size()<<'\n';
        for(auto it:v)
            cout<<it<<' ';
        cout<<'\n';
        cout<<vv.size()<<'\n';
        for(auto it:vv)
            cout<<it<<' ';
    }
    return 0;
}
