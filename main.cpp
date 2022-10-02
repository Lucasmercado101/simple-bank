#include <iostream>
#include <cstring>
#include <string>

using namespace std;

string getStr(string name)
{
    string accName;
    cout << name << endl
         << ">";
    getline(cin, accName);
    return accName;
}
typedef struct userAccount
{
    string name;
    int money;
} userAccount;
class UsersArr
{
public:
    int size;
    int length;
    userAccount *accounts;
    UsersArr(int newSize)
    {
        size = newSize;
        accounts = (userAccount *)malloc(sizeof(userAccount) * size);
        length = 0;
    }
    ~UsersArr()
    {
        free(accounts);
    }
    void push(userAccount acc)
    {
        if (size == length + 1)
        {
            accounts =
                (userAccount *)realloc(accounts, sizeof(userAccount) * (size * 2));
            size *= 2;
        }
        accounts[length] = acc;
        length++;
    }
};
int main()
{
    UsersArr users(5);
    for (;;)
    {
        cout << "Total accounts - " << users.length
             << "\nWhat do you want to do?\n\n0 - add account | 1 - check account\n>";
        string command;
        getline(cin, command);
        if (command.compare("exit") == 0)
        {
            return 0;
        }
        if (command.compare("0") == 0)
        {
            string accName;
            cout << "account name" << endl
                 << ">";
            getline(cin, accName);
            users.push({accName, 1});
        }

        if (command.compare("1") == 0)
        {
            string accName = getStr("user's name");

            for (int i = 0; i < users.length; i++)
            {
                string name = users.accounts[i].name;
                if (name.compare(accName) == 0)
                {
                    cout << "Found!" << endl;
                }
            }
        }
    }
    cout << "not found" << endl;
    return 0;
}