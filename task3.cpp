#include <iostream>

using namespace std;

class Calculator {
public:
    double add(double a, double b) { return a + b; }
    double subtract(double a, double b) { return a - b; }
    double multiply(double a, double b) { return a * b; }
    double divide(double a, double b) { return a / b; }
};

int main() {
    Calculator calc;
    char choice;

    do {
        double num1, num2;
        char op;

        cout << "\nEnter num1, operator (+, -, *, /), num2: ";
        cin >> num1 >> op >> num2;

        cout << "Result: ";
        switch (op) {
            case '+': cout << calc.add(num1, num2); break;
            case '-': cout << calc.subtract(num1, num2); break;
            case '*': cout << calc.multiply(num1, num2); break;
            case '/': 
                if (num2 != 0) cout << calc.divide(num1, num2); 
                else cout << "Error: Division by zero!"; 
                break;
            default: cout << "Invalid operator!";
        }

        cout << "\nAgain? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}