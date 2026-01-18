#include "Logger.h"

Logger& Logger::Get() {
    static Logger instance;
    return instance;
}

Logger::Logger() {
    // Overwrite log each run
    m_file.open("application.log", std::ios::out | std::ios::trunc);
}

Logger::~Logger() {
    if (m_file.is_open())
        m_file.close();
}

void Logger::Info(const std::string& message) {
    Log(LogLevel::Info, message);
}

void Logger::Warning(const std::string& message) {
    Log(LogLevel::Warning, message);
}

void Logger::Error(const std::string& message) {
    Log(LogLevel::Error, message);
}

void Logger::Log(LogLevel level, const std::string& message) {
    m_messages.push_back({ level, message });

    if (m_file.is_open()) {
        m_file << LevelToString(level) << ": "
                << message << std::endl;
    }
}

const char* Logger::LevelToString(LogLevel level) {
    switch (level) {
        case LogLevel:: Info:       return "Info";
        case LogLevel:: Warning:    return "Warning";
        case LogLevel:: Error:      return "Error";
        defaul:                     return "Unknown";
    }
}

const std::vector<LogMessage>& Logger::GetMessages() const {
    return m_messages;
}