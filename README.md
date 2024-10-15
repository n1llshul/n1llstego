PROGRAM USAGE:

Compile .cpp files and execute.

TO ENCODE:
Create stegocontainer file named "input.txt" with plaintext and "msg.txt" with the message you want to hide. Run the executable file. Choose the 'e' option. Ciphertext will appear in the same directory in file "ct.txt". 
 
TO DECODE:
Rename the file containing ciphertext to "ct.txt". Run the executable file. Choose the 'd' option and the hidden message will appear in the command line. 

ERROR HANDLING:
If the program says "Stegocontainter is too small" it means that the plaintext file has too little amount of latin symbols similar-looking to cyrillic ones. Try expanding the "input.txt" and make sure it contains enough specified symbols.
