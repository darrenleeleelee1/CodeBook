#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	// String to Integer
	char str[30] = {'-', '1', '2', '3', '4', '5', '\0'};
	printf("%d\n", stoi(str));
	// Integer to String
	int x = 185;
	char temp[30];
	int base = 10;
	itoa(x, temp, base);
	printf("%s\n", temp);
	// String to Double
	char strd[30] = {'0', '.', '6', '0', '2', '2', '2', '9', '\0'};
	printf("%lf\n", stod(strd));
	// Double to String
	double y = 3.1415926;
	string dstr = to_string(y);
	cout << dstr << endl;
	// String initialize
	char null[30] = {'\0'};
	char A[30];
	strcpy(A, null);
	// String Length
	char strl[30] = {'H', 'E', 'L', 'L', 'O', '\0'};
	printf("%d\n", strlen(strl));
	return 0;
}