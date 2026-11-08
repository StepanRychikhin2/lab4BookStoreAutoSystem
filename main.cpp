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
    string title;
    string author;
    int year;
    double price;
};

// Функція для збереження у файл
void saveToFile(const vector<Book>& books) {
    ofstream file("database.txt");
    for (int i = 0; i < books.size(); i++) {
        file << books[i].id << "|" << books[i].title << "|" << books[i].author
            << "|" << books[i].year << "|" << books[i].price << "\n";
    }
    file.close();
    cout << "\nДані збережено у файл!\n";
}

// Функція для відображення книг
void showBooks(const vector<Book>& books) {
    if (books.empty()) {
        cout << "Список порожній!\n";
        return;
    }
    cout << "\n--- КАТАЛОГ КНИГ ---\n";
    for (int i = 0; i < books.size(); i++) {
        cout << books[i].id << ". " << books[i].title << " (" << books[i].author << ", " << books[i].year
            << ") - " << books[i].price << " грн\n";
    }
}

// ========== МОДУЛЬ ДОДАВАННЯ КНИГ ==========


int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);


}