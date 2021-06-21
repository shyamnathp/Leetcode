//
// Created by shyamnath on 5/13/21.
//
#include <iostream>
#include <memory>
#include <vector>

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

std::vector<int> rightNodes;

void right_view(std::shared_ptr<Node> current, bool right)
{
    if(current == nullptr)
        return;

    if(right)
        std::cout<<current->data;

    right_view(current->right, true);
    right_view(current->left, false);
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

    std::cout<<root->data;
    right_view(root->right, true);
}
