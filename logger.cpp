#include "logger.h"

logger* logger::instance = nullptr;


logger::logger(){}

    logger* logger::get_instance()
    {
        if(instance == nullptr)
        {
            instance = new logger();
        }
        return instance;
    }
    
    
    void logger::log_info(const std::string message)
    {
        LOG(INFO) << message;
    }
    
    void logger::log_error(const std::string message)
    {
        LOG(ERROR) << message;
    }

    void logger::log_fatal(const std::string message)
    {
        LOG(FATAL) << message;
    }

    void logger::log_warning(const std::string message)
    {
        LOG(WARNING) << message;
    }

    void logger::log_trace(const std::string message)
    {
        LOG(TRACE) << message;
    }


// singleton + 1/2 adapter
