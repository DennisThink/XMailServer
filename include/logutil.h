#ifndef _XMAIL_LOG_UTIL_H_
#define _XMAIL_LOG_UTIL_H_
#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_INFO 
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_sinks.h"
#define XMAIL_INFO(X) SPDLOG_INFO(X)
#define XMAIL_DEBUG(X) SPDLOG_INFO(X)
#endif