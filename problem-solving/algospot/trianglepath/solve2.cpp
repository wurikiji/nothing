#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int arr[102][102];
int n;

int main() {
  ios_base::sync_with_stdio(false);
  int c;
  cin >> c;
  while (c--) {
    cin >> n;
    memset(arr, 0, sizeof(arr));
    int answer = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j <= i; ++j) {
        int tmp;
        cin >> tmp;
        tmp += arr[i][j];
        answer = max(answer, tmp);
        arr[i + 1][j] = max(arr[i + 1][j], tmp);
        arr[i + 1][j + 1] = max(arr[i + 1][j + 1], tmp);
      }
    }
    cout << answer << endl;
  }
  return 0;
}