#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#define Size 3

class Player
{
private:
    string name;
    char symbol;

public:
    Player() : name(""), symbol(' '){};
    Player(string name, char symbol) : name(name), symbol(symbol){};
    string getName()
    {
        return name;
    }
    char getSymbol()
    {
        return symbol;
    }

    void setName(string name)
    {
        this->name = name;
    }
    void setSymbol(char symbol)
    {
        this->symbol = symbol;
    }

    void Input()
    {
        cout << "Enter your name: ";
        cin >> name;
        cout << "Enter your symbol: ";
        cin >> symbol;
    }
};

class Tick_Tak_Toe
{
private:
    Player *P;
    char board[Size][Size];

public:
    Tick_Tak_Toe()
    {
        P = new Player[2];

        P[0].Input();
        P[1].Input();
    }
    void intial()
    {
        for (int i = 0; i < Size; i++)
        {
            for (int j = 0; j < Size; j++)
            {
                board[i][j] = ' ';
            }
        }
    }
    void Board_display()
    {
        cout << "  ";
        for (int i = 0; i < Size; i++)
        {
            cout << i << " ";
        }
        cout << endl;
        for (int i = 0; i < Size; i++)
        {
            cout << i << " ";
            for (int j = 0; j < Size; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }
    void check_end()
    {
        for (int k = 0; k < 2; k++)
        {
            for (int i = 0; i < Size; i++)
            {
                for (int j = 0; j < Size; j++)
                {
                    if (board[i][j] == P[k].getSymbol())
                    {
                        if (board[i][j + 1] == P[k].getSymbol() && board[i][j + 2] == P[k].getSymbol())
                        {
                            cout << P[k].getName() << " win!" << endl;
                            exit(0);
                        }
                        else if (board[i + 1][j] == P[k].getSymbol() && board[i + 2][j] == P[k].getSymbol())
                        {
                            cout << P[k].getName() << " win!" << endl;
                            exit(0);
                        }
                        else if (board[i + 1][j + 1] == P[k].getSymbol() && board[i + 2][j + 2] == P[k].getSymbol())
                        {
                            cout << P[k].getName() << " win!" << endl;
                            exit(0);
                        }
                    }
                }
            }
        }
    }

    bool check_full()
    {
        int count = 0;
        for (int k = 0; k < 2; k++)
        {
            for (int i = 0; i < Size; i++)
            {
                for (int j = 0; j < Size; j++)
                {
                    if (board[i][j] == P[k].getSymbol())
                    {
                        count++;
                    }
                }
            }
        }
        if (count == 9)
        {
            cout << "Draw!" << endl;
            exit(0);
        }
        return false;
    }

    void Play()
    {
        while (check_full() == false)
        {
            system("cls");
            int x, y;
            cout << P[0].getName() << " turn: ";
            cin >> x >> y;
            board[x][y] = P[0].getSymbol();
            Board_display();
            check_end();
            cout << P[1].getName() << " turn: ";
            cin >> x >> y;
            board[x][y] = P[1].getSymbol();
            Board_display();
            check_end();
        }
    }
    ~Tick_Tak_Toe()
    {
        delete[] P;
    }
};

int main()
{
    Tick_Tak_Toe TTT;
    cout << "Welcome to Tick Tak Toe game!" << endl;
    TTT.intial();
    TTT.Board_display();
    TTT.Play();
    return 0;
}
