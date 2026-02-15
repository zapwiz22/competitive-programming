// matrix multiplication 
/*
    if f(n) = c1*f(n-1) + c2*f(n-2) + ... + ck*f(n-k)
    then f(n) in k^3log(n) time complexity 
    X = 
    {   
        {0, 1, 0, 0, ..., 0},
        {0, 0, 1, 0, ..., 0},
        {0, 0, 0, 1, ..., 0},
        ...
        {0, 0, 0, 0, ..., 1},
        {ck, ck-1, ..., c2, c1}
    }

    general equation 
    X * {{f(i)}, {f(i+1)}, {f(i+2)}, ..., {f(i+k-1)}} = {{f(i+1)}, {f(i+2)}, ..., {f(i+k)}}
    so 
    {{f(n)}, {f(n+1)}, ..., {f(n+k-1)}} = X^n * {{f(0)}, {f(1)}, ..., {f(k-1)}}
    find  using binary exponentiation 
*/
auto prod = [&](vector<vector<int>>& a, vector<vector<int>>& b) {
    vector<vector<int>> nw(a.size(), vector<int>(b[0].size(),0));
    for (int i=0;i<(int)a.size();i++) {
        for (int j=0;j<(int)b[0].size();j++) {
            for (int k=0;k<(int)b.size();k++) {
                nw[i][j] += 1ll*a[i][k]*b[k][j];
            }
        }
    }
    return nw;
};

vector<vector<int>> x = {
    {0, 1},
    {1, 1}
};

vector<vector<int>> ans(2,vector<int>(2,0));
for (int i=0;i<2;i++) ans[i][i] = 1;
while (n>0) {
    if (n&1) {
        ans = prod(ans,x);
    }
    x = prod(x,x);
    n >>= 1;
}

vector<vector<int>> fib = {{0}, {1}};
ans = prod(ans, fib);
cout << ans[0][0] << endl;