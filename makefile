#Windows Makefile

all: Main.o
	@g++ ./obj/Main.o -o ColecaoLivros

Main.o: ./src/Main.cpp
	@g++ -c ./src/Main.cpp -o ./obj/main.o

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