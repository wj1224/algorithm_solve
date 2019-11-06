#include <iostream>

using namespace std;

int T, n;
string up_side[3][3] = { { "w", "w", "w" },{ "w", "w", "w" },{ "w", "w", "w" } };
string down_side[3][3] = { { "y", "y", "y" },{ "y", "y", "y" },{ "y", "y", "y" } };
string front_side[3][3] = { { "r", "r", "r" },{ "r", "r", "r" },{ "r", "r", "r" } };
string back_side[3][3] = { { "o", "o", "o" },{ "o", "o", "o" },{ "o", "o", "o" } };
string left_side[3][3] = { { "g", "g", "g" },{ "g", "g", "g" },{ "g", "g", "g" } };
string right_side[3][3] = { { "b", "b", "b" },{ "b", "b", "b" },{ "b", "b", "b" } };
char oper[2];

void UpSide()
{
	string temp_identity[3][3];
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			temp_identity[i][j] = up_side[i][j];
	up_side[0][0] = temp_identity[2][0];
	up_side[0][1] = temp_identity[1][0];
	up_side[0][2] = temp_identity[0][0];
	up_side[1][0] = temp_identity[2][1];
	up_side[1][2] = temp_identity[0][1];
	up_side[2][0] = temp_identity[2][2];
	up_side[2][1] = temp_identity[1][2];
	up_side[2][2] = temp_identity[0][2];

	string temp_other[3] = { back_side[2][0], back_side[2][1], back_side[2][2] };
	back_side[2][0] = left_side[2][2];
	back_side[2][1] = left_side[1][2];
	back_side[2][2] = left_side[0][2];
	left_side[2][2] = front_side[0][2];
	left_side[1][2] = front_side[0][1];
	left_side[0][2] = front_side[0][0];
	front_side[0][2] = right_side[0][0];
	front_side[0][1] = right_side[1][0];
	front_side[0][0] = right_side[2][0];
	right_side[0][0] = temp_other[0];
	right_side[1][0] = temp_other[1];
	right_side[2][0] = temp_other[2];
}

void DownSide()
{
	string temp_identity[3][3];
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			temp_identity[i][j] = down_side[i][j];
	down_side[0][0] = temp_identity[2][0];
	down_side[0][1] = temp_identity[1][0];
	down_side[0][2] = temp_identity[0][0];
	down_side[1][0] = temp_identity[2][1];
	down_side[1][2] = temp_identity[0][1];
	down_side[2][0] = temp_identity[2][2];
	down_side[2][1] = temp_identity[1][2];
	down_side[2][2] = temp_identity[0][2];

	string temp_other[3] = { right_side[0][2], right_side[1][2], right_side[2][2] };
	right_side[0][2] = front_side[2][2];
	right_side[1][2] = front_side[2][1];
	right_side[2][2] = front_side[2][0];
	front_side[2][2] = left_side[2][0];
	front_side[2][1] = left_side[1][0];
	front_side[2][0] = left_side[0][0];
	left_side[2][0] = back_side[0][0];
	left_side[1][0] = back_side[0][1];
	left_side[0][0] = back_side[0][2];
	back_side[0][0] = temp_other[0];
	back_side[0][1] = temp_other[1];
	back_side[0][2] = temp_other[2];
}

void FrontSide()
{
	string temp_identity[3][3];
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			temp_identity[i][j] = front_side[i][j];
	front_side[0][0] = temp_identity[2][0];
	front_side[0][1] = temp_identity[1][0];
	front_side[0][2] = temp_identity[0][0];
	front_side[1][0] = temp_identity[2][1];
	front_side[1][2] = temp_identity[0][1];
	front_side[2][0] = temp_identity[2][2];
	front_side[2][1] = temp_identity[1][2];
	front_side[2][2] = temp_identity[0][2];

	string temp_other[3] = { up_side[2][0], up_side[2][1], up_side[2][2] };
	up_side[2][0] = left_side[2][0];
	up_side[2][1] = left_side[2][1];
	up_side[2][2] = left_side[2][2];
	left_side[2][0] = down_side[2][0];
	left_side[2][1] = down_side[2][1];
	left_side[2][2] = down_side[2][2];
	down_side[2][0] = right_side[2][0];
	down_side[2][1] = right_side[2][1];
	down_side[2][2] = right_side[2][2];
	right_side[2][0] = temp_other[0];
	right_side[2][1] = temp_other[1];
	right_side[2][2] = temp_other[2];
}

void BackSide()
{
	string temp_identity[3][3];
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			temp_identity[i][j] = back_side[i][j];
	back_side[0][0] = temp_identity[2][0];
	back_side[0][1] = temp_identity[1][0];
	back_side[0][2] = temp_identity[0][0];
	back_side[1][0] = temp_identity[2][1];
	back_side[1][2] = temp_identity[0][1];
	back_side[2][0] = temp_identity[2][2];
	back_side[2][1] = temp_identity[1][2];
	back_side[2][2] = temp_identity[0][2];

	string temp_other[3] = { down_side[0][2], down_side[0][1], down_side[0][0] };
	down_side[0][2] = left_side[0][2];
	down_side[0][1] = left_side[0][1];
	down_side[0][0] = left_side[0][0];
	left_side[0][2] = up_side[0][2];
	left_side[0][1] = up_side[0][1];
	left_side[0][0] = up_side[0][0];
	up_side[0][2] = right_side[0][2];
	up_side[0][1] = right_side[0][1];
	up_side[0][0] = right_side[0][0];
	right_side[0][2] = temp_other[0];
	right_side[0][1] = temp_other[1];
	right_side[0][0] = temp_other[2];
}

void LeftSide()
{
	string temp_identity[3][3];
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			temp_identity[i][j] = left_side[i][j];
	left_side[0][0] = temp_identity[2][0];
	left_side[0][1] = temp_identity[1][0];
	left_side[0][2] = temp_identity[0][0];
	left_side[1][0] = temp_identity[2][1];
	left_side[1][2] = temp_identity[0][1];
	left_side[2][0] = temp_identity[2][2];
	left_side[2][1] = temp_identity[1][2];
	left_side[2][2] = temp_identity[0][2];

	string temp_other[3] = { back_side[0][0], back_side[1][0], back_side[2][0] };
	back_side[0][0] = down_side[2][2];
	back_side[1][0] = down_side[1][2];
	back_side[2][0] = down_side[0][2];
	down_side[2][2] = front_side[0][0];
	down_side[1][2] = front_side[1][0];
	down_side[0][2] = front_side[2][0];
	front_side[0][0] = up_side[0][0];
	front_side[1][0] = up_side[1][0];
	front_side[2][0] = up_side[2][0];
	up_side[0][0] = temp_other[0];
	up_side[1][0] = temp_other[1];
	up_side[2][0] = temp_other[2];
}

void RightSide()
{
	string temp_identity[3][3];
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			temp_identity[i][j] = right_side[i][j];
	right_side[0][0] = temp_identity[2][0];
	right_side[0][1] = temp_identity[1][0];
	right_side[0][2] = temp_identity[0][0];
	right_side[1][0] = temp_identity[2][1];
	right_side[1][2] = temp_identity[0][1];
	right_side[2][0] = temp_identity[2][2];
	right_side[2][1] = temp_identity[1][2];
	right_side[2][2] = temp_identity[0][2];

	string temp_other[3] = { back_side[2][2], back_side[1][2], back_side[0][2] };
	back_side[2][2] = up_side[2][2];
	back_side[1][2] = up_side[1][2];
	back_side[0][2] = up_side[0][2];
	up_side[2][2] = front_side[2][2];
	up_side[1][2] = front_side[1][2];
	up_side[0][2] = front_side[0][2];
	front_side[2][2] = down_side[0][0];
	front_side[1][2] = down_side[1][0];
	front_side[0][2] = down_side[2][0];
	down_side[0][0] = temp_other[0];
	down_side[1][0] = temp_other[1];
	down_side[2][0] = temp_other[2];
}

int main()
{
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				up_side[i][j] = "w";
				down_side[i][j] = "y";
				front_side[i][j] = "r";
				back_side[i][j] = "o";
				left_side[i][j] = "g";
				right_side[i][j] = "b";
			}
		}
		cin >> n;
		for (int idx = 0; idx < n; idx++)
		{
			cin >> oper[0] >> oper[1];
			if (oper[1] == '+')
			{
				if (oper[0] == 'U')
					UpSide();
				else if (oper[0] == 'D')
					DownSide();
				else if (oper[0] == 'F')
					FrontSide();
				else if (oper[0] == 'B')
					BackSide();
				else if (oper[0] == 'L')
					LeftSide();
				else if (oper[0] == 'R')
					RightSide();
			}
			else if (oper[1] == '-')
			{
				for (int num = 0; num < 3; num++)
				{
					if (oper[0] == 'U')
						UpSide();
					else if (oper[0] == 'D')
						DownSide();
					else if (oper[0] == 'F')
						FrontSide();
					else if (oper[0] == 'B')
						BackSide();
					else if (oper[0] == 'L')
						LeftSide();
					else if (oper[0] == 'R')
						RightSide();
				}
			}
		}
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cout << up_side[i][j][0];
			}
			cout << endl;
		}
	}

	return 0;
}