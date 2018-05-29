/** From leeCode && 牛客网
时间限制：1秒 空间限制：32768K 热度指数：17805

题目描述：
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree{1,#,2,3},

   1
    \
     2
    /
   3

return[1,2,3].

Note: Recursive solution is trivial, could you do it iteratively?

 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*
note: 遍历的节点push_back进vector，若左右子树非NULL，右子树左子树先后压栈。
*/
//非递归
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> val;
        if(!root)
            return val;
        stack<TreeNode*> node;
        node.push(root);
        while(node.size()){
            TreeNode* temp=node.top();
            node.pop();
            val.push_back(temp->val);
            if(temp->right)
                node.push(temp->right);
            if(temp->left)
                node.push(temp->left);
             
        }
        return val;
    }
};


//递归
class Solution {
public:
    void preorderTraversal(TreeNode *root,vector<int>& val){
        if(!root)
            return;
        val.push_back(root->val);
        preorderTraversal(root->left,val);
        preorderTraversal(root->right,val);
    }
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> val;
        preorderTraversal(root,val);
        return val;
    }
};