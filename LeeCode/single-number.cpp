/*
时间限制：1秒 空间限制：32768K 热度指数：15063
本题知识点： 复杂度 leetcode

题目描述

Given an array of integers, every element appears twice except for one. Find that single one.

Note: 
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

/*
Note:用异或直接将出现两次的位给消掉

*/

class Solution {
public:
    int singleNumber(int A[], int n) {
        if(n<=0)
            return 0;
        int single=0;
        for(int i=0;i<n;i++)
            single^=A[i];
        return single;
    }
};