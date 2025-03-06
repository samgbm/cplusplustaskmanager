#include "Task.h"
#include <iostream>

Task::Task(std::string t, std::string desc, int prio, std::string date)
    : title(t), description(desc), priority(prio), dueDate(date), completed(false) {}

void Task::markCompleted() { completed = true; }

void Task::display() const
{
    std::cout << "Title: " << title << "\n"
              << "Description: " << description << "\n"
              << "Priority: " << priority << "\n"
              << "Due Date: " << dueDate << "\n"
              << "Completed: " << (completed ? "Yes" : "No") << "\n\n";
}

int Task::getPriority() const { return priority; }
std::string Task::getTitle() const { return title; }
std::string Task::getDescription() const { return description; }
std::string Task::getDueDate() const { return dueDate; }

bool Task::isCompleted() const { return completed; }