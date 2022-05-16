#include <iostream>

using namespace std;

char chess[51][51];

char wChess[8][8] =
{
	{'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
	{'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
	{'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
	{'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
	{'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
	{'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
	{'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
	{'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
};

char bChess[8][8] =
{
	{'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
	{'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
	{'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
	{'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
	{'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
	{'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
	{'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
	{'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'}
};

int wChessResult(int _i, int _j)
{
	int result = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (chess[_i + i][_j + j] != wChess[i][j])
			{
				result++;
			}
		}
	}

	return result;
}

int bChessResult(int _i, int _j)
{
	int result = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (chess[_i + i][_j + j] != bChess[i][j])
			{
				result++;
			}
		}
	}

	return result;
}

int main()
{
	int count = 64;
	int wCount = 0, bCount = 0;

	// 가로세로 크기 입력
	int row, column;
	cin >> column >> row;

	for (int i = 0; i < column; i++)
	{
		for (int j = 0; j < row; j++)
		{
			cin >> chess[i][j];
		}
	}

	// 8x8 최솟값 탐색
	for (int i = 0; i <= column - 8; i++)
	{
		for (int j = 0; j <= row - 8; j++)
		{
			// 첫 시작이 'W'와 'B' 경우 둘다 탐색
			wCount = wChessResult(i, j);
			bCount = bChessResult(i, j);

			// 최솟값 갱신
			if (wCount < bCount)
			{
				count = (wCount < count) ? wCount : count;
			}
			else
			{
				count = (bCount < count) ? bCount : count;
			}
		}
	}

	cout << count;

	return 0;
}