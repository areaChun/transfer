/*From leetcode && 牛客网
时间限制：1秒 空间限制：32768K 热度指数：72433

题目描述
Given a binary tree, find its minimum depth.\
The minimum depth is the number of nodes along the shortest path from \
the root node down to the nearest leaf node.


如果不用递归，则采用queue，每次记住每层的开始节点后最后一个节点（queue.size()，或者queue.back()），
来增加层数就好了。遇到叶子节点就return。
      a            a
    /            /   \
   b            b     c
                       \
                         d
     (1)           (2)

采用递归则需要注意，(2)只需要判断left和right的深度哪个最小就好了，
但是(1)的a节点只有一个left的深度2，不能直接左右判断最小，这是最初考虑欠缺的地方。
所有要增加代码：
if(root->left==NULL||root->right==NULL)
            return depth_left+depth_right+1;


*/



class Solution {
public:
    int run(TreeNode *root) {
        if(root==NULL)
            return 0;
        int depth_left=run(root->left);
        int depth_right=run(root->right);
        if(root->left==NULL||root->right==NULL)
            return depth_left+depth_right+1;
        return (depth_left<depth_right)?depth_left+1:depth_right+1;
    }
};