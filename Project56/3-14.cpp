#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 10010;
int h[N], n;
bool cheak(int E)
{
	for (int i = 0; i < n; i++)
	{
		E = E * 2 - h[n];
		if (E >= 1e5)
		{
			return true;
		}
		if (E < 0)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> h[n];
	}

	int l = 0;
	int j = 1e5;
	while (l < j)
	{
		int mid = (l + j) >> 1;
		if (cheak(mid)) j = mid;
		else l = mid + 1;
	}
	cout << j;
	return 0;
}