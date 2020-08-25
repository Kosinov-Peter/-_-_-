//
#include <iostream>
#include <windows.h>
#include <vector>
#include <conio.h>
using namespace std;

class Ctower
{
public:
    int color;
    int Size;
};

enum ConsoleColor
{
        Black         = 0,
        Blue          = 1,
        Green         = 2,
        Cyan          = 3,
        Red           = 4,
        Magenta       = 5,
        Brown         = 6,
        LightGray     = 7,
        DarkGray      = 8,
        LightBlue     = 9,
        LightGreen    = 10,
        LightCyan     = 11,
        LightRed      = 12,
        LightMagenta  = 13,
        Yellow        = 14,
        White         = 15
};

void SetColor(int text, int background)
{
   HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
   SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

void gotoxy(int x, int y)
{
    HANDLE StdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD  coord  = {x, y};
    SetConsoleCursorPosition(StdOut, coord);
}

void Vivod_Sterzh(int x, int y, int kol)
{

    SetColor(White, Black);
    for (int i = 0; i < 3; i++)
    {

        for (int j = 0; j < 11; j++)
        {
            gotoxy(x+i*20+10, y-j-1);
            cout << (char) 179;
        }
    }
}


void Vivod_vec(vector < vector <Ctower> > towers, int x, int y, int kol)
{

    Vivod_Sterzh(x, y, kol);

    for (int i = 0; i < 3; i++)
    {
        gotoxy(x+i*20, y);
        for (int j = 0; j < towers[i].size(); j++)
        {
            if (j == 0)
            {
                SetColor(White, Black);

                for (int q = 0; q < towers[i][j].Size; q++ )
                {
                    cout << (char) 178;
                }
            }
            else
            {
                for (int q = 0; q < towers[i][j].Size; q++ )
                {
                    cout << (char) 223;
                }
            }

         //   gotoxy(x+i*20, y-(j+1));
//            if (j >= 0)
//            {
            int sdx = towers[i][j+1].Size / 2 ;
               // gotoxy(x+i*20+j, y-(j+1));
        //    }

            gotoxy(x+i*20 + 10 - sdx, y - j - 1);

            SetColor(LightGreen, Black);


        }
    }
}

void Change ( vector < vector <Ctower> > &towers, int w, int t)
{
    Ctower chan = towers[w][towers[w].size() - 1];   // последний элемент
    towers[w].pop_back();
    towers[t].push_back(chan);
}

void Chelovek( vector < vector <Ctower> >& towers, int x, int y, int kol)
{
    cout << "Будет играть человек c " << kol << " дисками" << endl << endl;



    while (true)
    {

        system("cls");
        Vivod_vec(towers, x, y, kol);

        gotoxy(0,23);
        int w;
        int t;
        cout << "From ";
        cin >> w;
        cout << "To ";
        cin >> t;

        w--;
        t--;
        // Проверка на размеры дисков
        Ctower disk1 = towers[w][towers[w].size() - 1];
        Ctower disk2 = towers[t][towers[t].size() - 1];

        if ( disk1.Size > disk2.Size )
        {
            cout << "Недьзя больший класть на меньший" << endl;
            continue;
        }
        //

        Change (towers, w, t);

        if (towers[1].size() == kol+1 || towers[2].size() == kol+1)
        {
            cout << "YOU WIN!" << endl;
            break;
        }
    }

    Vivod_vec(towers, x, y, kol);
}




void Change_Rekyr(int kol, vector < vector <Ctower> > &towers, int x, int y, int from, int to)
{
    if ( kol == 1)
    {
        system("cls");
        Change( towers, from, to);
        Vivod_vec(towers, x, y, kol);
        Sleep(1000);// ждать 1 секунду
    }
    else
    {
        int pr = 3 - from - to;

        Change_Rekyr(kol-1, towers, x, y, from, pr);
        system("cls");
        Change( towers, from, to);
        Vivod_vec(towers, x, y, kol);
        Sleep(1000);// ждать 1 секунду
        Change_Rekyr(kol-1, towers, x, y, pr, to);
    }

}


void I_intelect(int kol, vector < vector <Ctower> > towers, int x, int y)
{

    Vivod_vec(towers, x, y, kol);
    int from = 0;
    int to = 2;
    Change_Rekyr(kol, towers, x, y, from, to);
    cout << "YOU WIN!" << endl;

}

//////////////////MAIN////////////////////////////////////

int main (int argc, char *argv[])
{
    SetColor(LightGreen, Black);
    // || Вектора ||

        vector <Ctower> tower0;
        vector <Ctower> tower1;
        vector <Ctower> tower2;


        Ctower p1;
        p1.Size = 20;
        p1.color = 1;


        tower0.push_back(p1);
        tower1.push_back(p1);
        tower2.push_back(p1);


        vector < vector <Ctower> > towers;

        towers.push_back(tower0);
        towers.push_back(tower1);
        towers.push_back(tower2);

    // || Вектора ||


    //setlocale(0,"");
    int kol; // кол-во колец
    cout << "How much kolec? (2-10): ";
    cin >> kol;
    while (kol < 2 || kol > 10)
    {
        cout << "How much kolec? (2-10): ";
        cin >> kol;
    }
    // Заполнение 1-го вектора

    for (int i = 0; i < kol; i++)
    {
        Ctower p2;
        p2.Size = 2*kol - i*2 + 1;
        p2.color = 1;
        towers[0].push_back(p2);
    }


    cout << endl;

    int igra; // кто игрет
    cout << "You-(1) или Computer-(2): ";

    cin >> igra;
    while (igra != 1 && igra != 2)
    {
        cout << "You-(1) или Computer-(2): ";
        cin >> igra;
    }

    int x = 15;
    int y = 19;


    switch(igra)
    {
        case (1):    Chelovek(towers, x, y, kol);
                    break;

        case (2):    I_intelect(kol, towers, x, y);
                    break;
    }

    gotoxy(20, 20);

    return 0;

}
