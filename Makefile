EXEC_OUTPUT = bin/affichage bin/exemple bin/test 
EXEC_NAMES = affichage exemple test
OBJ_FILES = obj/mainAffichage.o obj/mainTest.o obj/mainExemple.o obj/Image.o obj/Pixel.o

CC = g++
CFLAGS = -Wall -ggdb
INCLUDES = 
LIBS = -lSDL2 -lSDL2_image

all: $(EXEC_OUTPUT)

clean:
	rm $(OBJ_FILES) $(EXEC_OUTPUT)

doc:
	doxygen doc/image.doxy

bin/affichage: obj/mainAffichage.o obj/Image.o obj/Pixel.o
	$(CC) obj/mainAffichage.o obj/Image.o obj/Pixel.o -o bin/affichage $(LIBS)

bin/exemple: obj/mainExemple.o obj/Image.o obj/Pixel.o
	$(CC) obj/mainExemple.o obj/Image.o obj/Pixel.o -o bin/exemple $(LIBS)

bin/test: obj/mainTest.o obj/Image.o obj/Pixel.o
	$(CC) obj/mainTest.o obj/Image.o obj/Pixel.o -o bin/test $(LIBS)

obj/mainAffichage.o: src/mainAffichage.cpp src/Image.h src/Pixel.h
	$(CC) $(CFLAGS) $(INCLUDES) -o obj/mainAffichage.o -c src/mainAffichage.cpp

obj/mainExemple.o: src/mainExemple.cpp src/Image.h src/Pixel.h
	$(CC) $(CFLAGS) $(INCLUDES) -o obj/mainExemple.o -c src/mainExemple.cpp

obj/mainTest.o: src/mainTest.cpp src/Image.h src/Pixel.h
	$(CC) $(CFLAGS) $(INCLUDES) -o obj/mainTest.o -c src/mainTest.cpp

obj/Image.o: src/Image.cpp src/Image.h src/Pixel.h
	$(CC) $(CFLAGS) $(INCLUDES) -o obj/Image.o -c src/Image.cpp

obj/Pixel.o: src/Pixel.cpp src/Pixel.h
	$(CC) $(CFLAGS) $(INCLUDES) -o obj/Pixel.o -c src/Pixel.cpp