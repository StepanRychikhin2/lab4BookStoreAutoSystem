#include <iostream>
#include <string>
#include <Windows.h>
#include <vector>

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

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    showBooks();
    return 0;
}