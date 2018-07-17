/* leecode&&牛客网
时间限制：1秒 空间限制：32768K 热度指数：4520
本题知识点： 数组 leetcode
 算法知识视频讲解
题目描述

Given an unsorted integer array, find the first missing positive integer.

For example,
Given[1,2,0]return3,
and[3,4,-1,1]return2.

Your algorithm should run in O(n) time and uses constant space.

/*
Note:基于计数排序
对0,1,2,...,n范围内的数把他放到对应的下标处。比如对于元素i放到下标i-1处，然后对数组从前往后遍历，找到第一个不匹配的，即是最小缺失正数。
while 很重要~~！是把数字一直换到正确的位置上为止。(若交换后A[i]与下标不对应，则继续交换)

最开始忽略O(1)的空间复杂度，结果新建了n的数组，用hash的方法来把A[i]映射到坐标i上。

*/




class Solution {
public:
    int firstMissingPositive(int A[], int n) {
    for(int i=0;i<n;i++)
        while(A[i]>0 && A[i]<=n && A[i]!=A[A[i]-1])
            swap(A[i],A[A[i]-1]);
    for(int i=0;i<n;i++){
        if(A[i]-1!=i)
            return i+1;
    }
    return n+1;
    }
};