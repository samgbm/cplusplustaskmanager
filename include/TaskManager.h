#include "Task.h"
#include <vector>
#include <fstream>

class TaskManager
{
private:
    std::vector<Task> tasks;
    std::string filename;

public:
    TaskManager(std::string fname);
    void addTask(const Task &task);
    void deleteTask(int index);
    void markTaskCompleted(int index);
    void sortByPriority();
    void sortByDueDate();
    void saveToFile();
    void loadFromFile();
    void displayAllTasks() const;
};