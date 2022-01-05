#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

long long calculateMinVar(vector<int>& v, int start, int end) {
  long long var = 0;
  for (int i = start; i <= end; ++i) {
    var += v[i];
  }
  var = (double)var / (end - start + 1) + 0.5;
  long long ret = 0;
  for (int i = start; i <= end; ++i) {
    int tmp = v[i] - var;
    ret += tmp * tmp;
  }
  return ret;
}

long long solve(vector<int>& v, vector<vector<long long>>& minVar, int start,
                int group) {
  if (start == v.size()) {
    return 0;
  }
  if (group == 0) {
    return -1;
  }

  long long& var = minVar[start][group];
  if (var != -1) {
    return var;
  }
  var = numeric_limits<long long>::max();
  for (int i = start; i < v.size(); ++i) {
    long long tempVar = calculateMinVar(v, start, i);
    long long nextVar = solve(v, minVar, i + 1, group - 1);

    if (nextVar != -1 && nextVar != numeric_limits<long long>::max()) {
      var = min(var, tempVar + nextVar);
    }
  }
  return var;
}

int main() {
  ios_base::sync_with_stdio(false);
  int c;
  cin >> c;
  while (c--) {
    int n, s;
    cin >> n >> s;
    vector<int> v(n);
    vector<vector<long long>> minVar(n + 1, vector<long long>(s + 1, -1));
    for (auto& in : v) {
      cin >> in;
    }
    sort(v.begin(), v.end());
    cout << solve(v, minVar, 0, s) << '\n';
  }
  return 0;
}