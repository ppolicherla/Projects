#include "rc4_enc.c"
#include "rc4.h"
#include "rc4_skey.c"
#include "rc4_locl.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <stdio.h>
#include <fcntl.h>
#include "md5.h"

using namespace std;
//definition of the key variables for the program to use to make the encryption 
#define RC4KEY "pavanisgreat"

#define RC4LEN (sizeof(RC4KEY) - 1)

//function prototypes
string encrypt(const string &input);

unsigned char* encryptChar(const char* input, int size);

void encdec(int fd);


int main(int argc, char *argv[])
{

    /*//turning the file data into binary for encryption
    ifstream infile;
    infile.open(argv[1], ios::binary);

    stringstream test;
    test << infile.rdbuf();
    string temp = test.str();
    string temp1 = encrypt(temp);
    infile.close();

    //storing the ecrypted data into a new file.
    ofstream out;
    out.open(argv[2], ios::binary);

    out << temp1;

    stringstream ststream;
    ststream << out.rdbuf();
    string temp2 = ststream.str();

    out.close();*/

    int fd;
    fd = open(argv[1], O_RDWR);
    encdec(fd1);


}

//function that will encrypt a file after the file data has been converted to a string object.
string encrypt(const string &input)
{
    RC4_KEY rc4;

    int length = input.size();
    //char variable that will hold the data for the actual encryption
    unsigned char *indata = (unsigned char *)malloc(length + 1);
    //setting the data to 0
    memset(indata, 0, length + 1);
    //creating the char variable that will hold encryption information based on key variables and the MD5 standard
    unsigned char *md[MD5_DIGEST_LENGTH];
    MD5((unsigned char*)RC4KEY, RC4LEN, (unsigned char*)&md);

    RC4_set_key(&rc4, MD5_DIGEST_LENGTH, (const unsigned char *)md);

    //encrypting the file
    RC4(&rc4, length, (const unsigned char *)input.c_str(), indata);

    //creating the string object that will hold the encrypted data
    string encoded((char *)indata, length);
    free(indata);
    return encoded;
}

//encryption function that works on unsigned char rather than string which will make it easier to encrypt based on a file descriptor object
unsigned char* encryptChar(const char* input, int size)
{
    RC4_KEY rc4;

    int length = size;
    unsigned char *indata = (unsigned char *)malloc(length + 1);
    memset(indata, 0, length + 1);

    unsigned char md[MD5_DIGEST_LENGTH];
    MD5((unsigned char*)RC4KEY, RC4LEN, (unsigned char *)md);
    //cout << "!!!!!!!!!!! RC4KEY AND LENGTH !!!!!!!!!!! " << RC4LEN << " " << RC4KEY << endl;
    //cout << "!!!!!!!!!!! MD Before !!!!!!!!!!!!!" << md << endl;

    RC4_set_key(&rc4, MD5_DIGEST_LENGTH, (const unsigned char *)md);

    //cout << "!!!!!!!!!!! MD after !!!!!!!!!!!!!" << md << endl;

    RC4(&rc4, length, (const unsigned char *)input, indata);

    unsigned char* encoded;
    encoded = indata;
    return encoded;
}

// the function that will be called by S3FS to encrypt the file that is being uploaded
void encdec(int fd)
{
    //setting the variables to work on fd obejects
    const int bufferSize = 4096;
    char incoming[bufferSize];
    unsigned char* outgoing;
    //setting the length to the size of the file
    int len = lseek(fd, 0, SEEK_END);
    //reseting the program to the beginning of the file
    lseek(fd, 0, SEEK_SET);

    //variables to keep track of how much data has been encrypted and how much is about to be encrypted.
    int found = 0;
    int changed = 0;
    //loop that will go through the file and encrypt it in parts.
    while(len>0)
    {
        //checking to see how much data is left
        if (len>=bufferSize)
        {
            changed=bufferSize;
            len = len-bufferSize;
        }
        else
        {
            changed =len;
            len=0;
        }

        //reading the part of the data that is being grabbed
        pread(fd, incoming, changed, found);
        //encrypting that data 
        outgoing = encryptChar(incoming, changed);
        //writing that data to the file
        pwrite(fd, outgoing, changed, found);

        //incrementing the amount of data that has been encrypted
        found= found+changed;
    }
}
