#include <iostream>
#include <fstream>
using namespace std;
class order
{
public:
    string type_of_food;
    int price_of_food;
    int date;
    string client;
};
order add_order(int food_prices[][3], char food_names[][10])
{
    order client_order;
    int food_choice;
    int date;
    string name;
    string tel_nimber;
    cout << "what is the order:\n kozunak -> 1\n qica -> 2\n agneshko -> 3";
    while (!(food_choice < 3 && food_choice > 0))
    {
        cin >> food_choice;
    }
    cout << "date: 13,14,15";
    while (!(date > 12 && date < 15))
    {
        cin >> date;
    }
    cout << "enter name:";
    getline(cin, name);
    cout << "\ntelephone number:";
    getline(cin, tel_nimber);
    client_order.type_of_food = food_names[food_choice - 1];
    client_order.date = date;
    client_order.price_of_food = food_prices[food_choice - 1][date - 13];
    return client_order;
}
int main(void)
{
    int food_prices[3][3] = {
        {15, 17, 18},
        {1, 2, 3},
        {18, 20, 24}};

    char food_names[3][10] = {
        "kozunak",
        "qica",
        "agneshko"};

    bool run = true;
    while (run)
    {
        int choice;
        cout << "add order -> 1\n edit order -> 2\n exit order -> 3\n";
        cin >> choice;
        if (choice == 1)
        {
            add_order(food_prices, food_names);
        }
    }
}