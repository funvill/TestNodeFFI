// Example.so 
// 
// This is a simple shared libary that has two exported functions. 
// - RegisterExample() - Registers the callback function into a global 
// - Loop() - Sets up a buffer and calls the callback function with this 
//            buffer. Prints the buffer before and after the callback 
//            function is called.
// 

#ifdef __cplusplus
#ifdef _WIN32
#define DllExport extern "C" __declspec(dllexport)
#else // WIN32
#define DllExport extern "C"
#endif // LINUX
#else // __cplusplus
#define DllExport
#endif // __cplusplus

#include <stdint.h>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <iomanip>

typedef uint32_t(*FPExample)(char* buffer, uint32_t maxBufferLength);

FPExample g_example; // global function pointer. 

DllExport void RegisterExample(uint32_t(*example)(char* buffer, uint32_t maxBufferLength)) {
	g_example = example; 
}

void printBuffer( char * buffer, uint32_t length) {

	std::cout << "Buffer length: " << std::dec << length << ", Buffer: " << std::endl; 
	for (uint32_t offset = 0; offset < length; offset++) {
		if( offset % 10 == 0 ) {
			std::cout << std::endl;		
			std::cout << "   ["  ;
			std::cout << std::dec << std::setfill('0') << std::setw(2) << offset ;
			std::cout << "]  " ;
		}

		std::cout << '(' << buffer[offset]  << ") x" ;
		std::cout << std::setfill('0') << std::setw(2) << std::hex << (int) buffer[offset] ;
		std::cout << ",  "; 

		
	}
	std::cout << std::endl;
	std::cout << std::endl;
}

DllExport void Loop() {

	const int BUFFER_SIZE = 100 ; 
	char buffer[BUFFER_SIZE];

	// Set up the buffer before. 
	memset( buffer, 0 , BUFFER_SIZE); 
	sprintf( buffer, "hello world" ); 

	std::cout << "CFYI: Buffer before: "; 
	printBuffer(buffer, BUFFER_SIZE ); 

	std::cout << "CFYI: Calling callback" << std::endl ; 
	// Calling callback 
	uint32_t ret = g_example(buffer, BUFFER_SIZE);
	if( ret > BUFFER_SIZE ) {
		std::cerr << "CError: Buffer length of [" << ret << "] is larger then then buffer allows (100)" << std::endl; 
		return ; 
	}

	// Print the buffer afterwards. 
	std::cout << std::endl;
	std::cout << "CFYI: Buffer afterwards: "; 
	printBuffer(buffer, ret ); 
}
