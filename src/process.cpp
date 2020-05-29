#include <unistd.h>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>

#include "process.h"
#include "linux_parser.h"

using std::string;
using std::to_string;
using std::vector;
using std::stof;


  Process::Process(int pid) {
  pid_ = pid;
  user_ = LinuxParser::User(pid_);
  command_ = LinuxParser::Command(pid_);
  cpuUtilization_ = Process::CpuUtilization();
  ram_=   LinuxParser::Ram(pid_);
  upTime_= LinuxParser::UpTime(); 
  LinuxParser::UpTime(pid_);
}


// TODO: Return this process's ID  :: Done
int Process::Pid() { 
    //The process identifier (PID) is accessible from the /proc directory. 
    return pid_;
 }

// TODO: Return this process's CPU utilization :: Done
float Process::CpuUtilization() { 
  float totaltime = LinuxParser::ActiveJiffies(Pid());  
  float uptime = LinuxParser::UpTime();                
  float secondsactive = uptime - (Process::UpTime() / sysconf(_SC_CLK_TCK));  
  float cpu_usage = (totaltime / sysconf(_SC_CLK_TCK)) / secondsactive;   
  return cpu_usage;
 }

// TODO: Return the command that generated this process :: Done
string Process::Command() { return command_; }

// TODO: Return this process's memory utilization :: Done
string Process::Ram() { return ram_; }

// TODO: Return the user (name) that generated this process :: Done
string Process::User() { return user_; }

// TODO: Return the age of this process (in seconds) :: Done
long int Process::UpTime() { return upTime_; }

// TODO: Overload the "less than" comparison operator for Process objects :: Done
// REMOVE: [[maybe_unused]] once you define the function
bool Process::operator<(Process const& a) const { 
     return (this->cpuUtilization_ > a.cpuUtilization_);
 }
