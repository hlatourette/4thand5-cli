BUILD_DIR := build

.PHONY: all build clean install package test

all: clean build test

build:
	mkdir -p ${BUILD_DIR} && cd build && cmake .. -DCMAKE_INSTALL_PREFIX=/ && cmake --build .

clean:
	rm -rf ${BUILD_DIR}

install:
	cd ${BUILD_DIR} && cmake --build . --target install

package:
	cd ${BUILD_DIR} && cpack -G DEB

test:
	cd ${BUILD_DIR} && ctest --verbose
