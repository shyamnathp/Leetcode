//
// Created by shyamnath on 6/11/21.
//
//Given an integer n, return all the structurally unique BST's (binary search trees), which has exactly n nodes of unique values from 1 to n. Return the answer in any order.
//

#include <vector>

struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

std::vector<TreeNode*> findTreesNodes(int start, int end)
{
    std::vector<TreeNode*> res;

    if(start>end)
    {
        res.emplace_back(nullptr);
        return res;
    }
    else if (start==end)
    {
        res.emplace_back(new TreeNode(start));
    }

    std::vector<TreeNode*> left, right;
    for (int i = start; i < end; ++i) {
        left = findTreesNodes(start, i-1);
        right = findTreesNodes(i+1, end);

        for (auto& lnode: left) {
            for(auto& rnode : right)
            {
                TreeNode* root = new TreeNode(i);
                root->left = lnode;
                root->right = rnode;
                res.push_back(root);
            }
        }
    }

    return res;
}

int main()
{
    int n=3;
    std::vector<TreeNode*> nodes;
//    if (n==0)
//        return std::vector<TreeNode*> ();
//    return findTreesNodes(1,n);
}