output: main.o Graph.o Node.o Tree.o
	g++ main.o Graph.o Tree.o Node.o -o output

main.o: main.cpp
	g++ -c main.cpp

Graph.o: Graph.cpp Graph.h
	g++ -c Graph.cpp

Tree.o: Tree.cpp Tree.h
	g++ -c Tree.cpp

Node.o: Node.cpp Node.h
	g++ -c Node.cpp

clean:
	rm *.o output

# target: dependencies
# 	action