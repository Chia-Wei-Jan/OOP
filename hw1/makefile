all:
	make a.out
	make Avg.class

a.out: Avg.cpp
	g++ Avg.cpp

Avg.class: Avg.java
	javac Avg.java

clean:
	rm -f a.out Avg.class
