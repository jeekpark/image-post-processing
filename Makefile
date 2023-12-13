TARGET				=	imagepp

CXX						= c++
CXXFLAGS			=	-I./lib/sfml/2.6.1/include -I./src -std=c++11

LDFLAGS				=	-L./lib/sfml/2.6.1/lib -Wl,-rpath,./lib/sfml/2.6.1/lib
LDLIBS				=	-lsfml-window -lsfml-graphics -lsfml-audio -lsfml-system 



SRC_DIR				=	./src
IPP_DIR				=	$(SRC_DIR)/ipp
CORE_DIR			=	$(IPP_DIR)/Core
FILTER_DIR		=	$(IPP_DIR)/Filter
IMAGE_DIR			=	$(IPP_DIR)/Image
VIEW_DIR			=	$(IPP_DIR)/View

OBJ_DIR				=	./obj

CLANGD_GEN		=	./clangd_gen.sh

SRC_FILES			=	$(SRC_DIR)/main.cpp											\
								$(CORE_DIR)/Core.cpp										\
								$(FILTER_DIR)/GrayscaleFilter.cpp				\
								$(IMAGE_DIR)/Image.cpp									\
								$(VIEW_DIR)/MainWindow.cpp							\
								$(VIEW_DIR)/Widgets/Elements/CheckBoxWidgetElement.cpp\
								$(VIEW_DIR)/Widgets/RadioButtonWidget.cpp

OBJ_FILES			=	$(SRC_FILES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

PCH						=	$(IPP_DIR)/common.hpp.gch
PCH_SRC				=	$(IPP_DIR)/common.hpp






all : $(TARGET)

$(TARGET) : $(OBJ_FILES)
	$(CXX) $(LDFLAGS) $(LDLIBS) $^ -o $@

pch : $(PCH)

$(PCH) : $(PCH_SRC)
	$(CXX) $(CXXFLAGS) -x c++-header -o $@ $<



$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp $(PCH)
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -include-pch $(PCH) -c $< -o $@

clean :
	rm -rf $(OBJ_DIR) $(TARGET) $(PCH)

clangd :
	/bin/bash $(CLANGD_GEN)

re : clean
	make all

.PHONY: all clean clangd re