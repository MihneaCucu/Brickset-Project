#ifndef logger_h
#define logger_h
#include "easylogging++.h"

class logger
{
private:
    static logger* instance;
    logger();
    

public:
    static logger* get_instance();
    
    logger(const logger&) = delete;
    logger& operator= (const logger&) = delete;
    
    void log_info(const std::string message);
    
    void log_error(const std::string message);
    
    void log_fatal(const std::string message);
    
    void log_warning(const std::string message);
    
    void log_trace(const std::string message);
};

#endif
