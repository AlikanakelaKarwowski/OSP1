# Project Group:
Alex Karwowski, Chayton Hamric, Dominic Cumba

Date: 2/14/20

# What we did:
* Created **readString()**, **readInt()**, and **writeInt()** functions and defined cases 1, 13, and 14 of **handleInterrupt21()**

* **readString()**, takes a character array as a parameter and stores user input inside the array until ENTER is pressed

* **readInt()**, converts user input in the form of a string into a numeric value

* **writeInt()**, converts an integer value into a string and outputs the string

* **handleInterrupt21()** has case 1 defined as a call to function **readString()**, case 13 defined as a call to **writeInt()**, and case 14 defined as a call to **readInt()**.

* Included madLibKernel code to test new functions

* Replaced function calls to interrupt call

# How to verify the project works

Run the following commands in order:

* Open xterm or other terminal that can run x server programs
* cd into the directory of the Lab2 folder

```
cd Lab2/
sh compileOS.sh
echo "c" | bochs -f bdos.txt
```
* At this point the emulator should run and print out to the screen the BlackDOS logo. And it should start the MadLibs program. Answer the questions until the program is finished.

* Click the “power button” in bochs to close the emulator
```
more printer.out
```
* This will allow you to view the results of your MadLibs


This concludes everything that you need to do to run the project and confirm that it is working correctly
