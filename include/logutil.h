#ifndef _XMAIL_LOG_UTIL_H_
#define _XMAIL_LOG_UTIL_H_
#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_INFO 
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_sinks.h"
#define XMAIL_ERROR(...) SPDLOG_ERROR(__VA_ARGS__)
#define XMAIL_INFO(...) SPDLOG_INFO(__VA_ARGS__)
#define XMAIL_DEBUG(...) SPDLOG_INFO(__VA_ARGS__)
#endif