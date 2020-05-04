# Project Group:

## Chayton Hamric

### Date: 4/19/2020

---

# What we did:
* Made the following commands work: W, E, C, X, H, P, S, D, Q, L, M.
* Because when using bochs I kept getting errors because our Shell.c file was to large. For that reason I had to use C++

* The above commands are for: W clears the screen, E echos back, C copy one file into another, X executes a command, H help for command list, P Prints what's in the file, S Surfs the web, D Deletes a file, Q Exits the shell, L List all files in the directory, M Make or edit a file.

---

# How to verify the project works

Run the following commands in order:

* Open xterm or other terminal that can run x server programs
* Navigate to the directory which contains the `LabX` folder
* Type the following commands into your terminal

```
cd LabX/
make all
./Shell
```

* Once you run the shell all above functions are able to be used.
* Typing `H` brings up the entire list of commands as well as their functionality
* Professor O'Neil has given permission to use a .cpp file instead of a .c file
* Once you want to quit the shell type `Q` and the shell will exit

---
