#include<iostream> 

using namespace std;

int main(){ 
  system("grep -m 1 'model name' /proc/cpuinfo");
  cout<< "\n Kernel version: "<<endl;
  system("uname -r"); 
  system("grep MemTotal /proc/meminfo");
  cout<<"\n Last time since system was booted(uptime): "<<endl;
  system("uptime -p");

  return 0;
} 