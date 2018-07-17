/* leecode&&牛客网
时间限制：1秒 空间限制：32768K 热度指数：4058
本题知识点： 数组 leetcode
 算法知识视频讲解
题目描述

You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?
*/


/*
Note:大神其他思路写法:做两次翻转，先沿右上-左下的对角线翻转，再沿水平中线上下翻转
如：
		1	2    ------->   4	2	-------->	3	1
		3	4				3	1				4	2

*/


//做两次翻转，先沿右上-左下的对角线翻转，再沿水平中线上下翻转
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        //对角线翻转
        const int n = matrix.size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n - i; j++)
                swap(matrix[i][j], matrix[n-1-j][n-1-i]);
        for (int i = 0; i < n/2; i++)
            for (int j = 0; j < n; j++)
                swap(matrix[i][j],matrix[n-1-i][j]);
    }
};





/*
Note:另外的升级版：每次一次性每条边对应的数字对调
		如：1--3--9--7
            2--6--8--4
*/

//层层旋转
public class Solution {
    public void rotate(int[][] matrix) {
        int n=matrix.length;
        int temp=0;
        for(int i=0;i<n/2;i++){
            for(int j=i;j<n-1-i;j++){
                temp=matrix[i][j];
                matrix[i][j]=matrix[n-j-1][i];
                matrix[n-j-1][i]= matrix[n-i-1][n-j-1];
                matrix[n-i-1][n-j-1]=matrix[j][n-i-1];
                matrix[j][n-i-1]=temp;
            }
        }
      return;
    }
}


/*
Note:自己拐角写法：每次矩阵每条边的一整列/行将一整行/列进行复制

		················
		·   ···········|····
		·       ·······|···|····
        1	2	3·······   |   |
        4	5	6···········   |
        7	8	9···············   


*/
#include <math.h>
class Solution {
public:
void rotate(vector<vector<int> > &matrix) {
	if (matrix.size() <= 1)
		return;
	int n = matrix.size();
	int middle = int(ceil((float(n) / 2.0)));
	for (int i = 0; i<middle; i++) {
		int width = i, height = i;
		int* temp = new int[n];
		for (int j = i; j<n - i; j++) {
			*(temp + j) = matrix[n - 1 - j][n - 1 - i];
			matrix[n - 1 - j][n - 1 - i] = matrix[i][n - 1 - j];
		}
		for (int j = n - i - 1; j>i - 1; j--) {
			matrix[i][j] = matrix[n - 1 - j][i];
		}
		for (int j = n - i - 1; j>i - 1; j--) {
			matrix[n-1-j][i] = matrix[n - 1 - i][n-1-j];
		}
		for (int j = i; j<n - i; j++) {
			matrix[n - 1 - i][j] = *(temp + j);
		}
	}
}
};