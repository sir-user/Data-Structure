prepare: 
	rm -rf build
	mkdir build

main:
	cd build; cmake ..; cmake --build .
	cd build/app && ./main

standart:
	clear
	rm -rf build
	mkdir build
	cd build; cmake ..; cmake --build .

runmain:
	cd build/app && ./main

