// 
// This script loads the example shared libary with its two functions. 
// Sets up a callback function that gets called in the loop. Then runs 
// the loop. 
// 
// In the callback function, we don't know the size of the "buffer". so 
// we need to "Reinterpret" the buffer and set the size of the buffer. 
// After the buffer has been reinterpret we can write to it. 
// 

var ffi = require('ffi'); // DLL interface. https://github.com/node-ffi/node-ffi 
var ref = require('ref'); // DLL Data types. https://github.com/TooTallNate/ref 

// Define a callback function 
var charPtr = ref.refType('char *');
var uint8Ptr = ref.refType('uint8 *');

var FuncPtrExample = ffi.Callback('uint32', [charPtr, 'uint32', uint8Ptr], CallbackExample)

// Load the example libary with its two functions. 
var libExample = ffi.Library('./libExample', {
    'Loop': ['void', []],
    'RegisterExample': ['void', ['pointer']]
})

// Callback function 
function CallbackExample(buffer, maxBufferSize, randomNumber) {

    // This is the value that we are going to write to the CString buffer. 
    var valueToWrite = "one two three";

    // Reinterpret the buffer with its correct size, so we can write to it
    // later on in this function. 
    var newBuffer = ref.reinterpret(buffer, maxBufferSize, 0)

    // Get the current buffer as a CString 
    console.log("Debug: current buffer: ", ref.readCString(buffer, 0))
    console.log("Debug: current randomNumber: ", randomNumber.readUInt8())


    // Update the current buffer as a CString 
    ref.writeCString(newBuffer, 0, valueToWrite);

    randomNumber.writeUInt8(98, 0)

    // Get the current buffer as a CString after writing to it. 
    console.log("Debug: after buffer: ", ref.readCString(buffer, 0))
    console.log("Debug: after randomNumber: ", randomNumber.readUInt8())

    // Return the size of the buffer. 
    return valueToWrite.length
}

// Register the callback function 
libExample.RegisterExample(FuncPtrExample)

// Run the loop. 
libExample.Loop()
