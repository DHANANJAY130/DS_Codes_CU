#include <iostream>
using namespace std;
void create(int);
void display();
void insertafter(int, int);
struct node1
{
    int data;
    node1 *next;
};
class LinkedList
{
private:
    node1 *start;

public:
    LinkedList()
    {
        start = NULL;
    }
    void create(int data)
    {
        node1 *ptr;
        node1 *newnode = new node1;
        newnode->data = data;
        if (start == NULL)
        {
            newnode->next = NULL;
            start = newnode;
        }
        else
        {
            ptr = start;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = newnode;
            newnode->next = NULL;
        }
    }
    void insertafter(int before_num, int num)
    {
        node1 *ptr;
        ptr = start;
        node1 *newnode = new node1;
        newnode->data = num;
        while (ptr->data != before_num)
        {
            ptr = ptr->next;
        }
        newnode->next = ptr->next;
        ptr->next = newnode;
    }
    void display()
    {
        node1 *ptr;
        ptr = start;
        while (ptr != NULL)
        {
            cout << '\t' << ptr->data;
            ptr = ptr->next;
        }
    }
};
int main()
{
    LinkedList l;
    int data;
    int before_num, inp, n;
    cout << "Enter no. of nodes: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> data;
        l.create(data);
    }
    cout << "Linked List before Insertion: ";
    l.display();
    cout << "\nEnter position and Number to be inserted: ";
    cin >> before_num >> inp;

    l.insertafter(before_num, inp);

    cout << "\nLinked List after insertion" << endl;
    l.display();
}