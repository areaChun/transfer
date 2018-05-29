/**From leecode && 牛客网
时间限制：1秒 空间限制：32768K 热度指数：27255

题目描述

Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree{1,#,2,3},

   1
    \
     2
    /
   3

return[3,2,1].

Note: Recursive solution is trivial, could you do it iteratively?
*/

/*
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*
note:
开始的想法只用一个函数递归，但该函数无法传递vector，所以只能每次递归回溯都将左子树和右子树的
遍历vector进行拼接，在Push_back上中间节点。
参考别人后，在声明一个和穿入vector的函数来递归，那就跟很普通的左子数右子树递归完在push_back中间节点就好了。

而非递归巧妙的方法：前序遍历 根->左->右 变成 根->右->左 结果再reverse一下变成 左—>右->根，逆思维。

*/


//递归（修改后）：
class Solution {
public:
    void postorderTraversal(TreeNode *root, vector<int> &val){
        if(root!=NULL){
        postorderTraversal(root->left,val);
        postorderTraversal(root->right,val);
        val.push_back(root->val);
        }
    }
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> val;
        postorderTraversal(root,val);
        return val;
    }
};

//递归

class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> leftVec,rightVec;
        if(root==NULL)
            return leftVec;
        if(root->left!=NULL){
            leftVec = postorderTraversal(root->left);
            //leftVec.insert(leftVec.end(),leftVec.begin(),leftVec.end()); 
        }
        if(root->right!=NULL){
            rightVec = postorderTraversal(root->right);
            leftVec.insert(leftVec.end(),rightVec.begin(),rightVec.end()); 
        }
        leftVec.push_back(root->val);
        return leftVec;
        
    }
};




//非迭代：

class Solution {
public:
     vector<int> postorderTraversal(TreeNode *root){
        vector<int> val;
        if(root==NULL)
            return val;
        stack<TreeNode*> node;
        node.push(root);
        while(node.size()){
            TreeNode* temp = node.top();
            node.pop();
            val.push_back(temp->val);
            if(temp->left)
                node.push(temp->left);
            if(temp->right)
                node.push(temp->right);
        }
        reverse(val.begin(),val.end());
        return val;
    }
};