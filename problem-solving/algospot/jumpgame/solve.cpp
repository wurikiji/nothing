#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

struct Board
{
	vector<vector<int>> v;
	vector<vector<int>> reachable;
	int size;
	Board(int n) : size{n}, v{vector<vector<int>>(n, vector<int>(n))}, reachable{vector<vector<int>>(n, vector<int>(n, -1))}
	{
	}
};

bool isReachable(Board &, int, int);

int main()
{
	int c;
	ios_base::sync_with_stdio(false);
	cin >> c;
	while (c--)
	{
		int n;
		cin >> n;

		Board board{n};

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin >> board.v[i][j];
			}
		}
		if (isReachable(board, n - 1, n - 1))
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
	return 0;
}

bool isReachable(Board &board, int row, int col)
{
	if (row == 0 && col == 0)
	{
		return true;
	}
	if (board.reachable[row][col] != -1)
	{
		return board.reachable[row][col];
	}
	int &reachable = board.reachable[row][col];
	reachable = 0;

	for (int i = 0; i < row; i++)
	{
		int distance = row - i;
		if (distance == board.v[i][col])
		{
			reachable = reachable || isReachable(board, i, col);
		}
	}
	for (int i = 0; i < col; i++)
	{
		int distance = col - i;
		if (distance == board.v[row][i])
		{
			reachable = reachable || isReachable(board, row, i);
		}
	}

	return reachable;
}