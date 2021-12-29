#define fastio                      \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL)

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

string board[5];

bool is_in_bound(int nx, int ny)
{
	return 0 <= nx && nx < 5 && 0 <= ny && ny < 5;
}

int main(void)
{
	fastio;
	int t;
	cin >> t;
	while (t--)
	{
		for (int i = 0; i < 5; ++i)
		{
			cin >> board[i];
		}
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			string word;
			cin >> word;
			bool visited[5][5][12];
			memset(visited, 0, sizeof(visited));
			for (int idx = 0; idx < word.size(); ++idx)
			{
				for (int x = 0; x < 5; ++x)
				{
					for (int y = 0; y < 5; ++y)
					{
						for (int d = 0; d < 8 && idx > 0; ++d)
						{
							int nx = x + dx[d];
							int ny = y + dy[d];
							if (is_in_bound(nx, ny) && visited[nx][ny][idx - 1])
							{
								visited[x][y][idx] = true;
								break;
							}
						}
						visited[x][y][idx] = (visited[x][y][idx] || idx == 0) && (board[x][y] == word[idx]);
					}
				}
			}
			bool exist = false;
			for (int x = 0; x < 5; ++x)
			{
				for (int y = 0; y < 5; ++y)
				{
					exist |= visited[x][y][word.size() - 1];
				}
			}
			cout << word << ' ';
			if (exist)
			{
				cout << "YES";
			}
			else
			{
				cout << "NO";
			}
			cout << endl;
		}
	}
	return 0;
}
