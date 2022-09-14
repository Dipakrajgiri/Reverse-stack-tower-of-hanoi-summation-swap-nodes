#  Tower Of Hanoi
The Tower of Hanoi (also called The problem of Benares Temple or Tower of Brahma or Lucas' Tower and sometimes pluralized as Towers, or simply pyramid puzzle) is a mathematical game or puzzle consisting of three rods and a number of disks of various diameters, which can slide onto any rod. The puzzle begins with the disks stacked on one rod in order of decreasing size, the smallest at the top, thus approximating a conical shape. The objective of the puzzle is to move the entire stack to the last rod, obeying the following rules:

Only one disk may be moved at a time.
Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack or on an empty rod.
No disk may be placed on top of a disk that is smaller than it.
With 3 disks, the puzzle can be solved in 7 moves. The minimal number of moves required to solve a Tower of Hanoi puzzle is 2<sup>n</sup> − 1, where n is the number of disks.

## Solution 
To get the solution i have used the recurtion as moving the n rings from source to destination is same as first moving the (n-1) rings to intermediate(i.e indermesiate will act as destination and destination will act as intermediate for this process) and then moving n<sup>th</sup> ring to destination and then moving new set of rings i.e n-1 for which source is intermediate and intermediate is source.

In program i have used three stacks for representing three towers and the algorithm below is appied.

**Algorithm:**

<ol>
<b> To solve n ringed tower of hanoi problem following steps are followed, </b>
<li>move n-1 rings to intermediate i.e for n-1 rings our destination is actual intermediate and actual destination is intermediate</li>
<li>move nth ring to destination</li>
<li>now we get n-1th ring problem for which our source is actual intermdiate and actual intermediate is source</li>
</ol>

**Code:**
```
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
    toh(n - 1, intermediate, destination, source, s, p, d);
}
```
 
**Result:**
```
Enter a number
3
tower A:  3 2 1 
tower B:  
tower C:  
Move disk 1 from tower A to tower C
tower A:  3 2
tower B:
tower C:  1
Move disk 2 from tower A to tower B
tower A:  3
tower B:  2
tower C:  1
Move disk 1 from tower C to tower B
tower A:  3
tower B:  2 1
tower C:
Move disk 3 from tower A to tower C
tower A:
tower B:  2 1
tower C:  3
Move disk 1 from tower B to tower A
tower A:  1
tower B:  2
tower C:  3
Move disk 2 from tower B to tower C
tower A:  1
tower B:
tower C:  3 2
Move disk 1 from tower A to tower C
tower A:
tower B:
tower C:  3 2 1
```