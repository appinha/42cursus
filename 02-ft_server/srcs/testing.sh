#!/bin/bash

if [[ $1 == "fclean" ]];
then
    docker rm $(docker ps -qa) -f
    docker rmi apuchill
    docker build -t apuchill .
fi

docker run --name apuchill_cont -it -p 80:80 -p 443:443 apuchill