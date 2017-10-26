#include <iostream>

using namespace std;

int main()
{
	int a, b, c, result = 1;
	cin >> a >> b >> c;
	for(int i = 1; i <= b; i++)
	{
		result *= a;
		result %= c;
	}
	cout << result;
	return 0;
}