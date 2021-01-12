// double checked lock
// magic static

#include <iostream>
#include <vector>

#include <string>
#include <fstream>

using namespace std;

class Logger final {
public:
    enum class LogLevel {
        Error,
        Info,
        Debug
    };

    static Logger& instance();
    Logger(const Logger&) = delete;
    Logger(Logger&&) = delete;

    Logger& operator=(const Logger&) = delete;
    Logger& operator=(Logger&&) = delete;

    void setLogLevel(LogLevel level);
    void log(string_view message, LogLevel logLevel);
    void log(const vector<string>& messages, LogLevel logLevel);

private:
    Logger();
    ~Logger();

    string_view getLogLevelString(LogLevel level) const;
    static inline const char* const kLogFileName = "log.out";
    ofstream mOutputStream;
    LogLevel mLogLevel = LogLevel::Error;
};

Logger& Logger::instance() {
    static Logger instance;
    return instance;
}

Logger::Logger() {
    mOutputStream.open(kLogFileName, ios_base::app);
    if (!mOutputStream.good()) {
        throw runtime_error("Unable to initialize the Logger!");
    }
}

Logger::~Logger() {
    mOutputStream << "Logger shutting down." << "\n";
    mOutputStream.close();
}

void Logger::setLogLevel(LogLevel level) {
    mLogLevel = level;
}

string_view Logger::getLogLevelString(LogLevel level) const {
    switch (level) {
        case LogLevel::Error:
            return "ERROR";
        case LogLevel::Info:
            return "INFO";
        case LogLevel::Debug:
            return "DEBUG";
    }
    throw runtime_error("Invalid log level.");
}

void Logger::log(string_view message, LogLevel logLevel) {
    if (mLogLevel < logLevel) {
        return ;
    }

    mOutputStream << getLogLevelString(logLevel).data()
        << ": " << message << "\n";
}

void Logger::log(const vector<string>& messages, LogLevel logLevel) {
    if (mLogLevel < logLevel) {
        return ;
    }

    for (const auto& message : messages) {
        log(message, logLevel);
    }
}

int main() {
    Logger::instance().setLogLevel(Logger::LogLevel::Debug);
    
    Logger::instance().log("test message", Logger::LogLevel::Debug);
    vector<string> items = {"items1", "items2"};
    Logger::instance().log(items, Logger::LogLevel::Error);

    Logger::instance().setLogLevel(Logger::LogLevel::Error);
    Logger::instance().log("A debug message", Logger::LogLevel::Debug);

    return 0;
}