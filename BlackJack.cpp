#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

class Koloda
{
public:
    vector <int> coloda{ 6, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 9, 10, 10, 10, 10, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 11, 11, 11, 11 };

    void shake()
    {
        for (int i = 0; i < 36; i++)
        {
            int temp = 0;
            int temp2 = coloda[rand() % 36];

            temp = coloda[i];
            coloda[i] = coloda[temp2];
            coloda[temp2] = temp;
        }
    }
    vector <int> coloda1(36);
    void print()
    {
        for (int i = 0; i < 36; i++)
        {
            cout << coloda[i] << "  ";
            coloda1[i] = coloda[i];
        }
        cout << endl;
        for (int i = 0; i < 36; i++)
        {
            cout << coloda1[i] << " - ";
        }
        cout << endl;
    }
};

class Player : public Koloda
{
public:
    int score = 0;

    void start_play()
    {
        score += coloda[0];
        score += coloda[1];
        coloda.erase(coloda.begin());
        coloda.erase(coloda.begin());
    }
};

class Ai : public Koloda
{
public:
    int score = 0;

    void start_ai()
    {
        score += coloda[0];
        score += coloda[1];
        coloda.erase(coloda.begin());
        coloda.erase(coloda.begin());
    }
    
};


int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(NULL));
    /////////////////
    Koloda koloda;
    Player player;
    Ai ai;

    koloda.shake();
    koloda.print();
    cout << endl;
    /////////////////
    player.start_play();
    ai.start_ai();
    cout << "Ваш счёт: " << player.score;
    cout << endl;
    cout << "Счёт Ai: " << ai.score;
    cout << endl;
    if (player.score == ai.score)
    {
        cout << "Ничья" << endl;
    }
    else if (player.score < 21 and ai.score < 21)
    {

    }
    else if (player.score == 21)
    {
        cout << "Игрок получил 21" << endl;
    }
    else if (ai.score == 21)
    {
        cout << "Ai получил 21" << endl;
    }
    else if (player.score > 21)
    {
        cout << "У Игрока выпало больше 21" << endl;
    }
    else if (ai.score > 21)
    {
        cout << "У Ai выпало больше 21" << endl;
    }
}