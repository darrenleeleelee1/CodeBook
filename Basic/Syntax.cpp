// 加速cin, cout
#define IOS cin.tie(nullptr); cout.tie(nullptr); ios_base::sync_with_stdio(false);
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
	char strd[30] = {'0', '.', '6', '0', '2', '9', '\0'};
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
	// String Reverse
	char a[] = {'a', 'b', 'c', 'd', 'e', 'f', '\0'};
	strrev(a); reverse(a, a + 6);
	string s = "abcdefg";
	reverse(s.begin(), s.end());
	/* Complexity
	O(N) 大概 N 可以到 1億
	O(N log N) 大概 N 可以到數百萬~千萬
	O(N^1.5) 大概可以到數萬
	O(N^2) 大概 5000~10000
	 */
	return 0;
}