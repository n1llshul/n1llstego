CONCEPT:
The method of replacing visually identical characters involves replacing (bit 1) or refusing to replace (bit 0) a Latin character with a Cyrillic character of the same appearance. 

REQUIREMENTS:
It's very important that both the plaintext and the message must contain only latin letters. 
Even 1 cyrillic letter in plaintext can ruin all the algorithm. 
If cyrillic symbols occur in the message file it won't ruin all the program but it can't be decoded after. Example: msg.txt "what if i include just some слово in cyrillic?" outputs "what if i include just some ╤Б╨╗╨╛╨▓╨╛ in cyrillic?"

PROGRAM USAGE:
Compile all three "*.cpp" files and execute.

TO ENCODE:
Create stegocontainer file named "input.txt" with plaintext and "msg.txt"(both mustn't contain cyrillic symbols, see REQUIREMENTS) with the message you want to hide. Run the executable file. Choose the 'e' option. Ciphertext will appear in the same directory in file "ct.txt". 
 
TO DECODE:
Rename the file containing ciphertext to "ct.txt". Run the executable file. Choose the 'd' option and the hidden message will appear in the command line. 

ERROR HANDLING:
If the program says "Stegocontainter is too small" it means that the plaintext file has too little amount of latin symbols similar-looking to cyrillic ones. Try expanding the "input.txt" and make sure it contains enough specified symbols.
