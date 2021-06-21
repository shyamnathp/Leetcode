//
// Created by shyamnath on 6/14/21.
//

struct TreeNode {
    int val;
    TreeNode  *left;
    TreeNode  *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool sameTree(TreeNode* t1, TreeNode* t2)
{
    if (t1 == nullptr or t2==nullptr)
    {
        if(t1==nullptr and t2==nullptr)
            return true;
        else
            return false;
    }

    if(t1->val != t2->val)
        return false;

    bool left = sameTree(t1->left, t2->left);
    bool right = sameTree(t1->right, t2->right);

    return left and right;
}

sameTree(root->left, root->right);
