#include <iostream>
using namespace std;

int main()
{
    const char* name[3] = {"도적", "전사", "마법사"};

    const char** pName = new const char*[3] {"도적", "전사", "마법사"};

    return 0;
}

