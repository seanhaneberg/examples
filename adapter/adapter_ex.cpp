#include <stdio.h>
#include <time.h>

#include "Tasks.h"
#include "TaskWriterAdapter.h"
#include "ConsoleWriterAdapter.h"

int main()
{
  TaskTime due;
  Task t1("foo", "bar", PENDING, due);
  Task t2("foo", "bat", COMPLETED, due);
  Task t3("fop", "bar", PENDING, due);

  ConsoleTaskWriter writer;

  // Inject the writer as a dependency
  TaskManager manager(&writer);
  manager.addTask(&t1);
  manager.addTask(&t2);
  manager.addTask(&t3);
  manager.writeAll();

  return 0;
}
