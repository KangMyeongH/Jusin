#include <iostream>
using namespace std;

int main()
{
    FILE*   loadFile = nullptr;
    FILE*   newFile = nullptr;
    errno_t errSave = fopen_s(&loadFile, "../Data/Image.jpg", "rb");
    
    if (errSave != 0)
    {
        cout << "File open error!" << endl;
        return 0;
    }

    fseek(loadFile, 0, SEEK_END);
    const int size = ftell(loadFile);
    const auto buffer = new char[size];
    memset(buffer, 0, size);

    fseek(loadFile, 0, SEEK_SET);
    fread(buffer, sizeof(char), size, loadFile);
    fclose(loadFile);

    errSave = fopen_s(&newFile, "../Data/ImageCopy.jpg", "wb");
    
    if(errSave!= 0)
    {
        cout << "File open error!" << endl;
        return 0;
    }
    
    fwrite(buffer, 1, size, newFile);
    fclose(newFile);
    cout << size;
    delete[] buffer;
    
    return 0;
}