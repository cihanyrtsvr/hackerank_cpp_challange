#include <deque>
#include <iostream>
#include <vector>

using namespace std;

void printKMax(int arr[], int n, unsigned int k) {
  deque<int> subarray;
  for (int i = 0; i < n; i++) {

    if(!subarray.empty() && subarray.front()==i-k){
        subarray.pop_front();
    }
    while(!subarray.empty() &&arr[subarray.back()]<arr[i]){
        subarray.pop_back();
    }

    subarray.push_back(i);

    if(i>= k-1){
        cout<<arr[subarray.front()]<<" ";
    }

    
  }
  cout << endl;
}

int main() {

  int t;
  cin >> t;
  while (t > 0) {
    int n, k;
    cin >> n >> k;
    int i;
    int arr[n];
    for (i = 0; i < n; i++)
      cin >> arr[i];
    printKMax(arr, n, k);
    t--;
  }
  return 0;
}