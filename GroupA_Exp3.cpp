/*
Experiment No 3: Imagine a publishing company which does marketing for book and audio cassette versions.
Create a class publication that stores the title(a string) and price(type float) of a publication.
From this class derive two classes: book, which adds a page count(type int), and tape, which adds a playing time in minutes(type float).
Write a program that instantiates the book and tape classes, allows user to enter data and displays the data members.
If an exception is caught, replace all the data member values with zero values.
*/

#include <iostream>
#include <string.h>

using namespace std;

class publication // Creating class publication
{
private:
    string title;
    float price;

public:
    publication();
    void add_titleprice();
    void display();
};

class book : public publication // class book, it inherits publicly from class publication.
{
private:
    int page_count;

public:
    book();
    void add_book();
    void display_book();
};

class tape : public publication // class tape, it inherits publicly from class publication.
{
private:
    float play_time;

public:
    tape();
    void add_tape();
    void display_tape();
};

// class publication functions
publication::publication()
{ // publication class default constructor
    title = "";
    price = 0;
}

void publication::add_titleprice()
{
    cout << "\nEnter the Publication information" << endl;
    cout << "\nEnter Title of the Publication: ";
    cin.ignore();
    getline(cin, title);
    cout << "Enter Price of Publication: ";
    cin >> price;
}

void publication::display()
{
    cout << "\nTitle of Publication: " << title;
    cout << "\nPublication Price: " << price;
}

// class book functions
book::book()
{ // book class default constructor
    page_count = 0;
}

void book::add_book()
{
    try
    {
        add_titleprice();
        cout << "Enter Page Count of Book: ";
        cin >> page_count;
        if (page_count <= 0)
        {
            throw page_count;
        }
    }
    catch (...)
    {
        cout << "\nInvalid Page Count." << endl;
        page_count = 0;
    }
}

void book::display_book()
{
    display();
    cout << "\nPage Count: " << page_count;
    cout << "\n------------------------------";
}

// class tape functions
tape::tape()
{ // tape class default constructor
    play_time = 0;
}

void tape::add_tape()
{
    try
    {
        add_titleprice();
        cout << "Enter Play Duration of the Tape(in minutes): ";
        cin >> play_time;
        if (play_time <= 0)
            throw play_time;
    }
    catch (...)
    {
        cout << "\nInvalid Play Time.";
        play_time = 0;
    }
}

void tape::display_tape()
{
    display();
    cout << "\nPlay Time: " << play_time << " min";
    cout << "\n------------------------------";
}

int main()
{
    tape t1[100];
    book b1[100];
    int ch, book_count = 0, tape_count = 0;

    do
    {
        cout << "\n\n     PUBLICATION DATABASE";
        cout << "\n             MENU" << endl;
        cout << "\n 1. Add a book to database.";
        cout << "\n 2. Add a tape to database.";
        cout << "\n 3. Display Books present in database.";
        cout << "\n 4. Display Tapes present in database.";
        cout << "\n 5. Exit.";
        cout << "\n\nEnter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            b1[book_count].add_book();
            book_count++;
            break;
        case 2:
            t1[tape_count].add_tape();
            tape_count++;
            break;
        case 3:
            cout << "\nBOOKS Present In Database: " << endl;
            for (int j = 0; j < book_count; j++)
            {
                b1[j].display_book();
            }
            break;
        case 4:
            cout << "\nTAPES Present In Database: " << endl;
            for (int j = 0; j < tape_count; j++)
            {
                t1[j].display_tape();
            }
            break;
        case 5:
            cout << "Program ended.";
            exit(0);
        }
    } while (ch != 5);
    return 0;
}
