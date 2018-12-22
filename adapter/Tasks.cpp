#include <string.h>
#include <time.h>

#include "Tasks.h"
#include "TaskWriterAdapter.h"

Task::Task(const char* pShortDesc, const char* pLongDesc, TaskState state, TaskTime due)
  : m_pShortDesc(NULL),
    m_pLongDesc(NULL)
{
  setShortDesc(pShortDesc);
  setLongDesc(pLongDesc);
  setTaskState(state);
  setDueTime(due);
}

Task::~Task()
{
  if (m_pShortDesc)
  {
    delete m_pShortDesc;
    m_pShortDesc = NULL;
  }

  if (m_pLongDesc)
  {
    delete m_pLongDesc;
    m_pLongDesc = NULL;
  }
}

void Task::setLongDesc(const char* pLongDesc)
{
  if (m_pLongDesc)
  {
    delete m_pLongDesc;
    m_pLongDesc = NULL;
  }

  int len = strlen(pLongDesc);
  m_pLongDesc = new char[len];
  strncpy(m_pLongDesc, pLongDesc, len);
}

void Task::setShortDesc(const char* pShortDesc)
{
  if (m_pShortDesc)
  {
    delete m_pShortDesc;
    m_pShortDesc = NULL;
  }

  int len = strlen(pShortDesc);
  m_pShortDesc = new char[len];
  strncpy(m_pShortDesc, pShortDesc, len);
}

void Task::setTaskState(TaskState state)
{
  m_state = state;
}

void Task::setDueTime(TaskTime due)
{
  m_due = due;
}

char* Task::getShortDesc()
{
  return m_pShortDesc;
}

char* Task::getLongDesc()
{
  return m_pLongDesc;
}

TaskState Task::getTaskState()
{
  return m_state;
}

TaskManager::TaskManager(TaskWriterAdapter* writer)
{
  _taskCount = 0;
  _writer = writer;
}

bool TaskManager::writeAll()
{
  for (int i = 0; i < _taskCount; i++)
  {
    writeId(i);
  }

  return true;
}

bool TaskManager::writeId(int id)
{
  _writer->write(_tasks[id]);
  return true;
}

int TaskManager::addTask(Task* task)
{
  int id = _taskCount;
  _tasks[id] = task;
  _taskCount++;
  return id;
}

