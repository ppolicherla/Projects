README FILE TO USE PAVAN POLICHERLA'S SECURE VERSION OF S3FS


1. after downloading the zip file, extract the s3fs-fuse folder to the location you want to have it stored.



RUN THESE COMMANDS IN THE TERMINAL


2. cd s3fs-fuse-secure



3. ./autogen.sh



4. ./configure



5. make



6. Next you will need to find the security credentials of the s3 server you will be linking with, 
   once found you will need to create a password file in the s3fs-fuse directory.



7. the file should look like this
    
   MYIDENTITY:MYCREDENTIAL
 
   these can be found on the web browser client of the server in the security section.


8. next you will need to change the permissions on the password file with the command 
   chmod 600 /path/to/"passwordfile"



9. finally to run the program and mount you bucket locally you will need to run the following command in the terminal. 
   mybucket is the bucket you are linking to and /path/to/mountpoint is the local directory location that is 
   linking to it. umask is a command that will allow you access files that are uploaded through the browser client 
   in the locally mounted directory.



   s3fs mybucket /path/to/mountpoint -o passwd_file=/path/to/passwd umask="0011"



   if there are issues you can run debug mode with the following command.
  
   

s3fs mybucket /path/to/mountpoint -o passwd_file=/path/to/passwd umask="0011" -d -d


 
   this will allow you to do some error checking to see where problems are occuring. 



10. There are test images and text files to test the functionality of the program. 

Happy mounting!!!!
