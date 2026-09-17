#include <iostream>
using namespace std;

enum heroClass { warrior, mage, rogue };                // класс героя, который выбирает игрок
enum itemType { weapon, armor, potion, scroll };        // предмет, который подбирает игрок

string classOutput(heroClass player) { return (player == warrior ? "Воин" : (player == mage ? "Маг" : "Разбойник")); }

// Я посчитал, что тут будет уместна именно функция, тк в таких играх
// может бить несколько игроков и для каждого будет создаватьсвя свой герой
void selectClass(heroClass *player)
{
    int input;

    cout << "Выберите класс своего героя\n";
    cout << "1 - воин\n2 - маг\n3 - Разбойник\n\n> ";

    while(true)
    {
        cin >> input;
        if(input == 1)
        {
            *player = warrior;
            break;
        }
        else if(input == 2)
        {
            *player = mage;
            break;
        }
        else if(input == 3)
        {
            *player = rogue;
            break;
        }
        else cout << "\nОшибка ввода!\n\n> ";
    }
}

int main()
{
    heroClass player_1;

    selectClass(&player_1);

    cout << "\nВы выбрали класс: " << classOutput(player_1) << "\n\n";
}