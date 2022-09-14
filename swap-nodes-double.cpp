#include <iostream>
using namespace std;
class linked_list
{
public:
    int value;
    linked_list *next, *previous;
};
linked_list *head = NULL;
void createlist()
{
    int var;
    linked_list *newnode, *ptr;
    head = NULL;
    while (1)
    {
        cout << "enter 1 to add node" << endl
             << "enter 2 to end the process" << endl;
        cin >> var;
        if (var == 1)
        {
            newnode = new linked_list;
            cout << "enter the value\n";
            cin >> newnode->value;
            newnode->next = NULL;
            if (head == NULL)
            {
                head = newnode;
                newnode->previous = NULL;
            }
            else
            {
                ptr = head;
                while (ptr->next != NULL)
                {
                    ptr = ptr->next;
                }
                ptr->next = newnode;
                newnode->previous = ptr;
            }
        }
        else if (var == 2)
        {
            break;
        }
        else
        {
            continue;
        }
    }
}

void swap()
{
    int val1, val2;
    linked_list *node1 = head, *node2 = head, *pre1 = head, *pre2 = head, *ptr;
    if (head == NULL || head->next == NULL)
    {
        cout << "no swap process can executed" << endl;
        return;
    }
    cout << "enter the values to the nodes to swap\n";
    cin >> val1 >> val2;
    if (val1 == val2)
    {
        return;
    }
    while (node1->value != val1)
    {
        pre1 = node1;
        node1 = node1->next;
    }
    while (node2->value != val2)
    {
        pre2 = node2;
        node2 = node2->next;
    }
    if (node1->next == node2 || node2->next == node1)
    {
        if (node2->next == node1)
        {
            ptr = node2;
            node2 = node1;
            node1 = ptr;
        }
        if (node2->next == NULL)
        {
            if (node1 == head)
            {
                head = node2;
                node2->next = node1;
                node1->previous = node2;
                node1->next = NULL;
                node2->previous = NULL;
            }
            else
            {
                node1->previous->next=node2;
                node2->previous=node1->previous;
                node1->next=NULL;
                node1->previous=node2;
                node2->next=node1;

            }
        }
        else if (node1 == head)
        {
            node1->next = node2->next;
            node1->previous = node2;
            node2->next->previous = node1;
            node2->next = node1;
            node2->previous = NULL;
            head = node2;
        }
        else
        {
            node2->next->previous=node1;
            node1->previous->next=node2;
            node1->next=node2->next;
            node2->previous=node1->previous;
            node1->previous=node2;
            node2->next=node1;
        }
    }
    else
    {
        if ((node1 == head && node2->next == NULL) || (node2 == head && node1->next == NULL))
        {
            if (node2 == head && node1->next == NULL)
            {
                node2 = node1;
                node1 = head;
            }
            head = node2;
            node2->previous->next = node1;
            node1->next->previous = node2;
            node1->previous = node2->previous;
            node2->previous = NULL;
            node2->next = node1->next;
            node1->next = NULL;
            return;
        }
        if (node1 == head || node2 == head)
        {
            if (node2 == head)
            {
                node2 = node1;
                node1 = head;
            }
            head = node2;
            node2->previous->next = node1;
            node1->next->previous = node2;
            node2->next->previous = node1;
            node1->previous = node2->previous;
            node2->previous = NULL;
            ptr = node1->next;
            node1->next = node2->next;
            node2->next = ptr;
        }
        else if (node1->next == NULL || node2->next == NULL)
        {
            if (node2->next == NULL)
            {
                ptr = node2;
                node2 = node1;
                node1 = ptr;
            }
            node1->previous->next = node2;
            node2->previous->next = node1;
            node2->next->previous = node1;
            ptr = node1->previous;
            node1->previous = node2->previous;
            node2->previous = ptr;
            node1->next = node2->next;
            node2->next = NULL;
        }
        else
        {
            node1->previous->next = node2;
            node2->previous->next = node1;
            node1->next->previous = node2;
            node2->next->previous = node1;
            ptr = node1->previous;
            node1->previous = node2->previous;
            node2->previous = ptr;
            ptr = node1->next;
            node1->next = node2->next;
            node2->next = ptr;
        }
    }
}

void display()
{
    linked_list *ptr;
    if (head == NULL)
    {
        printf("\nList is empty\n");
        return;
    }
    else
    {
        ptr = head;
        printf("\nThe List elements are:\n");
        while (ptr != NULL)
        {
            printf("%d\t", ptr->value);
            ptr = ptr->next;
        }
        cout << endl;
    }
}
int main()
{
    int var;
    while (1)
    {
        cout << "enter 1 for create list" << endl
             << "enter 2 for swap nodes" << endl
             << "enter 3 for display" << endl
             << "enter 4 for exit" << endl;
        cin >> var;
        switch (var)
        {
        case 1:
            createlist();
            break;
        case 2:
            swap();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            break;
        }
    }
}
