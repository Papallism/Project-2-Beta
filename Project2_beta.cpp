#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Account{
    int number;
    int type; // 1 = checking, 2 = savings, 3 = money market
    double balance;
};

struct Customer{
    char name[20];
    char address[50];
    char id[10];
    Account accounts[5];
    int totalAccounts;
};

const int MAX = 100;
Customer customers[MAX];
int currentCustomers = 0;

int menu();
void addCustomer(); // unfinished - missing open new account
int numberOfCustomers();
bool findCustomer(char []);
void printAccHolderDetails(int);
void printCustomerDetails(char []);
void openNewAccount(char [], char []);
void deleteCustomer(char []);

int main()
{
    char findID[10], name[20];
    int choice, givenAccNum;
    do
    {
        choice = menu();
        switch(choice)
        {
            case 1: addCustomer();
                    break;
            case 2: cout << "\nThe number of current customers is " << numberOfCustomers() << endl << endl;
                    break;
            case 3: cout << "\nEnter customer ID to search for: ";
                    cin.ignore();
                    cin.getline(findID, 10);
                    if(findCustomer(findID))
                        cout << "\nCustomer with given ID found!\n";
                    else
                        cout << "\nCustomer with given ID not found!\n";
                    break;
            case 4: cout << "\nPlease enter account number: ";
                    cin >> givenAccNum;
                    printAccHolderDetails(givenAccNum);
                    break;
            case 5: cout << "\nPlease enter customer ID: ";
                    cin.ignore();
                    cin.getline(findID, 10);
                    printCustomerDetails(findID);
                    break;
            case 6: cout << "\nEnter customer name: ";
                    cin.ignore();
                    cin.getline(name, 20);
                    cout << "Enter customer ID: ";
                    cin.getline(findID, 10);
                    openNewAccount(name, findID);
                    break;
            case 7: cout << "\nEnter customer ID: ";
                    cin.ignore();
                    cin.getline(findID, 10);
                    deleteCustomer(findID);
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
        for(int i = 0; i < 50; i++)
            cout << "-";
        cout << "\nOperations\n";
        for(int i = 0; i < 50; i++)
            cout << "-";
        cout << "\n1) Add a new customer\n2) Print current total of customers\n3) Find a customer\n4) Print account holder details\n5) Print customer details\n6) Open a new account\n7) Delete customer\n8) Withdraw amount\n9) Provide reports\n10) Exit\n\nPlease choose operation: ";
        cin >> choice;
        if(choice < 1 || choice > 10)
            cout << "\nInvalid input!\n";
    }while(!(choice > 0 && choice < 11));
    return choice;
}

void addCustomer()
{
    cin.ignore();
    cout << "\nPlease enter customer name: ";
    cin.getline(customers[currentCustomers].name, 20);
    cout << "Please enter customer address: ";
    cin.getline(customers[currentCustomers].address, 50);
    bool check;
    do
    {
        check = false;
        cout << "Please enter customer ID: ";
        cin.getline(customers[currentCustomers].id, 10);
        for(int i = 0; i < currentCustomers; i++)
        {
            if(strcmp(customers[i].id, customers[currentCustomers].id) == 0)
            {
                cout << "\nThe ID entered is already in use!\n";
                check = true;
                i = currentCustomers;
            }
        }
    }while(check);
    customers[currentCustomers].totalAccounts = 0;
    currentCustomers++;
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
        openNewAccount(customers[currentCustomers - 1].name, customers[currentCustomers - 1].id);
}

int numberOfCustomers()
{
    return currentCustomers;
}

bool findCustomer(char givenID[])
{
    for(int i = 0; i < currentCustomers; i++)
        if(strcmp(givenID, customers[i].id) == 0)
            return true;
    return false;
}

void printAccHolderDetails(int givenNum)
{
    bool found = false;
    for(int i = 0; i < currentCustomers; i++)
    {
        for(int j = 0; j < customers[i].totalAccounts; j++)
        {
            if(customers[i].accounts[j].number == givenNum)
            {
                found = true;
                cout << "\nAccount holder name: " << customers[i].name;
                cout << "\nAccount holder address: " << customers[i].address;
                cout << "\nAccount holder ID: " << customers[i].id << endl;
            }
        }
    }
    if(!found)
        cout << "\nNo account found with such account number!\n";
}

void printCustomerDetails(char givenID[])
{
    if(!findCustomer(givenID))
        cout << "\nID not found.\n";
    else
    {
        for(int i = 0; i < currentCustomers; i++)
        {
            if(strcmp(givenID, customers[i].id) == 0)
            {
                cout << "\nCustomer name: " << customers[i].name;
                cout << "\nCustomer address: " << customers[i].address << endl;
                for(int j = 0; j < customers[i].totalAccounts; j++)
                {
                    cout << "\nAccount number: " << customers[i].accounts[j].number;
                    cout << "\nAccount type: ";
                    switch(customers[i].accounts[j].type)
                    {
                        case 1: cout << "Checking account";
                                break;
                        case 2: cout << "Savings account";
                                break;
                        case 3: cout << "Money market account";
                                break;
                    }
                    cout << "\nAccount balance: " << customers[i].accounts[j].balance << endl;
                }
                i = currentCustomers;
            }
        }
    }
}

void openNewAccount(char custName[], char custID[])
{
    int i = 0;
    bool check = true, regen;
    if(!findCustomer(custID))
        cout << "\nCustomer ID not found.\n";
    else
    {
        while(check)
        {
            if(strcmp(custID, customers[i].id) == 0)
                check = false;
            i++;
        }
        i--;
        if(strcmp(custName, customers[i].name) != 0)
            cout << "\nCustomer name and ID do not match.\n";
        else
        {
            if(customers[i].totalAccounts == 5)
                cout << "\nMaximum number of accounts reached.\n";
            else
            {
                do
                {
                    regen = false;
                    srand(time(0));
                    customers[i].accounts[customers[i].totalAccounts].number = (rand() % 9000) + 1000;
                    for(int j = 0; j < currentCustomers; j++)
                        for(int k = 0; k < customers[j].totalAccounts; k++)
                            if(customers[i].accounts[customers[i].totalAccounts].number == customers[j].accounts[k].number)
                                regen = true;
                }while(regen);
                cout << "\nAccount number: " << customers[i].accounts[customers[i].totalAccounts].number;
                cout << "\nTypes of account:\n1) Checking\n2) Savings\n3) Money market\n\nPlease choose an account type: ";
                cin >> customers[i].accounts[customers[i].totalAccounts].type;
                cout << "\nEnter balance: ";
                cin >> customers[i].accounts[customers[i].totalAccounts].balance;
                customers[i].totalAccounts++;
            }
        }
    }
}

void deleteCustomer(char givenID[])
{
    int i = 0, step;
    bool check = true;
    double totBalance = 0.0;
    if(!findCustomer(givenID))
        cout << "\nCustomer ID not found.\n";
    else
    {
        while(check)
        {
            if(strcmp(givenID, customers[i].id) == 0)
                check = false;
            if(check)
                i++;
        }
        for(int j = 0; j < customers[i].totalAccounts; j++)
            totBalance += customers[i].accounts[j].balance;
        if(totBalance > 0)
            cout << "\nCustomer balance is not 0. Deletion not allowed.\n";
        else
        {
            step = i;
            while(step < currentCustomers - 1)
            {
                strcpy(customers[i].name, customers[i + 1].name);
                strcpy(customers[i].address, customers[i + 1].address);
                strcpy(customers[i].id, customers[i + 1].id);
                customers[i].totalAccounts = customers[i + 1].totalAccounts;
                for(int k = 0; k < customers[i].totalAccounts; k++)
                {
                    customers[i].accounts[k].number = customers[i + 1].accounts[k].number;
                    customers[i].accounts[k].type = customers[i + 1].accounts[k].type;
                    customers[i].accounts[k].balance = customers[i + 1].accounts[k].balance;
                }
                step++;
            }
            cout << "\nCustomer deleted.\n";
            currentCustomers--;
        }
    }
}





















