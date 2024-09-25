#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

class Account{ // account class
private:
    string name;
    int acctNo;
    int acctType; // 1 for savings, 2 for current
    double balance;
public:
    Account(string Name, int AcctNo, int AcctType, double Balance) { // used to create an account
        name = Name;
        acctNo = AcctNo;
        acctType = AcctType; // 1 for savings, 2 for current
        balance = Balance;
    }

    string getName() { // returns account name
        return name;
    }
    int getAcctNo() { // returns account number
        return acctNo;
    }
    int getAcctType() { // returns account type
        return acctType;
    }
    double getBal() { // returns account balance
        return balance;
    }
    double updateBal(double Amount) { // updates account balance
        balance += Amount;
        return balance;
    }
};

class Bank { // bank class
private:
    vector<Account> accounts; // vector for storing accounts

    int generateAcctNo() { // function to generate an account number
        return accounts.size() + 1;
    }
public:
    void createAccount(string Name, int AcctType, double Balance) { // function to create an account
        int AcctNo = generateAcctNo();
        accounts.push_back(Account(Name, AcctNo, AcctType, Balance));
    }

    void getBalance(int AcctNo, int AcctType) { // function to get account balance
        for (auto &acct : accounts) {
            if (acct.getAcctNo() == AcctNo && acct.getAcctType() == AcctType) { // searches the vector for the account
                int acctNo = acct.getAcctNo();
                string name = acct.getName();
                int acctType = acct.getAcctType();
                double balance = acct.getBal();

                cout << "\n-[Account Details for " << name << ":]-" << endl; // displays account info
                cout << "Account Number: " << acctNo << endl;
                if (acctType == 1) {
                    cout << "Account Type: Savings" << endl;
                } else {
                    cout << "Account Type: Current" << endl;
                }
                cout << "Account Balance: " << balance << endl;
                cout << "Thank you for banking with ODB! :D";
                return;
            }
        }
        cout << "Account not found! >:("; // cout this if not found
    }

    void deposit(int AcctNo, int AcctType, double Amount) { // function to deposit funds to an account
        for (auto &acct : accounts) {
            if (acct.getAcctNo() == AcctNo && acct.getAcctType() == AcctType) { // searches the vector for the account
                if (Amount > 0) { // checks to see if deposit amount isn't <= 0
                    int acctNo = acct.getAcctNo();
                    string name = acct.getName();
                    int acctType = acct.getAcctType();
                    double balance = acct.getBal();

                    cout << "Deposit Success for " << name << "!" << endl; // displays confirmation message
                    cout << "Account Number: " << acctNo << endl;
                    if (acctType == 1) {
                        cout << "Account Type: Savings" << endl;
                    } else {
                        cout << "Account Type: Current" << endl;
                    }
                    cout << "Old Balance: " << balance << endl;
                    cout << "Deposit Amount: " << Amount << endl;
                    acct.updateBal(Amount);
                    cout << "New Balance: " << acct.getBal() << endl;
                    cout << "Thank you for banking with ODB! :D" << endl;
                    return;
                } else { // if deposit amount is <= 0
                    cout << "Invalid Input! >:(" << endl;
                    return;
                }
            }
        }
        cout << "Account not found! :(" << endl; // couts if account is not found
    }

    void withdraw(int AcctNo, int AcctType, double Amount) { // function to withdraw funds
        for (auto &acct : accounts) {
            if (acct.getAcctNo() == AcctNo && acct.getAcctType() == AcctType) { // searches the vector for the account
                if (Amount > 0) { // checks to see if withdraw amount isn't <= 0
                    int acctNo = acct.getAcctNo();
                    string name = acct.getName();
                    int acctType = acct.getAcctType();
                    double balance = acct.getBal();

                    if (balance >= Amount) { // checks to see if there are sufficient funds
                        cout << "Withdraw Success for " << name << "!" << endl; // displays success message
                        cout << "Account Number: " << acctNo << endl;
                        if (acctType == 1) {
                            cout << "Account Type: Savings" << endl;
                        } else {
                            cout << "Account Type: Current" << endl;
                        }
                        cout << "Old Balance: " << balance << endl;
                        cout << "Withdraw Amount: " << Amount << endl;
                        acct.updateBal(Amount * -1);
                        cout << "New Balance: " << acct.getBal() << endl;
                        cout << "Thank you for banking with ODB! :D" << endl;
                        return;
                    } else { // if insufficient funds
                        cout << "Insufficient Funds! :(";
                        return;
                    }
                } else { // if withdraw amount is <= 0
                    cout << "Invalid Input! >:(" << endl;
                    return;
                }
            }
        }
        cout << "Account not found! :(" << endl; // couts if account is not found
    }
};

int main() {
    Bank bank;
    int option;
    int opType;
    int acctType;
    int acctNo;
    double amount;
    bool running = true;
    string name;

    while (running) { // main program loop
        cout << "\n-[ODB BANK]-" << endl;
        cout << "[1] Savings Account" << endl;
        cout << "[2] Current Account" << endl;
        cout << "[3] Create Account" << endl;
        cout << "[4] Exit" << endl;
        cout << "INPUT: ";
        cin >> option;
        cin.clear();
        cin.ignore();

        switch (option) {
            case 1:
                cout << "-[SAVINGS MENU]-" << endl;
                cout << "[1] Deposit" << endl;
                cout << "[2] Withdraw" << endl;
                cout << "[3] Check Balance" << endl;
                cout << "[4] Exit" << endl;
                cout << "INPUT: ";
                cin >> opType;
                cin.clear();
                cin.ignore();
                
                switch (opType) {
                    case 1:
                        cout << "Enter Account Number: ";
                        cin >> acctNo;
                        cin.clear();
                        cin.ignore();
                        cout << "Enter Amount: ";
                        cin >> amount;
                        cin.clear();
                        cin.ignore();
                        bank.deposit(acctNo, option, amount);
                        break;
                    
                    case 2:
                        cout << "Enter Account Number: ";
                        cin >> acctNo;
                        cin.clear();
                        cin.ignore();
                        cout << "Enter Amount: ";
                        cin >> amount;
                        cin.clear();
                        cin.ignore();
                        bank.withdraw(acctNo, option, amount);
                        break;

                    case 3:
                        cout << "Enter Account Number: ";
                        cin >> acctNo;
                        bank.getBalance(acctNo, acctType);
                        break;

                    default:
                        cout << "Invalid Input! >:(";
                }
                break;
            
            case 2:
                cout << "-[CURRENT MENU]-" << endl;
                cout << "[1] Deposit" << endl;
                cout << "[2] Withdraw" << endl;
                cout << "[3] Check Balance" << endl;
                cout << "[4] Exit" << endl;
                cout << "INPUT: ";
                cin >> opType;
                cin.clear();
                cin.ignore();
                
                switch (opType) {
                    case 1:
                        cout << "Enter Account Number: ";
                        cin >> acctNo;
                        cin.clear();
                        cin.ignore();
                        cout << "Enter Amount: ";
                        cin >> amount;
                        cin.clear();
                        cin.ignore();
                        bank.deposit(acctNo, option, amount);
                        break;
                    
                    case 2:
                        cout << "Enter Account Number: ";
                        cin >> acctNo;
                        cin.clear();
                        cin.ignore();
                        cout << "Enter Amount: ";
                        cin >> amount;
                        cin.clear();
                        cin.ignore();
                        bank.withdraw(acctNo, option, amount);
                        break;

                    case 3:
                        cout << "Enter Account Number: ";
                        cin >> acctNo;
                        bank.getBalance(acctNo, acctType);
                        break;

                    default:
                        cout << "Invalid Input! >:(";
                }
                break;

            case 3:
                cout << "-[CREATE ACCOUNT]-" << endl;
                cout << "Enter Account Name: ";
                getline(cin, name);
                do {
                    cout << "Account Type: " << endl;
                    cout << "[1] Savings Account" << endl;
                    cout << "[2] Current Account" << endl;
                    cout << "INPUT: ";
                    cin >> acctType;
                    cin.clear();
                    cin.ignore();
                } while (!(acctType == 1 || acctType == 2));
                if (acctType == 1) {
                    bank.createAccount(name, acctType, 1000.0); // 1000 is automatically added when creating a savings account
                } else {
                    bank.createAccount(name, acctType, 0.0);
                }
                cout << "Account Created!" << endl;
                cout << "Thank you for banking with ODB! :D" << endl;
                //cin.clear();
                //cin.ignore();

                break;

            case 4:
                running = false;
                break;

            default:
                cout << "Invalid Input! >:(" << endl;

        }
    }
    return 0;
}