# Algorithmique avancée TP1
# 13/02/2013
# Hicham Benjelloun


# ID
AUTEUR=benjelloun
NUM_TP=projet

# Répertoires
SRC=./src/
INCLUDE=./include/
OBJ=./obj/
BIN=./bin/
LIB=./lib/

# Compilation
CC=gcc -O3 -I$(INCLUDE)
CFLAG=
RM=rm -f
TAR=tar -cvf

all : list vect pilot map vertex graph dijkstra path fib io
	$(CC) $(OBJ)*.o $(SRC)$(AUTEUR).c -o $(BIN)$(AUTEUR)

# modules
vertex : $(SRC)vertex.c
	$(CC) -o $(OBJ)$@.o $< -c
path : $(SRC)path.c
	$(CC) -o $(OBJ)$@.o $< -c
graph : $(SRC)graph.c
	$(CC) -o $(OBJ)$@.o $< -c

# modules
map : $(SRC)map.c
	$(CC) -o $(OBJ)$@.o $< -c
pilot : $(SRC)pilot.c
	$(CC) -o $(OBJ)$@.o $< -c
list : $(SRC)list.c
	$(CC) -o $(OBJ)$@.o $< -c
vect : $(SRC)vect.c
	$(CC) -o $(OBJ)$@.o $< -c
dijkstra : $(SRC)dijkstra.c
	$(CC) -o $(OBJ)$@.o $< -c
fib : $(SRC)fib.c
	$(CC) -o $(OBJ)$@.o $< -c
io : $(SRC)io.c
	$(CC) -o $(OBJ)$@.o $< -c
# Clean
clean :
	$(RM) *~ $(SRC)*~ $(INCLUDE)*~ $(OBJ)*

distclean : clean
	$(RM) $(BIN)*

# Archive
tarball : distclean
	$(TAR) $(AUTEUR)_$(NUM_TP).tar *





