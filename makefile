all:derle bagla calistir

derle:
	g++ -c -I "./include" ./src/Dugum.cpp -o ./lib/Dugum.o
	g++ -c -I "./include" ./src/BagliListe.cpp -o ./lib/BagliListe.o
	g++ -c -I "./include" ./src/DosyaOku.cpp -o ./lib/DosyaOku.o
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o

bagla:
	g++ ./lib/Dugum.o ./lib/BagliListe.o ./lib/DosyaOku.o ./lib/main.o -o ./bin/program
calistir:
	./bin/program.exe