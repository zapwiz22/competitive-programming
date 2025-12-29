/* Binary Exponentiation */
int binexpo(int a, int b, int MOD = LLONG_MAX) {
    int res = 1;
    while (b > 0) {
        if (b & 1)
            res = 1ll * res * a % MOD;
        a = 1ll * a * a % MOD;
        b >>= 1;
    }
    return res;
}

/* Fermat's Little Theorem - Modular Inverse */
int modinv(int x, int MOD) { return binexpo(x, MOD - 2, MOD); }
