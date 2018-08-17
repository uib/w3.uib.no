DOCKERHUB_USER=gisleaas

.PHONY: dev run pull push rebuild

build:
	docker build -f Dockerfile .. --tag w3:dev

run:
	docker run -it -p 8080:80 --env PG_HOST=host.docker.internal --volume w3-files:/var/www/html/sites/default/files w3:dev

pull:
	docker pull php:5.6-apache

push:
	docker tag w3:dev $(DOCKERHUB_USER)/w3:latest
	docker push $(DOCKERHUB_USER)/w3:latest

rebuild: pull build push
