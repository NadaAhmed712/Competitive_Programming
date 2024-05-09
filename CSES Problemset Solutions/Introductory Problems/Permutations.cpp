#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    ll n;
    cin>>n;
    if(n==2||n==3)
        cout<<"NO SOLUTION";
    else {
        for(int i=2; i<=n; i+=2)
            cout<<i<<' ';
        for(int i=1; i<=n; i+=2)
            cout<<i<<' ';
    }
    return 0;
}
