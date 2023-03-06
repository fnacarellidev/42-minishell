<h1 align="center">
ft_42-libft
</h1>
<p align="center">
<b><i>The very first project proposed by 42 School </b></i>
</p>

## How to test this project
Clone this repo and cd into it
```zsh
git clone https://github.com/fnacarellidev/42-libft.git
cd 42-libft
```
You can compile the library by running the ```make``` command

## Introduction
The aim of the project is to recode a bunch of C functions, some usual, some don't.

* **<b><i>First part</b></i>:** re-code a set of the libc functions, as defined in their man, with the same prototype and behaviors as the originals.
* **<b><i>Second part</b></i>:** code a set of functions that are either not included in the libc, or included in a different form.
* **<b><i>Bonus part</b></i>:** code functions to manipulate lists.

### Part_1

**ctype.h**

| Function | Description |
| --- | --- |
| [**ft\_isalpha**](https://github.com/fnacarellidev/42-libft/blob/main/ft_isalpha.c) |checks for an alphabetic character.|
| [**ft\_isdigit**](https://github.com/fnacarellidev/42-libft/blob/main/ft_isdigit.c) | checks for a digit (0 - 9).|
| [**ft\_isalnum**](https://github.com/fnacarellidev/42-libft/blob/main/ft_isalnum.c) | checks for an alphanumeric character; it  is  equivalent  to (isalpha(c)) || isdigit(c)).|
| [**ft\_isascii**](https://github.com/fnacarellidev/42-libft/blob/main/ft_isascii.c) | checks  whether  c  is a 7-bit unsigned char value that fits into the ASCII character set. |
| [**ft\_isprint**](https://github.com/fnacarellidev/42-libft/blob/main/ft_isprint.c) | checks for any printable character including space.|
| [**ft\_isupper**](https://github.com/fnacarellidev/42-libft/blob/main/ft_isupper.c) | checks if character is uppercase, returns 0 if not.|
| [**ft\_toupper**](https://github.com/fnacarellidev/42-libft/blob/main/ft_toupper.c) | convert lowercase letters to uppercase. |
| [**ft\_tolower**](https://github.com/fnacarellidev/42-libft/blob/main/ft_tolower.c) | convert uppercase letters to lowercase. |

**string.h**

| Function | Description |
| --- | --- |
| [**ft\_memset**](https://github.com/fnacarellidev/42-libft/blob/main/ft_memset.c) | fills the first n bytes of the memory area pointed to by s with the constant byte c.|
| [**ft\_bzero**](https://github.com/fnacarellidev/42-libft/blob/main/ft_bzero.c) | erases the data in the n bytes of the memory starting at the location pointed to by s, by writing null characters to that area.|
| [**ft\_memcpy**](https://github.com/fnacarellidev/42-libft/blob/main/ft_memcpy.c) | copies n bytes from memory area src to memory area dest.  The memory areas must not overlap. Use  memmove(3)  if the memory areas do overlap.
| [**ft\_memccpy**](https://github.com/fnacarellidev/42-libft/blob/main/ft_memccpy.c) | copies no more than n bytes from memory area src to memory area dest, stopping when the character c is found. If the memory areas overlap, the results are undefined.|
| [**ft\_memmove**](https://github.com/fnacarellidev/42-libft/blob/main/ft_memmove.c) | copies n bytes from memory area src to memory area dest. The two strings may overlap, if they do, there's no problem.|
| [**ft\_memchr**](https://github.com/fnacarellidev/42-libft/blob/main/ft_memchr.c) | searches for the first occurrence of the char c in the string .|
| [**ft\_memcmp**](https://github.com/fnacarellidev/42-libft/blob/main/ft_memcmp.c) | function compares the first n bytes (each interpreted as unsigned char) of the memory areas s1 and s2.|
| [**ft\_strlen**](https://github.com/fnacarellidev/42-libft/blob/main/ft_strlen.c) | returns the length of the string s.|
| [**ft\_strlcpy**](https://github.com/fnacarellidev/42-libft/blob/main/ft_strlcpy.c) | copies at max size - 1 characters from src to dst, NUL-terminating the result.|
| [**ft\_strlcat**](https://github.com/fnacarellidev/42-libft/blob/main/ft_strlcat.c) |  appends the NUL-terminated string src to the end of dst.  It will append at most size - strlen(dst) - 1 bytes, NUL-terminating the result.|
| [**ft\_strchr**](https://github.com/fnacarellidev/42-libft/blob/main/ft_strchr.c) | returns a pointer to the first occurrence of the character c in the string s.|
| [**ft\_strrchr**](https://github.com/fnacarellidev/42-libft/blob/main/ft_strrchr.c) | returns a pointer to the last occurrence  of the character c in the string s.|
| [**ft\_strnstr**](https://github.com/fnacarellidev/42-libft/blob/main/ft_strnstr.c) | locates the first occurrence of the null-terminated string little in the string big, where not more than len characters are searched.|
| [**ft\_strncmp**](https://github.com/fnacarellidev/42-libft/blob/main/ft_strncmp.c) | lexicographically compares the null-terminated strings s1 and s2. Returns an integer greater than, equal to, or less than 0, according as the string s1 is greater than, equal to, or less than the string s2. Compares not more than n characters. The comparison is done using unsigned characters, so that '\200' is greater than '\0'.|
| [**ft\_strdup**](https://github.com/fnacarellidev/42-libft/blob/main/ft_strdup.c) | returns a pointer to a new string which is a duplicate  of  the string s.|

**stdlib.h**

| Function | Description |
| --- | --- |
| [**ft\_atoi**](https://github.com/fnacarellidev/42-libft/blob/main/ft_atoi.c) | converts an string to an int . |
| [**ft\_calloc**](https://github.com/fnacarellidev/42-libft/blob/main/ft_calloc.c) | allocates nmemb * size bytes. The memory is set to zero.|

### Part_2

**string's functions**

| Function | Description |
| --- | --- |
| [**ft\_substr**](https://github.com/fnacarellidev/42-libft/blob/main/ft_substr.c) | Allocates and returns a substring from the string ’s’. The substring begins at index ’start’ and is of maximum size ’len’.|
| [**ft\_strjoin**](https://github.com/fnacarellidev/42-libft/blob/main/ft_strjoin.c) | Allocates and returns a new string, which is the result of the concatenation of ’s1’ and ’s2’.|
| [**ft\_strtrim**](https://github.com/fnacarellidev/42-libft/blob/main/ft_strtrim.c) | Allocates and returns a copy of ’s1’ with the characters specified in ’set’ removed from the beginning and the end of the string.|
| [**ft\_split**](https://github.com/fnacarellidev/42-libft/blob/main/ft_split.c) | Allocates and returns an array of strings obtained by splitting ’s’ using the character ’c’ as a delimiter.|
| [**ft\_strmapi**](https://github.com/fnacarellidev/42-libft/blob/main/ft_strmapi.c) | Applies the function ’f’ to each character of the string ’s’ to create a new string resulting from successive applications of ’f’.|

**string to int**

| Function | Description |
| --- | --- |
| [**ft\_itoa**](https://github.com/fnacarellidev/42-libft/blob/main/ft_itoa.c) | Allocates and returns a string representing the integer received as an argument. Negative numbers must be handled.|

**file-descriptor's functions**

| Function | Description |
| --- | --- |
| [**ft\_putchar\_fd**](https://github.com/fnacarellidev/42-libft/blob/main/ft_putchar_fd.c) | Outputs the character ’c’ to the given file descriptor.|
| [**ft\_putstr\_fd**](https://github.com/fnacarellidev/42-libft/blob/main/ft_putstr_fd.c) | Outputs the string ’s’ to the given file descriptor.|
| [**ft\_putendl\_fd**](https://github.com/fnacarellidev/42-libft/blob/main/ft_putendl_fd.c) | Outputs the string ’s’ to the given file descriptor, followed by a newline.|
| [**ft\_putnbr\_fd**](https://github.com/fnacarellidev/42-libft/blob/main/ft_putnbr_fd.c) | Outputs the integer ’n’ to the given file descriptor.|

### Bonus

**Linked Lists**

| Function | Description |
| --- | --- |
| [**ft\_lstnew**](https://github.com/fnacarellidev/42-libft/blob/main/ft_lstnew.c) | Allocates and returns a new element. The variable ’content’ is initialized with the value of the parameter ’content’. The variable ’next’ is initialized to NULL.|
| [**ft\_lstadd_front**](https://github.com/fnacarellidev/42-libft/blob/main/ft_lstadd_front.c) | Adds the element ’new’ at the beginning of the list.|
| [**ft\_lstsize**](https://github.com/fnacarellidev/42-libft/blob/main/ft_lstsize.c) | Counts the number of elements in a list.|
| [**ft\_lstlast**](https://github.com/fnacarellidev/42-libft/blob/main/ft_lstlast.c) | Returns the last element of the list.|
| [**ft\_lstadd_back**](https://github.com/fnacarellidev/42-libft/blob/main/ft_lstadd_back.c) | Adds the element ’new’ at the end of the list.|
| [**ft\_lstdelone**](https://github.com/fnacarellidev/42-libft/blob/main/ft_lstdelone.c) | Takes as a parameter an element and frees the memory of the element’s content using the function ’del’ given as a parameter and free the element.|
| [**ft\_lstclear**](https://github.com/fnacarellidev/42-libft/blob/main/ft_lstclear.c) | Deletes and frees the given element and every successor of that element, using the function ’del’ and free. Finally, the pointer to the list is set to NULL.|
| [**ft\_lstiter**](https://github.com/fnacarellidev/42-libft/blob/main/ft_lstiter.c) | Iterates the list ’lst’ and applies the function ’f’ to the content of each element.|
| [**ft\_lstmap**](https://github.com/fnacarellidev/42-libft/blob/main/ft_lstmap.c) | Iterates the list ’lst’ and applies the function ’f’ to the content of each element. Creates a new list resulting of the successive applications of the function ’f’. The ’del’ function is used to delete the content of an element if needed.|
