# Library Management System

## Description
This is a simple library management system written in C. The project demonstrates basic concepts of data structures (linked lists) and dynamic memory management. It provides functionality to add, delete, and view books in the library through a command-line interface. The system is built using a `Makefile` for compilation.

---

## Features
- **Add a Book:** Add a new book with its details, including name, author, pages, year of publication, and ISBN.
- **Delete a Book:** Remove a book from the library using its ISBN.
- **View Books:** Display all books currently stored in the library.
- **Quit Application:** Exit the program gracefully, freeing allocated memory.

---

## How to Build
1. Clone this repository to your local machine:
   ```bash
   git clone https://github.com/imran-mamin/library-management.git
   cd library-management
2. Build the project using the provided Makefile:
   ```bash
   make
3. To run the application enter the following command:
   ```bash
   ./booklibrary

---

## How to Use
The program accepts commands through the command-line interface. Here are the available commands:

### Add a Book
Use the A command to add a new book. The format is:
A;name;author;pages;year_of_publication;isbn

Example:
A;The Great Gatsby;F. Scott Fitzgerald;180;1925;1234567890123

### Delete a Book
Use the D command to delete a book by its ISBN. The format is:
D;isbn

Example:
D;1234567890123

### Show All Books
Use the S command to display all books currently stored in the library:
S

### Quite the Application
Use Q command to exit the application:
Q