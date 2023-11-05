#!/usr/bin/zsh

cd "/home/prabhatsuresh/OS_LAB/myexpos/spl"

for file in $HOME/OS_LAB/myexpos/spl/spl_progs/*.spl; do
    echo $file
    spl $file  
done

cd "../expl"

for file in $HOME/OS_LAB/myexpos/expl/samples/*.expl; do
    echo $file
    expl $file  
done
