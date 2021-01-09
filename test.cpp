#include <iostream>
#include "linkedlist.cpp"

using namespace std;

int main()
{
    Node * head;

    print(head);
    cout << "\nSize: " << size(head) << endl;

    head = removeIdx(head, 0);

    print(head);
    cout << "\nSize: " << size(head) << endl;

    return 0;
}