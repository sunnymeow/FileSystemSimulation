# Commands
Each command that may be processed by the file system is matched by an input command line. The syntax of these command lines, and the processing to be performed, is as follows:
  * CREATE type name  
>"type" is either U or D, and indicates whether a User data file or a Directory file is to be created.  
"name" is a full file name in the form described above. <br>Neither of these items is enclosed in quotes.  
The **CREATE** command should cause a new directory entry to be created for the type of file specified.   
If **CREATE** is given for an existing file, no error should occur, but the file should ve deleted and then **reCREATEd**.  
**CREATE** also leaves the file in the same states as an **OPEN** in the output mode.  
  * OPEN mode name   
>"mode" is either I, O or U indicating the file named "name" is to be opened in the Input, Output, or Update mode.  
**Input mode** means that only **READ** and **SEEK** commands are permitted.  
**Output mode** means only **WRITE** commands are permitted.  
**Update mode** allows **READ**, **WRITE**, and **SEEK** commands.  
Associated with each open file is a pointer to the next byte to be read or written.  
Opening a file for input or update places the pointer at the first byte of the file, while opening a file for output places the pointer athe the byte immediately after the last byte of the file.  
  * CLOSE  
>This command causes the last **OPENed** or **CREATEd** file to be closed. No filename is given.  
  * DELETE name  
>This command causes the named file to be deleted.  
  * READ n  
>This command may only be used between an **OPEN** (in input or update mode) and the corresponding **CLOSE**.  
If possible, "n" bytes of data should be read and displayed. If fewer than "n" bytes remain before the end of file, then those bytes should be read and displayed with a message indicating that the end of file was reached.  
  * WRITE n 'data'  
>This command causes the first "n" ata bytes from 'data'(actually enclosed in single quotes in the comman line) to be written to the file.  
If fewer than "n" bytes are given, then append sufficient blanks to 'data' to make "n" bytes.  
If it is impossible to write "n" bytes(because the disk is full) then an appropriate message should be issued, but the command should be otherwise treated as if the largest possible value o "n" was specified. (That is, the remaining available disk space should be filled.)  
  * SEEK base offset  
>"base" is either -1, 0, or +1 indicating the beginning of the file, the current position in the file, or the end of file.  
"offset" is a signed integer indicating the number of bytes from the "base" that the file pointer should be moved.  
For example, **"SEEK -1 0"** is equivalent to a rewind, **"SEEK +1 0"** is equivalent to a position to end of file, and **"SEEK 0 -5"** positions the file pointer backward by five bytes.  
