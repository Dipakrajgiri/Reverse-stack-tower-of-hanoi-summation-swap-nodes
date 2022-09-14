# Summation Report

## Linked lists

  A linked list is a linear collection of data elements whose order is not given by their physical placement in memory. Instead, each element points to the next. It is a data structure consisting of a collection of nodes which together represent a sequence.
  ### Node 
    Node is an object which contains the data for that node and location to the next node.


## Problem:
To read the numbers from user untill **x** is not encountered and finally print the sum.

**Algorithm:**
<ol>
<li>Taking input untill X is not encountered </li>
<li>Creating nodes for each numbers and storing them in linked lists . </li>
<li>Finally adding the values to each nodes and printing sum.</li>
<li>Replacing next of each other. </li>
</ol>

**Code:**
<ol>
<li>

```
//Taking Inputs
 while (1)
    {
    again:
        val = 0;
        cout << "Enter number to add and x to stop\n";
        cin >> ch;
        len = strlen(ch) - 1;
        lent = strlen(ch);
        if (ch[0] == 'x' && ch[1] == '\0')
        {
            break;
        }
        for (int i = 0; i < lent; i++)
        {
            if (ch[i] >= '0' && ch[i] <= '9')
            {
                val = val + ((ch[i] - '0')) * pow(10, len);
                len--;
            }
            else
            {
                goto again;
            }
        }
        createlist(val);
    }

```
</li>
<li>

```
//Finding Sum
 while (ptr != NULL)
    {
        sum = sum + ptr->value;
        ptr = ptr->next;
    }
```
</li>
</ol>

**Result:**
```

Enter number to add and x to stop
1
Enter number to add and x to stop
2
Enter number to add and x to stop
3
Enter number to add and x to stop
xdfd
Enter number to add and x to stop
4
Enter number to add and x to stop
x
sum=10
```
