panelpp: src/main.cpp src/aerofoil.cpp
	g++ -c src/aerofoil.cpp -I ./include/ -o object/aerofoil.o
	g++ -c src/main.cpp -I ./include/ -o object/main.o
	g++ -o panelpp object/aerofoil.o object/main.o

clean:
	rm -f object/*