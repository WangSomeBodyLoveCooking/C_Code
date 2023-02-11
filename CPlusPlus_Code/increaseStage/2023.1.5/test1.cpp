#include <iostream>
int main()
{
    using namespace std;
    float hats = 50.25, heads = 11.17;

    
    
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout << hats << endl << heads << endl;
    cout << hats + heads << endl;
    cout << hats - heads << endl;

    cout << hats * heads << endl;

    cout << hats / heads << endl;
    system("pause");
    return 0;
}