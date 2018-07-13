.PHONY: dev run

build:
	docker build -f Dockerfile .. --tag w3:dev

run:
	docker run -it -p 8080:80 --env PG_HOST=host.docker.internal --volume w3-files:/var/www/html/sites/default/files w3:dev
