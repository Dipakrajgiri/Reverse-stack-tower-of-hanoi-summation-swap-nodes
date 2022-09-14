
#include <iostream>
using namespace std;
#include <iostream>
using namespace std;
class stack
{
public:
    int top;
    int maxSize;
    int *array;

    stack()
    {
    }
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
    }

    int pop()
    {

        if (!isEmpty())
        {
            return array[top--];
        }
        else
        {
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
            return array[top];
        }
    }

    void displayStack(char ch)
    {
        char tower;
        if (isEmpty())
        {
            cout << "tower " << ch << ":  " << endl;
        }
        else
        {
            cout << "tower " << ch << ":  ";
            for (int i = 0; i <= top; i++)
                cout << array[i] << " ";
            cout << "\n";
        }
    }
    friend void toh(int n, char source, char destination, char intermediate, stack &s, stack &p, stack &d);
};

void toh(int n, char source, char destination, char intermediate, stack &s, stack &p, stack &d)
{
    int var;
    if (n == 0)
    {
        return;
    }
    toh(n - 1, source, intermediate, destination, s, p, d);
    cout << "Move disk " << n << " from tower " << source
         << " to tower " << destination << endl;
    if (source == 'A')
    {
        var = s.pop();
    }
    if (source == 'B')
    {
        var = p.pop();
    }
    if (source == 'C')
    {
        var = d.pop();
    }
    if (destination == 'A')
    {
        s.push(var);
    }
    if (destination == 'B')
    {
        p.push(var);
    }
    if (destination == 'C')
    {
        d.push(var);
    }
    s.displayStack('A');
    p.displayStack('B');
    d.displayStack('C');
    toh(n - 1, intermediate, destination, source, s, p, d);
}
int main()
{
    int n;
    cout << "Enter a number\n";
    cin >> n;
    stack s(n), p(n), d(n);
    for (int i = n; i >= 1; i--)
    {
        s.push(i);
    }
    s.displayStack('A');
    p.displayStack('B');
    d.displayStack('C');
    toh(n, 'A', 'C', 'B', s, p, d);
    return 0;
}
