#include <iostream>
#include <fstream>
using namespace std;
class order
{
public:
    string type_of_food;
    int price_of_food;
    int date;
    string name;
    string phone;
};

order add_order(int food_prices[][3], char food_names[][10])
{
    order client_order;
    int food_choice;
    int date;
    string name;
    string tel_nimber;
    cout << "what is the order:\n kozunak -> 1\n qica -> 2\n agneshko -> 3\n->";
    while (!(food_choice < 4 && food_choice > 0))
    {
        cin >> food_choice;
    }
    cout << "date: 13,14,15:";
    while (!(date > 12 && date < 15))
    {
        cin >> date;
    }
    cin.ignore(); // take scare of new line left by cin
    cout << "\nenter name:";
    getline(cin, name);
    cout << "\ntelephone number:";
    getline(cin, tel_nimber);
    client_order.type_of_food = food_names[food_choice - 1];
    client_order.date = date;
    client_order.price_of_food = food_prices[food_choice - 1][date - 13];
    client_order.name = name;
    client_order.phone = tel_nimber;
    return client_order;
}
void handle_file(order orders[])
{
    int size_of_arr = sizeof(orders) / sizeof(order);
    ofstream Orders;
    Orders.open("Orders.txt");
    for (int i = 0; i < size_of_arr; i++)
    {
        Orders << orders[i].name;
        Orders << orders[i].date;
        Orders << orders[i].type_of_food;
        Orders << orders[i].price_of_food;
        Orders << orders[i].phone;
    }
    Orders.close();
}
void all_orders_by_date(order orders[])
{
    char dates[] = {13, 14, 15};
    int size_of_arr = sizeof(orders) / sizeof(order);
    for (int i = 0; i < 3; i++)
    {
        int count = 0;
        while (count < size_of_arr)
        {
            if (orders[i].date == dates[i])
            {
                cout << orders[i].name << orders[i].type_of_food << orders[i].price_of_food << orders[i].phone;
            }
            count++;
        }
    }
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
    int i = 0;
    order orders[40];
    while (run)
    {
        int choice;
        cout << "add order -> 1\nedit order -> 2\nexit -> 3\nall orders by date -> 4\nall orders by type -> 5\ndelete order -> 6";
        cin >> choice;
        if (choice == 1)
        {
            order order = add_order(food_prices, food_names);
            orders[i] = order;
            i++;
        }
        else if (choice == 2)
        {
        }
        else if (choice == 3)
        {
            run = false;
        }
        else if (choice == 4)
        {
            all_orders_by_date(orders);
        }
        else if (choice == 5)
        {
        }
        else
        {
        }
    }
    handle_file(orders);
    return 0;
}