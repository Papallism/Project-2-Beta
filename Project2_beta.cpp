#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 100;
int currentCustomers = 0;

struct Account{
    int number;
    int type;
    float balance;
};

struct Customer{
    char name[20];
    char address[50];
    char id[10];
    Account accounts[5];
    int totalAccounts;
};

int menu();

int main()
{
    int choice;
    do
    {
        choice = menu();
        switch(choice)
        {
            case 1: break;
            case 2: break;
            case 3: break;
            case 4: break;
            case 5: break;
            case 6: break;
            case 7: break;
            case 8: break;
            case 9: break;
            default: cout << "\nGood bye!\n";
                     break;
        }
    }while(choice != 10);
    return 0;
}

int menu()
{
    int choice;
    do
    {
        cout << "\nOperations:\n1) Add a new customer\n2) Print current total of customers\n3) Find a customer\n4) Print account holder details\n5) Print customer details\n6) Open a new account\n7) Delete customer\n8) Withdraw amount\n9) Provide reports\n10) Exit\nPlease choose operation: ";
        cin >> choice;
        if(choice < 1 || choice > 10)
            cout << "\nInvalid input!\n";
    }while(choice < 1 || choice > 10);
}
