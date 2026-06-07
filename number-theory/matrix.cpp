const int32_t MOD = 1e9 + 7;
const int64_t MOD2 = static_cast<int64_t>(MOD) * MOD;

struct Matrix {
    vector<vector<int32_t>> mat;
    int32_t n_rows, n_cols;

    Matrix() {}

    Matrix(vector<vector<int32_t>> values): mat(values), n_rows(values.size()), n_cols(values[0].size()) {}

    static Matrix identity_matrix(int32_t n) {
        vector< vector<int32_t> > values(n, vector<int32_t>(n, 0));
        for(int32_t i = 0; i < n; i++) values[i][i] = 1;
        return values;
    }

    Matrix operator*(const Matrix &other) const {
        int32_t n = n_rows, m = other.n_cols;
        vector<vector<int32_t>> result(n_rows, vector<int32_t>(n_cols, 0));
        for(int32_t i = 0; i < n; i++)
            for(int32_t j = 0; j < m; j++) {
                int64_t tmp = 0;
                for(int32_t k = 0; k < n_cols; k++) {
                    tmp += mat[i][k] * 1ll * other.mat[k][j];
                    while(tmp >= MOD2) tmp -= MOD2;
                }
                result[i][j] = tmp % MOD;
            }
        return move(Matrix(move(result)));
    }

    inline bool is_square() const {
        return n_rows == n_cols;
    }
};
Matrix pw(Matrix a,int32_t p){
    Matrix result = Matrix::identity_matrix(a.n_cols);
    while (p > 0) {
        if (p & 1)
            result = a * result;
        a = a * a;
        p >>= 1;
    }
    return result;
}