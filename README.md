# Pseudo-Shell
Pseudo-Shell is a Docker container that runs a fake interpreter.  It enables the volumes storage in containers.

----------
## Prerequisites
The build requires the installation of gcc, strip, upx and [docker](https://docs.docker.com/engine/installation/) in a Linux environment.

----------
## Building
The Makefile will compile the C program and build the container.  You have then to add it into Docker Hub.  The following commands have to be launched in a Linux environment:

    export DOCKER_ID_USER="MY_DOCKER_ID_USER"
    make
    docker login
    docker push $DOCKER_ID_USER/pseudo-shell:1.0

----------
## Launching
Test the container using the following command:

    docker run -it --rm --name pseudo-shell pseudo-shell:1.0