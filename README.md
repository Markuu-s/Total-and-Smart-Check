TSC (Total and Smart Check)
=============================
> A utility for checking the write availability of files and directories of a user and a group. If it is possible to
  write, the terminal displays the full path to the directory (d) or file(f).

INSTALLATION
------------
For **amd64**:
- Install the deb package https://github.com/Markuu-s/Total-and-Smart-Check/releases/download/1.1/Total-and-Smart-Check_1.1-1_amd64.deb

Or build the project

- git clone https://github.com/Markuu-s/Total-and-Smart-Check
- make
- ./TSC

REQUIREMENTS
------------

The minimum requirement by utility is that 
- Your c++ compiler support **C++20**
- Linux system

QUICK START
-----------

- Open terminal
- sudo TSC -u < **user name** > -p < **start path** > -g < **group name** >

