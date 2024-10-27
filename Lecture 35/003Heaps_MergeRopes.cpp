/*

    There are given n ropes of different lengths, we need to connect these ropes into one rope.
    The cost to connect two ropes is equal to the sum of their lengths. We need to connect the
    ropes with minimum cost.

    Example :

    Input : {4, 3, 2, 6}
    Output: 29

*/

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int findMinCost(const vector<int>& ropeLengths) {

    // priority_queue<int, vector<int>, greater<int>> minHeap;
    // for(int i=0; i<ropeLengths.size(); i++) {
    //     minHeap.push(ropeLengths[i]);
    // }

    priority_queue<int, vector<int>, greater<int>> minHeap(ropeLengths.begin(), ropeLengths.end());

    int total = 0;

    while (minHeap.size() > 1) {

        // take out two smallest ropes from the minHeap

        int fs = minHeap.top(); minHeap.pop();
        int ss = minHeap.top(); minHeap.pop();

        // merge them

        total += fs + ss;

        // add the merged to the minHeap

        minHeap.push(fs + ss);

    }

    return total;

}

int main() {

    vector<int> ropeLengths = {4, 3, 2, 6};

    cout << findMinCost(ropeLengths) << endl;

    return 0;
}