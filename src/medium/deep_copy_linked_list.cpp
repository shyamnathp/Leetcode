//
// Created by shyamnath on 6/13/21.
//
//A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.
//
//Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.
//
//For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.
//
//Return the head of the copied linked list.
//
//The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:
//
//val: an integer representing Node.val
//        random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
//Your code will only be given the head of the original linked list.
//

#include <iostream>
#include <vector>

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

int main()
{
    auto root = new Node(7);
    root->next = new Node(13);
    root->next->next = new Node(11);
    root->next->next->next = new Node(10);
    root->next->next->next->next = new Node(1);
    root->next->random = root;
    root->next->next->next->random =  root->next->next;
    root->next->next->next->next->random = root;
    root->next->next->random =  root->next->next->next->next;

    auto current = root;
    auto deepRoot = new Node(root->val);
    auto deepCurrent = deepRoot;

    std::vector<Node*> nextNodes;
    while (current != nullptr)
    {
        if (current->next != nullptr)
            deepCurrent->next = new Node(current->next->val);
        else
            deepCurrent->next = nullptr;
        deepCurrent->random = current;
        nextNodes.emplace_back(current->next);
        auto temp = current->next;
        current->next = deepCurrent;

        current = temp;
        deepCurrent = deepCurrent->next;
    }

    deepCurrent = deepRoot;

    while (deepCurrent != nullptr)
    {
        if ( deepCurrent->random->random != nullptr)
            deepCurrent->random = deepCurrent->random->random->next;
        else
            deepCurrent->random = nullptr;
        deepCurrent=deepCurrent->next;
    }

   //correct the original list
    current=root;
    for(auto& node: nextNodes)
    {
        current->next = node;
        current=current->next;
    }

    int test = 0;

}