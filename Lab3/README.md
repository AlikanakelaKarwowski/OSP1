# Project Group:
Alex Karwowski, Chayton Hamric, Dominic Cumba

Date: 2/21/20

# What we did:
* Created **readSectors()**, **writeSectors()**, and edited **clearScreen()**

* **readSectors()**, Reads from file

* **writeSectors()**, Writes to file

* Included msg and config

# How to verify the project works

Run the following commands in order:

* Open xterm or other terminal that can run x server programs
* cd into the directory of the Lab3 folder

```
cd Lab3/
sh compileOS.sh
echo "c" | bochs -f bdos.txt
```
* At this point the emulator should run and print out to the screen the BlackDOS logo and prints out soft kitty from the msg file.

* Click the “power button” in bochs to close the emulator

This concludes everything that you need to do to run the project and confirm that it is working correctly
