#include "processor.h"
#include "linux_parser.h"

// TODO: Return the aggregate CPU utilization  :: Done
float Processor::Utilization() { 
  float totalTime = LinuxParser::Jiffies();
  float activeTime = LinuxParser::ActiveJiffies() ;
  float util = activeTime/totalTime;
  return util;
 }