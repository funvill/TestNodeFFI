# Test Node FFI

Example script to test the functionality of [node-ffi](https://github.com/node-ffi/node-ffi), and [ref](https://github.com/TooTallNate/ref#built-in-types)

## How to run

```bash
sudo apt install build-essential
sudo npm install ffi
make
node test.js
```

## Example output

```txt
CFYI: Buffer before: Buffer length: 100, Buffer:

   [00]  (h) x68,  (e) x65,  (l) x6c,  (l) x6c,  (o) x6f,  ( ) x20,  (w) x77,  (o) x6f,  (r) x72,  (l) x6c,
   [10]  (d) x64,  ( ) x00,  ( ) x00,  ( ) x00,  ( ) x00,  ( ) x00,  ( ) x00,  ( ) x00,  ( ) x00,  ( ) x00,
   [20]  ( ) x00,  ( ) x00,  ( ) x00,  ( ) x00,  ( ) x00,  ( ) x00,  ( ) x00,  ( ) x00,  ( ) x00,  ( ) x00,
   [30]  ( ) x00,  ( ) x00,  ( ) x00,  ( ) x00,  ( ) x00,  ( ) x00,  ( ) x00,  ( ) x00,  ( ) x00,  ( ) x00,
   [40]  ( ) x00,  ( ) x00,  ( ) x00,  ( ) x00,  ( ) x00,  ( ) x00,  ( ) x00,  ( ) x00,  ( ) x00,  ( ) x00,
   [50]  ( ) x00,  ( ) x00,  ( ) x00,  ( ) x00,  ( ) x00,  ( ) x00,  ( ) x00,  ( ) x00,  ( ) x00,  ( ) x00,
   [60]  ( ) x00,  ( ) x00,  ( ) x00,  ( ) x00,  ( ) x00,  ( ) x00,  ( ) x00,  ( ) x00,  ( ) x00,  ( ) x00,
   [70]  ( ) x00,  ( ) x00,  ( ) x00,  ( ) x00,  ( ) x00,  ( ) x00,  ( ) x00,  ( ) x00,  ( ) x00,  ( ) x00,
   [80]  ( ) x00,  ( ) x00,  ( ) x00,  ( ) x00,  ( ) x00,  ( ) x00,  ( ) x00,  ( ) x00,  ( ) x00,  ( ) x00,
   [90]  ( ) x00,  ( ) x00,  ( ) x00,  ( ) x00,  ( ) x00,  ( ) x00,  ( ) x00,  ( ) x00,  ( ) x00,  ( ) x00,

CFYI: Calling callback
Debug: current buffer:  hello world
Debug: current buffer:  one two three

CFYI: Buffer afterwards: Buffer length: 13, Buffer:

   [00]  (o) x6f,  (n) x6e,  (e) x65,  ( ) x20,  (t) x74,  (w) x77,  (o) x6f,  ( ) x20,  (t) x74,  (h) x68,
   [10]  (r) x72,  (e) x65,  (e) x65,

```
