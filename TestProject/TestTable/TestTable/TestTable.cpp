#include <iostream>

using namespace std;

void Test(char* name)
{
    
}

int main()
{
    char name[128] = "ABCDEF";
    char* pName = name;

    cout << &name << endl;
    Test(name);
    return 0;
}
