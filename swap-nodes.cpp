#include <iostream>
using namespace std;
class linked_list
{
public:
    int value;
    linked_list *next;
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
            }
            else
            {
                ptr = head;
                while (ptr->next != NULL)
                {
                    ptr = ptr->next;
                }
                ptr->next = newnode;
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
    if (node1 == head || node2 == head)
    {
         if(node2==head)
        {
            node2=node1;
            node1=head;
        }
        head = node2;
        pre2->next = node1;
        ptr = node1->next;
        node1->next = node2->next;
        node2->next = ptr;
        return;
    }
    else
    {
        pre1->next = node2;
        pre2->next = node1;
        ptr = node1->next;
        node1->next = node2->next;
        node2->next = ptr;
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

/*


#include <iostream>
using namespace std;
class linked_list
{
public:
    int value;
    linked_list *next;
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
            }
            else
            {
                ptr = head;
                while (ptr->next != NULL)
                {
                    ptr = ptr->next;
                }
                ptr->next = newnode;
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

void swapnodes()
{
    int val, var;
    linked_list *ptr, *qtr, *str;
    if (head == NULL)
    {
        cout << "no swap process can executed" << endl;
        return;
    }
    if (head->next == NULL)
    {
        cout << "no swap process can executed" << endl;
        return;
    }
    cout << "enter 1 for swap at begning" << endl
         << "enter 2 for swap at end" << endl
         << "enter 3 to swap with previous node" << endl
         << "enter 4 for swap with next node" << endl;
    cin >> var;
    switch (var)
    {
    case 1:
        ptr = head->next;
        head->next = ptr->next;
        ptr->next = head;
        head = ptr;
        break;
    case 2:
        ptr = head->next;
        if (ptr->next == NULL)
        {
            head->next = ptr->next;
            ptr->next = head;
            head = ptr;
        }
        else
        {
            ptr = head;
            while (ptr->next != NULL)
            {
                str = qtr;
                qtr = ptr;
                ptr = ptr->next;
            }
            str->next = ptr;
            ptr->next = qtr;
            qtr->next = NULL;
        }
        break;
    case 3:
        cout << "enter the value of the node\n";
        cin >> val;
        ptr = head;
        str = head;
        qtr = head;
        while (ptr->value != val)
        {
            str = qtr;
            qtr = ptr;
            ptr = ptr->next;
        }
        str->next = ptr;
        qtr->next = ptr->next;
        ptr->next = qtr;
        break;
    case 4:
        cout << "enter the value of the node\n";
        cin >> val;
        ptr = head;
        str = head;
        qtr = head;
        while (qtr->value != val)
        {
            str = qtr;
            qtr = ptr;
            ptr = ptr->next;
        }
        str->next = ptr;
        qtr->next = ptr->next;
        ptr->next = qtr;

        break;
    default:
        break;
    }
}
void swap()
{
    int val1, val2;
    linked_list *node1 = head, *node2 = head, *pre1, *pre2,*ptr;
    if (head == NULL || head->next == NULL)
    {
        cout << "no swap process can executed" << endl;
        return;
    }
    cout << "enter the values to the nodes to swap";
    cin >> val1, val2;
    while (node1->value != val1)
    {
        pre1=node1;
        node1 = node1->next;
    }
    while (node2->value != val2)
    {
        pre2=node2;
        node2 = node2->next;
    }
    pre1=node2;
    pre2=node1;
    node1->next=ptr;
    node1->next=node2->next;
    node2->next=ptr;


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
            swapnodes();
            break;
        case 3:
            display();
            break;
        case 4:
            swap();
            break;
        case 5:
            exit(0);
        default:
            break;
        }
    }
} */