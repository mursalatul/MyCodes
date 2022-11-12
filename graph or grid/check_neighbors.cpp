#include <iostream>
#include <vector>
typedef long long ll;

//this function can check or perform particular operation on the neighbors of an cell in a grid/2d matrix
void check_neighbors(vector<vector<ll>> v, ll r, ll c)
{
	// iterating in row
	for (ll row = 0; row < r; row++)
	{
		// iterating in column
		for (ll col = 0; col < c; col++)
		{
			// iterating neighbours of v[row][col] cell (excluding itself)
			for (ll i = row - 1; i <= row + 1; i++)
			{
				if (i < 0 || i >= r) // checking range
					continue;
				else
				{
					for (ll j = col - 1; j <= col + 1; j++)
					{
						if (j < 0 || j >= c) // checking range
							continue;
						else if (i != row || j != col) // excluding the cell itself
						{
							// do operations with the neighbours v[i][j]
						}
					}
				}
			}
		}
	}
}

int main()
{
	return 0;
}
