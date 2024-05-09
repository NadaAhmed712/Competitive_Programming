#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int n, ans=1, cnt=1;
    string s;
    cin>>s;
    n=s.size();
    for(int i=1; i<n; i++) {
        if(s[i]==s[i-1])
            cnt++;
        else
            cnt=1;
        ans=max(ans,cnt);
    }
    cout<<ans;
    return 0;
}
