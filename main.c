#include <sys/time.h>
#include <sys/resource.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printBoard(char board [21][21], int n) { //print the entire board

    int row, col;

    for (row = 0; row < n; row++) {
        for (col = 0; col < n; col++) {
            printf("%c", board[row][col]);
        }
        printf("\n");

    }
}

int findLongest(char board[21][21], int n, int row, int col, char color) {
    int num = 0;
    //int number1 = 0, number2 = 0, number3 = 0, number4 = 0;
	int longest = 0;
    int i;

	//vertical
    for (i = 0; row + i + 1 < n && board[row + i + 1][col] == color; i++) {
    }
	num += i;
    for (i = 0; row - i - 1 >= 0 && board[row - i - 1][col] == color; i++) {
    }
	num += i;
	num++;//count the spot itself
	if(longest < num)
		longest = num;
	num = 0;

    // horizontally count numbers, end the loop when the character is not consecutive
    for (i = 0; col + i + 1 < n && board[row][col + i + 1] == color; i++) {
        //num++;
    }
	num += i;
    for (i = 0; col - i - 1 >= 0 && board[row][col - i - 1] == color; i++) {
        //num++;
    }
	num += i;
	num++;
	if(longest < num)
		longest = num;
	num = 0;

    // diagonal 1 count numbers
    for (i = 0; col + i + 1 < n && row - i - 1 >= 0 && board[row - i - 1][col + i + 1] == color; i++) {
        //number3++;
    }
	num += i;
    for (i = 0; col - i - 1 >= 0 && row + i + 1 < n && board[row + i + 1][col - i - 1] == color; i++) {
        //number3++;
    }
	num += i;
	num++;
	if(longest < num)
		longest = num;
	num = 0;

    //check diagonal 2 count numbers

    for (i = 0; row - i - 1 >= 0 && col - i - 1 >= 0 && board[row - i - 1][col - i - 1] == color; i++) {
        //number4++;
    }
	num += i;
    for (i = 0; row + i + 1 < n && col + i + 1 < n && board[row + i + 1][col + i + 1] == color; i++) {
        //number4++;
    }
	num += i;
	num++;
	if(longest < num)
		longest = num;
	num = 0;

    return longest;
}


//this function is to calculate the longest possible line on this spot. there is no point to take this spot if the return value is less than 6.
int findpossiblelongest(char board[21][21], int n, int row, int col, char color)
{
	int longest = 0;
	int num = 0;
	int i;

    for (i = 0; row + i + 1 < n && (board[row + i + 1][col] == color || board[row + i + 1][col] == 'U'); i++) {
    }
	num += i;
    for (i = 0; row - i - 1 >= 0 && (board[row - i - 1][col] == color || board[row - i - 1][col] == 'U'); i++) {
    }
	num += i;
	num++;
	if(longest < num)
		longest = num;
	num = 0;

    // horizontally count numbers, end the loop when the character is not consecutive
    for (i = 0; col + i + 1 < n && (board[row][col + i + 1] == color || board[row][col + i + 1] == 'U'); i++) {
        //num++;
    }
	num += i;
    for (i = 0; col - i - 1 >= 0 && (board[row][col - i - 1] == color || board[row][col - i - 1] == 'U'); i++) {
        //num++;
    }
	num += i;
	num++;
	if(longest < num)
		longest = num;
	num = 0;

    // diagonal 1 count numbers
    for (i = 0; col + i + 1 < n && row - i - 1 >= 0 && (board[row - i - 1][col + i + 1] == color || board[row - i - 1][col + i + 1] == 'U'); i++) {
        //number3++;
    }
	num += i;
    for (i = 0; col - i - 1 >= 0 && row + i + 1 < n && (board[row + i + 1][col - i - 1] == color || board[row + i + 1][col - i - 1] == 'U'); i++) {
        //number3++;
    }
	num += i;
	num++;
	if(longest < num)
		longest = num;
	num = 0;

    //check diagonal 2 count numbers

    for (i = 0; row - i - 1 >= 0 && col - i - 1 >= 0 && (board[row - i - 1][col - i - 1] == color || board[row - i - 1][col - i - 1] == 'U'); i++) {
        //number4++;
    }
	num += i;
    for (i = 0; row + i + 1 < n && col + i + 1 < n && (board[row + i + 1][col + i + 1] == color || board[row + i + 1][col + i + 1] == 'U'); i++) {
        //number4++;
    }
	num += i;
	num++;
	if(longest < num)
		longest = num;
	num = 0;


	return longest;
}

// print where the color of chess changed(black/white) at particular positions
void humanMove(char board[21][21], int n, char inFirstPlayer[10]) {
    int row = 0, col = 0;
    bool check = 1;
    do {
        if (inFirstPlayer[0] == 'B') {

            printf("Enter White Move (ROW COL): ");
            scanf("%d %d", &row, &col);


            if ((row >= n) || (col >= n) || (row < 0) || (col < 0)) {
                printf("Out of range row or column\n");

            } else if (board[row][col] != 'U') {
                printf("That square is already occupied or blocked\n");

            } else {
                board[row][col] = 'W';
                printBoard(board, n);
                check = 0;
            }

        } else if (inFirstPlayer[0] == 'W') {
            printf("Enter Black Move (ROW COL): ");
            scanf("%d %d", &row, &col);

            if ((row >= n) || (col >= n) || (row < 0) || (col < 0)) {
                printf("Out of range row or column\n");

            } else if (board[row][col] != 'U') {
                printf("That square is already occupied or blocked\n");

            } else {
                board[row][col] = 'B';
                printBoard(board, n);
                check = 0;
            }
        }

    } while (check);
}


void computerMove(char board[21][21], int n, char inFirstPlayer[10]) {
    struct rusage usage; // a structure to hold "resource usage" (including time
    struct timeval start, end; // will hold the start and end times
    getrusage(RUSAGE_SELF, &usage);
    start = usage.ru_utime;
    double time_start = start.tv_sec + start.tv_usec / 1000000.0; // in seconds

    int longestSequence = 0;
    int maxRow = -1, maxCol = -1;
    int i, j;
    int score[21][21];
	
	int danger = 0;
	int dangerRow = -1;
	int dangerCol = -1;
	int temp = 0;
	char opponent;
	if(inFirstPlayer[0] == 'B')
		opponent = 'W';
	else
		opponent = 'B';
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (board[i][j] == 'U') {
				//if(findpossiblelongest(board, n, i, j, 'B') < 6 && findpossiblelongest(board, n, i, j, 'W') < 6)//no need to take when longest possible is less than 6
				//{
				//	continue;
				//}
				//if(inFirstPlayer[0] == 'B')
				//	board[i][j] = 'W';
				//else
				//	board[i][j] = 'B';
				temp = findLongest(board, n, i, j, opponent);
				if(danger < temp)
				{
					danger = temp;
					dangerRow = i;
					dangerCol = j;
				}
				//board[i][j] = 'U';
			}
		}
    }

	
    if(danger <= 4)//consider it not dangerous when have less or equal to three consecutive enemy point, can change to four
	{
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if (board[i][j] == 'U') {
					//board[i][j] = 'B';
					//score[i][j] = findLongest(board, n, i, j);
					//board[i][j] = inFirstPlayer[0];
					score[i][j] = findLongest(board, n, i, j, inFirstPlayer[0]);
					//board[i][j] = 'U';
				}
			}
		}

		for (i = n / 2; i < n; i++) {
			for (j = n / 2; j < n; j++) {
				if (board[i][j] == 'U') {
					if(findpossiblelongest(board, n, i, j, 'B') < 6 && findpossiblelongest(board, n, i, j, 'W') < 6)//no need to take when longest possible is less than 6
					{
						continue;
					}
					if (longestSequence < score[i][j]) {
						maxRow = i;
						maxCol = j;
						longestSequence = score[i][j];
					}
				}
			}
		}
		for (i = n / 2; i < n; i++) {
			for (j = n / 2 - 1; j >= 0; j--) {
				if (board[i][j] == 'U') {
					if(findpossiblelongest(board, n, i, j, 'B') < 6 && findpossiblelongest(board, n, i, j, 'W') < 6)//no need to take when longest possible is less than 6
					{
						continue;
					}
					if (longestSequence < score[i][j]) {
						maxRow = i;
						maxCol = j;
						longestSequence = score[i][j];
					}
				}
			}
		}
		for (i = n / 2 - 1; i >= 0; i--) {
			for (j = n / 2; j < n; j++) {
				if (board[i][j] == 'U') {
					if(findpossiblelongest(board, n, i, j, 'B') < 6 && findpossiblelongest(board, n, i, j, 'W') < 6)//no need to take when longest possible is less than 6
					{
						continue;
					}
					if (longestSequence < score[i][j]) {
						maxRow = i;
						maxCol = j;
						longestSequence = score[i][j];
					}
				}
			}
		}
		for (i = n / 2 - 1; i >= 0; i--) {
			for (j = n / 2 - 1; j >= 0; j--) {
				if (board[i][j] == 'U') {
					if(findpossiblelongest(board, n, i, j, 'B') < 6 && findpossiblelongest(board, n, i, j, 'W') < 6)//no need to take when longest possible is less than 6
					{
						continue;
					}
					if (longestSequence < score[i][j]) {
						maxRow = i;
						maxCol = j;
						longestSequence = score[i][j];
					}
				}
			}
		}
	}
	else
	{
		maxRow = dangerRow;
		maxCol = dangerCol;
	}
    
    if(maxRow < 0 || maxCol < 0)
	{
		for (i = n / 2; i < n; i++) {
			for (j = n / 2; j < n; j++) {
				if (board[i][j] == 'U') {
					if (longestSequence < score[i][j]) {
						maxRow = i;
						maxCol = j;
						longestSequence = score[i][j];
						
					}
				}
			}
		}
		for (i = n / 2; i < n; i++) {
			for (j = n / 2 - 1; j >= 0; j--) {
				if (board[i][j] == 'U') {
					if (longestSequence < score[i][j]) {
						maxRow = i;
						maxCol = j;
						longestSequence = score[i][j];
						
					}
				}
			}
		}
		for (i = n / 2 - 1; i >= 0; i--) {
			for (j = n / 2; j < n; j++) {
				if (board[i][j] == 'U') {
					if (longestSequence < score[i][j]) {
						maxRow = i;
						maxCol = j;
						longestSequence = score[i][j];
						
					}
				}
			}
		}
		for (i = n / 2 - 1; i >= 0; i--) {
			for (j = n / 2 - 1; j >= 0; j--) {
				if (board[i][j] == 'U') {
					if (longestSequence < score[i][j]) {
						maxRow = i;
						maxCol = j;
						longestSequence = score[i][j];
						
					}
				}
			}
		}
	}
    
    printf("Computer moves %s at %d %d\n", inFirstPlayer, maxRow, maxCol);
    board[maxRow][maxCol] = inFirstPlayer[0];
    printBoard(board, n);

    getrusage(RUSAGE_SELF, &usage);
    end = usage.ru_utime;
    double time_end = end.tv_sec + end.tv_usec / 1000000.0; // in seconds
    double total_time = time_end - time_start; // total_time now holds the time
    printf("computer move in %.2lfms\n", total_time * 1000);
}

int whoIsWinner(char board[21][21], int n) {
    int numOfCharacter = 0;
    int maxrow = 0, maxcol = 0;

    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (board[i][j] == 'B' || board[i][j] == 'W') {
                if (numOfCharacter < findLongest(board, n, i, j, board[i][j])) {
                    numOfCharacter = findLongest(board, n, i, j, board[i][j]);

                    maxrow = i; // save the position of longest number to maxrow, and maxcol
                    maxcol = j;
                }
            }
        }
    }
    if (numOfCharacter == 6) {
        if (board[maxrow][maxcol] == 'B')
            printf("\nBlack player wins.\n");
        else if (board[maxrow][maxcol] == 'W')
            printf("\nWhite player wins.\n");


    }
    return numOfCharacter;
}


void blockedSquare(char board [21][21], int n) { // print the positions of blocked squares
    int row, col;


    do {
        printf("Enter position (ROW COL) of blocked square; (-1 -1) to finish: ");
        scanf("%d %d", &row, &col);

        if (row == -1 && col == -1)
            break;

        else if ((row >= n) || (col >= n) || (row < 0) || (col < 0)) {
            printf("Out of range row or column\n");

        } else if (board[row][col] != 'U') {
            printf("Position already occupied, try again\n");
        } else {
            board[row][col] = 'R';
            printBoard(board, n);
        }

    } while (1);
}


int Draw(char board[21][21], int n, char inFirstPlayer[10]) {
    int count = 0;
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            if (board[i][j] == 'U')
                count++;
    }
    return count;
}



int main(void) {

    int nsize, winner, count;
    int row = 0, col = 0;
    char board[21][21];
    char inFirstPlayer[10];
    bool first = true;

    do {
        printf("Enter board dimensions (n), n>=6 and n<=21: ");
        scanf("%d", &nsize);
    } while (nsize < 6 || nsize > 21);
    for (row = 0; row < 21; row++) {
        for (col = 0; col < 21; col++)
            board[row][col] = 'U';
    }
    printBoard(board, nsize); 
    // 

    do {
        printf("Computer playing B or W?: ");
        scanf("%s", inFirstPlayer);
    } while (!(inFirstPlayer[0] == 'B' || inFirstPlayer[0] == 'W'));
    
    //
    blockedSquare(board, nsize); 
    // 
    
    if (inFirstPlayer[0] == 'W')
        first = false;
    count = Draw(board, nsize, inFirstPlayer);

    while (winner != 6 && count != 0) {
        winner = whoIsWinner(board, nsize);

        if ((winner != 6 && first) && (count != 0)) {
            computerMove(board, nsize, inFirstPlayer);
            winner = whoIsWinner(board, nsize);
            count = Draw(board, nsize, inFirstPlayer);

        } else if (count == 0) {
            printf("Draw!");
        }
        first = true;
        if (winner != 6 && count != 0) {
            humanMove(board, nsize, inFirstPlayer); // determine if computer starts with black or white
            winner = whoIsWinner(board, nsize);
            count = Draw(board, nsize, inFirstPlayer);
        } else if (count == 0) {
            printf("\nDraw!\n");
        }
    }

    printBoard(board, nsize);

    return 0;
}
