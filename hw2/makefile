all:
	make a.out
	make Validation.class

a.out: Validation.cpp
	g++ Validation.cpp

Validation.class: Validation.java
	javac Validation.java

clean:
	rm -f a.out Validation.class
