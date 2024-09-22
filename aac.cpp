#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

class Account{
private:
    string name;
    int acctNo;
    int acctType; // 1 for savings, 2 for current
    double balance;
public:
    Account(string Name, int AcctNo, int AcctType, double Balance) {
        name = Name;
        acctNo = AcctNo;
        acctType = AcctType; // 1 for savings, 2 for current
        balance = Balance;
    }

    string getName() {
        return name;
    }
    int getAcctNo() {
        return acctNo;
    }
    int getAcctType() {
        return acctType;
    }
    double getBal() {
        return balance;
    }
    double updateBal(double Amount) {
        balance += Amount;
        return balance;
    }
};

class Bank {
private:
    vector<Account> accounts;

    int generateAcctNo() {
        return accounts.size() + 1;
    }
public:
    void createAccount(string Name, int AcctType, double Balance) {
        int AcctNo = generateAcctNo();
        accounts.push_back(Account(Name, AcctNo, AcctType, Balance));
    }

    void getBalance(int AcctNo, int AcctType) {
        for (auto &acct : accounts) {
            if (acct.getAcctNo() == AcctNo && acct.getAcctType() == AcctType) {
                int acctNo = acct.getAcctNo();
                string name = acct.getName();
                int acctType = acct.getAcctType();
                double balance = acct.getBal();

                cout << "\n-[Account Details for " << name << ":]-" << endl;
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
        cout << "Account not found! >:(";
    }

    void deposit(int AcctNo, int AcctType, double Amount) {
        for (auto &acct : accounts) {
            if (acct.getAcctNo() == AcctNo && acct.getAcctType() == AcctType) {
                if (Amount > 0) {
                    int acctNo = acct.getAcctNo();
                    string name = acct.getName();
                    int acctType = acct.getAcctType();
                    double balance = acct.getBal();

                    cout << "Deposit Success for " << name << "!" << endl;
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
                } else {
                    cout << "Invalid Input! >:(" << endl;
                    return;
                }
            }
        }
        cout << "Account not found! :(" << endl;
    }

    void withdraw(int AcctNo, int AcctType, double Amount) {
        for (auto &acct : accounts) {
            if (acct.getAcctNo() == AcctNo && acct.getAcctType() == AcctType) {
                if (Amount > 0) {
                    int acctNo = acct.getAcctNo();
                    string name = acct.getName();
                    int acctType = acct.getAcctType();
                    double balance = acct.getBal();

                    if (balance >= Amount) {
                        cout << "Withdraw Success for " << name << "!" << endl;
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
                    } else {
                        cout << "Insufficient Funds! :(";
                        return;
                    }
                } else {
                    cout << "Invalid Input! >:(" << endl;
                    return;
                }
            }
        }
        cout << "Account not found! :(" << endl;
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

    while (running) {
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
                    bank.createAccount(name, acctType, 1000.0);
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