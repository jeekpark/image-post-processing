Target				=	ipp

CXX						= c++
CXXFLAGS			=	-I./lib/sfml/2.6.1/include -I./src -std=c++11

LDFLAGS				=	-L./lib/sfml/2.6.1/lib -Wl,-rpath,./lib/sfml/2.6.1/lib
LDLIBS				=	-lsfml-window -lsfml-graphics -lsfml-audio -lsfml-system 



SRC_DIR				=	./src
IPP_DIR				=	$(SRC_DIR)/ipp
CORE_DIR			=	$(IPP_DIR)/Core


OBJ_DIR				=	./obj

CLANGD_GEN		=	./clangd_gen.sh

SRC_FILES			=	$(SRC_DIR)/main.cpp

OBJ_FILES			=	$(SRC_FILES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

PCH						=	$(IPP_DIR)/common.hpp.gch
PCH_SRC				=	$(IPP_DIR)/common.hpp






all : $(TARGET)

$(TARGET) : $(OBJ_FILES)
	$(CXX) $(LDFLAGS) $(LDLIBS) $^ -o $@


$(PCH) : $(PCH_SRC)
	$(CXX) $(CXXFLAGS) -x c++-header -o $@ $<

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -include $(PCH) -c $< -o $@

clean :
	rm -rf $(OBJ_DIR) $(TARGET) $(PCH)

clangd :
	/bin/bash $(CLANGD_GEN)

re : clean
	make all

.PHONY: all clean clangd re