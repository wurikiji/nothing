#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

void solve(vector<int> &input, vector<int> &solution, int last) {
  for (int i = 0; i < last; ++i) {
    if (input[i] < input[last]) {
      solution[last] = max(solution[last], solution[i] + 1);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  int c;
  cin >> c;
  while (c--) {
    int n;
    cin >> n;
    vector<int> input(n, 0);
    vector<int> solution(n, 0);
    for (int i = 0; i < n; ++i) {
      cin >> input[i];
      solution[i] = 1;
      solve(input, solution, i);
    }
    int answer = -1;
    for (int i = 0; i < solution.size(); ++i) {
      answer = max(answer, solution[i]);
    }
    cout << answer << "\n";
  }

  return 0;
}
