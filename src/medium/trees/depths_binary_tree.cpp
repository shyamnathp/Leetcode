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

int minimum_height(std::shared_ptr<Node> current, int h) {
    if(current == nullptr)
        return h - 1;

    int leftDepth = minimum_height(current->left, h + 1);
    int rightDepth = minimum_height(current->right, h + 1);

    return (leftDepth>rightDepth) ? leftDepth : rightDepth;
}

int height(std::shared_ptr<Node> current, int h) {

    if(current == nullptr)
        return h - 1;

    int leftDepth = height(current->left, h + 1);
    int rightDepth = height(current->right, h + 1);

    return (leftDepth<rightDepth) ? leftDepth : rightDepth;
}


int main()
{
    auto root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->left->left->right = newNode(8);
    root->left->right->right = newNode(9);
    root->right->right->left = newNode(10);
    root->right->right->left = newNode(11);
    root->left->left->right->right = newNode(12);

    int h=1;
    auto depth = height(root, h);
    h = 1;
    depth = minimum_height(root, h);

}

