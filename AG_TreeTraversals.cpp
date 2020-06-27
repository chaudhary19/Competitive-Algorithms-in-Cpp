#include<bits/stdc++.h>
using namespace std;

#define int long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl "\n"

struct Node
{
    int data;
    struct Node *left, *right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    } 
};

void PrintInorder(struct Node* node)
{
    if(node == NULL)
        return;
    
    PrintInorder(node->left);
    cout<<node->data<<" ";
    PrintInorder(node->right);
}

void PrintPreOrder(struct Node* node)
{
    if(node == NULL)
        return;
    
    cout<<node->data<<" ";
    PrintPreOrder(node->left);
    PrintPreOrder(node->right);
}

void PrintPostOrder(struct Node* node)
{
    if(node == NULL)
        return;
    PrintPostOrder(node->left);
    PrintPostOrder(node->right);
    cout<<node->data<<" ";

}

int32_t main()
{
    
}

