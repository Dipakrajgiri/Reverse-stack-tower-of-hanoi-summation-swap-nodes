#include <iostream>
using namespace std;
class stack
{
public:
    int top;
    int maxSize;
    int *array;
    void reversestack();
    void buttompush(int temp);
    stack(int max)
    {
        top = -1;
        maxSize = max;
        array = new int[max];
    }

    bool isFull()
    {

        return (top == maxSize - 1);
    }

    bool isEmpty()
    {

        return (top == -1);
    }

    void push(int item)
    {
        if (!isFull())
        {
            top++;
            array[top] = item;
        }
        else
        {
            cout << "stack is full cannot push\n";
        }
    }

    int pop()
    {

        if (!isEmpty())
        {
            return array[top--];
        }
        else
        {
            cout << "stack is empty cannot pop\n";
            return array[top];
        }
    }

    int peek()
    {

        if (!isEmpty())
        {
            return array[top];
        }
        else
        {
            cout << "stack is empty cannot pop\n";
            return array[top];
        }
    }

    void displayStack()
    {
        if (isEmpty())
        {
            cout << "stack is empty!\n";
        }
        else
        {
            cout << "\nStack: ";
            for (int i = 0; i <= top; i++)
                cout << array[i] << " ";
            cout << "\n";
        }
    }
};
void stack::buttompush(int temp)
{
    int t;
    if (isEmpty())
    {
        push(temp);
    }
    else
    {
        t = pop();
        buttompush(temp);
        push(t);
    }
}
void stack::reversestack()
{
    int temp;
    temp = pop();
    if (isEmpty())
    {
        push(temp);
    }
    else
    {
        reversestack();
        buttompush(temp);
    }
}
int main()
{
    int size, val;
    cout << "enter the size of stack\n";
    cin >> size;
    stack s(size);
    cout << "enter the elements to stack\n";
    for (int i = 0; i < size; i++)
    {
        cin >> val;
        s.push(val);
    }
    cout << "stack before reverse";
    s.displayStack();
    cout << "stack after reversed";
    s.reversestack();
    s.displayStack();
    return 0;
    
}
