import sys
ten=10;hun=100;one=1;
dividend=1;divisor=2;
iter=8000;
sys.stdout.write('1.')
while iter>0: 
   iter=iter-1;
   dividend=dividend*(hun);
   for i in range(0,10):
     if ((divisor*ten) + i ) * i<dividend and dividend<((divisor*ten) + i + one)*(i+one):
      divisor=(divisor*ten)+i;
      break;
   quo=(int)(dividend/divisor);
   rem=dividend%divisor;
   divisor=divisor+quo;dividend=rem;
   sys.stdout.write(str(quo)) 


