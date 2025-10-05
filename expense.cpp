#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>
using namespace std;

class Expense {
public:
    int id;
    double amount;
    string date;
    string note;

    Expense() {}
    Expense(int i, double a, string d, string n) {
        id = i;
        amount = a;
        date = d;
        note = n;
    }
};

class ExpenseTracker {
private:
    vector<Expense> expenses;
    int nextId;

public:
    ExpenseTracker() {
        nextId = 1;
        loadFromFile();
    }

    void saveToFile() {
        ofstream out("expenses.txt");
        if (!out) {
            cout << "Error saving data!" << endl;
            return;
        }
        for (auto &e : expenses) {
            out << e.id << "," << e.amount << "," << e.date << "," << e.note << endl;
        }
        out.close();
    }

    void loadFromFile() {
        ifstream in("expenses.txt");
        if (!in) return;
        expenses.clear();
        string line;
        while (getline(in, line)) {
            size_t p1 = line.find(",");
            size_t p2 = line.find(",", p1 + 1);
            size_t p3 = line.find(",", p2 + 1);

            int id = stoi(line.substr(0, p1));
            double amount = stod(line.substr(p1 + 1, p2 - p1 - 1));
            string date = line.substr(p2 + 1, p3 - p2 - 1);
            string note = line.substr(p3 + 1);

            expenses.push_back(Expense(id, amount, date, note));
            if (id >= nextId) nextId = id + 1;
        }
        in.close();
    }

    void addExpense() {
        double amount;
        string date, note;
        cout << "Enter amount: ";
        while (!(cin >> amount)) {
            cout << "Invalid input. Enter a valid amount: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin.ignore();
        cout << "Enter date (YYYY-MM-DD): ";
        getline(cin, date);
        cout << "Enter note: ";
        getline(cin, note);

        expenses.push_back(Expense(nextId++, amount, date, note));
        saveToFile();
        cout << "Expense added successfully!\n";
    }

    void viewExpenses() {
        if (expenses.empty()) {
            cout << "No expenses recorded.\n";
            return;
        }
        cout << left << setw(5) << "ID" << setw(10) << "Amount" << setw(15) << "Date" << "Note" << endl;
        cout << "--------------------------------------------------\n";
        for (auto &e : expenses) {
            cout << left << setw(5) << e.id << setw(10) << e.amount << setw(15) << e.date << e.note << endl;
        }
    }

    void updateExpense() {
        int id;
        cout << "Enter expense ID to update: ";
        cin >> id;
        cin.ignore();
        for (auto &e : expenses) {
            if (e.id == id) {
                cout << "Enter new amount: ";
                cin >> e.amount;
                cin.ignore();
                cout << "Enter new date (YYYY-MM-DD): ";
                getline(cin, e.date);
                cout << "Enter new note: ";
                getline(cin, e.note);
                saveToFile();
                cout << "Expense updated successfully!\n";
                return;
            }
        }
        cout << "Expense with ID " << id << " not found.\n";
    }

    void deleteExpense() {
        int id;
        cout << "Enter expense ID to delete: ";
        cin >> id;
        for (auto it = expenses.begin(); it != expenses.end(); ++it) {
            if (it->id == id) {
                expenses.erase(it);
                saveToFile();
                cout << "Expense deleted successfully!\n";
                return;
            }
        }
        cout << "Expense with ID " << id << " not found.\n";
    }

    void menu() {
        int choice;
        do {
            cout << "\n====== Personal Expense Tracker ======\n";
            cout << "1. Add Expense\n";
            cout << "2. View Expenses\n";
            cout << "3. Update Expense\n";
            cout << "4. Delete Expense\n";
            cout << "5. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;
            cin.ignore();
            switch (choice) {
                case 1: addExpense(); break;
                case 2: viewExpenses(); break;
                case 3: updateExpense(); break;
                case 4: deleteExpense(); break;
                case 5: cout << "Exiting... Data saved.\n"; break;
                default: cout << "Invalid choice. Try again.\n";
            }
        } while (choice != 5);
    }
};

int main() {
    ExpenseTracker tracker;
    tracker.menu();
    return 0;
}
