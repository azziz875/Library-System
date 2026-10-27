#include <iostream>
#include <string>
using namespace std;
int id[100];
string title[100];
string auther[100];
bool aval[100];
int books = 0;
void PrintList() {
    cout << 1 << ".Add Book" << endl;
    cout << 2 << ".Searching Book" << endl;
    cout << 3 << ".Removing Book" << endl;
    cout << 4 << ".Updating Book" << endl;
    cout << 5 << ".Borrowing Book" << endl;
    cout << 6 << ".returning Book" << endl;
    cout << 7 << ".Displaying Book" << endl;
}
void AddingBook() {
    int count;
    cout << "Number of Books: ";
    cin >> count;
    for (int i = 0;i < count;i++) {
        cout << "Enter Id: ";
        cin >> id[i];
        cout << "Enter Title: ";
        cin >> title[i];
        cout << "Enter Auther: ";
        cin >> auther[i];
        books++;
    }
    for (int i = 0;i < count;i++) {
        cout << "Id : " << id[i] << endl;
        cout << "Title : " << title[i] << endl;
        cout << "Auther : " << auther[i] << endl;
    }
}
string Searching() {
    int idInput;
    cout << "Enter Id: ";
    cin >> idInput;
    for (int i = 0;i<books;i++) {
        if (idInput == id[i]) {
            return "Found";
        }
    }
    return "Not Found";
}
void RemovingBook() {
    int remove;
    cout << "Enter the book id to remove : ";
    cin >> remove;
    bool flag = false;
    for (int i = 0;i < books;i++) {
        if (remove == id[i]) {
            for (int j = i;j < books - 1;j++) {
                id[j] = id[j + 1];
                title[j] = title[j + 1];
                auther[j] = auther[j + 1];
            }
            books--;
            flag = true;
            break;
        }
        

    }
    cout << "Deleted" << endl;
    for (int i = 0;i < books;i++) {
        cout << "Id : " << id[i] << endl;
        cout << "Title : " << title[i] << endl;
        cout << "Auther : " << auther[i] << endl;
    }
    
}
void UpdatingBook() {
    int idInput;
    cout << "Enter Id: ";
    cin >> idInput;
    bool flage = false;
    for (int i = 0;i<books;i++) {
        if (idInput == id[i]) {
            flage = true;
            cout << "what you want change" << endl;
            cout << 1<<".title" << endl;
            cout << 2 << ".auther" << endl;
            cout << 3 << ".both" << endl;
            int choose;
            cin >> choose;
            cout << "choose " << choose << endl;
            switch (choose) {
            case 1:
                cout << "Enter new title : "<<endl;
                cin >> title[i];
                break;
            case 2:
                cout << "Enter new auther : "<<endl;
                cin >> auther[i];
                break;
            case 3:
                cout << "Enter new title : "<<endl;
                cin >> title[i];
                cout << "Enter new auther : "<<endl;
                cin >> auther[i];
                break;
            default:
                cout << "Erorr" << endl;
            }
            break;
        }
        
    }
    if (flage == false) {
        cout << "There is no Book with this Id" << endl;
    }
}
void BorrowingBook() {
    int idInput;
    cout << "Enter Id: ";
    cin >> idInput;
    bool flage = false;
    for (int i = 0;i < books;i++) {
        if (idInput == id[i]) {
            flage = true;
            if (aval[i] == true) {
                aval[i] = false;
                cout << "You Borrowed the Book" << endl;
           }
            else {
                cout << "This Book is Borroed" << endl;
            }
            break;
        }
        }
    if (flage == false) {
        cout << "Erorr" << endl;
    }
}
void ReturningBook() {
    int idInput;
    cout << "Enter Id: ";
    cin >> idInput;
    bool flage = false;
    for (int i = 0;i < books;i++) {
        if (idInput == id[i]) {
            flage = true;
            if (aval[i]==false) {
                aval[i] = true;
                cout << "You return the Book" << endl;
            }
            else  {
                cout << "This Book is already Available" << endl;
            }
            break;
        }
    }
    if (flage == false) {
        cout << "Erorr" << endl;
    }
}
void DisplayingBook() {
    cout << "List of Books" << endl;
    for (int i = 0;i < books;i++) {
        cout << "Id: " << id[i] << endl;
        cout << "Title: " << title[i] << endl;
        cout << "Auther: " << auther[i] << endl;
        cout << "Status: ";
        if (aval[i] == true) {
            cout << "Available" << endl;
        }
        else {
            cout << "Borrowed" << endl;
        }
    }
}
int main()
{
    int choose;

    while (true) {   
        PrintList();
        cout << "Choose From List: ";
        cin >> choose;
        switch (choose) {
            case 1:
                AddingBook();
                break;
            case 2:
                cout << Searching();
                break;
            case 3:
                RemovingBook();
                break;
            case 4:
                UpdatingBook();
                break;
            case 5:
                BorrowingBook();
                break;
            case 6:
                ReturningBook();
                break;
            case 7:
                DisplayingBook();
        }
        
        cout << endl;
    }

    return 0;
}
