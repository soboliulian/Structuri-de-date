#include <iostream>
#include <string.h>
using namespace std;



void citire_cnp(char cnp[14])
{
    cout << "Introduceti cnp: ";
    cin.getline(cnp, 14);
}

bool eAnBisect(int numar)
{
    if ((numar % 4 == 0) && (numar % 100 != 0))
        return 1;
    if (numar % 400 == 0)
        return 1;
    return 0;
}







bool erori_citire_data_de_azi(char data_de_azi[20])
{
    int zi, luna, an;

    if (data_de_azi[9] < '0' || data_de_azi[9]>'9')


        return 0;

    if (data_de_azi[8] < '0' || data_de_azi[8]>'9')


        return 0;

    if (data_de_azi[7] < '0' || data_de_azi[7]>'9')


        return 0;

    if (data_de_azi[6] < '0' || data_de_azi[6]>'9')


        return 0;

    if (data_de_azi[4] < '0' || data_de_azi[4]>'9')


        return 0;

    if (data_de_azi[3] < '0' || data_de_azi[3]>'9')


        return 0;

    if (data_de_azi[0] < '0' || data_de_azi[0]>'9')


        return 0;

    if (data_de_azi[1] < '0' || data_de_azi[1]>'9')

        return 0;


    if (data_de_azi[2] != '.')

        return 0;


    if (data_de_azi[5] != '.')

        return 0;

    zi = (data_de_azi[0] - '0') * 10 + (data_de_azi[1] - '0');
    luna = (data_de_azi[3] - '0') * 10 + (data_de_azi[4] - '0');
    an = (data_de_azi[6] - '0') * 1000 + (data_de_azi[7] - '0') * 100 + (data_de_azi[8] - '0') * 10 + (data_de_azi[9] - '0');
    if (an < 2023)

        return 0;
    if (luna < 1 || luna>12)

        return 0;
    if ((luna == 1 || luna == 3 || luna == 5 || luna == 7 || luna == 8 || luna == 10 || luna == 12) && (zi < 1 || zi>31))

        return 0;
    if ((luna == 4 || luna == 6 || luna == 9 || luna == 11) && (zi < 1 || zi>30))

        return 0;

    if (eAnBisect(an) == 0 && (zi < 1 || zi>28))
        return 0;



    return 1;

}

void citire_data_de_azi(char data_de_azi[20], int& an_azi, int& luna_azi, int& zi_azi)
{

    cout << "Data de azi trebuie sa aiba formatul: zz.ll.aaaa" << endl;
    cout << "Introduceti data de azi: "; cin.getline(data_de_azi, 20); cout << endl;
    while (erori_citire_data_de_azi(data_de_azi) == 0)
    {
        cout << "Nu ati introdus o data valida!" << endl;
        cout << "Introduceti data de azi: "; cin.getline(data_de_azi, 20); cout << endl;

    }

    zi_azi = (data_de_azi[0] - '0') * 10 + data_de_azi[1] - '0';
    luna_azi = (data_de_azi[3] - '0') * 10 + data_de_azi[4] - '0';
    an_azi = (data_de_azi[6] - '0') * 1000 + (data_de_azi[7] - '0') * 100 + (data_de_azi[8] - '0') * 10 + (data_de_azi[9] - '0');

}


void aflare_si_afisare_data_nasterii(char cnp[14], int& an_cnp, int& luna_cnp, int& zi_cnp)
{
    an_cnp = (cnp[1] - '0') * 10 + (cnp[2] - '0');
    luna_cnp = (cnp[3] - '0') * 10 + (cnp[4] - '0');
    zi_cnp = (cnp[5] - '0') * 10 + (cnp[6] - '0');


    if (an_cnp <= 23)
        an_cnp += 2000;
    else
        an_cnp += 1900;

    cout << "Data nasterii: ";
    if (zi_cnp <= 9)
        cout << "0" << zi_cnp << ".";
    else
        cout << zi_cnp << ".";
    if (luna_cnp <= 9)
        cout << "0" << luna_cnp << ".";
    else
        cout << luna_cnp << ".";
    cout << an_cnp << endl;




}

void aflare_si_afisare_sex(char cnp[14])
{
    int sex;
    sex = cnp[0] - '0';
    if (sex % 2 == 1)
        cout << "Sex: Masculin" << endl;
    else
        cout << "Sex: Feminin" << endl;
}


void aflare_si_afisare_varsta(int an_azi, int luna_azi, int zi_azi, int an_cnp, int luna_cnp, int zi_cnp)
{
    int varsta;

    if (an_azi == an_cnp)
        varsta = 0;
    else
    {
        varsta = an_azi - an_cnp - 1;
        if (luna_cnp > luna_azi)
            varsta++;

        else if (luna_azi == luna_cnp && zi_cnp >= zi_azi)
            varsta++;


    }

    cout << "Varsta: " << varsta;

}


int main()
{
    char cnp[14], data_de_azi[20];
    int an_azi, luna_azi, zi_azi, an_cnp, luna_cnp, zi_cnp;
    citire_data_de_azi(data_de_azi, an_azi, luna_azi, zi_azi);
    cout << "Scrieti exit pentru a iesi." << endl << endl;
    while (strcmp(cnp, "exit") != 0)
    {
        cnp[0] = '\0';
        citire_cnp(cnp);
        aflare_si_afisare_sex(cnp);
        aflare_si_afisare_data_nasterii(cnp, an_cnp, luna_cnp, zi_cnp);
        aflare_si_afisare_varsta(an_azi, luna_azi, zi_azi, an_cnp, luna_cnp, zi_cnp);
        cout << endl << endl;
    }

    return 0;
}