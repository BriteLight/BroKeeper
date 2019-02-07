#!/usr/bin/tcsh -f
   
foreach x ( east west )
   foreach y (`aws --region=us-$x-2 ec2 describe-instances | grep '"InstanceId":' | awk -F":" '{print $2}' | awk -F"," '{print $1}'`)
   echo ======
   echo $y
   aws --region=us-$x-2 ec2 describe-instances --instance-id="`echo $y`" | grep -B6 -A2 '"Name":'
   echo ===================
   echo ""
   echo ""
   end
   end
