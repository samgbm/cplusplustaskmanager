#include "TaskManager.h"
#include <iostream>
#include <string>

void displayMenu()
{
    std::cout << "\n--- Task Management System ---\n";
    std::cout << "1. Add Task\n";
    std::cout << "2. Delete Task\n";
    std::cout << "3. Mark Task as Completed\n";
    std::cout << "4. Sort Tasks by Priority\n";
    std::cout << "5. Sort Tasks by Due Date\n";
    std::cout << "6. Display All Tasks\n";
    std::cout << "0. Exit\n";
    std::cout << "-------------------------------\n";
}

int main()
{
    TaskManager manager("tasks.txt"); // Initialize task manager with file persistence
    int choice;

    do
    {
        displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore(); // Clear newline from input buffer

        switch (choice)
        {
        case 1:
        { // Add Task
            std::string title, description, dueDate;
            int priority;

            std::cout << "Enter title: ";
            std::getline(std::cin, title);

            std::cout << "Enter description: ";
            std::getline(std::cin, description);

            std::cout << "Enter priority (1-5): ";
            std::cin >> priority;
            std::cin.ignore();

            std::cout << "Enter due date (YYYY-MM-DD): ";
            std::getline(std::cin, dueDate);

            Task newTask(title, description, priority, dueDate);
            manager.addTask(newTask);
            std::cout << "Task added successfully!\n";
            break;
        }

        case 2:
        { // Delete Task
            int index;
            std::cout << "Enter the index of the task to delete: ";
            std::cin >> index;
            manager.deleteTask(index - 1); // Adjust for 0-based indexing
            std::cout << "Task deleted successfully!\n";
            break;
        }

        case 3:
        { // Mark Task as Completed
            int index;
            std::cout << "Enter the index of the task to mark as completed: ";
            std::cin >> index;
            manager.markTaskCompleted(index - 1); // Adjust for 0-based indexing
            std::cout << "Task marked as completed!\n";
            break;
        }

        case 4:
        { // Sort Tasks by Priority
            manager.sortByPriority();
            std::cout << "Tasks sorted by priority!\n";
            break;
        }

        case 5:
        { // Sort Tasks by Due Date
            manager.sortByDueDate();
            std::cout << "Tasks sorted by due date!\n";
            break;
        }

        case 6:
        { // Display All Tasks
            std::cout << "\n--- All Tasks ---\n";
            manager.displayAllTasks();
            break;
        }

        case 0:
        { // Exit
            std::cout << "Exiting the Task Management System. Goodbye!\n";
            break;
        }

        default:
        {
            std::cout << "Invalid choice. Please try again.\n";
            break;
        }
        }
    } while (choice != 0);

    manager.saveToFile(); // Save tasks to file before exiting
    return 0;
}