#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;

/****T70. 爬楼梯*****/

int climbStairs(int n) {
	int* step = new int[n+1];
	step[0] = 0, step[1] = 1,step[2]=2;
	for (int i = 3; i <=n; i++) {
		step[i] = step[i - 2] + step[i - 1];
	}
	return step[n];

}

int main()
{
	cout << climbStairs(6);
	int c;
	cin >> c;

	return 0;
}