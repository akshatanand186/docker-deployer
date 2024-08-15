#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>


void createYAMLFile(){
    // Not Working as of 16.08.2024 - 3:40AM IST
    std::ofstream yamlFile("kaniko-job.yaml");
    std::string jobName = "kaniko", dockerfilePath = "Dockerfile", contextPath = "dir:///directory", dockerImage = "/username/image-name:version", dockerSecretName = "regsec";
    if (!yamlFile.is_open()) {
        std::cerr << "Unable to open file for writing!" << std::endl;
        return;
    }
    yamlFile << "apiVersion: batch/v1\n";
    yamlFile << "kind: Job\n";
    yamlFile << "metadata:\n";
    yamlFile << "  name: " << jobName << "\n";
    yamlFile << "spec:\n";
    yamlFile << "  template:\n";
    yamlFile << "    spec:\n";
    yamlFile << "      containers:\n";
    yamlFile << "      - name: kaniko\n";
    yamlFile << "        image: gcr.io/kaniko-project/executor:latest\n";
    yamlFile << "        args:\n";
    yamlFile << "          - \"--dockerfile=" << dockerfilePath << "\"\n";
    yamlFile << "          - \"--context=" << contextPath << "\"\n";
    yamlFile << "          - \"--destination=" << dockerImage << "\"\n";
    yamlFile << "        volumeMounts:\n";
    yamlFile << "          - name: kaniko-secret\n";
    yamlFile << "            mountPath: /kaniko/.docker\n";
    yamlFile << "      restartPolicy: Never\n";
    yamlFile << "      volumes:\n";
    yamlFile << "        - name: kaniko-secret\n";
    yamlFile << "          secret:\n";
    yamlFile << "            secretName: " << dockerSecretName << "\n";
    yamlFile << "  backoffLimit: 1\n";

    // Close the file stream
    yamlFile.close();

    std::cout << "Kaniko Job YAML file created successfully!" << std::endl;
}

void submitBuildJob(){
    std::string yamlFileName = "kaniko-job.yaml";
    std::string command = "kubectl apply -f " + yamlFileName;
    int result = std::system(command.c_str());
    if (result == 0) {
        std::cout << "Submitted the Build Job Succesfully" << std::endl;
    } else {
        std::cerr << "Build Job could not be submitted" << std::endl;
    }
}