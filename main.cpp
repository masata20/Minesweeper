// @BEGIN_OF_SOURCE_CODE
#include<iostream>
using namespace std;


void outputField(int, int, char**);
bool checkMines(int, int, char**);

int main()
{
	// read row and column
	int row, colunm;
	int counter = 0;

	scanf("%d%d", &row, &colunm);
	while (row != 0 && colunm != 0)	
	{
		counter++;
		
		// allocate 2d array with specified row and column
		char **field = new char*[row];
		for (int i = 0; i < row; i++)
		{
			field[i] = new char[colunm];
		}


		// read the rest of file and create one field
		for (int i = 0; i < row; i++)
		{
			char temp[101];
			scanf("%100s", temp);
			for(int j = 0; j < colunm; j++)
			{
				field[i][j] = temp[j];
			}

		}	

		if(counter > 1)
			printf("\n");


		printf("Field #%d:\n", counter);


		// if row is 1, the outputfield function cannot work correctly	
	
		// output the fields
		outputField(row, colunm,field);

		
		// Delete
		for(int i = 0; i < row; i++)
			delete[] field[i];

		delete[] field;
		
		scanf("%d%d", &row, &colunm);
	}
	return 0;
}

void outputField(int sizeOfRow, int sizeOfColunm, char** field)
{

	for (int row = 0; row < sizeOfRow; row++)
	{
		for (int colunm = 0; colunm < sizeOfColunm; colunm++)
		{
			if(field[row][colunm] == '*')
			{
				printf("*");
			}
			else
			{
				int mineCounter = 0;
				if (row == 0)
				{
					if (colunm != 0)
					{
						//check left
						if (checkMines(row, colunm-1, field))
							mineCounter++;
						// check left bottom, iff row size is bigger than 1
						if (sizeOfRow > 1)
						{
							if (checkMines(row+1, colunm-1, field))
								mineCounter++;
						}
					}
					if (colunm != sizeOfColunm-1)
					{
						// check right
						if (checkMines(row, colunm+1, field))
							mineCounter++;
						// check right bottom, iff row size is bigger than 1
						if (sizeOfRow > 1)
						{
							if (checkMines(row+1, colunm+1, field))
								mineCounter++;
						}
					}	
	
					// Check bottom, iff row size is bigger than 1
					if(sizeOfRow > 1)
					{
		
						if (checkMines(row+1, colunm, field))
						mineCounter++;
					}
				}
				else
				{
					if (row == sizeOfRow - 1)
					{
						if (colunm != 0)
						{
							// check left
							if (checkMines(row, colunm-1, field))
								mineCounter++;
							// check up left
							if (checkMines(row-1, colunm-1, field))
								mineCounter++;

						}
						if (colunm != sizeOfColunm-1)
						{
							// check right
							if (checkMines(row, colunm+1, field))
								mineCounter++;
							// check up right
							if (checkMines(row-1, colunm+1, field))
								mineCounter++;
						}	
						// check up
						if(checkMines(row-1, colunm, field))
							mineCounter++;
					}
					else
					{
						if (colunm != 0)
						{
							// check left
							if (checkMines(row, colunm-1, field))
								mineCounter++;
							// check left up
							if (checkMines(row-1, colunm-1, field))
								mineCounter++;
							// check left bottom
							if (checkMines(row+1, colunm-1, field))
								mineCounter++;
						}
						if (colunm != sizeOfColunm-1)
						{
							// check right
							if (checkMines(row, colunm+1, field))
								mineCounter++;
							// check rightu p
							if (checkMines(row-1, colunm+1, field))
								mineCounter++;
							// check right bottom
							if (checkMines(row+1, colunm+1, field))
								mineCounter++;
						}
						// checkup
						if(checkMines(row-1, colunm, field))
							mineCounter++;
						// check bottom
						if(checkMines(row+1, colunm, field))
							mineCounter++;
					}
				}

				printf("%d", mineCounter);
			}
		}
		printf("\n");
	}
}

bool checkMines(int row, int colunm, char** field)
{
	if(field[row][colunm] == '*')
		return true;

	return false;
}
// @END_OF_SOURCE_CODE
