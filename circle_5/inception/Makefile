NAME = inception
SRC_DIR = ./srcs
DOCKER_COMPOSE_FILE = $(SRC_DIR)/docker-compose.yml
DOCKER_COMPOSE = sudo docker-compose -f $(DOCKER_COMPOSE_FILE)
VOLUME_MOUNTPOINT = /home/hyeslim/data
NETWORKS = srcs_nginx-wordpress srcs_wordpress-mariadb

$(NAME) : all

all : up

fclean : clean
	rm -rf $(VOLUME_MOUNTPOINT)

clean : stop
	docker rm $$(docker ps -qa); \
	docker rmi -f $$(docker images -q); \
	docker volume rm $$(docker volume ls -q); \
	docker network rm $(NETWORKS)

re : fclean
	docker pull alpine:3.17.5
	mkdir -p $(VOLUME_MOUNTPOINT)/mariadb $(VOLUME_MOUNTPOINT)/wordpress
	$(DOCKER_COMPOSE) build --no-cache
	$(DOCKER_COMPOSE) up -d

up :
	docker pull alpine:3.17.5
	mkdir -p $(VOLUME_MOUNTPOINT)/mariadb $(VOLUME_MOUNTPOINT)/wordpress
	$(DOCKER_COMPOSE) up -d --build

down :
	$(DOCKER_COMPOSE) down

start :
	$(DOCKER_COMPOSE) start

restart :
	$(DOCKER_COMPOSE) restart

stop :
	$(DOCKER_COMPOSE) stop

.PHONY: all clean re up down start restart stop
