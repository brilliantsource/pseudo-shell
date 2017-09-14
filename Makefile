# Build a Container running a Pseudo-Shell
# Requires the installation of gcc, strip, upx and docker

CFLAGS = -static -Os -o
SFLAGS = --strip-unneeded --remove-section=.comment --remove-section=.note --remove-section=.gnu.version
MANDATORY = gcc strip upx docker

default: build

check:
	$(if $(shell echo $(DOCKER_ID_USER)),, $(error "DOCKER_ID_USER is not set"))
	$(foreach exec, $(MANDATORY), $(if $(shell which $(exec)),, $(error "No $(exec) in $(PATH)")))

makedir:
	mkdir -p bin

compile:
	gcc $(CFLAGS) sh sh.c

shrink:
	strip --strip-all sh
	strip $(SFLAGS) sh
	upx --brute sh

move:
	mv -f sh bin/sh

compress:
	tar -cf - bin/ | xz -9e -c - > bin.tar.xz

clean:
	rm -Rf bin

containerize:
	docker build -t pseudo-shell:1.0 .
	docker tag pseudo-shell:1.0 $(DOCKER_ID_USER)/pseudo-shell:1.0

build: check makedir compile shrink move compress clean containerize