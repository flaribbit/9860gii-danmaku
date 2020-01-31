CC=gcc
CFLAGS=-I include #-mwindows

a.exe: res.o main.o wrapper.o game.o
	$(CC) res.o main.o wrapper.o game.o SDL2.dll $(CFLAGS)
res2hex.exe: res2hex.c
	$(CC) res2hex.c $(CFLAGS) -o res2hex.exe
res.h: res.pix res2hex.exe
	res2hex
main.o: main.c res.h
	$(CC) -c main.c $(CFLAGS)
res.o: res.rc manifest.xml
	windres res.rc -o res.o
wrapper.o: wrapper.c
	$(CC) -c wrapper.c $(CFLAGS)
game.o: game.c
	$(CC) -c game.c $(CFLAGS)
