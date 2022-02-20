// https://www.geeksforgeeks.org/prime-numbers/?ref=lbp
// A prime number is a natural number greater than 1
// Two and Three are only two consecutive natural numbers that are prime.
// Goldbach Conjecture: Every even integer greater than 2 can be expressed as the sum of two primes.

#include <bits/stdc++.h>
using namespace std;

template <typename T>
void printVector(vector<T> vec)
{
	cout << "[ ";
	for (auto num : vec)
	{
		cout << num << " ";
	}
	cout << "]\n";
}

// O(n), O(1)
bool isPrime1(int num)
{
	if (num <= 1)
		return false;

	for (int i = 2; i < num; i++)
	{
		if (num % i == 0)
			return false;
	}

	return true;
}

// O(sqrt(n)), O(1)
bool isPrime2(int num)
{
	if (num <= 1)
		return false;

	//check till sqrt(num)
	for (int i = 2; i * i <= num; i++)
	{
		if (num % i == 0)
			return false;
	}
	return true;
}

void primeSieve(int N)
{
	vector<int> ans;

	vector<bool> sieve(N + 1, true);

	for (int num = 2; num * num <= N; num++)
	{
		if (sieve[num])
		{
			for (int i = num * num; i <= N; i += num)
			{
				sieve[i] = false;
			}
		}
	}

	for (int i = 2; i <= N; i++)
	{
		if (sieve[i])
			ans.push_back(i);
	}
	printVector(ans);
}

// O(n^2), O(n)
vector<int> primeRange(int M, int N)
{
	vector<int> ans;
	if (M <= 1)
		M = 2;

	for (int i = M; i <= N; i++)
	{
		bool flag = true;
		for (int j = 2; j * j <= i; j++)
		{
			if (i % j == 0)
			{
				flag = false;
				break;
			}
		}
		if (flag)
			ans.push_back(i);
	}
	return ans;
}

void primeFactors(int num)
{
	//spf -> smallest prime factor
	vector<int> spf(num + 1);

	// assume every number is a prime number
	for (int i = 2; i <= num; i++)
	{
		spf[i] = i;
	}

	for (int i = 2; i * i <= num; i++)
	{
		for (int j = i * i; j <= num; j += i)
		{
			if (spf[j] == j)
			{
				spf[j] = i;
			}
		}
	}
	int n = num;
	cout << "prime factors: [ ";
	while (n != 1)
	{
		cout << spf[n] << " ";
		n /= spf[n];
	}
	cout << "]\n";
}

int main()
{

	cout << isPrime1(11) << endl;
	cout << isPrime2(12) << endl;
	primeSieve(23);
	primeFactors(31);
	primeFactors(1);
	return 0;
}