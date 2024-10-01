panelpp: src/main.cpp src/aerofoil.cpp src/spline.cpp
	g++ -c src/spline.cpp -I ./include/ -o object/spline.o
	g++ -c src/aerofoil.cpp -I ./include/ -o object/aerofoil.o
	g++ -c src/main.cpp -I ./include/ -I /home/tom/.pyenv/versions/3.10.14/include/python3.10/ -I /home/tom/.pyenv/versions/3.10.14/lib/python3.10/site-packages/numpy/_core/include/ -o object/main.o
	g++ -o panelpp -L /home/tom/.pyenv/versions/3.10.14/lib/ -lpython3.10 object/spline.o object/aerofoil.o object/main.o

clean:
	rm -f object/*