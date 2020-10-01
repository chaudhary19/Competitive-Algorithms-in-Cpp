#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define endl "\n"

// Floyd Cycle Detection
class Node {
public:
    int data;
    Node* next;
};
 
bool detectLoop(Node* head)
{
    Node *slow = head, *fast = head;
    while (slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) 
        {
            return true;
        }
    }
    return false;
}
 
int32_t main()
{
    IOS
    Node * head = NULL;
    Node * second = NULL;
    head = new Node();
    second = new Node();
    head->data = 1;
    head->next = second;
    second-> data = 2;
    second-> next = head;          // creating a loop
    if (detectLoop(head))
        cout << "Loop detected";
    else
        cout << "No Loop detected";
}
