cmake_minimum_required(VERSION 3.0)
project(XMailServer)
set(CMAKE_CXX_STANDARD 14)
if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    add_definitions(-D__LINUX__)
    message(STATUS "This is Linux")
else()
    message(STATUS "This is Windows")
    add_definitions(-DWIN32)
    link_libraries(ws2_32)
endif()
include_directories(./include/)
include_directories(./thirdparty/)
include_directories(./thirdparty/SQLiteCpp/include/)
include_directories(./thirdparty/SQLiteCpp/sqlite3/)
SET(FILE_SOURCE  ./src/AliasDomain.cpp   
./src/Maildir.cpp      
./src/MiscUtils.cpp       
./src/SSLBind.cpp    
./src/SvrUtils.cpp
./src/Hash.cpp
./src/ResLocks.cpp        
./src/DNS.cpp  
./src/SSLConfig.cpp
./src/UsrAuth.cpp
./src/Array.cpp 
./src/LMAILSvr.cpp  
./src/SList.cpp                 
./src/DNSCache.cpp    
./src/POP3GwLink.cpp  
./src/SSLMisc.cpp  
./src/SysDepCommon.cpp  
./src/UsrMailList.cpp
./src/Base64Enc.cpp  
./src/MD5.cpp
./src/SMAILSvr.cpp                     
./src/Errors.cpp               
./src/POP3Svr.cpp                       
./src/UsrUtils.cpp
./src/BuffSock.cpp 
./src/MailConfig.cpp  
./src/SMAILUtils.cpp 
./src/ShBlocks.cpp                     
./src/ExtAliases.cpp        
./src/POP3Utils.cpp                              
./src/MailDomains.cpp  
./src/SMTPSvr.cpp   
./src/StrUtils.cpp 
./src/FINGSvr.cpp       
./src/PSYNCSvr.cpp   
./src/MailSvr.cpp 
./src/MessQueue.cpp  
./src/SMTPUtils.cpp                        
./src/CTRLSvr.cpp    
./src/Filter.cpp      
./src/QueueUtils.cpp        
./src/TabIndex.cpp
./src/SysUtil.cpp
./src/UserUtil.cpp
./src/CDBUtil.cpp
)

SET(DB_SOURCE_FILE 
./thirdparty/SQLiteCpp/src/Backup.cpp  
./thirdparty/SQLiteCpp/src/Database.cpp   
./thirdparty/SQLiteCpp/src/Savepoint.cpp  
./thirdparty/SQLiteCpp/src/Transaction.cpp
./thirdparty/SQLiteCpp/src/Column.cpp  
./thirdparty/SQLiteCpp/src/Exception.cpp  
./thirdparty/SQLiteCpp/src/Statement.cpp
./thirdparty/SQliteCpp/sqlite3/sqlite3.c)
if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    message(STATUS "This is Linux")
    add_executable(xmail ./src/MainLinux.cpp ./src/SysDepLinux.cpp ./src/SysDepUnix.cpp ./src/SysOsEventfd_pipe.cpp ${FILE_SOURCE} ${DB_SOURCE_FILE})
else()
    message(STATUS "This is Windows")
    add_definitions(-DWIN32)
    link_libraries(ws2_32)
    add_executable(xmail ./src/MainWin.cpp ./src/SysDepWin.cpp ${FILE_SOURCE} ${DB_SOURCE_FILE})
endif()

add_executable(xmailsqliteutil ./src/XMailSQLiteMain.cpp ./src/CDBUtil.cpp ${DB_SOURCE_FILE})
