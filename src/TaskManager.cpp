#include "TaskManager.h"
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>

TaskManager::TaskManager(std::string fname) : filename(fname)
{
    loadFromFile();
}

void TaskManager::addTask(const Task &task)
{
    tasks.push_back(task);
}

void TaskManager::deleteTask(int index)
{
    if (index >= 0 && index < tasks.size())
    {
        tasks.erase(tasks.begin() + index);
    }
}

void TaskManager::markTaskCompleted(int index)
{
    if (index >= 0 && index < tasks.size())
    {
        tasks[index].markCompleted();
    }
}

void TaskManager::sortByPriority()
{
    std::sort(tasks.begin(), tasks.end(), [](const Task &a, const Task &b)
              {
                  return a.getPriority() > b.getPriority(); // Higher priority first
              });
}

void TaskManager::sortByDueDate()
{
    std::sort(tasks.begin(), tasks.end(), [](const Task &a, const Task &b)
              {
                  return a.getDueDate() < b.getDueDate(); // Chronological order
              });
}

void TaskManager::saveToFile()
{
    std::ofstream outFile(filename);
    for (const auto &task : tasks)
    {
        outFile << task.getTitle() << ","
                << task.getDescription() << ","
                << task.getPriority() << ","
                << task.getDueDate() << ","
                << task.isCompleted() << "\n";
    }
}

void TaskManager::loadFromFile()
{
    std::ifstream inFile(filename); // Open the file for reading
    if (!inFile.is_open())
    {
        std::cerr << "Error: Could not open file for reading. Starting with an empty task list.\n";
        return; // Exit if the file cannot be opened
    }

    std::string line;
    while (std::getline(inFile, line))
    {                               // Read each line from the file
        std::stringstream ss(line); // Use a stringstream to parse the line
        std::string title, description, dueDate;
        int priority;
        bool completed;

        // Extract fields using ',' as the delimiter
        if (std::getline(ss, title, ',') &&
            std::getline(ss, description, ',') &&
            (ss >> priority) && ss.ignore() && // Read priority and ignore the delimiter
            std::getline(ss, dueDate, ',') &&
            (ss >> completed))
        { // Read completion status
            // Create a new Task object and add it to the tasks vector
            Task task(title, description, priority, dueDate);
            if (completed)
            {
                task.markCompleted(); // Mark the task as completed if needed
            }
            tasks.push_back(task);
        }
        else
        {
            std::cerr << "Error: Failed to parse line in file. Skipping...\n";
        }
    }

    inFile.close(); // Close the file
    std::cout << "Tasks loaded successfully from " << filename << ".\n";
}

void TaskManager::displayAllTasks() const
{
    for (const auto &task : tasks)
    {
        task.display();
    }
}