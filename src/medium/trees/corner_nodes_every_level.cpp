//
// Created by shyamnath on 5/13/21.
//
#include <iostream>
#include <memory>
#include <map>
#include <vector>

typedef std::map<int, std::vector<int>> mapVec;

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

mapVec levelMap;

void levelOrder(std::shared_ptr<Node> current, int h) {

    if(current == nullptr)
        return;

    levelMap[h].emplace_back(current->data);

    levelOrder(current->left, h + 1);
    levelOrder(current->right, h + 1);
}

int main()
{
    /* Construct the following tree
                 1
               /   \
              2     3
            /     /   \
           4     5     6
         /     /   \     \
        7     8     9     10
    */

    auto root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->right->left = newNode(5);
    root->right->right = newNode(6);
    root->left->left->left = newNode(7);
    root->right->left->left = newNode(8);
    root->right->left->right = newNode(9);
    root->right->right->right = newNode(10);

    levelOrder(root, 0);
    auto newMap = levelMap;
    int test = 0;
}