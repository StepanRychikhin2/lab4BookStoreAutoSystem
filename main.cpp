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

// ========== МОДУЛЬ РЕДАГУВАННЯ ==========
namespace editModule
{
    void editBook()
    {
        while (true)
        {
            int id;
            cout << "\nВведіть ID книги, яку ви хочете редагувати\n"
                    "0 - вихід: ";
            while (!(cin >> id))
            {
                cout << "Помилка. ID має бути числом. Спробуйте ще раз: ";
                cin.clear();
                cin.ignore(10000, '\n');
            }
            if (id == 0) return;

            int index = -1;
            for (int i = 0; i < (int)books.size(); i++)
            {
                if (books[i].id == id)
                {
                    index = i;
                    break;
                }
            }

            if (index == -1)
            {
                cout << "Книгу з таким ID не знайдено.\n";
                continue;
            }

            cout << "\nЩо ви хочете редагувати?\n"
                    "========================================\n"
                    "1. Автор\n"
                    "2. Ціна\n"
                    "3. Наявність\n"
                    "4. Рік\n"
                    "========================================\n"
                    "Ваш вибір: ";

            int choice;
            while (!(cin >> choice) || choice < 1 || choice > 4)
            {
                cout << "Помилка. Введіть число від 1 до 4: ";
                cin.clear();
                cin.ignore(10000, '\n');
            }
            cin.ignore(10000, '\n');

            switch (choice)
            {
            case 1:
            {
                string newAuthor;
                do
                {
                    cout << "Введіть нового автора: ";
                    getline(cin, newAuthor);
                } while (newAuthor.empty());
                books[index].author = newAuthor;
                break;
            }
            case 2:
            {
                double newPrice;
                cout << "Введіть нову ціну (грн): ";
                while (!(cin >> newPrice) || newPrice <= 0)
                {
                    cout << "Помилка. Ціна має бути додатним числом. Спробуйте ще раз: ";
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
                books[index].price = newPrice;
                break;
            }
            case 3:
            {
                int stockInput;
                cout << "Чи є книга в наявності? (1 - так, 0 - ні): ";
                while (!(cin >> stockInput) || (stockInput != 0 && stockInput != 1))
                {
                    cout << "Помилка. Введіть лише 1 (так) або 0 (ні): ";
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
                books[index].inStock = (stockInput == 1);
                break;
            }
            case 4:
            {
                int newYear;
                cout << "Введіть новий рік видання: ";
                while (!(cin >> newYear) || newYear < 1000 || newYear > 2026)
                {
                    cout << "Помилка. Некоректний рік. Спробуйте ще раз: ";
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
                books[index].year = newYear;
                break;
            }
            }

            cout << "\nКнигу оновлено!\n";
        }
    }
}

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    showBooks();
    return 0;
}git branch --show-current