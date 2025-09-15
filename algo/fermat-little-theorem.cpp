const ll MOD = 998244353;

/* Binary Exponentiation */
ll modmul(ll a, ll b) { return ((a % MOD) * (b % MOD)) % MOD; }
ll binExpo(ll a, ll b) {
  if (b == 0)
    return 1;
  if (b & 1) { // odd
    ll p = binExpo(a, (b - 1) / 2);
    return 1LL * p * p % MOD * a % MOD;
  } else { // even
    ll p = binExpo(a, b / 2);
    return 1LL * p * p % MOD;
  }
}

ll modInverse(ll x) { return binExpo(x, MOD - 2); }
