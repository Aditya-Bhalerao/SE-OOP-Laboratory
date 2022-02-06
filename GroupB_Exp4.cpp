/*
Experiment No 4: Write a C++ program that creates an output file, writes information to it, closes the file,
open it again as an input file and read the information from the file.
*/

#include <iostream>
#include <fstream>
using namespace std;

class Student // Creating class Student
{
private:
    string Name;
    int roll_no;
    int dob;

public:
    Student() // Student class default constructor
    {
        Name = "";
        roll_no = 0;
        dob = 0;
    }
    void accept()
    {
        cout << "Name: ";
        cin.ignore();
        getline(cin, Name);
        cout << "Roll no: ";
        cin >> roll_no;
        cout << "Date of Birth(ddmmyyyy): ";
        cin >> dob;
    }
    void display()
    {
        cout << "Name: " << Name << endl;
        cout << "Rollno: " << roll_no << endl;
        cout << "Date of Birth: " << dob << endl;
    }
};

int main()
{
    Student obj[1000];
    fstream f;
    int n;
    cout << "\n-----Adding student details to file-----";
    f.open("studentdata.txt", ios::out);  // Writing in the file
    cout << "\n\nEnter the number of students you want to store: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter details of Student " << i + 1 << "\n";
        obj[i].accept();
        f.write((char *)&obj[i], sizeof obj[i]);
    }
    cout << "\nInformation added to file." << endl;
    f.close();

    char option;
    cout << "\nEnter 'y' to display information present in the file: ";
    cin >> option;
    if (option == 'y' || option == 'Y')
    {
        cout << "\n-----Opening file to read contents in it-----" << endl;
        f.open("studentdata.txt", ios::in); // Reading from the file
        cout << "\nDetails of Students in file is as follows: \n";
        for (int i = 0; i < n; i++)
        {
            cout << "\nStudent " << i + 1 << "\n";
            f.write((char *)&obj[i], sizeof obj[i]);
            obj[i].display();
        }
        f.close();
    }
    else
    {
        cout << "Program ended.";
        exit(0);
    }

    cout << "\nProgram ended.";

    return 0;
}
