# Sep

BUILD_DIR = build
SRC_DIR = src
CPP_VERSION = c++17

all:
	@mkdir -p $(BUILD_DIR)
	g++ -Wall -std=${CPP_VERSION} -o ${BUILD_DIR}/main.out ${SRC_DIR}/*.cc

run:
	./${BUILD_DIR}/main.out

clean:
	rm -rf ${BUILD_DIR}/* ${SRC_DIR}/*.out

git:
	git add .
	git commit -m "update"
	git push