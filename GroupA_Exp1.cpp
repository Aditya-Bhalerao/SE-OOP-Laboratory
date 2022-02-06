/*
Experiment No 1:
Implement a class Complex which represents the Complex Number data type.
Implement the following-
1.	Constructor (including a default constructor which creates the complex number 0+0i).
2.	Overload operator + to add two complex numbers.
3.	Overload operator * to multiply two complex numbers.
4.	Overload operators << and >> to print and read Complex Numbers.
*/

#include <iostream>
using namespace std;

class complexNumber // Creating Class for Complex Number
{
private:
    int real;
    int img;

public:
    complexNumber();                                        // Default Constructor
    complexNumber operator+(complexNumber);                 // Overloading + Operator
    complexNumber operator*(complexNumber);                 // Overloading * Operator
    friend ostream &operator<<(ostream &, complexNumber &); // Overloading << Operator
    friend istream &operator>>(istream &, complexNumber &); // Overloading >> Operator
};

complexNumber::complexNumber() // Default Constructor
{
    real = 0;
    img = 0;
}
complexNumber complexNumber::operator+(complexNumber c1) // Overloading + operator
{
    complexNumber temp;
    temp.real = real + c1.real;
    temp.img = img + c1.img;
    return temp;
}
complexNumber complexNumber::operator*(complexNumber c2) // Overloading * Operator
{
    complexNumber tmp;
    tmp.real = real * c2.real - img * c2.img;
    tmp.img = real * c2.img + img * c2.real;
    return tmp;
}
ostream &operator<<(ostream &o, complexNumber &y) // Overloading << Operator
{
    o << y.real << " + " << y.img << "i" << endl;
    return cout;
}
istream &operator>>(istream &i, complexNumber &x) // Overloading >> Operator
{
    i >> x.real >> x.img;
    return i;
}

int main()
{
    char option;
    complexNumber Cn1, Cn2, Cn3, Cn4;
    int flag = 1;
    while (flag == 1)
    {
        int f = 1;
        while (f == 1)
        {
            cout << "\n--------MENU--------" << endl;
            cout << "1. Addition of Complex Numbers" << endl;
            cout << "2. Multiplication of Complex Numbers" << endl;
            cout << "3. Exit\n";
            int a;
            cout << "Enter your choice from above MENU (1 to 3): ";
            cin >> a;
            if (a == 1) // Addition operation.
            {
                cout << "\nEnter Real and Imaginary part of the Complex Number 1: ";
                cin >> Cn1;
                cout << "Enter Real and Imaginary part of the Complex Number 2: ";
                cin >> Cn2;
                cout << "\nComplex Number 1: " << Cn1;
                cout << "Complex Number 2: " << Cn2;
                Cn3 = Cn1 + Cn2;
                cout << "\nAddition result:  " << Cn3 << endl;
                cout << "Do you wan to perform another operation (y/n): ";
                cin >> option;
                if (option == 'y' || option == 'Y')
                {
                    f = 1;
                }
                else
                {
                    cout << "Pragram ended.\n";
                    flag = 0;
                    f = 0;
                }
            }
            else if (a == 2) // Multiplication operation.
            {
                cout << "\nEnter Real and Imaginary part of the Complex Number 1: ";
                cin >> Cn1;
                cout << "Enter Real and Imaginary part of the Complex Number 2: ";
                cin >> Cn2;
                cout << "\nComplex Number 1: " << Cn1;
                cout << "Complex Number 2: " << Cn2;
                Cn4 = Cn1 * Cn2;
                cout << "\nMultiplication result: " << Cn4 << endl;
                cout << "Do you wan to perform another operation (y/n): ";
                cin >> option;
                if (option == 'y' || option == 'Y')
                {
                    f = 1;
                }
                else
                {
                    cout << "Program ended.\n";
                    flag = 0;
                    f = 0;
                }
            }
            else if (a == 3) // Exit
            {
                cout << "Program ended.\n";
                flag = 0;
                f = 0;
            }
            else // Error value
            {
                cout << endl;
                cout << "Enter value only between 1-3\n";
                cout << endl;
                flag = 1;
                f = 1;
            }
        }
    }
    return 0;
}
