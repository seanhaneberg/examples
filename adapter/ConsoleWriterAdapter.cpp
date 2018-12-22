#include <stdio.h>
#include <time.h>

#include "Tasks.h"
#include "TaskWriterAdapter.h"
#include "ConsoleWriterAdapter.h"

void ConsoleTaskWriter::write(Task* pTask)
{
  if (!pTask)
  {
    return;
  }

  const char* state = getStateName(pTask->getTaskState());
  char* shortDesc = pTask->getShortDesc();
  char* longDesc = pTask->getLongDesc();
  const char* due = "TODAY";

  printf("[%s] \t %s \t %s - %s\n", state, due, shortDesc, longDesc);
}

const char* ConsoleTaskWriter::getTimeString(TaskTime time)
{
  // TODO: Actually parse out the time spec
  // Is strftime available?
  return "TODAY";
}

const char* ConsoleTaskWriter::getStateName(TaskState state)
{
  const char* name = "";
  switch(state)
  {
    case PENDING:
      name = "PENDING";
      break;
    case COMPLETED:
      name = "COMPLETED";
      break;
    default:
      name = "UNKNOWN";
      break;
  }

  return name;
}
