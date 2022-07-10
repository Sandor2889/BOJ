#include <iostream>
#include <vector>

#define SIZE 21

using namespace std;

char map[SIZE][SIZE];
bool visited[SIZE][SIZE];
vector<char> alphabet;
vector<int> vCnt;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };

int r, c;
string input;
int cnt = 1;
bool flag;


// 동일 알파벳이 있는지 체크
void checkAlphabet(int _nextX, int _nextY)
{
	for (int j = 0; j < alphabet.size(); j++)
	{
		if (alphabet[j] == map[_nextY][_nextX])
		{
			flag = true;
		}
	}
}

void dfs(int _x, int _y)
{
	visited[_y][_x] = true;
	alphabet.push_back(map[_y][_x]);
	cnt++;

	for (int i = 0; i < 4; i++)
	{
		int nextX = _x + dx[i];
		int nextY = _y + dy[i];

		if (0 <= nextX && nextX < c && 0 <= nextY && nextY < r)
		{
			checkAlphabet(nextX, nextY);
			if (!visited[nextY][nextX] && !flag)
			{
				flag = true;
				dfs(nextX, nextY);
			}
		}
	}

	vCnt.push_back(cnt);
	cnt = 1;
}

int main()
{
	// 세로 x 가로 : r x c
	cin >> r >> c;

	for (int i = 0; i < r; i++)
	{
		cin >> map[i];
	}

	dfs(0, 0);

	cout << cnt;

	return 0;
}
