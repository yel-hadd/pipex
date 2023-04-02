# PIPEX

The PIPEx project is a part of the curriculum of the 42 School, which is aimed at helping students develop their skills in UNIX systems, file descriptors, processes, and interprocess communication.

The project involves the creation of a program called "pipex" that simulates the behavior of the shell command-line sequence 
```bash
< infile cmd1 | cmd2 > outfile
```
The program will read the input from a file, pass it through two commands, and write the output to a file.

## Installation
Clone the repository using the following command:

```bash
git clone https://github.com/yel-hadd/pipex.git
```
Navigate to the project directory using the following command:

```bash
cd pipex
```
Compile the program using the following command:
```bash
make
```
Usage
To use the pipex program, execute the following command:

```bash
./pipex file1 cmd1 cmd2 file2
```
The parameters are described as follows:

file1: the input file that contains the text to be processed
cmd1: the first command that will be executed to process the input from file1
cmd2: the second command that will be executed to process the output from cmd1
file2: the output file where the final result will be stored

## Here is an example usage:

```bash
./pipex infile "ls -l" "grep pipex" outfile
```
This command will execute the ls -l command on the input file infile, and then execute the grep pipex command on the output of the previous command. Finally, the result will be written to the outfile.

## Contributions
Contributions to the pipex project are welcome. If you find a bug or have a suggestion for improvement, please submit an issue or a pull request. We follow the standard 42 School guidelines for code style and conduct.

## License
The pipex project is licensed under the MIT License. Please see the LICENSE file for more information.
