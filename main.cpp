#include <iostream>
using namespace std;

enum heroClass { warrior, mage, rogue };                // класс героя, который выбирает игрок
enum itemType { sword, scroll, knifes, potion };        // предмет, который подбирает игрок
// Меч - может использовать только воин, свиток - маг, ножи - берсерк, а зелье - все классы

string classOutput(heroClass player) { return (player == warrior ? "Воин" : (player == mage ? "Маг" : "Разбойник")); }
string itemOutput(itemType item) { return (item == sword ? "Меч" : (item == scroll ? "Свиток" : (item == knifes ? "Ножи" : "Зелье"))); }

// Я посчитал, что тут будет уместна именно функция, тк в таких играх
// может бить несколько игроков и для каждого будет создаватьсвя свой герой
void selectClass(heroClass *player)
{
    int input;

    cout << "Выберите класс своего героя\n";
    cout << "1 - Воин\n2 - Маг\n3 - Разбойник\n\n> ";

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

void correctChoise(itemType *item) { cout << "\nВы взяли " << itemOutput(*item) << "!\n\n"; }

void wrongChoise(heroClass *player, itemType *item) { cout << "\nКласс " << classOutput(*player) << " не может использовать " << itemOutput(*item) << "!\n\n"; }

void checkOutput(heroClass *player, itemType *item)
{
    if(*item == potion) correctChoise(item);
    else if(*player == warrior) (*item == sword ? correctChoise(item) : wrongChoise(player, item));
    else if(*player == mage) (*item == scroll ? correctChoise(item) : wrongChoise(player, item));
    else (*item == knifes ? correctChoise(item) : wrongChoise(player, item));
}

int main()
{
    int input;
    heroClass player;
    itemType item;

    selectClass(&player);

    cout << "\nВы выбрали класс: " << classOutput(player) << "\n\n";

    while(true)
    {
        cout << "Вы идете по подземелью и что-то находите...\n";
        cout << "Что это?\n\n";
        cout << "0 - Ничего! (Выйти)\n";
        cout << "1 - Меч!\n";
        cout << "2 - Свиток!\n";
        cout << "3 - Ножи!\n";
        cout << "4 - Зелье!\n\n> ";
        
        cin >> input;

        if(input == 0) break;
        else if(input == 1)
        {
            item = sword;
            checkOutput(&player, &item);
        }
        else if(input == 2)
        {
            item = scroll;
            checkOutput(&player, &item);
        }
        else if(input == 3)
        {
            item = knifes;
            checkOutput(&player, &item);
        }
        else if(input == 4)
        {
            item = potion;
            checkOutput(&player, &item);
        }
        else cout << "\nОшибка ввода!\n\n> ";
    }
}