//
// Created by shyamnath on 5/13/21.
//
#include <iostream>
#include <memory>
#include <vector>
#include <map>

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

mapVec verticalOrder;

void fillVertical(std::shared_ptr<Node> current, int column)
{
    if(current == nullptr)
        return;

    verticalOrder[column].emplace_back(current->data);

    fillVertical(current->left, column - 1);
    fillVertical(current->right, column + 1);
}


int main()
{
    auto root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->right->left = newNode(5);
    root->right->right = newNode(6);
    root->right->left->left = newNode(7);
    root->right->left->right = newNode(8);
    root->right->left->right->left = newNode(9);
    root->right->left->right->right = newNode(10);

    fillVertical(root, 0);
    for(const auto& [i, vec]: verticalOrder)
    {
        for(const auto& values: vec)
        {
            std::cout<<values;
        }
        std::cout<<"\n";
    }
}