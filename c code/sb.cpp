2202 11 29 2202 12 31
(y1/10==202) || (y1%1000==202) || (y1%10==2 && m1==2) || (m1==2 && d1==2)
pp=to_string(y1)+to_string(m1)+to_string(d1);
			int flag1=0,flag2=0,flag3=0,k;
			for(k=0;k<pp.size();k++)
			{
				if(pp[k]=='2')
				 flag1=1;
				if(pp[k]=='0' && flag1)
				 flag2=1;
				if(pp[k]=='2' && flag1 && flag2)
				 flag3=1;
			}
			
			
			 || (y1%10==2 && m1==2) || (m1==2 && d1==2) ||(m1==12 && d1==2)
