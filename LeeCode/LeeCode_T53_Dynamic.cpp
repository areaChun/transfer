#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;

/*******T53. 最大子序和*********/

int maxSubArray(vector<int>& nums) {
	int aSum=0;
	
	int max = 0x80000000;
	for (vector<int>::iterator pBegin = nums.begin(); pBegin != nums.end(); pBegin++) {
		/***修改后运行速率提升10ms***/
		aSum = (aSum + (*pBegin)) > (*pBegin)? (*pBegin) + aSum:(*pBegin);

		//if (aSum <= 0) {
		//	aSum = *pBegin;
		//}
		//else {
		//	aSum += *pBegin;
		//}
		if (max < aSum)
			max = aSum;
		
	}
	return max;
}

int main()
{
	int n[9] = { -2,1,-3,4,-1,2,1,-5,4 };
	vector<int> nums;
	
	for (int i = 0; i < 9; i++) {
		nums.push_back(n[i]);
	}
	cout<<maxSubArray(nums);
	int c;
	cin >> c;
    return 0;
}