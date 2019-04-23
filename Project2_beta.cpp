#include <iostream>
#include <cstring>
using namespace std;

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

int main()
{
    return 0;
}
