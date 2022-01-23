CXX := g++
CXXFLAGS := -std=c++17

SRC_DIR := ./src
BIN_DIR := ./bin

PROG := ${BIN_DIR}/lang
FLEX_OUT := ${SRC_DIR}/scanner.cpp ${SRC_DIR}/scanner.h
FLEX_SRC := ${SRC_DIR}/grammar.l
BISON_OUT := ${SRC_DIR}/parser.cpp ${SRC_DIR}/parser.h
BISON_SRC := ${SRC_DIR}/grammar.y

all: ${PROG}

${BISON_OUT}: ${BISON_SRC}
	cd $(SRC_DIR) && bison ../${BISON_SRC}

${FLEX_OUT}: ${BISON_OUT} ${FLEX_SRC}
	cd $(SRC_DIR) && flex ../${FLEX_SRC}

$(BIN_DIR):
	mkdir -p $@

${PROG}: ${FLEX_OUT} ${BISON_OUT} ${SRC} ${BIN_DIR}
	${CXX} ${CXXFLAGS} -o ${PROG} ${SRC_DIR}/*.cpp

clean:
	rm -rf ${BIN_DIR} ${BUILD_DIR}