#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>
using namespace std;

// BankAccount Class
class BankAccount {
private:
    double balance;

public:
    // Constructor
    BankAccount(double initialBalance) {
        balance = initialBalance;
    }

    // Deposit money
    bool deposit(double amount) {
        if (amount <= 0 || !isfinite(amount)) {
            return false;
        }

        balance += amount;
        return true;
    }

    // Withdraw money
    bool withdraw(double amount) {
        if (amount <= 0 || !isfinite(amount)) {
            return false;
        }

        if (amount > balance) {
            return false;
        }

        balance -= amount;
        return true;
    }

    // Get account balance
    double getBalance() const {
        return balance;
    }
};

// ATM Class
class ATM {
private:
    BankAccount &account;

    // Input validation
    double getAmount() {
        double amount;

        while (true) {
            cout << "Enter amount: Rs. ";

            if (cin >> amount && isfinite(amount)) {
                if (amount > 0) {
                    return amount;
                }
                cout << "Amount must be greater than zero!\n";
            } else {
                cout << "Invalid input! Enter a valid number.\n";
                cin.clear();
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

public:
    // Constructor
    ATM(BankAccount &acc) : account(acc) {}

    // Withdraw function
    void withdraw() {
        cout << "\n--- WITHDRAW MONEY ---\n";

        double amount = getAmount();

        if (account.withdraw(amount)) {
            cout << "Withdrawal successful!\n";
            cout << "Withdrawn: Rs. " << amount << endl;
        } else {
            cout << "Transaction failed! Insufficient balance.\n";
        }
    }

    // Deposit function
    void deposit() {
        cout << "\n--- DEPOSIT MONEY ---\n";

        double amount = getAmount();

        if (account.deposit(amount)) {
            cout << "Deposit successful!\n";
            cout << "Deposited: Rs. " << amount << endl;
        } else {
            cout << "Deposit failed!\n";
        }
    }

    // Check balance function
    void checkBalance() {
        cout << "\n--- ACCOUNT BALANCE ---\n";
        cout << "Available Balance: Rs. "
             << account.getBalance() << endl;
    }

    // Main ATM menu
    void run() {
        int choice;

        do {
            cout << "\n";
            cout << "============================\n";
            cout << "       WELCOME TO ATM       \n";
            cout << "============================\n";
            cout << "1. Check Balance\n";
            cout << "2. Deposit Money\n";
            cout << "3. Withdraw Money\n";
            cout << "4. Exit\n";
            cout << "============================\n";
            cout << "Enter your choice: ";

            if (!(cin >> choice)) {
                cout << "Invalid input! Enter a number.\n";
                cin.clear();
                cin.ignore(
                    numeric_limits<streamsize>::max(), '\n'
                );
                continue;
            }

            switch (choice) {
                case 1:
                    checkBalance();
                    break;

                case 2:
                    deposit();
                    break;

                case 3:
                    withdraw();
                    break;

                case 4:
                    cout << "\nThank you for using our ATM!\n";
                    break;

                default:
                    cout << "Invalid choice! Try again.\n";
            }

        } while (choice != 4);
    }
};

// Main Function
int main() {
    cout << fixed << setprecision(2);

    // Initial account balance
    BankAccount myAccount(5000.00);

    // Connect ATM with BankAccount
    ATM myATM(myAccount);

    // Start ATM
    myATM.run();

    return 0;
}