/*
Experiment No 6: Write C++ program using STL for sorting and searching user defined records such as
Item records (Item code, name, cost, quantity etc) using vector container.
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Item // creating class Item
{
public:
    char name[10];
    int quantity;
    int cost;
    int code;
    bool operator==(const Item &item1)
    {
        if (code == item1.code)
            return 1;
        else
            return 0;
    }
    bool operator<(const Item &item1)
    {
        if (code < item1.code)
            return 1;
        else
            return 0;
    }
};

vector<Item> arr;

void insert() // This function inserts items.
{
    Item item1;
    cout << "\nEnter Item Name: ";
    cin >> item1.name;
    cout << "Enter Item Quantity: ";
    cin >> item1.quantity;
    cout << "Enter Item Cost: ";
    cin >> item1.cost;
    cout << "Enter Item Code: ";
    cin >> item1.code;
    cout << "\nItem added." << endl;
    arr.push_back(item1);
}

void print(Item &item1) // print function to later use in display function.
{
    cout << "\nItem Name: " << item1.name;
    cout << "\nItem Quantity : " << item1.quantity;
    cout << "\nItem Cost: " << item1.cost;
    cout << "\nItem Code: " << item1.code;
    cout << "\n---------------------------";
    cout << "\n";
}

void display() // This function prints all the items.
{
    cout << "\nPrinting Items from record: " << endl;
    for_each(arr.begin(), arr.end(), print);
}

void search() // This function searches for a particular item.
{
    vector<Item>::iterator p;
    Item item1;
    cout << "\nEnter Item Code to search: ";
    cin >> item1.code;
    p = find(arr.begin(), arr.end(), item1);
    if (p == arr.end())
    {
        cout << "\nNot found" << endl;
    }
    else
    {
        cout << "\nFound" << endl;
    }
}

bool compare(const Item &item1, const Item &item2) // Function for later using in sort function.
{
    if (item1.name != item2.name)
    {
        return item1.cost < item2.cost;
    }
    else
    {
        return item1.cost < item2.cost;
    }
}

void remove() // Function for removing a particular item.
{
    vector<Item>::iterator p;
    Item item1;
    cout << "\nEnter Item Code to remove: ";
    cin >> item1.code;
    p = find(arr.begin(), arr.end(), item1);
    if (p == arr.end())
    {
        cout << "\nNot found" << endl;
    }
    else
    {
        arr.erase(p);
        cout << "\nItem Deleted" << endl;
    }
}

int main()
{
    int ch;
    do
    {
        cout << "\n   Menu";
        cout << "\n1. Insert item.";
        cout << "\n2. Display item.";
        cout << "\n3. Search item.";
        cout << "\n4. Sort items.";
        cout << "\n5. Delete item.";
        cout << "\n6. Exit.";
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            insert();
            break;

        case 2:
            display();
            break;

        case 3:
            search();
            break;

        case 4:
            sort(arr.begin(), arr.end(), compare);
            cout << "\nSorted on Cost: ";
            display();
            break;

        case 5:
            remove();
            break;

        case 6:
            cout << "Program ended.";
            exit(0);
        }

    } while (ch != 7);
    return 0;
}
