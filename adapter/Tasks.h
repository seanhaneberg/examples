// Tasks.h
#ifndef TASKS_H
#define TASKS_H

typedef struct tm TaskTime;

enum TaskState
{
  PENDING,
  COMPLETED
};

// Forward declare
class TaskWriterAdapter;

class Task
{
public:
  Task(const char* pShortDesc, const char* pLongDesc, TaskState state, TaskTime due);
  ~Task();

  void setLongDesc(const char* pLongDesc);
  void setShortDesc(const char* pShortDesc);
  void setTaskState(TaskState state);

  void setDueTime(TaskTime due);
  char* getShortDesc();
  char* getLongDesc();
  TaskState getTaskState();

private:
  char* m_pShortDesc;
  char* m_pLongDesc;
  TaskState m_state;
  TaskTime m_due;
};

#define MAX_TASKS 100
class TaskManager
{
public:
  TaskManager(TaskWriterAdapter* writer);

  bool writeAll();
  bool writeId(int id);

  // Returns a task Id
  int addTask(Task* task);  
  Task* getTaskById(int id);

private:
  Task* _tasks[MAX_TASKS];
  int _taskCount;
  TaskWriterAdapter* _writer;
};

#endif
