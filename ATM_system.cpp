#include <iostream>
#include <string>

using namespace std;


const int DEFAULT_PIN = 7907;
int currentBalance = 0;
string transactionHistory[100];
int transactionCount = 0;


void showMainMenu();
void checkBalance();
void depositMoney();
void withdrawMoney();
void viewTransactionHistory();
bool authenticateUser();

int main() {

    if (!authenticateUser()) {
        cout << "\n\033[31mATM BLOCKED. Too many failed attempts.\033[0m" << endl;
        return 0;
    }

    int choice;
    do {
        showMainMenu();
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                checkBalance();
                break;
            case 2:
                depositMoney();
                break;
            case 3:
                withdrawMoney();
                break;
            case 4:
                viewTransactionHistory();
                break;
            case 5:
                cout << "\n\033[33mThank You For Using BK ATM. Goodbye!\033[0m" << endl;
                break;
            default:
                cout << "\n\033[31mInvalid Choice. Please try again.\033[0m" << endl;
        }
    } while (choice != 5);

    return 0;
}

bool authenticateUser() {
    int pin;
    int maxAttempts = 3;

    cout << "\033[36m\t\t===============================\033[0m" << endl;
    cout << "\033[36m\t\t          BK ATM SYSTEM        \033[0m" << endl;
    cout << "\033[36m\t\t===============================\033[0m" << endl;

    do {
        cout << "\tEnter your PIN: ";
        cin >> pin;
        maxAttempts--;

        if (pin == DEFAULT_PIN) {
            cout << "\n\033[32m\tLogin Successful\033[0m" << endl;
            cout << "\033[35m\tWelcome to BK ATM\033[0m" << endl;
            return true;
        } else {
            cout << "\n\033[31mWrong PIN\033[0m" << endl;
            if (maxAttempts > 0) {
                cout << "\033[33mRemaining Attempts: " << maxAttempts << "\033[0m" << endl;
            }
        }
    } while (maxAttempts > 0);

    return false;
}

void showMainMenu() {
    cout << "\n\033[34m=========== MAIN MENU ===========\033[0m" << endl;
    cout << "[1] Check Balance" << endl;
    cout << "[2] Deposit Money" << endl;
    cout << "[3] Withdraw Money" << endl;
    cout << "[4] Transaction History" << endl;
    cout << "[5] Exit" << endl;
    cout << "\033[34m=================================\033[0m" << endl;
}

void checkBalance() {
    cout << "\n\033[32mCurrent Balance: " << currentBalance << " FRW\033[0m" << endl;
}

void depositMoney() {
    int amount;
    cout << "\nEnter amount to deposit: ";
    cin >> amount;

    if (amount > 0) {
        currentBalance += amount;
        cout << "\n\033[32mDeposit Successful\033[0m" << endl;
        cout << "New Balance: " << currentBalance << " FRW" << endl;

        transactionHistory[transactionCount] = "Deposited: " + to_string(amount) + " FRW";
        transactionCount++;
    } else {
        cout << "\n\033[31mInvalid amount.\033[0m" << endl;
    }
}

void withdrawMoney() {
    int amount;
    cout << "\nEnter amount to withdraw: ";
    cin >> amount;

    if (amount > currentBalance) {
        cout << "\n\033[31mInsufficient Funds\033[0m" << endl;
    } else if (amount <= 0) {
        cout << "\n\033[31mInvalid amount.\033[0m" << endl;
    } else {
        currentBalance -= amount;
        cout << "\n\033[32mWithdrawal Successful\033[0m" << endl;
        cout << "Withdrawn Amount: " << amount << " FRW" << endl;
        cout << "Remaining Balance: " << currentBalance << " FRW" << endl;


        transactionHistory[transactionCount] = "Withdrawn: " + to_string(amount) + " FRW";
        transactionCount++;
    }
}

void viewTransactionHistory() {
    cout << "\n\033[36m====== TRANSACTION HISTORY ======\033[0m" << endl;
    if (transactionCount == 0) {
        cout << "\033[31mNo Transactions Found\033[0m" << endl;
    } else {
        for (int i = 0; i < transactionCount; i++) {
            cout << i + 1 << ". " << transactionHistory[i] << endl;
        }
    }
}