#include <iostream>
#include <filesystem>
#include <string>
#include <cstdlib> 
#include "deployer.h"
namespace fs = std::filesystem;


void run_executable(const std::string& exec_name) {
    std::string command = "./" + exec_name;
    int result = std::system(command.c_str());

    if (result == 0) {
        std::cout << "Execution completed successfully." << std::endl;
    } else {
        std::cerr << "Execution failed. Please check the executable." << std::endl;
    }
}


void compile_file(const std::string& filename) {
    std::string command = "g++ " + filename + " -o output";
    int result = std::system(command.c_str());

    if (result == 0) {
        std::cout << "Compilation successful. Executable created: output" << std::endl;
    } else {
        std::cerr << "Compilation failed. Please check the source file for errors." << std::endl;
    }
}

void print_current_directory() {
    std::cout << "Current Directory: " << fs::current_path() << std::endl;
}

void list_directory_contents() {
    std::cout << "Contents of " << fs::current_path() << ":" << std::endl;
    for (const auto& entry : fs::directory_iterator(fs::current_path())) {
        std::cout << (entry.is_directory() ? "[DIR] " : "[FILE] ") << entry.path().filename().string() << std::endl;
    }
}

void change_directory(const std::string& path) {
    try {
        fs::current_path(path);
        std::cout << "Changed directory to: " << fs::current_path() << std::endl;
    } catch (fs::filesystem_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

int main() {
    std::string command;
    while (true) {
        std::cout << "> ";
        std::getline(std::cin, command);

        if (command == "exit") {
            break;
        } else if (command == "pwd") {
            print_current_directory();
        } else if (command == "ls") {
            list_directory_contents();
        } else if (command.rfind("cd ", 0) == 0) {
            std::string path = command.substr(3);
            change_directory(path);
        } else if (command.rfind("tool deploy",0) == 0){
            std::cout << detectDockerfile() << std::endl;
        }
        else{

        }
    }

    return 0;
}
