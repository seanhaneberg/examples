#ifndef CONSOLE_TASK_WRITER_H
#define CONSOLE_TASK_WRITER_H

class ConsoleTaskWriter : public TaskWriterAdapter
{
public:
  void write(Task* pTask);

private:
  static const char* getTimeString(TaskTime time);
  static const char* getStateName(TaskState state);
};

#endif
