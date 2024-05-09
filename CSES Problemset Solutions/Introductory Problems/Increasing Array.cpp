#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    ll n, ans=0;
    cin>>n;
    ll arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    for(int i=1; i<n; i++)
        if(arr[i]<arr[i-1]) {
            ans+=arr[i-1]-arr[i];
            arr[i]=arr[i-1];
        }
    cout<<ans;
    return 0;
}
