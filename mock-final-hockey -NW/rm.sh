#!/bin/bash
for n in $(ipcs -b -m | egrep ^m | awk '{ print $2; }'); 
do ipcrm -m $n;
done;
for n in $(ipcs -b -s | egrep ^s | awk '{ print $2; }'); 
do ipcrm -s $n;
done;
for n in $(ipcs -b -q | egrep ^q | awk '{ print $2; }'); 
do ipcrm -q $n;
done;