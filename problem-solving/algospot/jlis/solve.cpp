#include <cstring>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;

int jlis[201][201];

int solve(vector<int>& a, vector<int>& b, int aStart, int bStart) {
  int& lis = jlis[aStart + 100][bStart + 100];
  if (lis != -1) {
    return lis;
  }
  long long target =
      (aStart != -1) ? a[aStart] : numeric_limits<long long>::lowest();
  target = max(
      target, (bStart != -1) ? b[bStart] : numeric_limits<long long>::lowest());

  lis = 0;

  for (int i = aStart + 1; i < a.size(); ++i) {
    if (target < a[i]) {
      lis = max(lis, 1 + solve(a, b, i, bStart));
    }
  }
  for (int j = bStart + 1; j < b.size(); ++j) {
    if (target < b[j]) {
      lis = max(lis, 1 + solve(a, b, aStart, j));
    }
  }
  return lis;
}

int main() {
  ios_base::sync_with_stdio(false);
  int c;
  cin >> c;

  while (c--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    memset(jlis, -1, sizeof(jlis));
    for (auto& in : a) {
      cin >> in;
    }
    for (auto& in : b) {
      cin >> in;
    }
    solve(a, b, -1, -1);

    int answer = -1;
    for (int i = 0; i <= n + 100; ++i) {
      for (int j = 0; j <= m + 100; ++j) {
        answer = max(answer, jlis[i][j]);
      }
    }
    cout << answer << "\n";
  }

  return 0;
}