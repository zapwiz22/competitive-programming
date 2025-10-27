/* Binary Exponentiation */
ll binexpo(ll a, ll b, ll MOD = LLONG_MAX) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = 1ll * res * a % MOD;
        a = 1ll * a * a % MOD;
        b >>= 1;
    }
    return res;
}

/* Fermat's Little Theorem - Modular Inverse */
ll modinv(ll x, ll MOD) { return binexpo(x, MOD - 2, MOD); }