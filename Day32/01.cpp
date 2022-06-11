class NStack
{
    int *arr;
    int *top;
    int *next;
    int n, s, freeSpot;

public:
    // Initialize your data structure.
    NStack(int N, int S)
    {
        arr = new int[S];
        top = new int[N];
        next = new int[S];
        freeSpot = 0;
        n = N;
        s = S;

        // top initialise
        for (int i = 0; i < n; i++)
        {
            top[i] = -1;
        }

        // next initialise
        for (int i = 0; i < s; i++)
        {
            next[i] = i + 1;
        }
        next[s - 1] = -1;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        // Write your code here.
        if (freeSpot == -1)
        {
            return false;
        }

        int index = freeSpot;     // find index
        arr[index] = x;           // insert element
        freeSpot = next[index];   // update freespot
        next[index] = top[m - 1]; // update next
        top[m - 1] = index;       // update top

        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        if (top[m - 1] == -1)
            return -1;

        int index = top[m - 1];
        top[m - 1] = next[index];
        next[index] = freeSpot;
        freeSpot = index;

        return arr[index];
    }
};

// https://www.codingninjas.com/codestudio/problems/n-stacks-in-an-array_1164271