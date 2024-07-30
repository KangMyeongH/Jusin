#define BOARD_SIZE (5) // 빙고 판의 크기

#include <iostream>
using namespace std;
/*
- 1~25까지 5 X 5형태 숫자 출력
- 임의의 숫자 입력받음, 입력받은 숫자와 보드판의 숫자가 일치할 경우 *로 출력
- 가로, 세로, 대각선 방향으로 *이 5개인 경우 빙고가 하나 증가
- 5 빙고 이상이면 승리로 게임이 종료
- 컴퓨터와 1대1 대결
 */

void Bingo();
void InitBingoBoard(int[][BOARD_SIZE]);
void CheckBingoNumber(int[][BOARD_SIZE],int[][BOARD_SIZE], int);
int CheckBingo(int[][BOARD_SIZE]);
void RenderBingo(int[][BOARD_SIZE], int[][BOARD_SIZE], int, int);
bool InputNumber(int);

/*
 *  - 빙고 AI 로직
 *  1. 가로 세로 대각선 중에 빙고가 될 확률이 높은 라인 선정
 *  2. 여러개일 경우 중첩되는 라인에서 선택된 숫자가 많은 라인으로 선정
 *  3. 라인에 있는 숫자 중에 선택되지 않은 숫자를 선택
 */
int BingoAI(int[][BOARD_SIZE], int[], int[], int[]);
void CountBingoLine(int[][BOARD_SIZE], int[], int[], int[]);



int main()
{
    Bingo();
    return 0;
}

void Bingo()
{
    int playerBoard[BOARD_SIZE][BOARD_SIZE] = {};
    int pcBoard[BOARD_SIZE][BOARD_SIZE] = {};
    int playerBingoCount = 0;
    int pcBingoCount = 0;
    
    int pcHorizontal[BOARD_SIZE] = {};  // 가로 빙고 체크
    int pcVertical[BOARD_SIZE] = {};    // 세로 빙고 체크
    int pcDiagonal[2] = {};             // 대각선 빙고 체크
    
    int playerInput = 0;    
    int pcInput = 0;

    bool isPlayerWin = false;
    bool isPcWin = false;
    
    InitBingoBoard(playerBoard);
    InitBingoBoard(pcBoard);
    while(true)
    {
        // 플레이어 턴
        RenderBingo(playerBoard, pcBoard, playerBingoCount, pcBingoCount);
        if(playerBingoCount == 5 & pcBingoCount == 5)
        {
            cout << "Draw" << '\n';
            break;
        }
        if(playerBingoCount == 5)
        {
            cout << "Player Win" << '\n';
            break;
        }
        if(pcBingoCount == 5)
        {
            cout << "PC Win" << '\n';
        }
        cout << "Input Number : ";
        cin >> playerInput;
        CheckBingoNumber(playerBoard, pcBoard, playerInput);                // 입력 받은 값 각자의 빙고보드에 체크
        playerBingoCount = CheckBingo(playerBoard);                         // 플레이어 빙고 체크
        pcBingoCount = CheckBingo(pcBoard);                                 // PC 빙고 체크
        RenderBingo(playerBoard, pcBoard, playerBingoCount, pcBingoCount);
        // 승리 조건 체크
        if(playerBingoCount == 5 & pcBingoCount == 5)
        {
            cout << "Draw" << '\n';
            break;
        }
        if(playerBingoCount == 5)
        {
            cout << "Player Win" << '\n';
            break;
        }
        if(pcBingoCount == 5)
        {
            cout << "PC Win" << '\n';
        }
        pcInput = BingoAI(pcBoard, pcHorizontal, pcVertical, pcDiagonal);
        cout << "PC Input Number : " << pcInput << '\n';
        CheckBingoNumber(playerBoard, pcBoard, pcInput);
        playerBingoCount = CheckBingo(playerBoard);
        pcBingoCount = CheckBingo(pcBoard);
        system("pause");
    }
    
}

void InitBingoBoard(int board[][BOARD_SIZE])
{
    int tempArr[BOARD_SIZE * BOARD_SIZE] = {};
    
    for(int i = 0; i < BOARD_SIZE * BOARD_SIZE; i++)
    {
        tempArr[i] = i + 1;
    }

    for(int i = 0; i < 1000; i++)
    {
        const int dst = rand() % ( BOARD_SIZE * BOARD_SIZE );
        const int src = rand() % ( BOARD_SIZE * BOARD_SIZE );
        swap(tempArr[dst],tempArr[src]);
    }

    for(int i = 0; i < BOARD_SIZE; i++)
    {
        for(int j = 0; j < BOARD_SIZE; j++)
        {
            board[i][j] = tempArr[i * BOARD_SIZE + j];
        }
    }
}

void CheckBingoNumber(int playerBoard[][BOARD_SIZE],int pcBoard[][BOARD_SIZE], const int input)
{
    for(int i = 0; i < BOARD_SIZE; i++)
    {
        for(int j = 0; j < BOARD_SIZE; j++)
        {
            if(playerBoard[i][j] == input) playerBoard[i][j] = 0;
            if(pcBoard[i][j] == input) pcBoard[i][j] = 0;
        }
    }
}

/*
 * 1. 가로 빙고 체크
 * 2. 세로 빙고 체크
 * 3. 대각선 빙고 체크
 */
int CheckBingo(int board[][BOARD_SIZE])
{
    int bingoCount = 0;
    // 가로 열 체크
    for(int i = 0; i < BOARD_SIZE; i++)
    {
        for(int j = 0; j < BOARD_SIZE; j++)
        {
            if(board[i][j] != 0) break;
            if(j == BOARD_SIZE - 1) bingoCount++;            
        }
    }

    // 세로 열 체크
    for(int i = 0; i < BOARD_SIZE; i++)
    {
        for(int j = 0; j < BOARD_SIZE; j++)
        {
            if(board[j][i] != 0) break;
            if(j == BOARD_SIZE - 1) bingoCount++;            
        }
    }

    // 대각선 열 체크
    for(int i = 0; i < BOARD_SIZE; i++)
    {
        if(board[i][i] != 0) break;
        if(i == BOARD_SIZE - 1) bingoCount++;
    }
    
    for(int i = 0; i < BOARD_SIZE; i++)
    {
        if(board[i][BOARD_SIZE - i - 1] != 0) break;
        if(i == BOARD_SIZE - 1) bingoCount++;
    }
    
    return bingoCount;
}

void RenderBingo(int playerBoard[][BOARD_SIZE], int pcBoard[][BOARD_SIZE], const int playerBingoCount, const int pcBingoCount)
{
    system("cls");
    cout << "Player" << "                                          " << "PC" << '\n';
    cout << "==================================================================================" << '\n';
    for(int i = 0; i < BOARD_SIZE; i++)
    {
        for(int j = 0; j < BOARD_SIZE; j++)
        {
            playerBoard[i][j] != 0 ? cout << playerBoard[i][j] : cout << "*";
            cout << '\t';
        }
        cout << "        ";
        for(int j = 0; j < BOARD_SIZE; j++)
        {
            pcBoard[i][j] != 0 ? cout << pcBoard[i][j] : cout << "*";
            cout << '\t';
        }
        cout << '\n';
    }
    cout << "==================================================================================\n";
    cout << "Player Bingo : " << playerBingoCount << "\t PC Bingo : " << pcBingoCount << '\n';
}

bool InputNumber(int)
{
    return true;
}

int BingoAI(int board[][BOARD_SIZE], int horizontal[], int vertical[], int diagonal[])
{
    CountBingoLine(board, horizontal, vertical, diagonal);
    int hMax = *max_element(horizontal, horizontal + BOARD_SIZE);
    int vMax = *max_element(vertical, vertical + BOARD_SIZE);
    int dMax = *max_element(diagonal, diagonal + 2);
    int maxNum = max({hMax, vMax, dMax});
    int maxIndex[2] = {};
    bool isHorizontal[BOARD_SIZE] = {};
    bool isVertical[BOARD_SIZE] = {};
    bool isDiagonal[2] = {};
    
    for(int i = 0; i < BOARD_SIZE; i++)
    {
        if(horizontal[i] == maxNum) isHorizontal[i] = true;
        if(vertical[i] == maxNum) isVertical[i] = true;
    }

    for(int i = 0; i < 2; i++)
    {
        if(diagonal[i] == maxNum) isDiagonal[i] = true;
    }

    for(int i = 0; i < BOARD_SIZE; i++)
    {
        if(isHorizontal[i])
        {
            for(int j = 0; j < BOARD_SIZE; j++)
            {
                if(board[i][j] != 0 && (horizontal[i] + vertical[j]) >= maxNum)
                {
                    maxIndex[0] = i;
                    maxIndex[1] = j;
                    maxNum = horizontal[i] + vertical[j];
                }
            }
        }

        if(isVertical[i])
        {
            for(int j = 0; j < BOARD_SIZE; j++)
            {
                if(board[j][i] != 0 && (vertical[i] + horizontal[j]) >= maxNum)
                {
                    maxIndex[0] = j;
                    maxIndex[1] = i;
                    maxNum = horizontal[i] + vertical[j];
                }
            }
        }
    }

    for(int i = 0; i < 2; i++)
    {
        if(isDiagonal[i])
        {
            for(int j = 0; j < BOARD_SIZE; j++)
            {
                if(i == 0)
                {
                    if(board[j][j] != 0 && (diagonal[i] + horizontal[j] + vertical[j]) >= maxNum)
                    {
                        maxIndex[0] = j;
                        maxIndex[1] = j;
                        maxNum = diagonal[i] + horizontal[j] + vertical[j];
                    }
                }
                else
                {
                    if(board[j][BOARD_SIZE - j - 1] != 0 && (diagonal[i] + horizontal[BOARD_SIZE - j - 1] + vertical[j]) >= maxNum)
                    {
                        maxIndex[0] = j;
                        maxIndex[1] = BOARD_SIZE - j - 1;
                        maxNum = diagonal[i] + horizontal[j] + vertical[BOARD_SIZE - j - 1];
                    }
                }
            }
        }
    }
    return board[maxIndex[0]][maxIndex[1]];
}

void CountBingoLine(int board[][BOARD_SIZE], int horizontal[], int vertical[], int diagonal[])
{
    // 가로 세로 빙고 초기화
    for(int i = 0; i < BOARD_SIZE; i++)
    {
        horizontal[i] = 0;
        vertical[i] = 0;
    }
    
    for(int i = 0; i < 2; i++)
    {
        diagonal[i] = 0;
    }
    
    for(int i = 0; i < BOARD_SIZE; i++)
    {
        for(int j = 0; j < BOARD_SIZE; j++)
        {
            if(board[i][j] == 0)
            {
                horizontal[i]++;    // 가로 ++
                vertical[j]++;      // 세로 ++

                if(horizontal[i] == BOARD_SIZE) horizontal[i] = 0;
                if(vertical[j] == BOARD_SIZE) vertical[j] = 0;
            }
        }
    }

    // 대각선 열 체크
    for(int i = 0; i < BOARD_SIZE; i++)
    {
        if(board[i][i] == 0) diagonal[0]++;                     // \ 대각선 ++
        if(board[i][BOARD_SIZE - i - 1] == 0) diagonal[1]++;    // / 대각선 ++
    }

    if(diagonal[0] == BOARD_SIZE) diagonal[0] = 0;
    if(diagonal[1] == BOARD_SIZE) diagonal[1] = 0;
}
