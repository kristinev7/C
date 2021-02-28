/*Program name: Unit 3 HW
 * Author: Kristine Veneles
 * Purpose: Users, Files, and I/O in C language: Copy, sort and word and line counts>
 * Date: Due on 2/27/21
 */

#include <stdio.h>
#include <stdlib.h>  //atoi
#include "sortlines.h"

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
		int ch;   /* reads number of char of file to copy to new foler */
		int size, index, count;
		char c;
		char lstr[11];
		lstr[10] = '\0'; 
		index = 0;

	/* check arguments */

		if ( argc != 4)
   {  
		 fprintf(stderr, "usage error: format choice 1,2,or 3 in_file, out_file\n");
			return 1;
   }
		if (atoi(argv[1]) == 1)
		{
			if ( (fptr1 = fopen(argv[2], "r" )) == NULL )
			{
					fprintf(stderr, "Can't read %s.\n", argv[2]);
					return 2;
			}	
			
			if ( (fptr2 = fopen(argv[3], "w") ) == NULL )
			{
					fprintf(stderr, "Can't write %s.\n", argv[3]);
					return 3;
			}

			while ( (ch = getc(fptr1)) != EOF ) 
					putc(ch, fptr2);

			printf("File has been copied.\n"); 
	  
//			fclose(fptr1);
	//		fclose(fptr2);
			
		//	return 0;
													
		}// if argv==1
		if (atoi(argv[1]) == 2)
		{
					size = get_file_size(fptr1);
					printf("reading file:\n");
					while ( (c = getc(fptr1) ) != EOF) 
					{
							/*read char until new line*/
							lstr[index] = c;
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
								for (j=0; j<sizeof(lstr); j++)
								{
										lstr[j] = ' ';
								}
										/*reset index*/
								fputc('\n', fptr2);
								index = 0;
								continue;
							}// if \n
							/* increment */
							index++;
						}//while
					fclose(fptr1);
					fclose(fptr2);
					return 0;
		} //if argv == 2
}//int main()

		
