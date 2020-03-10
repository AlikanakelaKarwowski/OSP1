# Project Group:

## Alex Karwowski, Chayton Hamric, Dominic Cumba

### Date: 2/26/20

---

# What we did:
* Created **runProgram()** and created **stop()**

* **runProgram()** calls **readSectors()** to load the file into the local buffer, which then loads the file into memory via **putInMemory()**, and calls **launchProgram()** which runs the file in BlackDOS.

* **stop()** hangs the computer when the program finishes

---

# How to verify the project works

Run the following commands in order:

* Open xterm or other terminal that can run x server programs
* Navigate to the directory which contains the `Lab4` folder
* Type the following commands into your terminal

```
cd Lab4/
sh compileOS.sh
dd if=fib of=floppya.img bs=512 count=1 seek=30 conv=notrunc
echo "c" | bochs -f bdos.txt
```
* At this point the emulator should run and print out to the screen the BlackDOS logo (in light cyan color) and loads the **fib** file.
* It asks the user for the number of terms to print out. After entering a number hit the enter key and the **fib** file will print out that many terms of the fibonacci sequence.

* Click the “power button” in bochs to close the emulator

---
This concludes everything that you need to do to run the project and confirm that it is working correctly
