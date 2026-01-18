#pragma once
#include <string>
#include <vector>
#include <fstream>

enum class LogLevel
{
    Info = 0,
    Warning,
    Error
};

struct LogMessage
{
    LogLevel level;
    std::string message;
};

class Logger
{
public:
    static Logger& Get();

    void Info(const std::string& message);
    void Warning(const std::string& message);
    void Error(const std::string& message);

    const std::vector<LogMessage>& GetMessages() const;

private:
    Logger();
    ~Logger();

    void Log(LogLevel level, const std::string& message);
    const char* LevelToString(LogLevel level);

    std::vector<LogMessage> m_messages;
    std::ofstream m_file;
};
