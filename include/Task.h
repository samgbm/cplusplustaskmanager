#include <string>
#include <vector>
#include <ctime>

class Task
{
private:
    std::string title;
    std::string description;
    int priority;        // 1 (low) to 5 (high)
    std::string dueDate; // Format: YYYY-MM-DD
    bool completed;

public:
    Task(std::string t, std::string desc, int prio, std::string date);
    void markCompleted();
    void display() const;
    std::string getTitle() const;
    std::string getDescription() const;
    int getPriority() const;
    std::string getDueDate() const;
    bool isCompleted() const;
};