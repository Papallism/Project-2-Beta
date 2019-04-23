#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 100;
int currentCustomers = 0;

struct Account{
    int number;
    int type; // 1 = checking, 2 = savings, 3 = money market
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
void addCustomer(Customer []);
int numberOfCustomers();
bool findCustomer(Customer [], char []);
void printAccHolderDetails(Customer [], int);

int main()
{
    Customer customers[MAX];
    char findID[10];
    int choice, givenAccNum;
    do
    {
        choice = menu();
        switch(choice)
        {
            case 1: addCustomer(customers);
                    break;
            case 2: cout << "\nThe number of current customers is " << numberOfCustomers() << endl;
                    break;
            case 3: cout << "\nEnter customer ID to search for: ";
                    cin >> findID;
                    if(findCustomer(customers, findID))
                        cout << "\nCustomer with given ID found!\n";
                    else
                        cout << "\nCustomer with given ID not found!\n";
                    break;
            case 4: cout << "\nPlease enter account number: ";
                    cin >> givenAccNum;
                    printAccHolderDetails(customers, givenAccNum);
                    break;
            case 5:
                    break;
            case 6:
                    break;
            case 7:
                    break;
            case 8:
                    break;
            case 9:
                    break;
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
    }while(!(choice > 0 && choice < 11));
    return choice;
}

void addCustomer(Customer cust[])
{
    cin.ignore();
    cout << "\nPlease enter customer name: ";
    cin.getline(cust[currentCustomers].name, 20);
    cout << "Please enter customer address: ";
    cin.getline(cust[currentCustomers].address, 50);
    bool check;
    do
    {
        check = false;
        cout << "Please enter customer ID: ";
        cin >> cust[currentCustomers].id;
        for(int i = 0; i < currentCustomers; i++)
        {
            if(strcmp(cust[i].id, cust[currentCustomers].id) == 0)
            {
                cout << "\nThe ID entered is already in use!\n";
                check = true;
                i = currentCustomers;
            }
        }
    }while(check);
    cust[currentCustomers].totalAccounts = 0;
    int numOfAccs;
    do
    {
        cout << "\nHow many accounts would you like to open? ";
        cin >> numOfAccs;
        if(numOfAccs > 5)
            cout << "Maximum of accounts allowed is 5!\n";
        else if(numOfAccs < 0)
            cout << "\nInvalid input!\n";
    }while(numOfAccs < 0 || numOfAccs > 5);
    for(int i = 0; i < numOfAccs; i++)
    {
        // Function 6 - open new account
    }

    currentCustomers++;
}

int numberOfCustomers()
{
    return currentCustomers;
}

bool findCustomer(Customer cust[], char givenID[])
{
    for(int i = 0; i < currentCustomers; i++)
        if(strcmp(givenID, cust[i].id) == 0)
            return true;
    return false;
}

void printAccHolderDetails(Customer cust[], int givenNum)
{
    bool found = false;
    for(int i = 0; i < currentCustomers; i++)
    {
        for(int j = 0; j < cust[i].totalAccounts; j++)
        {
            if(cust[i].accounts[j].number == givenNum)
            {
                found = true;
                cout << "\nAccount holder name: " << cust[i].name;
                cout << "\nAccount holder address: " << cust[i].address;
                cout << "\nAccount holder ID: " << cust[i].id;
            }
        }
    }
    if(!found)
        cout << "\nNo account found with such account number!\n";
}





















