#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<bool> sieve_of_eratosthenes(int n)
{
	vector<bool> v(n + 1, true);
	// 0 and 1 is not prime, so we will start form 2
	// p * p <= n means we will check till sqrt of n, cause every
	// composite number has at least one divisor less or equal to
	// its sqrt.so checking till p * p or sqrt(n) is enoght.
	// using p * p is safe, cause it doesnt arise floating point exception
	v[0] = v[1] = false;		// 0 and 1 is not prime
	for (int p = 2; p * p <= n; p++)
	{
		if (v[p] == true)
			// marking as false all the multiples of the prime number
			// starting from p * p cause all the multiples less then
			// p * p already are marked by another prime number's multiple
			for (int i = p * p; i <= n; i += p)
				v[i] = false;
	}
	return v;
	// time complexity : O(n log log n)
	// space complexity : O(n)
}

vector<bool> sieve_of_eratosthenes_odd_only(int n)
{
	vector<bool> v(n + 1, true);
	// 0 and 1 is not prime
	v[0] = v[1] = false;
	// marking all evens greater then 2 at the beginning
	for (int i = 4; i <= n; i += 2)
		v[i] = false;
	// checking only the odds numbers, cause all the even numbers are
	// already marked as false in the previous loop as the smallest even
	// number 2 is prime and all the even numbers greater then 2 are the
	// multiples of 2
	for (int p = 3; p * p <= n; p += 2)
	{
		if (v[p] == true)
			for (int i = p * p; i <= n; i += p)
				v[i] = false;
	}
	return v;
	// it reduce number of operations by half
}

vector<bool> segmented_sieve(int L, int R)
{
	// step: 1
	// get primes <= sqrt(R)
	int limit = sqrt(R);
	vector<bool> prime_mark = sieve_of_eratosthenes(limit);
	// storing primes
	vector<int> prime;
	for (int i = 0; i <= limit; i++) // i < prime_mark.size() [prime_mark.size() = limit + 1]
		if (prime_mark[i])
			// emplace_back() is faster then push_back()
			prime.emplace_back(i);
	
	// step: 2
	// mark multiples of the primes in L to R
	//  prime_set will store all the primes between L to R as the bool vector index
	prime_mark.clear();
	prime_mark.resize(R - L + 1, true);
	for (int pm: prime)
	{
		// finding first multiple of the prime number in L ot R
		int firstMul = (L / pm) * pm;
		if (firstMul < L) firstMul += pm;
		for (int mul = max(pm * pm, firstMul); mul <= R; mul += pm)
			prime_mark[mul - L] = false;
	}
	// we didnt consider L = 1, so prime_mark[0] is still true
	// when L = 1 prime_mark[0] = false
	if (L == 1)
		prime_mark[0] = false;
	return prime_mark;
}

int main()
{
	
	return 0;
}
