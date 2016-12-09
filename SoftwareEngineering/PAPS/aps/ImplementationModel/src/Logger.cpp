#include <string>
#include <fstream>
#include <iostream>
#include "Logger.h"

Logger::~Logger() {
    logFile_.close();
}
Logger::Logger(){
    logFile_ = std::ofstream("output/log.txt", std::ios::out);
}

void Logger::report(const std::string& comment){
	std::string out = comment + "\n";
    logFile_ << out;
    logFile_.flush();
}
