#include<iostream>

using namespace std;

void incr(int& ref) {
  ref++;
}

// void incr(int* ptr) {
//   (*ptr)++;
// }

int main() {
  int a = 0;
  incr(a);
  // incr(&a); // passing addr by value
  cout << a << endl;
  return 0;
}