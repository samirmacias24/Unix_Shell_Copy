# Unix_Shell_Copy

## Description

Produced an application that acts like the UNIX Shell. It utilized system calls such as wait(), fork(), and execvp() to create a new child process that is able to handle user input. It takes the user input and processes the command as the actual shell does. 

## How it works

Analyzing the syntax of the program (unixShellCopy.c)
char input[50] // contains the user’s input
char * split[50] // splits the user’s input (where split[0] is the first word)

![](https://github.com/samirmacias24/Unix_Shell_Copy/blob/main/unixShellCopy_images/pic1.PNG)

While(1) : is an infite loop
In this section, “scanf” is used to get input from the user and it’s placed inside the “input”
character array. Next, we see if the user wants to exit the program. If the user enters “exit”, the
program will then terminate returning back to the official bash. Lastly, once we know the input
we can call the fork() function.
The fork system call will have the kernel create a new child process. The next section will ensure
that there are no errors with fork and if the new process is the child and or parent.

![](https://github.com/samirmacias24/Unix_Shell_Copy/blob/main/unixShellCopy_images/pic2.PNG)

**Section 1: (Black)**
Now that we have the new process we can check the fork_rv variable. If the fork system call
returns -1 we know that there was an error. If this is the case, we call perror() to display a
description of the error.

**Section 2: (Navy Blue)**
Everything in this section is handled by the new child process that was created earlier.
The first thing that needs to be done is to take the user input and break it into each
corresponding word (EX: ls -la -> [ls] [-la]). Using the strtok function, we can do such a thing. It
returns a pointer to the first token found in the string (pointer name is ‘ptr’).
As we traverse the given text, each word will be placed into the “split” array. Where each
element contains a single word (split[0] is the first word). Once that is complete, null is added
to the last element in the array.
After that process, “execvp” can be used. We know that split[0] has the first word, so the
command looks like the following “execvp(split[0], split);” The child process will now execute this
new program that the user has entered. If it fails then “perror” is called and the program
exits.

**Section 3: (Red)**
This is the section that contains what the parent process is doing. While the child process is
running the parent is simply waiting, it’s waiting until the child process is terminated. This is
done using the wait() system call.

Note: The comments in the code give additional insight into what is going on in each section.

![](https://github.com/samirmacias24/Unix_Shell_Copy/blob/main/unixShellCopy_images/pic3.PNG)


## Testing the Program

In this section, we will compile and run the program.

First, we will compile the program using GCC. Below we see that the program runs
properly and it asks the user to enter a command.

![](https://github.com/samirmacias24/Unix_Shell_Copy/blob/main/unixShellCopy_images/pic4.PNG)


**1.)** Command Used: cat /home/ubuntu1/Desktop

The new file we created is empty! Here we attempt to use the "cat" command within our program.
![](https://github.com/samirmacias24/Unix_Shell_Copy/blob/main/unixShellCopy_images/pic7.PNG)

**2.)** Command Used: nano /home/ubuntu1/Desktop
Using the nano text editor, we typed some random text. This was done to first show
that the program can properly request for nano to be opened. And secondly, so that
we can ensure that “cat” is working properly when called by our program.

![](https://github.com/samirmacias24/Unix_Shell_Copy/blob/main/unixShellCopy_images/pic8.PNG)

Thus, after editing the test.txt file and calling the “cat” command we get the proper output.

![](https://github.com/samirmacias24/Unix_Shell_Copy/blob/main/unixShellCopy_images/pic9.PNG)

**3.)** Command Used: ps (process status)
With the “ps” command we are given information about the processes running on
our Linux system. In this case, we see that we have two bash processes running (the
actual bash and ours). And also the ps process that we asked the kernel to run.

![](https://github.com/samirmacias24/Unix_Shell_Copy/blob/main/unixShellCopy_images/pic10.PNG)

**Entering wrong input**

When the input is not an actual command for the bash shell to process, it outputs “execvp failed: No such file
or directory” as intended. Then it asks the user to once again to enter a command

![](https://github.com/samirmacias24/Unix_Shell_Copy/blob/main/unixShellCopy_images/pic12.PNG)

