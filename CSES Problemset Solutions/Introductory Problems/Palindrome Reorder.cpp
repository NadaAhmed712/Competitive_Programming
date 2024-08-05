#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    std::ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll n, a[26]= {0}, odd=0, indx=0;
    string s;
    cin >> s;
    for(int i=0; i<s.size(); i++)
        a[s[i]-'A']++;
    for(int i=0; i<26; i++)  {
        if(a[i]&1)
            odd++, indx=i;
    }
    if(odd>1)
        cout<<"NO SOLUTION";
    else {
        for(int i=0; i<26; i++) {
            for(int j=0; j<a[i]/2; j++)
                cout<<char(i+'A');
        }
        if(odd)
            cout<<char(indx+'A');
        for(int i=25; i>=0; i--) {
            for(int j=0; j<a[i]/2; j++)
                cout<<char(i+'A');
        }
    }
    return 0;
}
