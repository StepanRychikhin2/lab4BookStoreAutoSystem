#include <iostream>
#include <string>
#include <Windows.h>
#include <vector>
#include <cctype>
using namespace std;

void welcome()
{
    cout << "Лабораторна робота №4\n";
    cout << "На тему: Автоматизована система книжкового магазину\n";
    cout << "Виконали студенти групи ІПЗ-11(3): Андросов Богдан, Ричихін Степан, Чумак Кирил\n";
}

struct Book
{
    int id;
    std::string author;
    std::string title;
    double price;
    bool inStock;
    int year;
};

vector<Book> books =
{
    {1, "J. R. R. Tolkien", "The Hobbit", 350.00, true, 2020},
    {2, "Frank Herbert", "Dune", 420.00, true, 2021},
    {3, "George Orwell", "1984", 280.00, false, 2019},
    {4, "George Orwell", "Animal Farm", 220.00, true, 2022},
    {5, "J. R. R. Tolkien", "The Fellowship of the Ring", 480.00, true, 2020},
    {6, "J. R. R. Tolkien", "The Two Towers", 460.00, false, 2020},
    {7, "J. R. R. Tolkien", "The Return of the King", 490.00, true, 2020},
    {8, "J. R. R. Tolkien", "The Silmarillion", 520.00, true, 2023}
};

void showBooks()
{
    for (const auto& element : books)
    {
        cout << "ID: " << element.id
            << " | Author: " << element.author
            << " | Title: \"" << element.title << "\""
            << " | Price: " << element.price
            << " UAH | In Stock: " << (element.inStock ? "Yes" : "No")
            << " | Year: " << element.year << "\n";
    }
}


// ========== МОДУЛЬ ДОДАВАННЯ КНИГ ==========
namespace AddModule
{
    void addBook()
    {

    }
}

// ========== МОДУЛЬ ПОШУКУ ==========

void searchBooks()
{
    string uqery;
    int searchType;

    cout << "1 - Search by author\n";
    cout << "2 - Search by title\n";
    cout << "3 - Search by availability\n";
    cout << "Choose: ";
    cin >> searchType;

    switch (searchType)
    {
    case 1:
    {
        cout << "Enter author: ";
        getline(cin >> ws, uqery);
bool isfound = false;
        for (char& letter : uqery)
        {
            letter = std::tolower(static_cast<unsigned char>(letter));
        }

        for (Book& book : books)
        {
            string letterbook = book.author;

            for (char& letter : letterbook)
            {
                letter = std::tolower(static_cast<unsigned char>(letter));
            }

            if (letterbook.find(uqery) != string::npos)
            {

                isfound = true;
                cout << "Author: " << book.author << " | "
                     << "Title: " << book.title << " | "
                     << "Price: " << book.price << " UAH | In Stock: "
                     << (book.inStock ? "Yes" : "No")
                     << " | Year: " << book.year << "\n";
            }
        }
if (!isfound)
            {
                cout << "No books found by this author \"" << uqery << "\".\n";
            }
        break;
    }

    case 2:
    {
        cout << "Enter title: ";
        getline(cin >> ws, uqery);
 bool isfound = false;
        for (char& letter : uqery)
        {
            letter = std::tolower(static_cast<unsigned char>(letter));
        }

        for (Book& book : books)
        {
            string letterbook = book.title;

            for (char& letter : letterbook)
            {
                letter = std::tolower(static_cast<unsigned char>(letter));
            }

            if (letterbook.find(uqery) != string::npos)
            {
                isfound = true;
                cout << "Author: " << book.author << " | "
                     << "Title: " << book.title << " | "
                     << "Price: " << book.price << " UAH | In Stock: "
                     << (book.inStock ? "Yes" : "No")
                     << " | Year: " << book.year << "\n";
            } 


        }
     if (!isfound)
            {
                cout << "No books found by this name \"" << uqery << "\".\n";
            }
        break;
    }

    case 3:
    {
        int availability;

        cout << "1 - In stock, 0 - Out of stock: ";
        cin >> availability;

        if (availability != 0 && availability != 1)
        {
            cout << "Enter only 0 or 1.\n";
            break;
        }

        bool wantedStock = (availability == 1);
         for ( const Book& book : books)
        {
            if (book.inStock == wantedStock)
            {
                cout << "Author: " << book.author << " | "
                     << "Title: " << book.title << " | "
                     << "Price: " << book.price << " UAH | In Stock: "
                     << (book.inStock ? "Yes" : "No")
                     << " | Year: " << book.year << "\n";
            }
        }
         
        
        break;
    }

    default:
        cout << "Unknown option.\n";
        break;
    }
}

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    showBooks();
    return 0;
}