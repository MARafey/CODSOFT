#include <iostream>
using namespace std;

template <typename T>
class Calculator
{
private:
    T a;
    T b;

public:
    Calculator(T a, T b) : a(a), b(b){};

    void Input()
    {
        cout << "Enterthe first numbers: ";
        cin >> a;
        cout << "Enter the second number: ";
        cin >> b;
    }

    void Menu()
    {
        cout << "1. Add" << endl;
        cout << "2. Subtract" << endl;
        cout << "3. Multiply" << endl;
        cout << "4. Divide" << endl;
        cout << "5. Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "The sum of " << a << " and " << b << " is " << add(a, b) << endl;
            break;
        case 2:

            cout << "The difference of " << a << " and " << b << " is " << subtract(a, b) << endl;
            break;
        case 3:
            cout << "The product of " << a << " and " << b << " is " << multiply(a, b) << endl;
            break;
        case 4:
            cout << "The quotient of " << a << " and " << b << " is " << divide(a, b) << endl;
            break;
        case 5:
            exit(0);
            break;
        default:
            cout << "Invalid choice!" << endl;
            break;
        }
    }

    T add(T a, T b)
    {
        return a + b;
    }

    T subtract(T a, T b)
    {
        return a - b;
    }

    T multiply(T a, T b)
    {
        return a * b;
    }

    T divide(T a, T b)
    {
        return a / b;
    }

    ~Calculator(){a = b = 0};
};

int main()
{
    Calculator<int> calc(0, 0);
    calc.Input();
    while (true)
    {
        system("cls");
        cout << "Welcome to the calculator!" << endl;
        calc.Menu();
        system("pause");
    }
    return 0;
}