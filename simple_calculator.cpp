#include <iostream>
using namespace std;

int main() {
    double num1, num2, result;
    char operation, choice;

    // repeat the whole calculation process until user decides to stop
    do {
        // input two numbers and the operator from user
        cout << "Enter first number: ";
        cin >> num1;

        cout << "Enter operator (+, -, *, /): ";
        cin >> operation;

        cout << "Enter second number: ";
        cin >> num2;

        // perform the operation based on user input
        switch (operation) {
            case '+':
                result = num1 + num2;
                break;
            case '-':
                result = num1 - num2;
                break;
            case '*':
                result = num1 * num2;
                break;
            case '/':
                if (num2 != 0) {
                    result = num1 / num2;
                } else {
                    cout << "Error: Cannot divide by zero." << endl;
                    continue; // skip rest of this loop iteration
                }
                break;
            default:
                // handle invalid operator case
                cout << "Error: Invalid operator." << endl;
                continue;
        }

        // output the result
        cout << "Result: " << result << endl;

        // ask if user wants to calculate again
        cout << "Do you want to calculate again? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "Exiting calculator. Have a good day!" << endl;
    return 0;
}