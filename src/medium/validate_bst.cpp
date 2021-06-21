//
// Created by shyamnath on 5/9/21.
//
#include <iostream>
#include <vector>

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool validity(TreeNode* current)
{
    if (current == nullptr)
        return true;

    //if (current->left== nullptr && current->right== nullptr)
    //    return true;

    if(current->right != nullptr and not (current->right->val > current->val))
        return false;
    else if(current->left != nullptr and not (current->left->val < current->val))
        return false;

    bool left = validity(current->left);
    bool right = validity(current->right);

    return left and right;;
}

int main()
{
 TreeNode* root= new TreeNode(5);
 root->left = new TreeNode(4);
 root->right = new TreeNode(6);
 root->right->left = new TreeNode(3);
 root->right->right = new TreeNode(7);
//TreeNode* root= new TreeNode(2);
//root->left = new TreeNode(1);
//root->right = new TreeNode(3);
 if (validity(root))
     std::cout<<"True";
 else
     std::cout<<"False";
}