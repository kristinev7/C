
install : CPS4200_HW1_venelesk.c 
	gcc -g CPS4200_HW1_venelesk.c -o sort 2> gcc_out.txt

clean :
	rm gcc_out.txt \
	rm core \
	rm out.txt \
  rm sort
