#!/bin/bash

mem_used=$(free -t | grep Mem: | awk '{print $3}').0
mem_total=$(free -t | grep Mem: | awk '{print $2}').0
percentage_mem_used=$(($mem_used / $mem_total * 100))

disk_used=
disk_total=
percentage_disk_used=

echo "#Architecture : $(uname -a)"
echo "#CPU physical : $(grep "physical id" /proc/cpuinfo | sort | uniq | wc -l)"
echo "#vCPU : $(grep "^processor" /proc/cpuinfo | wc -l)"

# !! mem_used affiche aussi les unités

echo "#Memory Usage : $(free -h --giga | grep Mem: | awk '{print $3}')/$(free -h --giga | grep Mem: | awk '{print $2}') ($(echo $percentage_mem_used | awk '{printf("%.2f",$1)}')%)"
echo "#Disk Usage : $(uname -a)"
echo "#CPU load : "$(uname -a)
echo "#Last boot : "$(uname -a)
echo "#LVM use : "$(uname -a)
echo "#Connexions TCP : "$(uname -a)
echo "#User log : "$(uname -a)
echo "#Network : $(hostname -I)"
echo "#Sudo : "$(uname -a
