# My third makefile

# Name of the project
PROJ_NAME=maze-game

# .c files
C_SOURCE=$(wildcard ./src/*.c ./src/*/*.c)

# .h files
H_SOURCE=$(wildcard ./src/*/*.h)

# Object files
OBJ=$(subst .c,.o,$(subst ./src,./objects,$(C_SOURCE)))

# Compiler and linker
CC=gcc

# Flags for compiler
CC_FLAGS=-c

# Flags for linker
LD_FLAGS=	-lraylib   \
			-lGL       \
			-lm        \
			-lpthread  \
			-ldl       \
			-lrt       \
			-lX11

# Command used at clean target
RM = rm -rf

#
# Compilation and linking
#
all: objFolder $(PROJ_NAME)

$(PROJ_NAME): $(OBJ)
	@ echo 'Building binary using GCC linker: $@'
	$(CC) $^ $(LD_FLAGS) -o $@
	@ echo 'Finished building binary: $@'
	@ echo ' '

./objects/%.o: ./src/%.c
	@ echo 'Building target using GCC compiler: $<'
	$(CC) $(CC_FLAGS) $< -o $@
	@ echo ' '

objFolder:
	@ mkdir -p objects
	@ mkdir -p objects/maze_anim
	@ mkdir -p objects/maze_loader
	@ mkdir -p objects/maze
	@ mkdir -p objects/maze_solver
	@ mkdir -p objects/stack
	@ mkdir -p objects/utils

clean:
	@ $(RM) ./objects $(PROJ_NAME) *~

run:
	./maze-game < labirinto.txt

.PHONY: all clean
