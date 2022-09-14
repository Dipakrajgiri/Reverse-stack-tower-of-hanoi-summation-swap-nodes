#include <iostream>
#include <string.h>
#include <cmath>
using namespace std;
class linked_list
{
public:
    int value;
    linked_list *next;
};
linked_list *head = NULL;
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
void createlist(int val)
{
    linked_list *newnode, *ptr;
    newnode = new linked_list;
    newnode->value = val;
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
int main()
{
    char ch[20];
    linked_list *ptr;
    int len, lent, sum = 0, val;
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
    ptr = head;
    while (ptr != NULL)
    {
        sum = sum + ptr->value;
        ptr = ptr->next;
    }
    cout << "sum=" << sum;
    return 0;
}