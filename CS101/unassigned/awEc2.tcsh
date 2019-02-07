#!/usr/bin/tcsh -f

set d = $PWD
set r = 1
set s = 1

cd $HOME/.aws

while ( $s )
	set node = `ls -lt | grep lrwx |head -$r |tail -1 |awk -F"> " '{print $2}'`
	if ( -f ./$node ) then
		set i = `head -1 $node`
		set n = `grep -w -A9 $i  ~/test | grep PublicIpAddress | awk -F"\"\" '{print $4}'`
		set q = `grep -w -A9 $i  ~/test | grep '"Name":' | awk -F"\"\" '{print $4}'`
		if ( $n == $node && $q == running ) then
			date +%b-%d" "%H:%M:%S ; scp ~/bin/awEc.tcsh ubuntu@$node':/home/ubuntu/' ; date +%b-%d" "%H:%M:%S ; ssh ubuntu@$node sudo /home/ubuntu/awEc.tcsh ; date +%b-%d" "%H:%M:%S ; ssh ubuntu@$node sudo rm /home/ubuntu/awEc.tcsh ; date +%b-%d" "%H:%M:%S ; date +%b-%d" "%H:%M:%S
			set s = 0
		endif
	endif
	set r = `expr $r + 1`
end

foreach name ( `ls -lt | grep lrwx|awk -F":" '{print $2}' |awk -F" " '{print $2}'` )
	if ( -f ./`ls -l $name |awk -F"> " '{print $2}'` ) then
		set i = `head -1 $name` 
		set n = `grep -w -A9 $i  ~/test | grep PublicIpAddress | awk -F"\"\" '{print $4}'`
		set p = `grep -w -A2 $i  ~/test |grep PrivateIpAddress | awk -F"\"\" '{print $4}'`
		set q = `grep -w -A9 $i  ~/test | grep '"Name":' | awk -F"\"\" '{print $4}'`
		if ( $n != `ls -l $name |awk -F"> " '{print $2}'` && $q == running ) then
			mv `ls -l $name |awk -F"> " '{print $2}'` $n
			ln -sf $n $name
		endif
		if ( `tail -1 $name` != $p ) then
			echo $i > $name
			echo $p >> $name
		endif
	endif
	grep -q `ls -l $name |awk -F"> " '{print $2}'` ~/test
	if ( $status == 0 && -e `ls -l $name |awk -F"> " '{print $2}'` == 0 ) then
		grep -w -B5 `ls -l $name |awk -F"> " '{print $2}'` ~/test | grep i- | awk -F"\"\" '{print $2}' > `ls -l $name |awk -F"> " '{print $2}'`
		grep -w -B5 `ls -l $name |awk -F"> " '{print $2}'` ~/test | grep PrivateIpAddress | awk -F"\"\" '{print $4}' >> `ls -l $name |awk -F"> " '{print $2}'`
	endif
	if ( -e `ls -l $name |awk -F"> " '{print $2}'` == 0 ) then
		ssh ubuntu@$node sudo aws --region=us-west-2 ec2 describe-instances --filters "Name=ip-address,Values="`ls -l $name |awk '{print $12}'`"" --query "Reservations[*].Instances[*].InstanceId" --output text > `ls -l $name |awk '{print $12}'`
		ssh ubuntu@$node sudo aws --region=us-west-2 ec2 describe-instances --filters "Name=ip-address,Values="`ls -l $name |awk '{print $12}'`"" --query "Reservations[*].Instances[*].PrivateIpAddress" --output text >> `ls -l $name |awk '{print $12}'`
	endif
end

cd $d
