INC_DIR:= ./inc
SRC_DIR:= ./src
BIN_DIR:= ./bin
SRCS:=$(wildcard $(SRC_DIR)/*.cc)
OBJS:= $(patsubst %.cc, %.o, $(SRCS))
LIBS:= -lpthread

CXX:=clang++-6.0
#CXX:=g++

CXXFLAGS:= -W -O3 -g  -v  -std=c++1z  $(addprefix -I, $(INC_DIR)) $(LIBS) 

EXE:=$(BIN_DIR)/main

$(EXE):$(OBJS)
	$(CXX) -o $(EXE) $(OBJS) $(CXXFLAGS)

clean:
	rm -rf $(EXE)
	rm -rf $(OBJS)
