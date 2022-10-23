#include<iostream> 
#include<bits/stdc++.h>

using namespace std;

int main(){ 
  int readrate,printrate;
  cout<<"Enter the print rate and read rate: ";
  cin>>printrate>>readrate;
    for (int i = 0; i< printrate/readrate; i++) {
    system("vmstat -s| grep 'CPU context switches' >> cs.txt"); // number of context switches 
    system("top -b -di n1|grep Cpu >> cpu.txt"); // perecntage of cpu idle 
    system("ps axu | WC -l >> pc.txt"); // no of process creations 
    system("grep MemFree /proc/meminfo >> mem.txt"); // free memory in system
    sleep (readrate);
    }

system("awk '{ print $2}' mem. txt >> memFree.txt"); // free memory values 
system("awk '{ print $1 }' cs.txt >> context.txt"); // no of context switches values 
system("awk '{print $2 }' cpu.txt >> usr.txt"); // user time on cpu values 
system("awk '{ print $4}' cpu.txt >> sys.txt"); // sys cpu usage values 
system("awk '{ print $8 }' cpu.txt >> idle.txt"); // cpu idle time values  

ifstream infile; 
double avgidle=0,num,x=0; 
infile.open("idle.txt"); //idle mode average

    while(!infile.eof()){
        infile>>num; 
        avgidle+=num; 
        x++; 
    }

avgidle = (avgidle - num)/(x-1);
infile.close(); 

double avUser=0;
x=0; 
infile.open("usr.txt"); // user mode average 
    while(!infile.eof()){
        infile>>num;
        avUser+=num; 
        x++;
    }
avUser = (avUser - num)/(x-1); 
infile.close(); 

double avsys=0;
x=0; 
infile.open("sys.txt"); // system mode avgerage, 
    while(!infile.eof()){ 
        infile>>num; 
        avsys+=num;
        x++;
    }
avsys = (avsys - num)/(x-1); 
infile.close(); 

double avCS=0, num2; 
x=0; 
infile.open("context.txt"); 
infile >> num; 
    while(!infile.eof()){
        infile>>num2; 
        x++;
    }
avCS= (num2 - num)/(printrate); 
infile.close(); 

double avFM=0;
x=0; 
infile.open("memFree.txt"); //avg free memory available 
    while(!infile.eof()){
        infile>>num; 
        avFM+=num; 
        x++;
    }
avFM = (avFM - num)/(x-1); 
infile.close(); 

double avPC=0; 
num2; 
x=0; 
infile.open("pc.txt"); // avg context switches 
infile >> num; 
    while(!infile.eof()){
        infile>>num2; 
        x++;
    }
avPC = (num2 - num)/(printrate); 
infile.close();


cout << "Percentage of time processor spends in user mode : "; 
cout << avUser << "%"; 
cout << "\nPercentage of time processor spends in system mode : ";
cout << avsys << "%";
cout << "\nPercentage of time processor is idle : "; 
cout << avgidle << "%";
cout << "\nRate of context switches in kernel : ";
cout << avCS << " per second"; 
cout << "\nAverage Amount of free memory available : "; 
cout << avFM << " KB";
cout << "\nRate of process creations in system : "; 
cout << avPC << " per second"; 

return 0;
}

