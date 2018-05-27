#include <iostream>

using namespace std;
#define tam 4

int main()
{
    int puzzle[tam][tam]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,0}};
    int (*ppuz)[tam] =puzzle;
    //int *ppuz2=&puzzle[0][0];
    cout << (int)puzzle << endl;

    cout << (int)(*(ppuz+1)+3)<< endl;
    return 0;
}
