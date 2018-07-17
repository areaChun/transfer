/*leecode 

题目描述
Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note: 
You are not suppose to use the library's sort function for this problem.

click to show follow up.

Follow up: 
A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.

Could you come up with an one-pass algorithm using only constant space?

*/

/*
Note：参考的一个方法

设置3个变量，分别代表数组前部zeroindex，当前遍历的位置 i，数组后部 twoindex
①当A[i] = 0时，必然属于数组前部，则交换A[i] 和 A[zeroindex] ,接着i++ , zeroindex++
②当A[i] = 1时，只需i++就好，因为只有排好了0和2,1自然就只能在中间了，故不作处理
③当A[i] = 2时，不然属于数组后部，则交换A[i]和A[twoindex]，接着twoindex--，不过此时就不能i++了因为，交换过去的A[i]有可能是0或者2，所以需要在下一个循环里判断，这样它的位置才能够正确
*/
class Solution {
public:
    void sortColors(int A[], int n) {
        int zeroindex = 0;
        int twoindex  = n - 1;
        int i = 0;
        while(i < twoindex + 1)
        {
            if(A[i] == 0)
            {
                swap(A[i],A[zeroindex]);
                zeroindex++;
                i++;
            }
            else if(A[i]==2)
            {
                swap(A[i],A[twoindex]);
                twoindex--;
            }
            else
                i++;
        }
    }
};



/*
Note:开始的方法是技术排序，记录1,2的个数，然后重写数组
*/
class Solution {
public:
    void sortColors(int A[], int n)
    {
        int* count=new int[3]{0,0,0};
          
        for(int i=0;i<n;++i)
        {
            if(A[i]==0)
                count[0]++;
            else if(A[i]==1)
                count[1]++;
            else
                count[2]++;
        }
          
        int index=0;
        for(int i=0;i<count[0];++i)
            A[index++]=0;
         for(int i=0;i<count[1];++i)
            A[index++]=1;
         for(int i=0;i<count[2];++i)
            A[index++]=2;
    }
};