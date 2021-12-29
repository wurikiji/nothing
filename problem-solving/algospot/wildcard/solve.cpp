#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isMatching(const string &pattern, int pStart, const string &file, int fStart);

int main()
{
	int c;
	ios_base::sync_with_stdio(false);
	cin >> c;
	while (c--)
	{
		string pattern;
		cin >> pattern;
		int n;
		cin >> n;
		vector<string> answer;
		while (n--)
		{
			string file;
			cin >> file;
			if (isMatching(pattern, 0, file, 0))
			{
				answer.push_back(file);
			}
		}
		sort(answer.begin(), answer.end());
		for (auto &file : answer)
		{
			cout << file << endl;
		}
	}

	return 0;
}

// can be memoized as visited[101][101]
bool isMatching(const string &pattern, int pStart, const string &file, int fStart)
{
	if (pStart == pattern.size())
	{
		if (fStart == file.size())
		{
			return true;
		}
		return false;
	}
	if (fStart == file.size() && pattern[pStart] != '*')
	{
		return false;
	}

	if (pattern[pStart] == '*')
	{
		// can be divided into two sub routines
		// 		isMatching(pattern, pStart, file, fStart + 1) || isMatching(pattern, pStart + 1, file, fStart)
		for (; fStart <= file.size(); ++fStart)
		{
			if (isMatching(pattern, pStart + 1, file, fStart))
			{
				return true;
			}
		}
	}
	else if (pattern[pStart] == '?' || pattern[pStart] == file[fStart])
	{
		return isMatching(pattern, pStart + 1, file, fStart + 1);
	}
	return false;
}