#include <iostream>
#include <string> 
#include "deployer.h"
#include "compile.h"
#include "kind.h"
#include "kaniko-job.h"
#include "directory.h"

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
            if(!detectDockerfile()){
                std::cout << "No Dockerfile detected: Please ensure a Dockerfile is there in current directory" << std::endl;
            }
            // initiateKubernetesCluster();
            createYAMLFile();
            // submitBuildJob();

        }
        else{
            std::cout << "Command not found: Try without spaces :(" << std::endl;
        }
    }

    return 0;
}
