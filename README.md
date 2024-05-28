# get_next_line

May it be a file, stdin, or even later a network connection, you will always need a way to read content line by line. It is time to start working on this function, which will be essential for your future projects.
Repeated calls (e.g., using a loop) to your get_next_line() function should let you read the text file pointed to by the file descriptor, one line at a time.


# Better To Check Before Push
- If a function doesn't need include header file, then DOES NOT include. (eg, ft_bzero.c, ft_isascii.c)
- Always check if your shcool header is correct or not in each .c file before push it to Git. Sometimes we will edit a new function in the copy of another function, in this case you need to remember to update the school header file to make sure the funciton name is matching correctly.
- Check the libft.h file, only include the necessary libraries. And make sure you know why you include the library, what it is for.
- Add "_bonus" to each bonus .c files. For example, get_next_line_bonus.c.


# Resources

## Makefile
https://makefiletutorial.com/

https://gl.developpez.com/tutoriel/outil/makefile/

http://perso.univ-lyon1.fr/jean-claude.iehl/Public/educ/Makefile.html

## Memory
https://www.geeksforgeeks.org/memory-layout-of-c-program/

https://craftofcoding.wordpress.com/2015/12/07/memory-in-c-the-stack-the-heap-and-static/

https://www.gnu.org/software/libc/manual/html_node/Memory-Allocation-and-C.html

https://openclassrooms.com/fr/courses/19980-apprenez-a-programmer-en-c/16595-lallocation-dynamique

https://rperrot.developpez.com/articles/c/allocationC/

https://waytolearnx.com/2019/03/difference-entre-allocation-dynamique-et-allocation-statique.html

https://buzut.net/cours/computer-science/differents-types-de-memoires

# Makefile
- This project doesn't need using Makefile. The Makefile I added here just for myself to fast run the command to compile the files. Just for testing.


# Suggestions
- Do the bonus part, it is almost same as mandatory part.
- Test your functions by yourself before using other testing tools.


# Link To libft Tester
https://github.com/xicodomingues/francinette

Note: remember using command 'paco --strict' to test your functions too.


# My Libft Results
<img width="858" alt="Screen Shot 2024-05-28 at 7 51 48 AM" src="https://github.com/Sherry5Wu/get_next_line/assets/132613292/b3f6153d-7ced-479a-96d5-fdcbbd864074">
