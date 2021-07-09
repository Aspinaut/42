#!/bin/bash
# code à insérer dans crontab -e en étant root :
# attention de bien chmod 755 monitoring.sh avant et de le placer dans /root
# */10 * * * * ./monitoring.sh

mem_used=$(free -t | grep Mem: | awk '{print $3}').0
mem_total=$(free -t | grep Mem: | awk '{print $2}').0
percentage_mem_used=$(($mem_used / $mem_total * 100))

#disk_used=
#disk_total=
#percentage_disk_used=

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

# ! trouver la bonne syntaxe pour faire fonctionner le wall, echo -e permet d'afficher le \n

( 
  echo -e "#Architecture : $(uname -a)\n"
  echo -e "#CPU physical : $(grep "physical id" /proc/cpuinfo | sort | uniq | wc -l)\n"
  echo -e "#vCPU : $(grep "^processor" /proc/cpuinfo | wc -l)\n"

  # !! mem_used affiche aussi les unités
  echo -e "#Memory Usage : $(free -h --giga | grep Mem: | awk '{print $3}')/$(free -h --giga | grep Mem: | awk '{print $2}') ($(echo $percentage_mem_used | awk '{printf("%.2f",$1)}')%)\n"

  # sur quelle partition ??
  echo -e "#Disk Usage :\n"

  # !! faut-il faire l'addition des cpus ou juste le 1er affiché ??
  echo -e "#CPU load : $(top -bn1 | grep '%Cpu(s):' | awk '{print $2}')%\n"
  echo -e "#Last boot : $(date --date=$reboot_date +%F\ %H:%M)\n"
  echo -e "#LVM use : $(check_lvm_usage)\n"
  echo -e "#Connexions TCP : $(netstat | grep '^tcp.*ESTABLISHED' | wc -l) ESTABLISHED\n"

  # nb d'users différents ou juste le nb de sessions ouvertes ? ex : 5 * vmasse42 pcq 5 terminaux ouverts
  echo -e "#User log : $(who | wc -l)\n"

  # !! bien vérifier l'adresse MAC (pq 2 adresses hors VM ??)
  echo -e "#Network : IP $(hostname -I)($(ip link show | grep link/ether | awk '{print $2}'))\n"
  echo -e "#Sudo : $(history | grep sudo | wc -l) cmd\n"
) | wall
