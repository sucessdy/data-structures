#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class List
{

public:
    Node *reverseList(Node *head)
    {
        Node *curr = head;
        Node *next = nullptr;
        Node *prev = nullptr;
        while (curr != nullptr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    Node *middleLinked(Node *head)
    {
        Node *slow = head;
        Node *fast = head;
        do {
             slow = slow->next;
            fast = fast->next->next;

        }while (fast != nullptr && fast->next != nullptr) ; 
        
        
        // while (fast != nullptr && fast->next != nullptr)
        // {
        //     slow = slow->next;
        //     fast = fast->next->next;
        // }
        return slow;
    }

    void PrintList(Node *head)
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "null" << endl;
    }
};

int main()
{
    List ll;
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    ll.PrintList(head) ;
    // Node *result = ll.reverseList(head);
    // ll.PrintList(result);

 Node *res = ll.middleLinked(head);
    ll.PrintList(res);

    return 0;
}