//
// Created by shyamnath on 5/13/21.
//
#include <iostream>
#include <memory>

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

bool checkSumTree(std::shared_ptr<Node> current)
{
    if (current == nullptr)
        return true;

    int leftData = 0, rightData = 0;
    if (current->left != nullptr)
        leftData = current->left->data;

    if (current->right != nullptr)
        rightData = current->right->data;

    if (current->data != leftData + rightData)
        return false;

    bool leftTree = checkSumTree(current->left);
    bool rightTree = checkSumTree(current->right);

    return leftTree and rightTree;
}


int makeSumTree(std::shared_ptr<Node> current)
{
    if (current == nullptr)
        return 0;

    if (current->left == nullptr and current->right == nullptr) {
        auto temp = current->data; current->data = 0;
        return temp;
    }

    int leftData = makeSumTree(current->left);
    int rightData = makeSumTree(current->right);

    int tmp = current->data;
    current->data = leftData + rightData;

    return current->data + tmp;
}

int main()
{
    auto root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(4);
    root->right->left = newNode(5);
    root->right->right = newNode(6);
    root->right->left->left = newNode(7);
    root->right->left->right = newNode(8);

    int test = makeSumTree(root);
    int test1 = checkSumTree(root);
}