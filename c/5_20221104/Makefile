5_20221104_3.out: ../utilities/basics.o ../utilities/binarySearchTree.o 5_20221104_3.o
	clang ../utilities/basics.o ../utilities/binarySearchTree.o 5_20221104_3.o -o 5_20221104_3.out
../utilities/basics.o: ../utilities/basics.h ../utilities/basics.c
	clang -c ../utilities/basics.c -o ../utilities/basics.o
../utilities/binarySearchTree.o: ../utilities/binarySearchTree.h ../utilities/binarySearchTree.c
	clang -c ../utilities/binarySearchTree.c -o ../utilities/binarySearchTree.o
5_20221104_3.o: ../utilities/basics.h ../utilities/binarySearchTree.h 5_20221104_3.c
	clang