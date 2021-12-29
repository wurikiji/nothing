#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void fillInGender(vector<int> &v, string line);
int solve(vector<int> &member, vector<int> &fans);
int main()
{
	ios_base::sync_with_stdio(false);
	int c;
	cin >> c;
	while (c--)
	{
		vector<int> members;
		vector<int> fans;
		string temp;
		cin >> temp;
		fillInGender(members, temp);
		cin >> temp;
		fillInGender(fans, temp);
		cout << solve(members, fans) << endl;
	}
	return 0;
}
int solve(vector<int> &members, vector<int> &fans)
{
	// find same sequences from both
	int ret = 0;
	for (int i = 0; i <= fans.size() - members.size(); i++)
	{
		int j = 0;
		for (; j < members.size(); j++)
		{
			if (fans[i + j] == 1 && members[j] == 1)
			{
				break;
			}
		}
		if (j == members.size())
		{
			ret++;
		}
	}
	return ret;
}

void fillInGender(vector<int> &v, string line)
{
	for (auto &s : line)
	{
		int genderNo = 0;
		if (s != 'F')
		{
			genderNo = 1;
		}
		v.push_back(genderNo);
	}
}