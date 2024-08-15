#include <iostream>
#include <cstdlib> 
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