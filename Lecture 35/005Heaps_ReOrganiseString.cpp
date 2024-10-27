
#include<iostream>
#include<queue>
#define pqmax priority_queue<pair<int, char>>
using namespace std;

void printHeap(pqmax maxHeap) {
    while (!maxHeap.empty()) {
        pair<int, char> p = maxHeap.top(); maxHeap.pop();
        cout << p.first << " " << p.second << endl;
    }
}

string reorganise(const string& str) {

    int freqMap[26] = {0};
    for (char ch : str) {
        freqMap[ch - 'a']++;
    }

    // for (int i = 0; i < 26; i++) {
    //     cout << freqMap[i] << " ";
    // }

    // cout << endl;

    pqmax maxHeap;

    for (int i = 0; i < 26; i++) {
        if (freqMap[i] > 0) {
            maxHeap.push({freqMap[i], i + 'a'});
        }
    }

    printHeap(maxHeap);

    string ans = "";

    while (!maxHeap.empty()) {

        if (maxHeap.size() == 1) {

            pair<int, char> fmax = maxHeap.top();
            maxHeap.pop();

            if (fmax.first > 1) {
                ans = "";
            } else {
                ans += fmax.second;
            }

        } else {

            pair<int, char> fmax = maxHeap.top();
            maxHeap.pop();

            pair<int, char> smax = maxHeap.top();
            maxHeap.pop();

            ans += fmax.second;
            fmax.first--;

            ans += smax.second;
            smax.first--;

            if (fmax.first > 0) {
                maxHeap.push(fmax);
            }

            if (smax.first > 0) {
                maxHeap.push(smax);
            }

        }

    }

    return ans;

}

int main() {

    string str = "aaaaaabbbc";

    cout << reorganise(str) << endl;

    return 0;
}