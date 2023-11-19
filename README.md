# This is 0x19. C - Stacks, Queues - LIFO, FIFO.

# monty
README file

#  MONTY Project README

This project was completed as part of the ALX Software Engineering Program, Cohort 18. The project commenced on November 14, 2023, at 6:00 AM and concluded on November 17, 2023, at 6:00 AM.
We were paired in a group of two and tasked with writing an interpreter for the Monty bytecode.

## Contributors:
- Onyedikachi Ejim (ejimovc@gmail.com)
- Erick Onwochei (erickchinyem@gmail.com)


## About the Monty Language:

## The Monty language
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

# Monty byte code files

Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:

## The code was compiled with: gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty

# TASKS:
### Task 0. push, pall: Implement the push and pall opcodes.
### Task 1. pint: Implement the pint opcode.
### Task 2. pop: Implement the pop opcode.
### Task 3. swap: Implement the swap opcode.
### Task 4. add: Implement the add opcode.
### Task 5. nop: Implement the nop opcode.
### Task 6. sub: Implement the sub opcode.
### Task 7. div: Implement the div opcode.
### Task 8. mul: Implement the mul opcode.
### Task 9. mod: Implement the mod opcode.
### Task 10. comments.
### Task 11. pchar: Implement the pchar opcode.
### Task 12. pstr: Implement the pstr opcode.
### Task 13. rotl: Implement the rotl opcode.
### Task 14. rotr: Implement the rotr opcode.
### Task 15. stack, queue: Implement the stack and queue opcodes.
### Task 16: Brainf*ck: Write a Brainf*ck script that prints School, followed by a new line.
### Task 17. Add two digits: Add two digits given by the user.
### Task 18. Multiplication: Multiply two digits given by the user.
### Task 19. Multiplication level up: Multiply two digits given by the user.

# Do Hard Things, THANK YOU!!!


########################################################################################

## The Monty language
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just 
like Python). It relies on a unique stack, with specific instructions to manipulate it. 
The goal of this project is to create an interpreter for Monty ByteCodes files.

# Monty byte code files

Files containing Monty byte codes usually have the .m extension. Most of the industry 
uses this standard but it is not required by the specification of the language. There is 
not more than one instruction per line. There can be any number of spaces before or 
after the opcode and its argument:


The primary objective of this project, in my view, is to provide a deeper understanding of data structures and guide the selection process. It delves into the concepts of stacks and queues, highlighting their differences.

A stack is a data structure where both insertions and deletions occur at the same end. Conversely, a queue is a data structure where elements are added from the back (enqueued) and removed from the front (dequeued).

PROJECTS

ALX provided two structures for our use. While I utilized them, I made modifications to better align with my code structure. Here are the original structures and my modifications:

typedef struct stack_s
{
		int n;
		struct stack_s *prev;
		struct stack_s *next;
} stack_t;



stack_t is a doubly linked list used for storing elements in either a stack or queue format.

typedef struct instruction_s
{
		char *opcode;
		void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

instruction_t is a structure that stores the current opcode and a pointer to the opcode command function. This function is invoked when the corresponding opcode is identified. Essentially, we create an array of instruction_t structures, each representing a potential opcode.

My personal structure:

typedef struct monty
{
	char *arg;
	char *line;
	FILE *file;
	unsigned int lineNum;
	bool isQ;
} m;

This structure houses the fundamental variables required for the operations:

char *arg: Stores the argument passed to the opcode.
char *line: Stores each line read from the file using getline.
FILE *file: Stores the file pointer passed as an argument. This allows me to close the file at any point during the program.
Unsigned int lineNum: This serves as a counter for the current line number in the file. Originally, this was a part of the instruction_t structure’s function pointer argument. However, I’ve transitioned it to the monty structure, which accommodates additional data necessary for each function. Consequently, the function pointer [f] now accepts stack_t and monty as arguments when invoked.
bool isQ: A switch that is initially set to false at the start of the program. This variable flips to true if the user prefers the operation order to be a queue, and remains false otherwise.
			
	TASKS BRIEF EXPLANATION AND WHAT I THINK WAS THE PURPOSE AND GOAL OF THE TASK.
	
The program functions as follows: At the onset, it validates whether the appropriate number of arguments (ac == 2) has been supplied. If this condition is satisfied, the file named stored in argv[1] is accessed, and a pointer to this opened file is stored in the file element of struct monty. Subsequently, the program commences reading the file, processing it one line at a time using getline.

Each line read is tokenized using strtok, provided getline does not return -1, which would indicate an error or EOF. The first token in each line is presumed to be an opcode and is compared against our array of instruction_t structs the second token is stored in the monty struct element char *arg. If a match is identified, the corresponding function pointer linked to the opcode name is invoked. If no match is found, the program advances to the next line of code.

In case of any errors encountered during the argument validation, file opening, or opcode execution, the program outputs an error message to stderr and terminates with a status indicating failure.
TASK 0: Implement the push and pall opcodes.

The opcode `push` introduces an element to the stack. This command is invoked with an integer as an argument, which represents the element to be stored in the stack. My implementation operates in the following manner: 
-	it verifies if the argument passed to `push` is an integer. If it is, the string is converted to an integer using the `atoi` function. If `arg` is null or not a valid number, the program outputs the appropriate error message to `stderr` and terminates with a status indicating failure. 

Lastly, we check if the monty struct element isQ is == true, if yes a node is added to the end of the list else, the node is added to the beginning of the list.

I have devised a function, `addNodeStart`, that appends a node to the start of a list. This function is utilized to add in stack format. Conversely, the function `addNodeEnd` appends to the end of a list, adhering to the queue format. 

**PSEUDOCODE:**
`addNodeStart`: Accepts a pointer to a pointer to the head of a `stack_t` head and an integer (the element to be added)

-	Validate if head is NULL
	a.	If it is, return

-	Allocate a new space of size stack_t to accommodate the new node.
-	Assign `new->next` to the head of the list
-	Set `new->prev` to NULL
-	Assign `new->n` to store the new element
-	Designate the new element as the head by setting the head of the list to point to it

-	Validate if the next node is NULL
-	If it isn't, assign the `prev` of the next node to point to the new node. This precaution prevents the dereferencing of a null pointer when the new element is the first element in the list.

`pall`
The opecode pall prints all the values on the stack, starting from the top of the stack. the opcode is called with no argument. The pall function is implementated in such a way that it moves throught the list and prints all the items in the stack till it encounters null.

**PSEUDOCODE:**
-	Check if head of the list is NULL
	a.	return if yes
-	while head of the list is not NULL
	a.	print the value at the node
	b.	set the head to point to the next node

	



**TASK 1:** Implement the pint opcode.
The pint function prints the value at the top of the stack.

**TASK 2:** Implement the pop opcode. The pop opcode removes the node at the top of the stack.

**PSEUDOCODE:**

-	Assign a new variable, curr, to point to the head of the list.
-	Set the head of the list to the next node on the list (head = head->next).
-	Free curr. Since curr points to the previous head of the list, freeing curr will free the previous head.
-	Check if the node pointed to by head is null.
	-	If it isn’t, set head->prev to NULL.



**TASK 3:** Implement the swap opcode. The swap opcode interchanges the top two elements of the stack.

The function initially verifies if there are at least two nodes in the list by checking if the next node is null. If it is, the program terminates and the appropriate error message is displayed on stderr.

The program designates two pointers, node1 and node2, of the stack_t struct. node1 points to the head of the list and node2 points to the next node. We then verify if node2->next is null, which indicates there are only two nodes in the list. In this case, node1->prev is set to node2, node2->next is set to node1, and both node1->next and node2->prev are set to NULL.

If node2->next is not null, the following operations are performed: we access node2->next and set its prev to point to node1. This ensures that we can still access the rest of the list. Also, node1->next is set to node2->next. After that, we ensure the head of the list is set to node2.

**PSEUDOCODE:**

- Initialize two pointers of stack_t struct: node1 and node2
- Set node1 to point to the head of the list
- Set node2 to point to the next node in the list

- Check if node2->next is null (indicating there are only two nodes in the list)
	- If yes:
		- Set node1->prev to node2
		- Set node2->next to node1
		- Set node1->next to NULL
		- Set node2->prev to NULL

- If node2->next is not null:
	- Access node2->next and set its prev to point to node1
	- Set node1->next to node2->next
	- Set node1->prev to node2
	- Set node2->next to node1
- Ensure the head of the list is set to node2


**TASK 4:** Implement the add opcode.
The opcode add adds the top two elements of the stack. The function addeds the values stored in the top two nodes of the list and then store the value in the second node, and the first node is removed, the list head then points to the second node making it the new head.

**TASK 5:** Implement the nop opcode.
The opcode nop doesn’t do anything.


**TASK 6:** Implement the sub opcode.
The opcode sub subtracts the top element of the stack from the second top element of the stack. The function subtracts the values stored in the top two nodes of the list and then store the value in the second node, and the first node is removed, the list head then points to the second node making it the new head.
TASK 7: Implement the div opcode.
The opcode div divides the second top element of the stack by the top element of the stack.

**TASK 8:** Implement the mul opcode.
The opcode mul multiplies the second top element of the stack with the top element of the stack.

**TASK 9:** Implement the mod opcode.
The opcode mod computes the rest of the division of the second top element of the stack by the top element of the stack.

**TASK 10:** Remove comments


**TASK 11:** Implement the pchar opcode.**
The `pchar` opcode prints the character at the top of the stack, followed by a new line. It displays the ASCII representation of the integer stored at the top of the stack.

**PSEUDOCODE:**
- Check if the stack is not empty
- If it is, print an error message and exit
- Otherwise, print the ASCII representation of the integer at the top of the stack


**TASK 12:** Implement the pstr opcode.**
The `pstr  opcode prints the string starting at the top of the stack, followed by a new line. This function traverses the entire list and prints the ASCII representation of each integer stored in each node.

**PSEUDOCODE:**
- Start at the top of the stack
- While the stack is not empty:
	- Print the ASCII representation of the integer at the current node
	- Move to the next node
- Print a new line


**TASK 13:** Implement the rotl opcode.**
The `rotl` opcode rotates the stack to the top. The function sets the first element in the list to be the last and sets the second element on the list to be the head of the list.

**PSEUDOCODE:**
rotl_opcode:
- Check if the stack has more than one node
- If it does:
	- Move the head of the stack to the end
	- Set the second node as the new head of the stack



**TASK 14:** Implement the rotr opcode. The rotr opcode rotates the stack to the bottom. This function promotes the last element on the stack to the top of the stack and sets the second element on the stack to null.

**PSEUDOCODE:**

rotr_opcode:
- Check if the stack has more than one node
- If it does:
	- Move the last node of the stack to the top
	- Set the second node's next pointer to NULL

**TASK 15:** Implement the stack and queue opcodes. The stack opcode sets the format of the data to a stack (LIFO). This is the default behavior of the program. When the opcode is passed, the isQ element of the monty struct is set to false.

The queue opcode sets the format of the data to a queue (FIFO). When the opcode is passed, the isQ element of the monty struct is set to true.

**PSEUDOCODE:**

stack_opcode:
- Set the isQ element of the monty struct to false

queue_opcode:
- Set the isQ element of the monty struct to true

**TASK 16:** Cracking Brainf*ck to Write "School" and Beyond

Imagine Brainf*ck as a quirky language with just eight super basic rules. It's like having a tiny set of LEGO blocks to build anything you want! But here's the twist: it works with two cool tools called data and instruction pointers, which help it decide what to do next.

**The Brainf*ck Rules:**

+: Add to the number in a memory spot
-: Subtract from the number in a memory spot
.: Show the written code as letters or symbols
,: Get a letter or symbol from someone and save it
[: If a memory spot's number is zero, skip forward
]: If a memory spot's number isn’t zero, go back
Trying to make Brainfck write "School" took me on a rollercoaster! At first, I thought about making each letter using numbers, but that felt too easy. So instead, I crafted a plan to gradually increase some numbers and tweak the rest myself. Working with loops in Brainfck is like playing a puzzle game careful moves to change the right numbers at the right time.

Then, the next challenge hit multiplication in Brainf*ck. Picture this: to multiply 'a' and 'b', you need a loop that goes 'b' times and repeats it 'a' times. Sounds like a mind-boggling loop within a loop, right? But here's the catch: after the inside loop finishes, I had to figure out a tricky way to reset it back to where it started. So, I danced between numbers, shifting them around to keep the loop going.

Now, the ultimate puzzle printing a number that's longer than one character. Multiplying numbers was like cracking a tough nut, but printing a number that's more than one character long? It’s like climbing the tallest mountain in Brainfck land! I've tried, failed, and tried again. The solution's hiding somewhere, and I'm on a quest to uncover it. Stay tuned for the next chapter in this Brainfck adventure!


**TASK 17:** Add two digits given by the user.
**TASK 18:** Multiply two digits given by the user.
**TASK 19:** Multiply two digits given by the user.

**THIS WAS FUN**
