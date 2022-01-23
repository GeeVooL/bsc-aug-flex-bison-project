CXX := g++
CXXFLAGS := -std=c++17

SRC_DIR := ./src
BUILD_DIR := ./build
BIN_DIR := ./bin

PROG := ${BIN_DIR}/lang
SRC := $(wildcard $(SRC_DIR)/*.cpp)
FLEX_OUT := ${BUILD_DIR}/scanner.cpp ${BUILD_DIR}/scanner.h
FLEX_SRC := ${SRC_DIR}/grammar.l
BISON_OUT := ${BUILD_DIR}/parser.cpp ${BUILD_DIR}/parser.h
BISON_SRC := ${SRC_DIR}/grammar.y

all: ${PROG}

${BISON_OUT}: ${BISON_SRC} $(BUILD_DIR)
	cd $(BUILD_DIR) && bison ../${BISON_SRC}

${FLEX_OUT}: ${BISON_OUT} ${FLEX_SRC} $(BUILD_DIR)
	cd $(BUILD_DIR) && flex ../${FLEX_SRC}

$(BIN_DIR):
	mkdir -p $@

$(BUILD_DIR):
	mkdir -p $@

${PROG}: ${FLEX_OUT} ${BISON_OUT} ${SRC} ${BIN_DIR}
	${CXX} ${CXXFLAGS} -o ${PROG} ${BUILD_DIR}/*.cpp ${SRC}

clean:
	rm -rf ${BIN_DIR} ${BUILD_DIR}