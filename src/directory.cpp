#include <filesystem>
#include <iostream>

void print_current_directory() {
    std::cout << "Current Directory: " << std::filesystem::current_path() << std::endl;
}

void list_directory_contents() {
    std::cout << "Contents of " << std::filesystem::current_path() << ":" << std::endl;
    for (const auto& entry : std::filesystem::directory_iterator(std::filesystem::current_path())) {
        std::cout << (entry.is_directory() ? "[DIR] " : "[FILE] ") << entry.path().filename().string() << std::endl;
    }
}

void change_directory(const std::string& path) {
    try {
        std::filesystem::current_path(path);
        std::cout << "Changed directory to: " << std::filesystem::current_path() << std::endl;
    } catch (std::filesystem::filesystem_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}