#include <iostream>

using namespace std;

void Shuffle(int* _iDst, int* _iSrc)
{
    int iTemp = *_iDst;
    *_iDst = *_iSrc;
    *_iSrc = iTemp;
}

int main()
{
    int iDst = 10;
    int iSrc = 20;
    Shuffle(&iDst, &iSrc);
    cout << iDst << '\n' << iSrc;
    return 0;
}