#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    ll n, x, sum=0, total;
    cin>>n;
    total=n*(n+1)/2;
    for(int i=1; i<n; i++) {
        cin>>x;
        sum+=x;
    }
    cout<<total-sum;
    return 0;
}
