*This project has been created as part of the 42 curriculum by andjajas and tvan-kop.*

## Description
The goal of this project is to discover algorithmic complexity in a very concrete way. Choosing an algorithm can make huge differences in how fast you can sort a list of integers.

## Instructions
After cloning the repo into a directory and going into the directory:

> git clone git@vogsphere-v2.codam.nl:vogsphere/intra-uuid-4e503d9f-c13d-4499-b189-fdd68f599a21-7364484-andjajas push_swap<br>
> cd push_swap

Run the `make` command:

> make

This should compile push_swap fully and produce an executeable called `push_swap`.
To use push_swap, start with executing the program and then listing all the numbers kind of like this:

> ./push_swap 9 -24 -5135 9873 (etc)

Ofcourse, you can put any numbers. Any invalid number will result in it printing `Error`<br>
You can also give the program flags. They must be listed right *after* the program name. For example:

> ./push_swap --bench 7 8 2 4 (etc)

The available flags are:
* --simple      forces the program to use the *simple* algorithm.
* --medium      forces the program to use the *medium* algorithm.
* --complex     forces the program to use the *complex* algorithm.
* --adaptive    forces the program to use the *adaptive* algorithm.

These are *mutually exclusive*, meaning you can only put one flag of this kind.
Then you can also put the optional flag:

* --bench

Which will print data about what algorithm it used.

## Algorithms
Handle trivial cases first<br>
* Already sorted → do nothing<br>
* 2 numbers → at most one sa<br>
* 3 numbers → hardcode the logic (only 6 permutations)<br>
* 5 numbers → push the lowest 2 values in b, sort remaining 3 with previous algorithm,
push back the 2 values from b

## Resources
#### Codam peers:
* alkhan, bandrade, cpfister, eschloss, ivan-der, lblonk, nakhatoo, pride-ol, stehoffm, tkroon, tveltman, vcoevert, vvan-der, webbers<br>
#### Algorithms:
* [analysis (wikipedia)](https://en.wikipedia.org/wiki/Analysis_of_algorithms)<br>
* [Big-O cheatsheet + links to different sorting algorithms](https://www.bigocheatsheet.com/)<br>
* [sorting algorithms (geeksforgeeks)](https://www.geeksforgeeks.org/dsa/sorting-algorithms/)<br>
* [selection sort (geeksforgeeks)](https://www.geeksforgeeks.org/dsa/selection-sort-algorithm-2/)<br>
* [radix sort (Wikipedia)](https://en.wikipedia.org/wiki/Radix_sort)<br>
* [significant digits, MSD, LSD (Wikipedia)](https://en.wikipedia.org/wiki/Significant_figures#Least_significant_digit)<br>
#### Operations:
* [stack, push, pop (wikipedia)](https://en.wikipedia.org/wiki/Stack_(abstract_data_type))<br>
* [stack in C, push, pop (geeksforgeeks)](https://www.geeksforgeeks.org/c/implement-stack-in-c/)<br>
#### Algorithmic visualizer:
* [visualizer for push_swap](https://push-swap42-visualizer.vercel.app/)<br>
#### Git:
* [A site to learn git](https://learngitbranching.js.org/)<br>
#### Automation commands:
* [A site to learn search and replace with sed](https://www.redhat.com/en/blog/edit-text-bash-command)<br>
#### The use of the gdb debugging tool:
* [A gdb cheatsheet](https://darkdust.net/files/GDB%20Cheat%20Sheet.pdf)<br>
#### Coloring the make commands:
* [Stackoverflow explaing how to color echo commands](https://stackoverflow.com/questions/24144440/color-highlighting-of-makefile-warnings-and-errors)<br>
#### Enumeration:
* [define or enum? (Stackoverflow)](https://stackoverflow.com/questions/3134757/define-or-enum)<br>
* [enum in C (geeksforgeeks)](https://www.geeksforgeeks.org/c/enumeration-enum-c/)<br>
* [enum in C (w3schools)](https://www.w3schools.com/c/c_enums.php)<br>
#### use of AI:
* tvan-kop didn't use AI
* andjajas used [Microsoft copilot](https://copilot.microsoft.com/) & [Claude AI](https://claude.ai/new) with a mandatory prompt (see below) so it would never give the code, but only acted as a guide for the logic when needed.
	* mandatory prompt: `remember for me, always stay in 'Study and learn' mode, never give me answers or code directly, keep your anwers short so I can ask questions.`
	* example of a follow-up prompt: `I challenge your logic, does it not stay 0(1) if we do not go through the whole list to find the bottom, because the bottom is right behind the top, so we just need to use the prev pointer to move to the bottom from the top in a doubly circular linked list.`<br>
	* topics where AI improved understanding: selection sort, radix sort, chunk sort, low-disorder sorting



# THINGS WE NEED TO DO BEFORE HANDING IN
Fix the too many functions norminette error in libft_functions.

## to-do
When adding/removing a file, update the makefile.
