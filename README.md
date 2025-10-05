## Personal Expense Tracker

A simple C++ console-based application to manage daily expenses.
This project allows users to add, view, update, and delete expense records, with all data saved in a text file for future use.

## Project Overview

The Personal Expense Tracker helps users keep track of their financial activities directly through a terminal interface.
It uses Object-Oriented Programming (OOP) concepts and File Handling to make data management efficient and persistent.

## Features

 1.Add a new expense (amount, date, note)
 2.View all saved expenses in a formatted table
 3.Update existing expense details
 4.Delete unwanted records
 5.Automatically save and load data from expenses.txt
 6.Input validation and error handling for a smooth user experience

## Concepts Used

Classes & Objects – For structuring the Expense and ExpenseTracker

Encapsulation – Data and behavior grouped in classes

File Handling (<fstream>) – To save and load expense records

Vectors (<vector>) – To store multiple expense objects dynamically

Formatting (<iomanip>) – To display data in a clean, tabular format

Validation (<limits>) – To handle invalid input safely

## File Structure
## PersonalExpenseTracker
├── expense.cpp               # Main source code
<br/>
├── expenses.txt              # Data file (auto-created)
<br>
└── README.md                 # Project documentation

## How to Run

Open your terminal or command prompt.

Navigate to the project folder.

Compile the code using:

g++ expense.cpp -o expense


Run the program:

./expense


Follow the menu instructions displayed on the screen.

## Sample Menu
====== Personal Expense Tracker ======
1. Add Expense
2. View Expenses
3. Update Expense
4. Delete Expense
5. Exit
Enter your choice:

## Example Data (expenses.txt)
1,250.50,2025-10-04,Grocery shopping
<br/>
2,1200.00,2025-10-05,Electricity bill
<br/>
3,99.99,2025-10-05,Coffee with friends

## Future Enhancements

🔹 Add category-wise expense tracking
🔹 Add total monthly/yearly expense summary
🔹 Add search/filter functionality
🔹 Use JSON or database storage instead of text file