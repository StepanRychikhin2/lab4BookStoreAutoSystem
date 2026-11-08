#include <iostream>
#include <string>
#include "../book.cpp"
using namespace std;

int main()
{
cout << "Book List:" << endl;
cout << books[0].title << books[0].price << endl;


//     const int size = 5;

//     string names[size] = {"Alice", "Bob", "Charlie", "David", "Eve"};
//     string name;

//     for (int i = 0; i < size; i++)
// {
//         cout << names[i] << endl;
//         if (names[i] == "Charlie")
//         {
//             cout << "Found Charlie!" << endl;
//             break;
//         }

//     }

    // cout << "Enter your name: ";
    // cin >> name;
    // cout << "Hello, " << name << "!" << endl;
    // std::cout << "Hello, World!" << std::endl;
    return 0;
}