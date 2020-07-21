all : addnbo
addnbo : nbo.out 
		gcc addnbo.cpp -o addnbo.exe
		./addnbo.exe a.bin b.bin
nbo.out : ./addnbo.exe a.bin b.bin
clean : rm -rf *.o 

