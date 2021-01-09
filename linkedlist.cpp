#include <iostream>

using namespace std;

class Node
{
    public:
        int data;
        Node * next;
};

// Method signatures.
int size(Node * head);
Node * insert(Node * head, int data);
Node * remove(Node * head, int data);
Node * removeIdx(Node * head, int idx);
int print(Node * head);

// Function that returns the number of nodes in a list.
int size(Node * head)
{
    // Size counter starts at -1 to offset the "empty" root node.
    int cur_size = -1;
    Node * tmp = head;

    // Simple loop through list.
    while(tmp != nullptr)
    {
        cur_size++;
        tmp = tmp->next;
    }

    return cur_size;
}

// Function that inserts a node at the end of the list.
Node * insert(Node * head, int data)
{
    Node * new_node = new Node();

    Node * tmp = head;

    // Case: empty list.
    if (tmp == nullptr)
    {
        tmp->data = data;
        tmp->next = new_node;

        return head;
    }

    // Case: not empty list.
    while (tmp->next != nullptr)
        tmp = tmp->next;

    new_node->data = data;

    tmp->next = new_node;

    return head;
}

Node * remove(Node * head, int data)
{
    Node * tmp = head;

    // Case: removing head.
    if (tmp->data == data)
    {
        Node * trash_node = tmp;
        tmp = tmp->next;

        delete trash_node;
        return tmp;
    }

    // Case: removing not head.
    while (tmp->next != nullptr)
    {
        if (tmp->next->data == data)
        {
            Node * trash_node = tmp->next;
            tmp->next = tmp->next->next;

            delete trash_node;
            return head;
        }
        tmp = tmp->next;
    }

    // Case: didn't find node to remove.
    return head;
}

Node * removeIdx(Node * head, int idx)
{
    Node * tmp = head;

    // Case: removing head.
    if (tmp->next != nullptr && idx == 0)
    {
        Node * trash_node = tmp->next;
        tmp->next = tmp->next->next;

        delete trash_node;
        return tmp;
    }

    // Case: removing not head.
    int counter = 0;
    while (tmp->next != nullptr)
    {
        if (counter == idx)
        {
            Node * trash_node = tmp->next;
            tmp->next = tmp->next->next;

            delete trash_node;
            return head;
        }
        counter++;
        tmp = tmp->next;
    }

    // Case: didn't find node to remove.
    return head;
}

int print(Node * head)
{
    Node * tmp = head->next;

    cout << "{";

    if (tmp != nullptr)
    {
        cout << tmp->data;
        tmp = tmp->next;
    }

    while (tmp != nullptr)
    {
        cout << ", " << tmp->data;
        tmp = tmp->next;
    }

    cout << "}" << endl;

    return 0;
}