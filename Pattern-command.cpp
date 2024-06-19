#include <iostream>
#include <string>
#include <fstream>

class LogCommand {
public:
    virtual ~LogCommand() = default;
    virtual void print(const std::string& message) = 0;
};

class LogCommandToConsole : public LogCommand {
public:
    void print(const std::string& message) override {
        std::cout << "LOG: " << message << std::endl;
    }
};

class LogCommandToFile : public LogCommand {
public:
    void print(const std::string& message) override {
        std::ofstream file;

        file.open("logs.txt", std::ios::app);

        if (file.is_open()) {
            file << message << std::endl;
        }
        else {
            std::cout << "ERROR: File is not open" << std::endl;
        }

        file.close();
    }
};

void print(LogCommand& command, const std::string& message) {
    command.print(message);
}

int main()
{
    LogCommandToConsole logToConsole;
    print(logToConsole, "Hello Console!");

    LogCommandToFile logToFile;
    print(logToFile, "Hello File!");

    return 0;
}