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
    Node *head;
    Node *tail;

public:
    List()
    {
        head = tail = nullptr;
    }

    void push_front(int val)
    {
        Node *newNode = new Node(val);
        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int val)
    {
        Node *newNode = new Node(val);

        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop_front()
    {

        Node *temp = head;
        if (head == nullptr)
        {
            cout << "list is empty";
            return;
        }
        if (head == tail)
        {
            delete head;
            head = tail = nullptr;
        }
        else
        {
            head = head->next;
            temp->next = nullptr;
            delete temp;
        }
    }

    void pop_back()
    {
        if (!head)
        {

            return;
        }
        if (head == tail)
        {
            delete tail;
            head = tail = nullptr;
        }

        else
        {
            Node *temp = head;
            while (temp->next != tail)
            {
                temp = temp->next;
            }
            temp->next = nullptr;
            delete tail;
            tail = temp;
        }
    }
    void printList()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void InsertAtMiddle(int pos, int val)
    {
        Node *newNode = new Node(val);
        if (pos < 0)
        {
            cout << "invalid" << endl;
            return;
        }
        if (pos == 0)
        {
            push_front(val);
            return;
        }

        Node *temp = head;

        for (int i = 0; i < pos - 1; i++)
        {
            if (temp == NULL)
            {
                cout << "list is empty";
            }
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }
    int getSizeOfList()
    {
        int cnt = 0;
        Node *curr = head;
        while (curr != nullptr)
        {
            cnt++;
            curr = curr->next;
        }
        return cnt;
    }
    // int sizeofLinkedListRecursion(Node *head)
    // {
    //     if (head == nullptr)
    //     {
    //         return 0;
    //     }

    //     return 1+ sizeofLinkedListRecursion(head->next) ;
    // }
    void reverse()
    {
        Node *prev = nullptr;
        Node *curr = head;
        Node *next = nullptr;
        tail = head;
        while (curr != nullptr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

bool Search(int target) { 
    
}

    ~List()
    {
        while (head != nullptr)
        {
            pop_front();
        }
    }
};

int main()
{
    List ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);
    // ll.pop_back() ;
    // ll.pop_front();
    ll.push_front(6);

    ll.printList();
    ll.reverse();
    // ll.MiddleLinkedList();
    ll.printList();
    cout << "size : " << ll.getSizeOfList() << endl;
    ll.InsertAtMiddle(1, 9);
    ll.printList();
    cout << "size : " << ll.getSizeOfList() << endl;
}
