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