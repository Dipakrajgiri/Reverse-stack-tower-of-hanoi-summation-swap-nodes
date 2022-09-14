#  Stack Reverse

##  Stack
Stack is a linear data structure which follows a particular order in which the operations are performed. The order may be LIFO(Last In First Out) or FILO(First In Last Out).

##  Stack Reverse
This task can done by two ways,
<li>By using another stack</li>
<li>By the help of recursion</li>
Here i have used recursion to reverse the stack

**Algorithm:**
```
Reverse stack of n sized stack is equivalent to:Reverse stack of  size n-1 stack and the top element at buttom of the n-1 stack.
```
**Code:**
```
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
```
To push the top element at the buttom again i have used recursiom

**Algorithm:**
```
To insert an Element at the buttom of n sized stack is equivalent to insert at the buttom of n-1 sized stack and push the top element which was taken out to make the stack n-1.
```
**Code:**
```

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
```
**Result:**
```
enter the size of stack
5
enter the elements to stack
1
2
3
4
5
stack before reverse
Stack: 1 2 3 4 5    
stack after reversed
Stack: 5 4 3 2 1    
```



