#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    unsigned char blist[4];
    float temp  = 0.01;
    unsigned  char* btemp = (unsigned char*)&temp;
    blist[0] = *btemp;
    blist[1] = *(btemp + 1);
    blist[2] = *(btemp + 2);
    blist[3] = *(btemp + 3);
    int a[4];
    for(int i = 3; i >= 0; i--)
    {
        a[i] = (int)blist[i];
        if(a[i] < 16)
            cout << setiosflags(ios::uppercase) << std::hex << "0" << (int)blist[i] << " ";
        else
            cout << setiosflags(ios::uppercase) << std::hex << (int)blist[i] <<"";
    }
    dec(cout);
    cout << endl;
    std::cout << "Hello world" << std::endl;
    return 0;
}

