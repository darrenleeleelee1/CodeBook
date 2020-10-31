const int maxn = 20;
struct Matrix  { 
    long long a[maxn][maxn];
    void zeroM() // 清空矩陣 
    {
        memset(a, 0, sizeof(a));
    }
    void identityM()
    {
        memset(a, 0, sizeof a);
        for(int i = 0; i < maxn; i++)
            a[i][i] = 1;
    }
};
int n; // n * n matrix

Matrix operator*(const Matrix &a, const Matrix &b) // 矩陣乘法
{
    Matrix ret;
    ret.all_0();
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            for (int k = 0; k < n; k++){
                ret.a[i][j] += a.a[i][k] * b.a[k][j];
                ret.a[i][j] %= m;
            }
        }
    }
    return ret;
}

Matrix mpower(Matrix a, int n)
{
    Matrix ret;
    ret.identityM();
    if (n==0)  return ret;
    if (n==1)  return a;
    ret = mpower(a, n/2);
    ret = ret * ret;
    if (n % 2 == 1)  ret = ret * a;
    return ret;
}
int main(int argc, char const *argv[])
{
    cin >> n; // n * n matrix
    Matrix A; // declare
    return 0;
}