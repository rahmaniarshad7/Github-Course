#include <iostream>
#include <map>
#include <string>
using namespace std;

class BankAccount
{
private:
  string accountHolder;
  double balance;
  string accountNumber;

public:
  BankAccount(string name, string accNum, double initialBalance = 0)
      : accountHolder(name), accountNumber(accNum), balance(initialBalance) {}

  void deposit(double amount)
  {
    if (amount > 0)
    {
      balance += amount;
      cout << "Deposited: $" << amount << endl;
    }
    else
    {
      cout << "Invalid deposit amount!" << endl;
    }
  }

  void withdraw(double amount)
  {
    if (amount > 0 && amount <= balance)
    {
      balance -= amount;
      cout << "Withdrawn: $" << amount << endl;
    }
    else
    {
      cout << "Invalid withdrawal amount or insufficient balance!" << endl;
    }
  }

  void checkBalance()
  {
    cout << "Account Holder: " << accountHolder << endl;
    cout << "Account Number: " << accountNumber << endl;
    cout << "Balance: $" << balance << endl;
  }

  string getAccountNumber() { return accountNumber; }
};

class Bank
{
private:
  map<string, BankAccount *> accounts;

public:
  void createAccount(string name, string accNum, double balance)
  {
    if (accounts.find(accNum) == accounts.end())
    {
      accounts[accNum] = new BankAccount(name, accNum, balance);
      cout << "Account created successfully!" << endl;
    }
    else
    {
      cout << "Account already exists!" << endl;
    }
  }

  void deposit(string accNum, double amount)
  {
    if (accounts.find(accNum) != accounts.end())
    {
      accounts[accNum]->deposit(amount);
    }
    else
    {
      cout << "Account not found!" << endl;
    }
  }

  void withdraw(string accNum, double amount)
  {
    if (accounts.find(accNum) != accounts.end())
    {
      accounts[accNum]->withdraw(amount);
    }
    else
    {
      cout << "Account not found!" << endl;
    }
  }

  void checkBalance(string accNum)
  {
    if (accounts.find(accNum) != accounts.end())
    {
      accounts[accNum]->checkBalance();
    }
    else
    {
      cout << "Account not found!" << endl;
    }
  }

  ~Bank()
  {
    for (auto &acc : accounts)
    {
      delete acc.second;
    }
  }
};

int main()
{
  Bank bank;
  int choice;

  while (true)
  {
    cout << "\n--- Banking System ---\n";
    cout << "1. Create Account\n2. Deposit\n3. Withdraw\n4. Check Balance\n5. Exit\n";
    cout << "Enter choice: ";
    cin >> choice;

    if (choice == 1)
    {
      string name, accNum;
      double balance;
      cout << "Enter account holder name: ";
      cin.ignore();
      getline(cin, name);
      cout << "Enter account number: ";
      getline(cin, accNum);
      cout << "Enter initial balance: ";
      cin >> balance;
      bank.createAccount(name, accNum, balance);
    }
    else if (choice == 2)
    {
      string accNum;
      double amount;
      cout << "Enter account number: ";
      cin.ignore();
      getline(cin, accNum);
      cout << "Enter deposit amount: ";
      cin >> amount;
      bank.deposit(accNum, amount);
    }
    else if (choice == 3)
    {
      string accNum;
      double amount;
      cout << "Enter account number: ";
      cin.ignore();
      getline(cin, accNum);
      cout << "Enter withdrawal amount: ";
      cin >> amount;
      bank.withdraw(accNum, amount);
    }
    else if (choice == 4)
    {
      string accNum;
      cout << "Enter account number: ";
      cin.ignore();
      getline(cin, accNum);
      bank.checkBalance(accNum);
    }
    else if (choice == 5)
    {
      cout << "Thank you for using our bank!" << endl;
      break;
    }
    else
    {
      cout << "Invalid choice!" << endl;
      cout << "Please try again." << endl;
    }
  }

  return 0;
}