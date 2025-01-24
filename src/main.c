#include <stdio.h>
#include <string.h>

#include "library.h"

#define NAME_SIZE 50

/** 
 * This function processes the user input.
 * @param lib: a pointer to an instance of struct Library.
 * @param user_input (char*) input string from user.
 * @return integer telling whether the processing was successful or not.
 */
int process_command(struct Library* lib, char* user_input) {
    int result = 1;
    const char s[2] = ";";
    char* token = strtok(user_input, s);
   
    if (token == NULL) {
        printf("Please enter a valid command. To see possible commands, please, use the README.md for reference.\n");
        return -1;
    }
   
    char c = (*token); // Read a given command.
    char isbn[14];

    switch (c)
    {
        case 'A': // Add book command.
            char name[NAME_SIZE];
            token = strtok(NULL, s);
            
            if (token == NULL) {
                printf("Invalid input for the name field. Please enter 'A;name;author;pages;year of publication;isbn' \n");
                return -1;
            }
            
            strncpy(name, token, sizeof(name) - 1);
            name[NAME_SIZE - 1] = '\0';

            char author[NAME_SIZE];
            token = strtok(NULL, s);
            
            if (token == NULL) {
                printf("Invalid input for the author field. Please enter 'A;name;author;pages;year of publication;isbn' \n");
                return -1;
            }
            
            strncpy(author, token, sizeof(author) - 1);
            author[NAME_SIZE - 1] = '\0';

            token = strtok(NULL, s);
            if (token == NULL) {
                printf("Invalid input for pages field. Please enter 'A;name;author;pages;year of publication;isbn' \n");
                return -1;
            }

            int pages = (int) (*token);
            token = strtok(NULL, s);
            if (token == NULL) {
                printf("Invalid input for year of publication field. Please enter 'A;name;author;pages;year of publication;isbn' \n");
                return -1;
            }

            int year_of_publication = (int) (*token);
            
            token = strtok(NULL, s);
            if (token == NULL) {
                printf("Invalid input isbn field. Please enter 'A;name;author;pages;year of publication;isbn' \n");
                return -1;
            }

            strncpy(isbn, token, sizeof(isbn) - 1);
            isbn[13] = '\0';
            
            printf("\nAdding a book was successful.\n");
            add_book(lib, name, author, pages, year_of_publication, isbn);
            break;
        case 'D': // Delete book command.
            token = strtok(NULL, s);
            if (token == NULL) {
                printf("Invalid input for isbn field. Please enter 'D;isbn'.\n");
                return -1;
            }
            strncpy(isbn, token, sizeof(isbn) - 1);
            delete_book(lib, isbn);
            break;
        case 'Q': // Quit command.
            printf("Stop command encountered.\n");
            result = 0;
            break;
        case 'S': // Show command.
            show_library(lib);
            break;
        case 'U': // Update command.
            // TODO: Update the information about the book.
            printf("Update a book\n");
            break;
        default:
            printf("Please enter a valid command. To see possible commands, please, use the README.md for reference.\n");
    }

    return result;
}

/** The main function, which initializes library, takes commands from the user input
 *  and passes it to process_command function. The execution stops, when the user enters
 *  stop command 'Q'.
 *  @return integer, which tells whether the execution was successful (return 0) or not
 *  return (-1).
 */
int main() {
    struct Library* lib = init_library();

    // Get the input from the user until 'Q' command is encountered.
    while (1) {
        char user_input[140];
    
        printf("Please, enter the command that you want to execute\n");
        if (fgets(user_input, sizeof(user_input), stdin) != NULL) {
            const int res_process_command = process_command(lib, user_input);

            if (res_process_command == 0) {
                break;
            }
        }
    }

    // Free the allocated memory: library, books.
    free_memory(lib);
    
    return 0;
}