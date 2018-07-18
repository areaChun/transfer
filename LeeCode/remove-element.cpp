/*
时间限制：1秒 空间限制：32768K 热度指数：5433
本题知识点： 数组 leetcode
 算法知识视频讲解
题目描述

Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.


*/

/*
Note:
没人吐槽这坑爹的测试样例嘛。。
输入:[1,2,3,4],1
输出:[4,2,3],3

一个Index指向elem值，一个指向非elem值

		i    		n
		|			|
		1	2	3	4	

*/
class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        for(int i=0; i<n; ++i) {
            if(A[i] == elem) {
                while(n>i && A[--n] == elem);
                A[i] = A[n];
            }
        }
        return n;
    }
};