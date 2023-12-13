#!/bin/bash
while true; do
	read -p "Type a word: " input
	if [ "$input" = "gp" ] || [ "$input" = "git pull" ]; then
		git pull
	elif [ "$input" = "up" ]; then
		docker-compose -f ./srcs/docker-compose.yml up -d --build
	elif [ "$input" = "down" ]; then
		docker-compose -f ./srcs/docker-compose.yml down
	elif [ "$input" = "rm" ]; then
		docker rm -f $(docker ps -aq)
		docker rmi -f $(docker images -q)
	# elif [ "$input" = "run" ]; then
		# docker build -t mynginx ./srcs/requirements/nginx
		# docker build -t mymariadb ./srcs/requirements/mariadb
		# docker build -t mywordpress ./srcs/requirements/wordpress
		# docker run --name nginx mynginx
		# docker run --name mariadb mymariadb
		# docker run --name wordpress mywordpress
	elif [ "$input" = "exit" ]; then
		exit
	else
		echo "Usage: git pull, up, down, rm, run, exit"
	fi
done
