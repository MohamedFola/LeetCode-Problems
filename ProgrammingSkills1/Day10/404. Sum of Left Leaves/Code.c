/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int isLeaf(struct TreeNode* root)
{
    if(root == NULL)
    {
        return 0;
    }
    
    if(root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    
    return 0;
}

int sumOfLeftLeaves(struct TreeNode* root)
{

    int result = 0;
    
    if(root != NULL)
    {
        if(isLeaf(root->left))
        {
            result += root->left->val;
        }
        else
        {
            result += sumOfLeftLeaves(root->left);
        }
        
        result += sumOfLeftLeaves(root->right);
    }
    
    
    return result;
}