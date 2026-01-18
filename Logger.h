#pragma once 

class Logger {
    public:
        static Logger& Get();

    private:
        Logger() = default;
};
