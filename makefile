#Windows Makefile

all: Main.o Livro.o
	@g++ ./obj/Main.o ./obj/Livro.o -o ColecaoLivros

Main.o: ./src/Main.cpp
	@g++ -c ./src/Main.cpp -o ./obj/Main.o

Livro.o: ./src/Livro.cpp
	@g++ -c ./src/Livro.cpp -o ./obj/Livro.o

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