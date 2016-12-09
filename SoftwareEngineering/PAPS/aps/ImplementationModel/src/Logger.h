#include <fstream>
class Logger{
public:
    static Logger& instance(){
        static Logger log;
        return log;
    }
    void report(const std::string&);

private:
    Logger();
    ~Logger();
    //open file in append mode
    std::ofstream logFile_;
};
