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
    cout << "\n===== BOOKS IN CATALOGUE =====\n";

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
        Book newBook;
        bool isUniqueId = false;

        while (!isUniqueId) {
            cout << "Введіть ID книги: ";

            while (!(cin >> newBook.id)) {
                cout << "Помилка. ID має бути числом. Спробуйте ще раз: ";
                cin.clear();
                cin.ignore(10000, '\n');
            }

            isUniqueId = true;
            for (const auto& element : books) {
                if (element.id == newBook.id) {
                    cout << "Книга з таким ID вже існує! ";
                    isUniqueId = false;
                    break;
                }
            }
        }

        cin.ignore(10000, '\n');

        cout << "Введіть автора книги: ";
        getline(cin, newBook.author);

        cout << "Введіть назву книги: ";
        getline(cin, newBook.title);

        cout << "Введіть ціну книги (грн): ";
        while (!(cin >> newBook.price) || newBook.price < 0) 
        {
            cout << "Помилка. Ціна має бути додатним числом. Спробуйте ще раз: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }

        int stockInput;
        cout << "Чи є книга в наявності? (1 - так, 0 - ні): ";
        while (!(cin >> stockInput) || (stockInput != 0 && stockInput != 1)) 
        {
            cout << "Помилка Введіть лише 1 (так) або 0 (ні): ";
            cin.clear();
            cin.ignore(10000, '\n');
        }
        newBook.inStock = (stockInput == 1);

        cout << "Введіть рік видання: ";
        while (!(cin >> newBook.year) || newBook.year > 2026) 
        {
            cout << "Помилка. Некоректний рік. Спробуйте ще раз: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }

        books.push_back(newBook);
        cout << "\nУспіх! Книгу \"" << newBook.title << "\" успішно додано!\n\n";
    }
}

// ========== МОДУЛЬ ПОШУКУ ==========

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    welcome();

    while (true)
    {
        int action;
        cout << "\nОберіть дію:\n"
            "1: Вивести весь каталог книг\n"
            "2: Додати книгу\n"
            "3: Редагувати книгу\n"
            "4: Пошук книги\n"
            "0: Вийти з програми\n";

        while (!(cin >> action))
        {
            cout << "Помилка. Введіть цифру 0-4. Спробуйте ще раз: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }

        switch (action)
        {
        case 1:
            showBooks();
            break;
        case 2:
            AddModule::addBook();
            break;
        case 3:
            break;
        case 4:
            break;
        case 0:
            return 0;
        }
    }
    return 0;
}