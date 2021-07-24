#!/bin/bash

mem_used=$(free -h --giga | grep Mem: | awk '{print $3}')
mem_total=$(free -h --giga | grep Mem: | awk '{print $2}')
mem_per=$(free -t | grep Mem: | awk '{print $3/$2*100}')
reboot_date=$(last reboot | head -1 | awk '{print $5 " " $6 " " $7 " " $8}')

check_lvm_usage() {

  if lsblk|grep 'lvm' > /dev/null
  then
    echo yes
  else
    echo no
  fi
}

( 
  echo "#Architecture : $(uname -a)"
  echo "#CPU physical : $(cat /proc/cpuinfo | grep 'cpu cores' | awk '{print $4}')"
  echo "#vCPU : $(cat /proc/cpuinfo | grep 'siblings' | awk '{print $3}')"
  echo "#Memory Usage : $mem_used/$mem_total ($mem_per%)"
  echo "#Disk Usage : $(df -hBM | awk '{total += $2} {used += $3} END {print used "/" total "MB (" used/total*100 "%)"}')"
  echo "#CPU load : $(vmstat -SM | awk 'NR==3{print 100-$15 "%"}')"
  echo "#Last boot : $reboot_date"
  echo "#LVM use : $(check_lvm_usage)"
  echo "#Connexions TCP : $(cat /proc/net/tcp | wc -l | awk '{print $1-1}') ESTABLISHED"
  echo "#User log : $(who | wc -l)"
  echo "#Network : IP $(hostname -I)($(ip link show | grep link/ether | awk '{print $2}'))"
  echo "#Sudo : $(cat /var/log/sudo/sudolog | grep 'COMMAND' | wc -l) cmd"
) | wall
