test:
	 g++ -Wall -o test_tensor test_tensor.cpp tensor.cpp
	 ./test_tensor

clean:
	 rm -f test_tensor

full:
	 g++ -Wall -o test_tensor test_tensor.cpp tensor.cpp
	 ./test_tensor
	 rm -f test_tensor
