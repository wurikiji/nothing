#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

// find lower bound
int findPosition(vector<int> &lis, int input) {
  int left = 1;
  int right = lis.size() - 1;
  while (left < right) {
    int mid = (left + right) / 2;
    if (lis[mid] == -1 || lis[mid] > input) {
      right = mid;
    } else if (lis[mid] == input) {
      return mid;
    } else {
      left = mid + 1;
    }
  }
  return left;
}

void solve(vector<int> &lis, int input) {
  int position = findPosition(lis, input);
  if (lis[position] == -1 || lis[position] > input) {
    lis[position] = input;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  int c;
  cin >> c;
  while (c--) {
    int n;
    cin >> n;
    vector<int> lis(n + 1, -1);
    for (int i = 0; i < n; ++i) {
      int tmp;
      cin >> tmp;
      solve(lis, tmp);
    }
    int answer = -1;
    for (int i = n; i >= 0; --i) {
      if (lis[i] != -1) {
        cout << i << "\n";
        break;
      }
    }
  }

  return 0;
}
