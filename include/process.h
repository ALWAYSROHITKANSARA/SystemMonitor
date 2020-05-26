#ifndef PROCESS_H
#define PROCESS_H

#include <string>
/*
Basic class for Process representation
It contains relevant attributes as shown below
*/
class Process {
 public:
  int Pid(return pid_);                               // TODO: See src/process.cpp
  std::string User();                      // TODO: See src/process.cpp
  std::string Command();                   // TODO: See src/process.cpp
  float CpuUtilization();                  // TODO: See src/process.cpp
  std::string Ram();                       // TODO: See src/process.cpp
  long int UpTime();                       // TODO: See src/process.cpp
  bool operator<(Process const& a) const;  // TODO: See src/process.cpp

  Process::Process(int pid) {
  pid_ = pid;
  user_ =    LinuxParser::User(pid_);
  command_ = LinuxParser::Command(pid_);
  cpuUtilization_ = Process::CpuUtilization();
  ram_=   LinuxParser::Ram(pid_);
  upTime_= LinuxParser::UpTime() - LinuxParser::UpTime(pid_);
}

  // TODO: Declare any necessary private members
 private:
};

#endif