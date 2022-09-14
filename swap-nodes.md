# Swap_nodes Reoprt

## Linked lists

  A linked list is a linear collection of data elements whose order is not given by their physical placement in memory. Instead, each element points to the next. It is a data structure consisting of a collection of nodes which together represent a sequence.
  ### Node 
    Node is an object which contains the data for that node and location to the next node.

## Swapping Nodes
Swapping is the process of changing the position of two nodes with each others position.For this we have two ways ,
<ol>
   <li>By replacing the values of nodes.</li>
   <li>By replacing thier actual position in te list.</li>
  </ol>

## Swaping by relpacing actual position of nodes in singly Linked Lists

**Algorithm:**
<ol>
<li>Finding the nodes to swap in the list. </li>
<li>Finding the previous nodes of the swaping nodes. </li>
<li>Replacing next of previous node of each other </li>
<li>Replacing next of each other </li>
</ol>

**Code:**
```
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

```
## Swaping by relpacing actual position of nodes in Doubly Linked Lists

**Algorithm:**
<ol>
<li>Finding the nodes to swap in the list. </li>
<li>Finding the previous nodes of the swaping nodes. </li>
<li>Replacing next of previous node of each other </li>
<li>Replacing previous of next node of each other </li>
<li>Replacing next and previos of each other </li>
</ol>

**Code:**
```
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

```
**Results:**

1.Singly Linked List

```
enter 1 for create list
enter 2 for swap nodes
enter 3 for display
enter 4 for exit
1
enter 1 to add node
enter 2 to end the process
1
enter the value
1
enter 1 to add node
enter 2 to end the process
1
enter the value
2
enter 1 to add node
enter 2 to end the process
1
enter the value
3
enter 1 to add node
enter 2 to end the process
2
enter 1 for create list
enter 2 for swap nodes
enter 3 for display
enter 4 for exit
3

The List elements are:
1       2       3
enter 1 for create list
enter 2 for swap nodes
enter 3 for display
enter 4 for exit
2
enter the values to the nodes to swap
1
2
enter 1 for create list
enter 2 for swap nodes
enter 3 for display
enter 4 for exit
3

The List elements are:
2       1       3
enter 1 for create list
enter 2 for swap nodes
enter 3 for display
enter 4 for exit
2
enter the values to the nodes to swap
1
3
enter 1 for create list
enter 2 for swap nodes
enter 3 for display
enter 4 for exit
3

The List elements are:
2       3       1
enter 1 for create list
enter 2 for swap nodes
enter 3 for display
enter 4 for exit
4
```
1.Doubly Linked List
```
enter 1 for create list
enter 2 for swap nodes 
enter 3 for display    
enter 4 for exit       
1
enter 1 to add node
enter 2 to end the process
1
enter the value
1
enter 1 to add node
enter 2 to end the process
1
enter the value
2
enter 1 to add node
enter 2 to end the process
1
enter the value
3
enter 1 to add node
enter 2 to end the process
2
enter 1 for create list
enter 2 for swap nodes
enter 3 for display
enter 4 for exit
3

The List elements are:
1       2       3
enter 1 for create list
enter 2 for swap nodes
enter 3 for display
enter 4 for exit
2
enter the values to the nodes to swap
1
2
enter 1 for create list
enter 2 for swap nodes
enter 3 for display
enter 4 for exit
3

The List elements are:
2       1       3
enter 1 for create list
enter 2 for swap nodes
enter 3 for display
enter 4 for exit
2
enter the values to the nodes to swap
1
3
enter 1 for create list
enter 2 for swap nodes
enter 3 for display
enter 4 for exit
3

The List elements are:
2       3       1
enter 1 for create list
enter 2 for swap nodes
enter 3 for display
enter 4 for exit
4
```