// mine.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
typedef vector<char>array1;
typedef vector<array1>array2;
int Count(array2*a, int l, int r, int m, int n, int count)//恩
{
	if ((*a)[l][r] == '*')return count;
	if (1)//((*a)[l][r] == '#')
	{
		if (r - 1 >= 0 && (*a)[l][r - 1] == '#')(*a)[l][r - 1] = count;
		else if (r - 1 >= 0 && (*a)[l][r - 1] != '#' && (*a)[l][r - 1] != '*')
		{
			(*a)[l][r] = count;
			return count;
		}
		if (r + 1 < n && (*a)[l][r + 1] == '#')(*a)[l][r + 1] = count;
		else if (r + 1 < n && (*a)[l][r + 1] != '#' && (*a)[l][r + 1] != '*')
		{
			(*a)[l][r] = count;
			return count;
		}
		if (l + 1 < n && (*a)[l + 1][r] == '#')(*a)[l + 1][r] = count;
		else if (l + 1 < n && (*a)[l + 1][r] != '#' && (*a)[l + 1][r] != '*')
		{
			(*a)[l][r] = count;
			return count;
		}
		if (l - 1 >= 0 && (*a)[l - 1][r] == '#')(*a)[l - 1][r] = count;
		else if (l - 1 >= 0 && (*a)[l - 1][r] != '#' && (*a)[l - 1][r] != '*')
		{
			(*a)[l][r] = count;
			return count;
		}
		if (l - 1 >= 0 && r - 1 >= 0 && (*a)[l - 1][r - 1] == '#')(*a)[l - 1][r - 1] = count;
		else if (l - 1 >= 0 && r - 1 >= 0 && (*a)[l - 1][r - 1] == '#' && (*a)[l - 1][r - 1] == '*')
		{
			(*a)[l][r] = count;
			return count;
		}
		if (l + 1 < n&&r - 1 >= 0 && (*a)[l + 1][r - 1] == '#')(*a)[l + 1][r - 1] = count;
		else if (l + 1 < n&&r - 1 >= 0 && (*a)[l + 1][r - 1] == '#' && (*a)[l + 1][r - 1] == '*')
		{
			(*a)[l][r] = count;
			return count;
		}
		if (l - 1 >= 0 && r + 1 < n && (*a)[l - 1][r + 1] == '#')(*a)[l - 1][r + 1] = count;
		else if (l - 1 >= 0 && r + 1 < n && (*a)[l - 1][r + 1] == '#' && (*a)[l - 1][r + 1] == '*')
		{
			(*a)[l][r] = count;
			return count;
		}
		if (l + 1 < n&&r + 1 < n && (*a)[l + 1][r + 1] == '#')(*a)[l + 1][r + 1] = count;
		else if (l + 1 < n&&r + 1 < n && (*a)[l + 1][r + 1] == '#' && (*a)[l + 1][r + 1] == '*')
		{
			(*a)[l][r] = count;
			return count;
		}

		if (((*a)[l][r] == '#'))count++;
		(*a)[l][r] = count;
	}
	return count;
}
int main()
{
	int n;
	cin >> n;
	array2*Mine = new array2;
	Mine->resize(n);
	for (int i = 0; i < n; i++)
	{
		(*Mine)[i].resize(n);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> (*Mine)[i][j];
		}
	}
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			count = Count(Mine, i, j, n, n, count);
		}
	}
	cout << count << endl;
	return 0;
}


