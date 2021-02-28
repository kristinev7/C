/*Program name: Unit 3 HW
 * Author: Kristine Veneles
 * Purpose: Users, Files, and I/O in C language: Copy, sort and word and line counts>
 * Date: Due on 2/27/21
 */

#include <stdio.h>
#include <stdlib.h>  //atoi
#include <ctype.h>
#include <fcntl.h>
#include <string.h>

#define MIN_SIZE 2048

/* to get file sie */
int get_file_size(FILE *fp) {
		/*seek end of file */
		if (fseek(fp, 0, SEEK_END) == 0) {
			int size = ftell(fp);
			fseek(fp, 0, SEEK_SET);
			return size;
		}
}

int main (int argc, char *argv[])
{
		FILE *fptr1; /* points to the original file */ 
		FILE *fptr2; /* copy original file here */
		int ch, charac, lines, words;   /* reads number of char of file to copy to new foler */
		int size, index, count;
		char c;
		char lstr[11];
		lstr[10] = '\0'; 
		index = 0;
		char fout_name[11]; 
		 fout_name[10] = '\0'; /* null terminated */
		char *sort_cmd = "sort";
		char *ret_cmd = " > ";
		char *sort_out = "sortedoutput.txt";
		char *wcs = "wc";
		char *wc_out = "output.txt";
	/* check arguments */

		if ( argc != 4)
   {  
		 fprintf(stderr, "usage error: format choice 1,2,or 3 in_file, out_file\n");
			return 1;
   }
		if ((fptr1 = fopen(argv[2], "r") ) == NULL)
		{
				fprintf(stderr, "Can't read or no such file - %s.\n", argv[2]);
				return 2;
		}
		
		if ( (fptr2 = fopen(argv[3], "w") ) == NULL )
		{
				fprintf(stderr, "Can't write %s.\n", argv[3]);
				return 3;
		}
		if ( (atoi(argv[1]) > 3) || (atoi(argv[1]) < 1)) 
		{
				fprintf(stderr, "Wrong choice, the only available values are 1, 2, 3.\n");
		}

		if (atoi(argv[1]) == 1)
		{
			while ( (ch = getc(fptr1)) != EOF )
			{ 
					if(islower(ch))
					{
						ch = toupper(ch);
					}
					
						putc(ch, fptr2);
			}
			printf("File has been copied.\n"); 
	  
//			fclose(fptr1);
	//		fclose(fptr2);
			
		//	return 0;
													
		}// if argv==1
		if (atoi(argv[1]) == 2)
		{
		//			size = get_file_size(fptr1);
					printf("reading file:\n");
					while ( (c = getc(fptr1) ) != EOF) 
					{
							/*read char until new line*/
							lstr[index] = c;

							/* if \n is met, store 10 cars */
							if (c == '\n') 
							{
									/* write the first 10 char to fout */
								int i;
								for (i=0; i < 11; i++) 
								{
										putc( lstr[i], fptr2);
								}
										/* clear buffer */
								int j;
								for (j=0; j< sizeof(lstr); j++)
								{
										lstr[j] = ' ';
								}
	
								/* if there is empty character */
								if (c != ' ')  {
								  fputc('\n', fptr2);
								}

								/* reset index */
								index = 0;
								continue;
							}// if \n
							/* increment */
							index++;
					}//while
						
			/* sort the file into output file */

					/* get length of system call strings */
					int length = strlen(sort_cmd) + sizeof(fout_name) + strlen(ret_cmd) + strlen(sort_out) + 1; 
					char sys_cmd[length +1]; //+1 for null termnator
					sys_cmd[length] = '\0';
					strcpy(&fout_name, argv[3]);
					strcpy(&sys_cmd, sort_cmd);
					strcat(&sys_cmd, " ");
					strcat(&sys_cmd, &fout_name);
					strcat(&sys_cmd, ret_cmd);
					strcat(&sys_cmd, sort_out);


					printf("command %s\n", &sys_cmd);
					system(&sys_cmd);
					printf("copied.\n");

		} //if argv == 2
		 
			if (atoi(argv[1]) == 3)
			{
					int len = strlen(wcs) + sizeof(fout_name) + strlen(ret_cmd) + 1;
					char sys_cmd2[len+1];
					sys_cmd2[len] ='\0';
					strcpy(&fout_name, argv[3]);
					strcpy(&sys_cmd2, wcs);
					
					/* concatenate the command strings */
					strcat(&sys_cmd2, " ");
					strcat(&sys_cmd2, &fout_name);
					strcat(&sys_cmd2, ret_cmd);
					strcat(&sys_cmd2, wc_out);
					
					printf("command %s\n", &sys_cmd2);
					system(&sys_cmd2);
					printf("counted.\n");
							
			}//if argv = 3
		
		fclose(fptr1);
		fclose(fptr2);				
		return 0;									
		
}//int main()
		
