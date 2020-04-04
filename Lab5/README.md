# Project Group:

## Alex Karwowski

### Date: 4/3/2020

---

# What we did:
* Created file **Shell.cpp**, **Shell.c**, and made updates to **compileOS.sh** and **kernel.c**
* Due to issues using bochs from home, we were not able to get the **Shell.c** file to work correctly *(only 3 commands work at a time)*.

* We created shell command functions **boot**, **clrs**, **echo**, **copy**, **ddir**, **exec**, **help**, **prnt**, **remv**, **senv**, **show**, **twet**, and **exit**, as well as a custom **sleep** function for "rebooting" purposes.

---

# How to verify the project works

Run the following commands in order:

* Open xterm or other terminal that can run x server programs
* Navigate to the directory which contains the `Lab5` folder
* Type the following commands into your terminal

```
cd Lab5/
make
./Shell
```

* At this point you should see the Shell program running. Any of the commands above are recognized by the Shell.
* Typing `help` brings up the entire list of commands as well as their functionality
* We are using a .cpp file due to issues with bochs over ssh, as well as issues with writing a large file to the floppya.img file.
* Professor O'Neil has given us permission to use a .cpp file instead of a .c file
* Once you are finished type the `exit` command to exit the Shell

---
This concludes everything that you need to do to run the project and confirm that it is working correctly
