
#!/usr/bin/perl -w
#Author: John A. Baughman 4/7/2017 
#version 1.1

use Net::FTP;
use Switch;

my $username = "username";
my $password = "password";


if ($#ARGV != 0) {
        printf "Incorrect number of arguments, usage: %s HOST\n", $0;
        exit(1);
}

my $var = $ARGV[0];

switch($var) {
        case 'UCONN' { $HOST = "ftp.uconn.edu/";
        system("curl", "-l", "ftp://anonymous\@$HOST");
        }
        case 'HostName1' { $HOST = "ftp.example.com"; }
        case 'HostName2' { $HOST = "ftp.example.com"; }
        case 'HostName3' { $HOST = "ftp.example.com"; }
        else { printf 'selection invalid' }
}


 if (my($ftp) = Net::FTP->new("$HOST")){
        if ($ftp->login("$username", "$password")) {
                my @files = $ftp->ls;
                my $file = @files;
                if ($file != "1"){
                        printf "3\n"; #No files in directory
                    } else {
                    printf "0\n"; #Everything is fine
                }
            } else {
        printf "2\n"; #Login didn't work
        }
    } else {
    printf "1\n"; #Couldn't fine host
}

