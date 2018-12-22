// TaskWriterAdapter.h
#ifndef TASK_WRITER_ADAPTER_H
#define TASK_WRITER_ADAPTER_H

// Forward declare
class Task;

class TaskWriterAdapter
{
public:
  // Does this take in a single task and write it to particular source?
  // Could it write multiple tasks at once?
  virtual void write(Task* t) = 0;
};

#endif
