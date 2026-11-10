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
        {8, "J. R. R. Tolkien", "The Silmarillion", 520.00, true, 2023}};

void showBooks()
{
    cout << "\n===== BOOKS IN CATALOGUE =====\n";

    for (const auto &element : books)
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

        while (!isUniqueId)
        {
            cout << "Введіть ID книги: ";

            while (!(cin >> newBook.id))
            {
                cout << "Помилка. ID має бути числом. Спробуйте ще раз: ";
                cin.clear();
                cin.ignore(10000, '\n');
            }

            isUniqueId = true;
            for (const auto &element : books)
            {
                if (element.id == newBook.id)
                {
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
namespace searchModule
{
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
            for (char &letter : uqery)
            {
                letter = std::tolower(static_cast<unsigned char>(letter));
            }

            for (Book &book : books)
            {
                string letterbook = book.author;

                for (char &letter : letterbook)
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
            for (char &letter : uqery)
            {
                letter = std::tolower(static_cast<unsigned char>(letter));
            }

            for (Book &book : books)
            {
                string letterbook = book.title;

                for (char &letter : letterbook)
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

            while (!(cin >> availability) || (availability != 0 && availability != 1))
            {
                cout << "Enter only 0 or 1.\n";
                cin.clear();
                cin.ignore(10000, '\n');
            }

            bool wantedStock = (availability == 1);
            for (const Book &book : books)
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
}

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
            if (id == 0)
                return;

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

                while (true)
                {
                    cout << "Введіть нового автора: ";

                    if (!getline(cin, newAuthor))
                        return;

                    if (newAuthor.find_first_not_of(" \t\r\n") != string::npos)
                        break;

                    cout << "Помилка. Автор не може бути порожнім "
                            "або складатися лише з пробілів.\n";
                }

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
            editModule::editBook();
            break;
        case 4:
            searchModule::searchBooks();
            break;
        case 0:
            return 0;
        
        default:
            cout << "Помилка. Введіть цифру 0-4. Спробуйте ще раз: ";
            break;
        }
    }
    return 0;
}