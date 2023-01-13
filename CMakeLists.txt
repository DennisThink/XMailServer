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
)
if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    message(STATUS "This is Linux")
    add_executable(xmail ./src/MainLinux.cpp ./src/SysDepLinux.cpp ./src/SysDepUnix.cpp ./src/SysOsEventfd_pipe.cpp ${FILE_SOURCE})
else()
    message(STATUS "This is Windows")
    add_definitions(-DWIN32)
    link_libraries(ws2_32)
    add_executable(xmail ./src/MainWin.cpp ./src/SysDepWin.cpp ${FILE_SOURCE})
endif()
