/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#include <sys/stat.h>
#include <ctime>
#include <cstdio>
#include <pwd.h>

#include <src/Scrift.hpp>
#include <src/Syntax/History.hpp>
#include <src/Syntax/Log.hpp>
#include <src/Syntax/FileFunction.hpp> 
#include <src/Syntax/CommandFunc.hpp>

/* TODO:
   * Clear.
*/
FeLog *loghistory = new FeLog();
std::ofstream historyfile;
std::string filepath_history, history_text;

FHistory::FHistory() { }

void
FHistory::ClearHistory() {
    std::string path;
    path.append(getenv("HOME"));

    path.append("/.scrift_history");
    historyfile.open(path); // append
    historyfile << "rmvhistory\n";
    historyfile.close();
}


const std::string
FHistory::TimeFunction() {
    time_t nowtime = time(0);
    struct tm tstruct;
    char    buff[80];
    tstruct = *localtime(&nowtime);
    std::strftime(buff, sizeof(buff), "%Y-%M-%d.%X", &tstruct);
    return buff;
}


void
FHistory::WriteHistory(fstr filepathw) {
	if(filepathw.length() != 0) history_text.append(filepathw);
}

void 
FHistory::WriteAllHistory() {
    std::string filepath_with_path;
    filepath_with_path.append(getenv("HOME"));

    filepath_with_path.append("/.scrift_history");
    std::ofstream file;
    file.open(filepath_with_path, std::ios::out | std::ios::app);
    
    if(file.fail())
        printlnf("ERROR\n");
    

    file.exceptions(file.exceptions() | std::ios::failbit | std::ifstream::badbit);

    file << history_text;
}

void 
FHistory::WriteInHistory(std::string element) {
    std::string filepath_with_path;
    filepath_with_path.append(getenv("HOME"));

    filepath_with_path.append("/.scrift_history");
    
    std::ofstream file;
    file.open(filepath_with_path, std::ios::out | std::ios::app);
    
    if(file.fail())
        std::cout << "[history]: error\n";
    

    file.exceptions(file.exceptions() | std::ios::failbit | std::ifstream::badbit);

    file << element;
    
    file.close();
}

void
FHistory::CreateFile() {   
    std::string path;
    path.append(getenv("HOME"));

    path.append("/.scrift_history");
    historyfile.open(path, std::ios::app);
    historyfile.close();
}   

bool
FHistory::IsExist() {
    struct stat buffer;
    return (stat(filepath_history.c_str(), &buffer) == 0);
}


void
FHistory::AllofThem() {
    if(IsExist() != true)
    	CreateFile();
    else {
        printlnf("FHistory file is exists\n");
        loghistory->WriteLog("FHistory file is exists! - ");
    }
}


FHistory::~FHistory() {}

