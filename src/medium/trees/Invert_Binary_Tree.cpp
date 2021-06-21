//
// Created by shyamnath on 5/13/21.
//
#include <iostream>
#include <memory>
#include <tuple>

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

void invert(std::shared_ptr<Node> current)
{
    if(current->left == nullptr) {
        current->left = current->right;
        return;
    }
    else if(current->right == nullptr) {
        current->right = current->left;
        return;
    }

    auto tmp = current->left;
    std::tie(current->left, current->right) = std::tie(current->right, tmp);

    invert(current->left);
    invert(current->right);
}


int main()
{
    /* Construct the following tree
          1
        /   \
       /     \
      2       3
     / \     / \
    4   5   6   7
*/

    auto root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->right->right = newNode(8);

    invert(root);
    int test = 1;

}