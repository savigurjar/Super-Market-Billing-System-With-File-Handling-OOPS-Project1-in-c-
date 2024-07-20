#include <iostream>
#include <fstream>
#include <sstream>
#include <windows.h>
using namespace std;

class Bill
{
private:
    string Item;
    int Rate, Quantity;

public:
    Bill() : Item(""), Rate(0), Quantity(0) {}

    void setItem(string item)
    {
        Item = item;
    }
    void setRate(int rate)
    {
        Rate = rate;
    }
    void setQuant(int quant)
    {
        Quantity = quant;
    }

    string getItem()
    {
        return Item;
    }
    int getRate()
    {
        return Rate;
    }
    int getQuant()
    {
        return Quantity;
    }
};
void addItem(Bill b)
{
    bool close = false;
    while (!close)
    {
        int choice;
        cout << "\t1.Add." << endl;
        cout << "\t2.Close." << endl;
        cout << "\tEnter Choice: ";
        cin >> choice;

        if (choice == 1)
        {
            system("cls");
            string item;
            int rate, quant;

            cout << "\tEnter Item Name: ";
            cin >> item;
            b.setItem(item);

            cout << "\tEnter Rate Of Item: ";
            cin >> rate;
            b.setRate(rate);

            cout << "\tEnter Quantity Of Item: ";
            cin >> quant;
            b.setQuant(quant);

            ofstream out("D:/project/Super Market Billing System With File Handling & OOPS/Bill.txt", ios::app);
            if (!out)
            {
                cout << "\tError: File can't Open!" << endl;
            }
            else
            {
                out << "\t" << b.getItem() << " : " << b.getRate() << " : " << b.getQuant() << endl
                    << endl;
            }
            out.close();
            cout << "\tItem Added Successfuly" << endl;
            Sleep(3000);
        }

        else if (choice == 2)
        {
            system("cls");
            close = true;
            cout << "\tBack to Main Menu!" << endl;
            Sleep(3000);
        }
    }
}

void printBill()
{
    system("cls");
    int count = 0;
    bool close = false;
    while (!close)
    {
        system("cls");
        int choice;
        cout << "\t1.Add." << endl;
        cout << "\t2.Close Session." << endl;
        cout << "\tEnter Choice: ";
        cin >> choice;

        if (choice == 1)
        {
            string item;
            int quant;
            cout << "\tEnter Item: ";
            cin >> item;
            cout << "\tEnter Quantity: ";
            cin >> quant;

            ifstream in("D:/project/Super Market Billing System With File Handling & OOPS/Bill.txt");
            ofstream out("D:/project/Super Market Billing System With File Handling & OOPS/Bill temp.txt");

            string line;
            bool found = false;

            while (getline(in, line)) // data enter and assign
            {
                stringstream ss(line);
                string itemName;
                int itemRate, itemQuant;
                char delimiter;

                ss >> itemName >> delimiter >> itemRate >> delimiter >> itemQuant;

                if (item == itemName)
                {
                    found = true;
                    if (quant <= itemQuant)
                    {
                        int amount = itemRate * quant;
                        cout << "\t Item | Rate | Quantity | Amount" << endl;
                        cout << "\t" << itemName << " " << itemRate << " " << quant << " " << amount << endl;
                        int newQuant = itemQuant - quant;
                        itemQuant = newQuant;
                        count += amount;

                        out << itemName << " : " << itemRate << " : " << itemQuant << endl;
                    }
                    else
                    {
                        // not enough quantity
                        cout << "\tSorry, " << item << " Ended!" << endl;
                    }
                }
                else
                {
                    // not item found
                    out << line << endl;
                }
            }
            if (!found)
            {
                cout << "\tItem Not Available!" << endl;
            }
            out.close();
            in.close();
            remove("D:/project/Super Market Billing System With File Handling & OOPS/Bill.txt");
            rename("D:/project/Super Market Billing System With File Handling & OOP/Bill temp.txt", "D:/project/Super Market Billing System With File Handling & OOPS/Bill.txt");
        }
        else if (choice == 2)
        {
            close = true;
            cout << "\tCounting Total Bill" << endl;
        }
        Sleep(3000);
    }
    system("cls");
    cout << endl
         << endl;
    cout << "\t Total Bill -------------------- : " << count << endl
         << endl;
    cout << "\tThanks For Shopping!" << endl;
    Sleep(5000);
}
int main()
{
    Bill b;

    bool exit = false;
    while (!exit)
    {
        system("cls");
        int val;
        cout << "\tWelcome To Super Market Billing System" << endl;
        cout << "\t**************************************" << endl;
        cout << "\t\t1.Add Item." << endl;
        cout << "\t\t2.Print Bill." << endl;
        cout << "\t\t3.Exit." << endl;
        cout << "\t\tEnter Choice: ";
        cin >> val;

        if (val == 1)
        {
            system("cls");
            addItem(b);
            Sleep(3000);
        }
        else if (val == 2)
        {
            printBill();
        }
        else if (val == 3)
        {
            system("cls");
            exit = true;
            cout << "\tGood Luck!" << endl;
            Sleep(3000);
        }
    }
}