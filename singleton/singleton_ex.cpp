#include <stdio.h>

class Logger
{
  public:
    // static members are shared across all instances of this class.
    static Logger* getInstance()
    {
        if (!s_instance)
        {
            s_instance = new Logger();
        }

        return s_instance;
    }

    void log(const char* message)
    {
        printf("[%d] %s\n", timesCalled, message);
        timesCalled++;
    }

  private:
    // *private* constructor, so that only 'getInstance()' may call it
    Logger() {};
    int timesCalled;

    // static members are shared across all instances of this class.
    static Logger* s_instance;
};

// This is a dumb thing we need to do to initialize static members in C++
Logger* Logger::s_instance = NULL;



int main() {
    // Singleton prevents us from directly allocating a Logger on the *stack.*
    // Uncomment to see Build Failure due to *private constructor!*
    // Logger stackLogger;

    // Singleton prevents us from directly allocating a Logger on the *heap.*
    // Uncomment to see Build Failure due to *private constructor!*
    // Logger* heapLogger = new Logger();

    // But we can use the getInstance() to get a pointer.
    Logger* logger = Logger::getInstance();
    logger->log("This is a test message");

    // You can make subsequent calls to getInstance and it will still
    // give you the same object.
    Logger::getInstance()->log("This is another message!");
    Logger::getInstance()->log("This is a third message!");

    return 0;
}