#include <iostream>

using namespace std;
void Render(int* pTable, int iSize)
{
    cout << sizeof(pTable) << endl; // 출력 값 4
    
    for (int i = 0; i < iSize; i++)
    {
        cout << pTable[i] << " ";
    }
    cout << endl;
}

int main()
{
    int iArray[5] = { 1, 2, 3, 4, 5 };
    cout << iArray;
    cout << sizeof(iArray) << endl; // 출력 값 20

    Render(iArray, 5);
    return 0;
}
