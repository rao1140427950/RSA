// RSA.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

#define P 23
#define Q 11
#define E 7
#define X 27

using namespace std;

int exgcd(int a, int b, int &x, int &y);
int power_mod(int c, int e, int n);

int main()
{
	int p = P;
	int q = Q;
	int e = E;
	int n = p * q;
	int phyn = (p - 1)*(q - 1);
	int d, k, y, z;
	int x = X;

	exgcd(e, phyn, d, k);
	y = power_mod(x, e, n);
	z = power_mod(y, d, n);

	cout << "Original data: " << x << endl;
	cout << "Key: " << d << endl;
	cout << "Encrypted data: " << y << endl;
	cout << "Decrypted data: " << z << endl;

	return 0;
}

int power_mod(int c, int e, int n)
{
	int rst = 1;

	while (e > 0)
	{
		if (e % 2 == 0)
		{
			c *= c;
			c %= n;
			e /= 2;
		}
		else
		{
			rst *= c;
			rst %= n;
			e -= 1;
		}
	}
	return rst;
}

int exgcd(int a, int b, int &x, int &y)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	int gcd = exgcd(b, a%b, x, y);
	int x2 = x, y2 = y;
	x = y2;
	y = x2 - (a / b)*y2;

	return gcd;
}