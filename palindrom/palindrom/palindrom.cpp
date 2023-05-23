#include <iostream>

using namespace std;


bool palindrom(unsigned long long int numar)
{
    unsigned long long int v[100], nrcif = 0;
    while (numar)
    {
        v[++nrcif] = numar % 10;
        numar /= 10;
    }
    int i = 1, j = nrcif;
    while (i < j)
    {
        if (v[i] != v[j])
            return 0;
        i++;
        j--;
    }
    return 1;
}





int main()
{
    unsigned long long int numar = 0;

    cout << "Scrieti -1 pentru a iesi. Introduceti doar numere pozitive." << endl << endl;

    while (numar != -1)
    {
        cout << "Introduceti numarul: "; cin >> numar;
        if (palindrom(numar) == 1)
            cout << "Numarul " << numar << " este palindrom." << endl << endl;
        else cout << "Numarul " << numar << " NU este palindrom." << endl << endl;
    }



    return 0;
}