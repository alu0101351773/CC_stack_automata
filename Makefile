
BUILD_DIR = build
SRC_DIR = src
CPP_VERSION = c++17

all:
	g++ -Wall -std=${CPP_VERSION} -o ${BUILD_DIR}/main ${SRC_DIR}/*.cc

run:
	./${BUILD_DIR}/main

clean:
	rm -rf ${BUILD_DIR}/*