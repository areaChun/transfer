/*leecode && 牛客网
时间限制：1秒 空间限制：32768K 热度指数：5254
本题知识点： 数组 leetcode
 算法知识视频讲解
题目描述

Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array A =[1,1,1,2,2,3],

Your function should return length =5, and A is now[1,1,2,2,3].
*/

/*
Note:因为超过两个的删除，而且是有序的数组，那就判断第三个位置index及其对应的i是否等于index-2，若等于则shift跳过，不等则复制到Index

     index-2     index          i
		—————————
		|		|               |
		1	1	1	1	1	1	2	2	3

         index-2     index          i
		    —————————
		    |		|               |
		1	1	2	1	1	1	2	2	3

*/


class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n <= 2)
            return n;
        int index=2;
        for(int i=2;i<n;i++){
            if(A[i]!=A[index-2]) A[index++]=A[i];
        }
        return index;
    }
};

