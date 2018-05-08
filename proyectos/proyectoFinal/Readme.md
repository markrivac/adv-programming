# WORDS1 : Play on words!

## Description

All submissions for this problem are available.
Some of the secret doors contain a very interesting word puzzle. The team of archaeologists has to solve it to open that doors. Because there is no other way to open the doors, the puzzle is very important for us.

There is a large number of magnetic plates on every door. Every plate has one word written on it. The plates must be arranged into a sequence in such a way that every word begins with the same letter as the previous word ends. For example, the word '**acm**' can be followed by the word '**motorola**'. Your task is to write a computer program that will read the list of words and determine whether it is possible to arrange all of the plates in a sequence (according to the given rule) and consequently to open the door.

### Input

The input consists of T test cases. The number of them (T, equal to about 500) is given on the first line of the input file. Each test case begins with a line containing a single integer number N that indicates the number of plates (1 <= N <= 100000). Then exactly Nlines follow, each containing a single word. Each word contains at least two and at most 1000 lowercase characters, that means only letters 'a' through 'z' will appear in the word. The same word may appear several times in the list.

### Output

Your program has to determine whether it is possible to arrange all the plates in a sequence such that the first letter of each word is equal to the last letter of the previous word. All the plates from the list must be used, each exactly once. The words mentioned several times must be used that number of times.

If there exists such an ordering of plates, your program should print the sentence "*Ordering is possible.*". Otherwise, output the sentence "*The door cannot be opened.*"

### Example

Sample input:

    3
    2 
    directi
    codechef
    3
    skenzo
    logicboxes
    orderbox
    2
    ok
    ok

Sample output:

    The door cannot be opened.
    Ordering is possible.
    The door cannot be opened.

## Solution

For this problem I created a Java program that solves the test cases. It receives the input as the instruction says and outputs the same way.

First it receives the test cases quantity, for each one of the asks for a words quantity and, then the words. It creates multiple variables that helps to solve the problem.

Creates several arrays of the abecedary size (26), one will save the first letters of the words and another the last letters of the words.

In short terms what the program does is to check in this array if a word in the *start_array* is on the *end_array*, if it does it marks this letters as visited and continues looking, if it is not a letter in one array that is in the other, then returns a **false** and with this the program sends a negative response.