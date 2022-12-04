# Stack automata simulator

## Author

* Jorge Cabrera Rodríguez (alu0101351773)

## Description

This project implements a non-deterministic stack automata in c++. The halt
criteria is if the actual state is the final state **(APf)**.

## Usage

How to compile the program:

```
make
```

How to run the program:

```
./build/main.out [-v | --verbose] <input_file_name> <test_string> [test_string ...]
```

If the `-v` flag in added, the program will show the progress of the algorithm.

## Example

```
./build/main.out input/APf.txt carro ab aba pedal baa aabb
```
