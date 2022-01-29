#include <iostream>
#include <algorithm>
#include <string>

#define ll unsigned long long int

// function prototypes
std::string largest_in_n(int n); // return largest palindrome number with n digits
std::string smallest_in_n(int n); // return smallest palindrome number with n digits

int main(void)
{
	int n = 0;
	std::cout << "Number of digits: ";
	std::cin >> n;
	std::cout << "Largest Palindrome with " << n << "digits is = " << largest_in_n(n) << "\n";
	std::cout << "Smallest Palindrome with " << n << "digits is = " << smallest_in_n(n);
	
	return 0;
}

std::string largest_in_n(int n)
{
	std::string l = "";
	l.resize(n, '9');
	return l;
}

std::string smallest_in_n(int n)
{
	std::string s = "";
	s.resize(n, '0');
	s[0] = '1';
	s[n - 1] = '1';
	return  s;
}