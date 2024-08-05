#include <iostream>
using namespace std;

enum JOB
{
    KNIGHT = 1,
    WIZARD,
    THIEF
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
    char* Level;
    int MaxHP;
    int HP;
    int ATK;
};


void MainMenu(Player*);
void SelectJobMenu(Player*);
void MainGame();
void SelectJob();

int main()
{
    
    return 0;
}

void MainMenu(Player*)
{
    while(true)
    {
        system("cls");
        cout << "1. 새로 하기 2. 이어 하기 3. 종료 : ";
        int input;
        cin >> input;
        switch (input)
        {
        case 1:
            SelectJobMenu(player);
            break;
        case 2:
            
        default:
            cout << "잘못된 입력입니다." << '\n';
            system("pause");
            break;
        }
    }
}

/*
struct Player
{
    char    Name[128];
    int     MaxHp;
    int     Hp;
    int     Atk;    
};

struct Monster
{
    char    Name[128];
    int     MaxHp;
    int     Hp;
    int     Atk; 
};

void SelectJobMenu(Player*);
void MainMenu(Player*);
void SelectLevelMenu(Player*);
void BattleMenu(Player*, Monster*);
bool Battle(Player*, Monster*);
void Attack(Player*, Monster*);

void SetPlayer(Player*, const char*, int, int);
void SetMonster(Monster*, const char*, int, int);

int main()
{
    Player player = {};
    SelectJobMenu(&player);
    MainMenu(&player);
    
    return 0;
}

void SelectJobMenu(Player* player)
{
    while(true)
    {
        system("cls");
        int input = 0;
        cout << "직업을 선택하세요(1. 전사 2. 마법사 3. 도적) : ";
        cin >> input;
        switch (input)
        {
        case 1:
            SetPlayer(player, "전사", 100, 10);
            return;
        case 2:
            SetPlayer(player, "마법사", 100, 10);
            return;
        case 3:
            SetPlayer(player, "도적", 100, 10);
            return;
        default:
            cout << "잘못된 입력입니다." << '\n';
            system("pause");
            break;
        }
    }
}

void MainMenu(Player* player)
{
    while(true)
    {
        int input = 0;
        system("cls");
        cout << "=====================================" << '\n';
        cout << "이름 : " << player->Name << '\n';
        cout << "체력 : " << player->Hp << '\t' << "공격력 : " << player->Atk << '\n';
        cout << "1. 사냥터 2. 종료 : ";
        cin >> input;
        switch (input)
        {
        case 1:
            SelectLevelMenu(player);
            break;
        case 2:
            return;
        default:
        cout << "잘못된 입력입니다." << '\n';
            system("pause");
            break;
        }
    }
}

void SelectLevelMenu(Player* player)
{
    while(true)
    {
        Monster monster = {};
        int input = 0;
        system("cls");
        cout << "=====================================" << '\n';
        cout << "이름 : " << player->Name << '\n';
        cout << "체력 : " << player->Hp << '\t' << "공격력 : " << player->Atk << '\n';
        cout << "1. 초급 2. 중급 3. 고급 4. 전 단계 : ";
        cin >> input;
        switch (input)
        {
        case 1:
            SetMonster(&monster, "초급", 30, 3);
            BattleMenu(player, &monster);
            break;
        case 2:
            SetMonster(&monster, "중급", 60, 6);
            BattleMenu(player, &monster);
            break;
        case 3:
            SetMonster(&monster, "고급", 90, 9);
            BattleMenu(player, &monster);
            break;
        case 4:
            return;
        default:
            cout << "잘못된 입력입니다." << '\n';
            system("pause");
            break;
        }
        
    }
}

void BattleMenu(Player* player, Monster* monster)
{
    while (true)
    {
        int input = 0;
        system("cls");
        cout << "=====================================" << '\n';
        cout << "이름 : " << player->Name << '\n';
        cout << "체력 : " << player->Hp << '\t' << "공격력 : " << player->Atk << '\n';
        cout << "=====================================" << '\n';
        cout << "이름 : " << monster->Name << '\n';
        cout << "체력 : " << monster->Hp << '\t' << "공격력 : " << monster->Atk << '\n';
        cout << "1. 공격 2. 도망 : ";
        cin >> input;
        switch (input)
        {
        case 1:
            if(Battle(player, monster)) return;
            break;
        case 2:
            return;
        default:
            cout << "잘못된 입력입니다." << '\n';
            system("pause");
            break;
        }
        
    }
}

bool Battle(Player* player, Monster* monster)
{
    Attack(player, monster);
    if (player->Hp <= 0)
    {
        cout << "패배" << '\n';
        system("pause");
        // 플레이어 사망 시 풀피로 부활
        player->Hp = player->MaxHp;
        return true;
    }
    if (monster->Hp <= 0)
    {
        cout << "승리" << '\n';
        system("pause");
        return true;
    }

    return false;
}

void Attack(Player* player, Monster* monster)
{
    player->Hp -= monster->Atk;
    monster->Hp -= player->Atk;
}

void SetPlayer(Player* player, const char* name, const int hp, const int atk)
{
    strcpy_s(player->Name, name);
    player->MaxHp = hp;
    player->Hp = player->MaxHp;
    player->Atk = atk;
}

void SetMonster(Monster* monster, const char* name, const int hp, const int atk)
{
    strcpy_s(monster->Name, name);
    monster->MaxHp = hp;
    monster->Hp = monster->MaxHp;
    monster->Atk = atk;
}*/
