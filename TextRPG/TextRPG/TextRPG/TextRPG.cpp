#include <iostream>
using namespace std;

enum JOB
{
    KNIGHT = 1,
    ARCHER,
    WIZARD
};

enum LEVEL
{
    EASY = 1,
    NORMAL,
    HARD
};

struct Player
{
    char* Job;
    int MaxHP;
    int HP;
    int ATK;
};

struct Monster
{
    char* Level[];
    int MaxHP;
    int HP;
    int ATK;
};

void SelectJobMenu(Player*);
void MainGame();
void SelectJob();

int main()
{
    return 0;
}

void SelectJobMenu(Player* player)
{
    while(true)
    {
        int input = 0;
        
    }
}

void MainGame()
{
    Player player;
    
}
