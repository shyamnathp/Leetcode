//
// Created by shyamnath on 5/21/21.
//
#include <iostream>
#include <map>

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* findNthNode(ListNode* current, int n)
{
    std::map<int, ListNode*> listmap;
    int i=1;
    while(current != nullptr)
    {
        listmap[i] = current;
        current=current->next;
        ++i;
    }

    int len= listmap.size();
    ListNode* prevNode = nullptr;
    if ((len-n) > 0)
        prevNode = listmap[len-n];

    ListNode* nextNode= nullptr;
    if ((len-n+2) <= len)
        nextNode = listmap[len-n+2];

    if (prevNode!= nullptr) {
        prevNode->next = nextNode;
        return listmap[1];
    }
    else
        return listmap[2];
}


int main()
{
    ListNode* root = new ListNode(1);
    int n = 1;
//    root->next = new ListNode(2);
//    root->next->next = new ListNode(3);
//    root->next->next->next = new ListNode(4);
//    root->next->next->next->next = new ListNode(5);

    if (root->next == nullptr and n==1)
       auto test = nullptr;

    newhead = findNthNode(root, n);
    int test = 1;
}