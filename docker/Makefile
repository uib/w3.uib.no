DOCKERHUB_USER=uibit

.PHONY: dev run push rebuild

build:
	docker build -f Dockerfile .. --pull --tag w3:dev --build-arg W3_VERSION=`git describe --tags`

run:
	docker run -it -p 8080:80 --env PG_HOST=host.docker.internal --volume w3-files:/var/www/html/sites/default/files w3:dev

push:
	docker tag w3:dev $(DOCKERHUB_USER)/w3:latest && docker push $(DOCKERHUB_USER)/w3:latest
	V=`docker inspect --format '{{ index .Config.Labels "W3_VERSION"}}' w3:dev` sh -c "docker tag w3:dev $(DOCKERHUB_USER)/w3:\$$V && docker push $(DOCKERHUB_USER)/w3:\$$V"

rebuild: pull build push
