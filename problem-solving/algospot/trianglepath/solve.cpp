#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct Node {
  int sum;
  int level;
  int index;
  Node(int sum, int level, int index) : sum{sum}, level{level}, index{index} {}
  bool operator<(const Node& node) const { return sum < node.sum; }
};

bool isInBound(int level, int index) { return index >= 0 && index <= level; }

int maximum[101][101];
int arr[101][101];
int n;

int main() {
  ios_base::sync_with_stdio(false);
  int c;
  cin >> c;
  while (c--) {
    cin >> n;
    memset(maximum, -1, sizeof(maximum));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j <= i; ++j) {
        cin >> arr[i][j];
      }
    }
    Node node{arr[0][0], 0, 0};
    int answer = -1;
    queue<Node> pq;
    pq.push(node);
    while (!pq.empty()) {
      node = pq.front();
      pq.pop();

      if (node.level == n - 1) {
        answer = max(answer, node.sum);
        continue;
      }

      int nLevel = node.level + 1;

      for (int i = 0; i <= 1; ++i) {
        int index = node.index + i;
        int newSum = node.sum + arr[nLevel][index];
        int& maximumCache = maximum[nLevel][index];
        if (isInBound(nLevel, index) &&
            (maximumCache == -1 || maximumCache < newSum)) {
          maximumCache = newSum;
          pq.push(Node{newSum, nLevel, index});
        }
      }
    }
    cout << answer << endl;
  }
  return 0;
}