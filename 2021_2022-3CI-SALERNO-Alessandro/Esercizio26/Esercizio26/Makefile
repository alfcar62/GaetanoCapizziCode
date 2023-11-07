CXX    := gcc
MAIN   := main.c
OUTPUT := ASCIIGebra
FLAGS  := -static -lm

ifeq ($(OS), Windows_NT)
	OUTPUT = ASCIIGebra.exe
	FLAGS  = -static
endif


build:
	$(CXX) $(MAIN) $(FLAGS) -o $(OUTPUT)
