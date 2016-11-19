all:
	@echo -n "Kompilacja torusa ..."
		g++ -g -Wall -std=c++11 -o torus torus_chain.cpp Torus.cpp -lGL -lGLU -lglut
test: torus
	@echo -n "Test torus..."
	./torus
clean: 
	@echo -n "Czyszczenie folderu..."
	rm torus
