#include <iostream>

using namespace std;

void Shuffle(int* _pDst, int* _pSrc)
{
    int iTemp = *_pDst;
    *_pDst = *_pSrc;
    *_pSrc = iTemp;
}

int main()
{
    int iDst = 10;
    int iSrc = 20;
    Shuffle(&iDst, &iSrc);
    cout << iDst << '\n' << iSrc;
    return 0;
}