#Windows Makefile

all: Main.o Livro.o AudioBook.o Eletronico.o Impresso.o
	@g++ ./obj/Main.o ./obj/Livro.o ./obj/AudioBook.o ./obj/Eletronico.o ./obj/Impresso.o -o ColecaoLivros.exe

Main.o: ./src/Main.cpp
	@g++ -c ./src/Main.cpp -o ./obj/Main.o

Livro.o: ./src/Livro.cpp
	@g++ -c ./src/Livro.cpp -o ./obj/Livro.o

AudioBook.o: ./src/AudioBook.cpp
	@g++ -c ./src/AudioBook.cpp -o ./obj/AudioBook.o

Eletronico.o: ./src/Eletronico.cpp
	@g++ -c ./src/Eletronico.cpp -o ./obj/Eletronico.o

Impresso.o: ./src/Impresso.cpp
	@g++ -c ./src/Impresso.cpp -o ./obj/Impresso.o

run:
	@./ColecaoLivros.exe

go:
	@cls
	@make all
	@make run

clean:
	@del *.exe /q
	@cd obj && del *.o /q && \
	@cls