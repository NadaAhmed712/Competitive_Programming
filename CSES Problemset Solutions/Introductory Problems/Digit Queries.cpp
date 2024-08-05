#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    std::ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    vector<ll>p(17);
    ll c=9;
    for(int i=1; i<17; i++)
        p[i]=p[i-1]+(c*i), c*=10;
    ll t, n;
    cin>>t;
    while(t--) {
        cin>>n;
        int indx=lower_bound(p.begin(),p.end(),n)-p.begin();
        ll ans=n-p[indx-1];
        ll num=1;
        for(int i=1; i<indx; i++)
            num*=10;
        c=ans%indx;
        ans=(ans+indx-1)/indx;
        num+=(ans-1);
        string x=to_string(num);
        if(!c) c=indx;
        while(x.size()>c)
            x.pop_back();
        cout<<x.back()<<' ';
    }
    return 0;
}
