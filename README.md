
RootPhisher
RootPhisher is an opensource social engineering tool to steal root passwords without cracking hashes, it is a malware that replaces the su and sudo files with a Login Spoof asking you for a password, the password is sent to your C&C server via HTTP.

RootPhisher is a script that allows you to steal linux passwords without Brute Force attacks.

The trick is the replacement of the file su and sudo. Once you have replaced that, when the victim executes su or sudo, the script will be ask for a password, if the victim enter the password it will be sent via HTTP Request to the server specified.

Usage
Server
First we need:

Any HTTP Server
MySQL
Upload the server files to the HTTP Server. Create a database (Eg.: rootphisher). Edit the mysql server parameters in the file db.inc.php. Then import the rootphisher.sql file (Server/db/rootphisher.sql) in the database via MySQL or PHPMyAdmin. Now the server is ready. Now you can login with the default credentials (admin:admin).

Client
Start rootphisher (sh rootphisher.sh)

Now follow the instructions to configure the client.

Once you have the executable, send it to your victim.

If the victim executes it as root and enter its password, it will be sent via HTTP GET Request to your server.

You can view the passwords in the Server Panel.

To know which victim is, watch out!, each client you generate will use a code to identify the victim.

You can view the client code while generating it (In the shell) or watch allof them in the directory 'codes'.

Authors
Alejandro Guerrero Rodriguez (Twitter: @LockedByte)

Eduardo Perez (Twitter: @blueudp)

Thanks for downloading ;)
