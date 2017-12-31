//
//  main.cpp
//  OSFS
//
//  Created by Sunny Lin on 10/22/17.
//  Copyright © 2017 Sunny Lin. All rights reserved.
//

#include <iostream>
#import "OSFS.hpp"
#define ARGLEN  50500   // token length
#define MAXARGS 3       // cmdline args
using namespace std;

// split a string into tokens
void parse( char* input, char* args[] ) {
    input[strlen(input)-1] = '\0';  // fgets reads the \n, so overwrite it
    args[0] = strtok(input, " ");
    args[1] = strtok(NULL, " ");
    args[2] = strtok(NULL, "\0");   // for writing long string
}


int main() {
    
    char arg [ARGLEN];
    char* arglist[MAXARGS];
    Disk* disk1;
    
    disk1 = new Disk();
    
    while (strcmp(arg, "exit\n") != 0) {
        printf("Sunny's File System > ");
        if ( fgets(arg, ARGLEN, stdin) == NULL) {
            perror( "read input failed" );
            exit(1);
        }
        else {
            if (strcmp(arg, "exit\n") == 0)     // exit command to finish
                exit(0);
            
            parse(arg, arglist);
            if ((strcmp(arglist[0], "create") == 0 || strcmp(arglist[0], "CREATE") == 0) && arglist[2]!= nullptr && arglist[1]!= nullptr) {
                disk1->create(arglist[1][0], arglist[2]);
                disk1->display();
            }
            else if ((strcmp(arglist[0], "open") == 0 || strcmp(arglist[0], "OPEN") == 0) && arglist[2] != nullptr && arglist[1]!= nullptr) {
                disk1->open(arglist[1][0], arglist[2]);
                disk1->display();
            }
            else if (strcmp(arglist[0], "close") == 0 || strcmp(arglist[0], "CLOSE") == 0) {
                disk1->close();
                disk1->display();
            }
            else if ((strcmp(arglist[0], "delete") == 0 || strcmp(arglist[0], "DELETE") == 0) && arglist[1]!= nullptr) {
                disk1->deleteNew(arglist[1]);
                disk1->display();
            }
            else if ((strcmp(arglist[0], "write") == 0 || strcmp(arglist[0], "WRITE") == 0) && arglist[2]!= nullptr && arglist[1]!= nullptr) {
                if (arglist[2][0] == '\'' && arglist[2][strlen(arglist[2])-1] == '\'') {
                    // trim off the single quotes
                    char trim[strlen(arglist[2])-2];
                    for (int i = 0; i < strlen(arglist[2])-2; i++) {
                        trim[i] = arglist[2][i+1];
                    }
                    disk1->write(atoi(arglist[1]), trim);
                    disk1->display();
                }
                else {
                    cout << "Error: Write failed. Please put single quote \' \' outside the writing input" << endl;
                    disk1->display();
                }
            }
            else if ((strcmp(arglist[0], "read") == 0 || strcmp(arglist[0], "READ") == 0) && arglist[1]!= nullptr) {
                disk1->read(atoi(arglist[1]));
                disk1->display();
            }
            else if ((strcmp(arglist[0], "seek") == 0 || strcmp(arglist[0], "SEEK") == 0) && arglist[1]!= nullptr && arglist[2]!= nullptr) {
                disk1->seek(atoi(arglist[1]), atoi(arglist[2]));
                disk1->display();
            }
            else {
                cout << "Error: please enter a valid input" << endl;
                disk1->display();
            }
        }
    }
    return 0;
}

    
    
//    // test everything
//    Disk* disk1 = new Disk();
//    disk1->display();
//    
//    disk1->create('U', "F1");
//    disk1->close();
//    disk1->open('U', "F1");
//    disk1->display();
//    
//    string essay = "012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789---100----012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789---200----012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789---300----012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789---400----012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789---500----012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789---600----012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789---700----012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789---800----012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789---900----012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789--1000----012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789--1100----012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789--1200----";
//    
//    disk1->write(1300, essay);
//    disk1->display();
//
//    disk1->seek(-1,0);
//    disk1->display();
//
//    disk1->read(1500);
//    disk1->display();
//    
//    disk1->seek(-1,0);
//    disk1->display();
//    
//    disk1->write(13, "happybirthday");
//    disk1->display();
//    
//    disk1->seek(0, -5);
//    
//    disk1->read(10);
//    disk1->display();
//    
//    return 0;
//}

//    // string test
//    string sample = "try";
//    sample = sample.substr(sample.find('y')+1);
//    
//    if (sample == "") {
//        cout << "yes" << endl;
//    }
//    else
//        cout << "no" << endl;
    
    
//    // pointer test
//    char test[3] = {'1','2','5'};
//    char* pt;
//    
//    pt = &test[0];
//    cout << "value: " << pt << endl;
//    cout << "value: " << (pt+1) << endl;
//    cout << "value: " << (pt+2) << endl;
//    cout << "value: " << (pt+3) << endl;
//    cout << "value: " << *(pt+3) << endl;
//    if (*(pt+3) == ' ')
//        cout << "nothing" << endl;
//    else
//        cout << "wtf" << endl;
//
//
//    cout << "address: " << *(&test[1]) << " " << *(&test[1]+1) << endl;
    
    
    
    
    
    
//    // open/close test
//    disk1->close();
//    disk1->open('I', "D1/D2/F4");
//    disk1->create('U', "D1/D3/F5");
//    disk1->display();
    
//    // delete final test
//    disk1->deleteNew("D1/D2");
//    disk1->display();

//    // delete test
//    disk1->deleteBlock((Directory*)disk1->sector[2], (Directory*)disk1->sector[5]);
//    disk1->display();
//    
//    disk1->deleteBlock((Directory*)disk1->sector[0], (Directory*)disk1->sector[2]);
//    disk1->display();
    

