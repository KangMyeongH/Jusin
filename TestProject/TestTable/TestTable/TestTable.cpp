#include <iostream>

using namespace std;

int main()
{
    int iNum = 10;
    int* pNum = &iNum;
    
    ++*pNum;
    cout << *pNum << '\n';
    
    (*pNum)++;
    cout << *pNum << '\n';

    
    return 0;
}
