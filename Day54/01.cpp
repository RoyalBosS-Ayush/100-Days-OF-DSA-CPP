#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class node
{
public:
    int data;
    int row;
    int col;

    node(int d, int i, int j)
    {
        this->data = d;
        this->row = i;
        this->col = j;
    }
};

class greaterNode
{
public:
    bool operator()(node *a, node *b)
    {
        return a->data > b->data;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>> &kArrays, int k)
{
    vector<int> ans;
    priority_queue<node *, vector<node *>, greaterNode> minHeap;

    for (int i = 0; i < k; i++)
    {
        node *temp = new node(kArrays[i][0], i, 0);
        minHeap.push(temp);
    }

    while (minHeap.size() > 0)
    {
        node *temp = minHeap.top();
        minHeap.pop();

        ans.push_back(temp->data);

        int i = temp->row;
        int j = temp->col;

        if (kArrays[i].size() > j + 1)
        {
            node *next = new node(kArrays[i][j + 1], i, j + 1);
            minHeap.push(next);
        }
    }
    return ans;
}

// https://www.codingninjas.com/codestudio/problems/merge-k-sorted-arrays_975379