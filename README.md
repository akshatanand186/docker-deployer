# docker-deployer

## This is an app to automate the deployment of your Docker Images using Kubernetes cluster.

Make sure you have Kind(Kubernetes in Docker) installed on your system. It can be installed by using the following command on MacOS systems.

```
brew install kind
```

### How to Run 

Install make using Homebrew or from their official website
```
make 
./build/output
make clean
```

### Usage Instructions

- ls - lists all the files and directories present in the current path
- pwd - prints the current path
- cd /path - navigate to the path you want to
- tool deploy - Finds the dockerfile in the current pwd and submit the build kaniko job to the kubernetes cluster present. (Under Progress)