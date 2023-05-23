#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

ifstream fin("date.in");
ofstream fout("date.out");

void citire_cnp(char cnp[13])
{
    fin >> cnp;
}

void afisare_cnp(char cnp[13])
{

    fout << cnp << endl;
}

void calculare_si_afisare_data_nasterii(char cnp[13], int& an, int& luna, int& zi)
{

    an = (cnp[1] - '0') * 10 + (cnp[2] - '0');
    luna = (cnp[3] - '0') * 10 + (cnp[4] - '0');
    zi = (cnp[5] - '0') * 10 + (cnp[6] - '0');

    if (an > 23)
        an += 1900;
    else
        an += 2000;

    fout << "Data nasterii: ";
    if (zi < 10)
        fout << "0" << zi << ".";
    else
        fout << zi << ".";
    if (luna < 10)
        fout << "0" << luna << ".";
    else
        fout << luna << ".";
    fout << an << endl;

}

void aflare_si_afisare_sex(char cnp[13])
{
    int sex;
    fout << "Sex: ";
    sex = cnp[0] - '0';
    if (sex % 2 == 1)
        fout << "masculin";
    else
        fout << "feminin";
    fout << endl;
}
void calculare_si_afisare_varsta(char cnp[13], int an, int luna, int zi)
{
    fout << "Varsta: ";
    if (an >= 2000)
        fout << 2023 - an;
    else
        fout << 2000 - an + 23;

    fout << " ani";



}

int main()
{
    int index, an, luna, zi;
    char cnp[13];

    while (fin >> index)
    {
        citire_cnp(cnp);
        fout << "Pentru cnp-ul: "; afisare_cnp(cnp);
        calculare_si_afisare_data_nasterii(cnp, an, luna, zi);
        aflare_si_afisare_sex(cnp);
        calculare_si_afisare_varsta(cnp, an, luna, zi);
        fout << endl << endl;
    }


    return 0;
}