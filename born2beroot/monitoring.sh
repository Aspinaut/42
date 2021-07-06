#!/bin/bash

mem_used=$(free -t | grep Mem: | awk '{print $3}').0
mem_total=$(free -t | grep Mem: | awk '{print $2}').0
percentage_mem_used=$(($mem_used / $mem_total * 100))

disk_used=
disk_total=
percentage_disk_used=

reboot_date=$(last reboot | head -1 | awk '{print $5,$6,$7,$8}')

function check_lvm_usage {
  isInFile=$(cat /etc/fstab | grep '^/dev/mapper/.*live-root')

  if [ $isInFile ]
  then
    echo yes
  else
    echo no
  fi
}

echo "#Architecture : $(uname -a)"
echo "#CPU physical : $(grep "physical id" /proc/cpuinfo | sort | uniq | wc -l)"
echo "#vCPU : $(grep "^processor" /proc/cpuinfo | wc -l)"

# !! mem_used affiche aussi les unités
echo "#Memory Usage : $(free -h --giga | grep Mem: | awk '{print $3}')/$(free -h --giga | grep Mem: | awk '{print $2}') ($(echo $percentage_mem_used | awk '{printf("%.2f",$1)}')%)"

# sur quelle partition ??
echo "#Disk Usage : $()"

# !! faut-il faire l'addition des cpus ou juste le 1er affiché ??
echo "#CPU load : $(top -bn1 | grep '%Cpu(s):' | awk '{print $2}')%"
echo "#Last boot : $(date --date=$reboot_date +%F\ %H:%M)"
echo "#LVM use : $(check_lvm_usage)"
echo "#Connexions TCP : $(netstat | grep '^tcp.*ESTABLISHED' | wc -l) ESTABLISHED"

# nb d'users différents ou juste le nb de sessions ouvertes ? ex : 5 * vmasse42 pcq 5 terminaux ouverts
echo "#User log : $(who | wc -l)"

# !! bien vérifier l'adresse MAC (pq 2 adresses hors VM ??)
echo "#Network : IP $(hostname -I)($(ip link show | grep link/ether | awk '{print $2}'))"
echo "#Sudo : $(history | grep sudo | wc -l) cmd"
