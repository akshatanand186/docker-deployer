#include <iostream>
#include <cstdlib>

void initiateKubernetesCluster(const std::string clusterName = "kind") {
    std::string command = "kind create cluster --name " + clusterName;
    int result = std::system(command.c_str());
    if (result == 0) {
        std::cout << "Cluster created successfully" << std::endl;
    } else {
        std::cerr << "Cluster could not be created" << std::endl;
    }
}
void deleteKubernetesCluster(const std::string clusterName = "kind") {
    std::string command = "kind delete cluster --name " + clusterName;
    int result = std::system(command.c_str());
    if (result == 0) {
        std::cout << "Cluster deleted successfully" << std::endl;
    } else {
        std::cerr << "Cluster could not be deleted" << std::endl;
    }
}