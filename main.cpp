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

string getStr()
{
    string accName;
    cout << ">";
    getline(cin, accName);
    return accName;
}

typedef struct userAccount
{
    int id;
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

            users.push({users.length + 1, accName, 0});
        }

        if (command.compare("1") == 0)
        {
            string accName = getStr("user's name");

            for (int i = 0; i < users.length; i++)
            {
                userAccount account = users.accounts[i];
                if (account.name.compare(accName) == 0)
                {
                    for (;;)
                    {
                        cout << account.name << " | "
                             << "$" << account.money << endl;

                        cout << "0 - return | 1 - add money | 2 - subtract amount" << endl;

                        string cmd = getStr();

                        if (cmd.compare("0") == 0)
                            break;

                        if (cmd.compare("1") == 0)
                        {
                            string amountToAdd = getStr("Enter amount to add");

                            int num = stoi(amountToAdd);

                            if (num > 0)
                            {
                                account.money += num;
                            }
                        }

                        if (cmd.compare("2") == 0)
                        {
                            string amountToSub = getStr("Enter amount to add");

                            int num = stoi(amountToSub);

                            if (num > 0)
                            {
                                account.money -= num;
                            }
                        }
                    }
                }
            }
        }
    }
}