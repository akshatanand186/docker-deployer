#include <filesystem>
#include <iostream>
namespace fs = std::filesystem;

bool detectDockerfile(){
    std::cout << "Contents of " << fs::current_path() << ":" << std::endl;
    for (const auto& entry : fs::directory_iterator(fs::current_path())) {
        if(entry.is_directory()) continue;
        std::string file = entry.path().filename().string();
        std::cout << file << std:: endl;
        if(file == "Dockerfile") return true;
    }
    return false;
}