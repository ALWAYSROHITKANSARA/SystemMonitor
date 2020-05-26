#include "processor.h"
#include "linux_parser.h"
#include <string> 

using std::stof;

// TODO: Return the aggregate CPU utilization  :: Done
float Processor::Utilization() { 
  float totalTime = LinuxParser::Jiffies();
  float activeTime = LinuxParser::ActiveJiffies() ;
  float util = std::stof(activeTime/totalTime);
  return util;
 }