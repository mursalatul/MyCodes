#include <iostream>
using namespace std;

bool isPowerof2(int x)
{
	return (x && !(x &(x - 1)));
}

int main()
{
	cout << isPowerof2(32) << '\n' << isPowerof2(34) << '\n';
	return 0;
}
