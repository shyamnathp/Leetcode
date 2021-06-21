//
// Created by shyamnath on 5/3/21.
//
#include <iostream>
#include <memory>
#include <algorithm>

struct Node
{
    int data;
    std::shared_ptr<Node> left = nullptr;
    std::shared_ptr<Node> right = nullptr;
    Node(int data)
    {
        this->data = data;
    }
};

std::shared_ptr<Node> newNode(int data)
{
    return std::make_shared<Node>(data);
}

int maxPathSum(std::shared_ptr<Node> root, int& res)
{
 if(root == nullptr)
     return 0;

 if(!root->left && !root->right)
     return root->data;

 int ls = maxPathSum(root->left, res);
 int rs = maxPathSum(root->right, res);

 if (root->left and root->right) {
     res = std::max(res, ls+rs+root->data);
     return std::max(ls, rs) + root->data;
 }

 return (!root->left)? rs + root->data: ls + root->data;
}


int main()
{
    auto root = newNode(-15);
    root->left = newNode(5);
    root->right = newNode(6);
    root->left->left = newNode(-8);
    root->left->right = newNode(1);
    root->left->left->left = newNode(2);
    root->left->left->right = newNode(6);
    root->right->left = newNode(3);
    root->right->right = newNode(9);
    root->right->right->right= newNode(0);
    root->right->right->right->left= newNode(4);
    root->right->right->right->right= newNode(-1);
    root->right->right->right->right->left= newNode(10);

    int res=0;
    maxPathSum(root, res);

    int test = 0;
}
