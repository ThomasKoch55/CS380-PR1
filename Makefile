
all: 
	gcc -o pr1 pr1.c -Wall

clean:
	rm pr1

test:
	./pr1 sample.txt 1
	cat sample_1_hist.txt

	