double Power(double x, int n)
{
    if (n == 0) return 1.00;
    if (n == 1) return x;
    double ans = Power(x, n / 2);
    if (n % 2 == 0) return ans * ans;
    else if (n < 0) return ans * ans / x;
    else return ans * ans * x;
}