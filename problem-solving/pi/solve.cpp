#include <cstring>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
using namespace std;

const long long maxDifficulty = 10000 * 11;

int checkLevelFive(string& num, int start, int length) {
  int gapExpect = num[start] - num[start + 1];
  for (int i = 0; i < length - 1; ++i) {
    int gap = num[start + i] - num[start + i + 1];
    if (gap != gapExpect) {
      return 10;
    }
  }
  return 5;
}
int checkLevelFour(string& num, int start, int length) {
  int gapExpect = num[start] - num[start + 1];
  for (int i = 0; i < length - 1; ++i) {
    int gap = num[start + i] - num[start + i + 1];
    if (gap != gapExpect) {
      return checkLevelFive(num, start, length);
    }
    gapExpect = -gapExpect;
  }
  return 4;
}
int checkLevelTwo(string& num, int start, int length) {
  int gap = num[start] - num[start + 1];
  for (int i = 0; i < length - 1; ++i) {
    if (gap * gap != 1 || gap != num[start + i] - num[start + i + 1]) {
      return checkLevelFour(num, start, length);
    }
  }
  return 2;
}
int checkLevel(string& num, int start, int length) {
  for (int i = 0; i < length - 1; ++i) {
    if (num[start + i] - num[start + i + 1] != 0) {
      return checkLevelTwo(num, start, length);
    }
  }
  return 1;
}
int getDifficulty(string& num, int start, int length) {
  if (start + length > num.size()) {
    return maxDifficulty;
  }
  int difficulty = checkLevel(num, start, length);
  return difficulty;
}
int solve(string& num, vector<long long>& difficulty, int start) {
  if (start == num.size()) return 0;
  long long& dif = difficulty[start];
  if (dif != maxDifficulty) {
    return dif;
  }

  dif = maxDifficulty;

  for (int i = 3; i <= 5; i++) {
    long long tempDif = getDifficulty(num, start, i);
    if (tempDif != maxDifficulty) {
      dif = min(dif, tempDif + solve(num, difficulty, start + i));
    }
  }

  return dif;
}

int main() {
  int c;
  cin >> c;
  while (c--) {
    string num;
    cin >> num;
    vector<long long> difficulty(num.size() + 1, maxDifficulty);
    cout << solve(num, difficulty, 0) << "\n";
  }
  return 0;
}