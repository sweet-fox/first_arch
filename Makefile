all: compile


compile:
	g++ Main.cpp ArchAlgorithm.cpp ProgressBar.cpp DeArchAlgorithm.cpp Node.cpp -lgmp -lgmpxx -o myzip

debug:
	g++ -g Main.cpp ArchAlgorithm.cpp ProgressBar.cpp DeArchAlgorithm.cpp Node.cpp -lgmp -lgmpxx -o myzip
