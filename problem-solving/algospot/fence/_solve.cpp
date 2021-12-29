#include <cstdio>
#include <vector>

using namespace std;

int solve(vector<int> &v, int begin, int end);
int main(void)
{
	int c;
	scanf("%d", &c);

	while (c--)
	{
		int n;
		scanf("%d", &n);
		vector<int> v;
		for (int i = 0; i < n; ++i)
		{
			int temp;
			scanf("%d", &temp);
			v.push_back(temp);
		}
		printf("%d\n", solve(v, 0, v.size()));
	}
}
int findMidMax(vector<int> &v, int begin, int end);

int solve(vector<int> &v, int begin, int end)
{
	if (begin == end)
	{
		return 0;
	}
	if (begin + 1 == end)
	{
		return v[begin];
	}

	int mid = (begin + end) / 2;
	int leftMax = solve(v, begin, mid);
	int rightMax = solve(v, mid, end);
	int midMax = findMidMax(v, begin, end);

	return max(leftMax, max(rightMax, midMax));
}

int findMidMax(vector<int> &v, int begin, int end)
{
	int mid = (begin + end) / 2;
	int left = mid - 1;
	int right = mid;
	int minHeight = min(v[left], v[right]);
	int size = 2 * minHeight;
	while (begin < left || right + 1 < end)
	{
		if (begin < left && (right + 1 == end || v[left - 1] > v[right + 1]))
		{
			--left;
			minHeight = min(minHeight, v[left]);
		}
		else
		{
			++right;
			minHeight = min(minHeight, v[right]);
		}
		size = max(size, minHeight * (right - left + 1));
	}
	return size;
}