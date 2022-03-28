#include "processor.h"
#include "linux_parser.h"
// TODO: Return the aggregate CPU utilization
Processor::Processor()
{
    GetLinuxParserForJiffies(prev_cpu_jiffies_);
}

float Processor::Utilization() { 
    return 0.0; }

    void Processor::CalculateDeltaTime(std::array<long,3>&first_cpu_jiffies,std::array<long,3>&second_cpu_jiffies)
 {
     for(int i=0;i<3;i++)
     {
        delta_jiffies_[i]=first_cpu_jiffies[i]-second_cpu_jiffies[i];
     }
 }
 void Processor::GetLinuxParserForJiffies(std::array<long,3>& cpu_jiffies)
{
    cpu_jiffies[LinuxParser::CPUTime::kIdleTime_]=LinuxParser::IdleJiffies();
    cpu_jiffies[LinuxParser::CPUTime::kActiveTime_]=LinuxParser::ActiveJiffies();
    cpu_jiffies[LinuxParser::CPUTime::kTotalTime_]=LinuxParser::Jiffies();   
}