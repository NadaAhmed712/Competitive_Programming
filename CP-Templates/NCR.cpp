struct ncr {
    vector<ll>fact, inv;
    int mod, n;
    ncr(int sz, int Mod) {
        n=sz, mod=Mod;
        fact=inv=vector<ll>(n);
        build();
    }
    ll fst_pow(ll a, ll b) {
        if(!b) return 1;
        ll t=fst_pow(a,b/2);
        return ((((t%mod)*(t%mod))%mod)*(b&1?(a%mod):1))%mod;
    }
    ll modInv(ll x) {
        return fst_pow(x,mod-2)%mod;
    }
    void build() {
        fact[0]=inv[0]=1;
        for(int i=1; i<n; i++) {
            fact[i]=(fact[i-1]*i)%mod;
            inv[i]=modInv(fact[i]);
        }
    }
    ll NCR(ll x, ll y) {
        if(x<y)
            return 0;
        return ((fact[x]*inv[y])%mod*inv[x-y]) %mod;
    }
}temp(2e5+5,1e9+7);
