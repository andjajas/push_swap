*This project has been created as part of the 42 curriculum by andjajas and tvan-kop.*

## Description
The goal of this project is to discover algorithmic complexity in a very concrete way. Choosing an algorithm can make huge differences in how fast you can sort a list of integers.<br>
Originally designed as an individual challenge, this version has been expanded into a collaborative group project for two people. Working as a team, you must design, implement, and optimize an efficient data-sorting program in C using two stacks (a and b) and a strictly limited set of manipulation instructions.<br>

Rules:
• You have 2 stacks named a and b.<br>
• At the beginning:
◦ The stack a contains a random amount of negative and/or positive numbers without any duplicate.<br>
◦ The stack b is empty.<br>
• The goal is to sort in ascending order numbers into stack a.
To do so you have the following operations at your disposal:<br>
* sa (swap a): Swap the first two elements at the top of stack a.<br>
Do nothing if there is only one or no elements.
* sb (swap b): Swap the first two elements at the top of stack b.<br>
Do nothing if there is only one or no elements.
* ss : sa and sb at the same time.<br>
* pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.<br>
* pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.<br>
* ra (rotate a): Shift up all elements of stack a by one.
The first element becomes the last one.<br>
* rb (rotate b): Shift up all elements of stack b by one.
The first element becomes the last one.
* rr : ra and rb at the same time.<br>
* rra (reverse rotate a): Shift down all elements of stack a by one.
The last element becomes the first one.<br>
* rrb (reverse rotate b): Shift down all elements of stack b by one.
The last element becomes the first one.<br>
* rrr : rra and rrb at the same time.

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
We had the advantage that many peer groups before us had struggled with testing different kinds of algorithms. We chose the following algorithms also based on their shared experiences with us.
* For the `simple algorithm` we chose the `selection sort` adaptation. We also coded a low disorder sort algorithm, which was basically a 'bubble sort' type of algorithm. We compared the results between the two algorithms and decided even though 'bubble sort' was more efficient when a low amount of numbers was given as input, it could not handle large numbers of input very well. We also are going with the assumption that this line in the given subject.pdf is a typo: 'Low disorder: if disorder < 0.2, your chosen method must run in O(n) time'. A time complexity of O(n^2) makes more sense, given the options in the subject<br>
* For the `medium algorithm` we chose the `chunk-based sorting` for these benefits (when compared to 'bucket sort'):
	* Memory allocation: fits entirely within the existing two-stack structure (a and b)
	* Access pattern: linear pointer movement (strictly top or bottom of the stack)
	* Rotation cost is low: leverages bidirectional scans (ra/rra/rb/rrb) to minimize movement<br>
* For the `complex algorithm` we chose `radix sort` adaptation, because we believe it to be the more constant & predictable choice compared to the other given options, because we only have 2 stacks to work with this option feels also the most logical one, because this 'radix sort' sorts at the binary level of the rank value. When we finished coding it, we were already satisfied with its results, we hardly looked at the other options<br> 

* The `adaptive algorithm` uses:<br>
	* our simple algorithm for disorder < 0.2,<br>
	* our medium algorithm for 0.2 <= disorder < 0.5,<br>
	* and our complex algorithm for disorder >= 0.5<br>
	* Also we have added additional `hardcoded logic for user inputs < 6 values` to this `adaptive algorithm`:<br>
		* Already sorted → do nothing<br>
		* 2 numbers → at most one sa<br>
		* 3 numbers → only 6 possible combinations as input<br>
		* 5 numbers → push the lowest 2 values in b, sort remaining 3 with previous algorithm, push back the 2 values from b

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
	* topics where AI improved understanding: selection sort, radix sort, chunk sort, low-disorder sorting(effort was done, but didn't succeed because of time-constraint)
