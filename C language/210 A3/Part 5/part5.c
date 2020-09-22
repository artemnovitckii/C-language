#include <stdio.h>  
#include <string.h> 

int main(int argc, char **argv){  
    FILE *file;  
    //FILE *fileout;  
    int r0;  
    int r1;  
    int r2;  
    int r3;   
    int r4;  
    int r5;  
    int r6;  
    int r7; 
    int offset;  
    int add = 1 << 12;  
    int and = 5 << 12;
    int jmp = 12 << 12;  
    int orig;  
    int orig2;
	int origpart5;
    int halt = 0xf025;  
    int r0write;  
    int r1write;  
    int r2write;  
    int r3write;  
    int r4write;  
    int r5write;  
    int r6write;  
    int r7write; 
    int offsetwrite;  
    int sumand;  
    int sumadd;
    int sumjump;  
    int sumaddpart1;  
    int sumaddpart2;  
    int sumandpart1;  
    int sumandpart2;  
    int haltpart1;  
    int haltpart2;  
    int offsetaddpart1; 
    int offsetaddpart2; 
    int offsetandpart1; 
    int offsetandpart2;
    int jumpart1;
    int jumpart2;
	int count;
    file = fopen(argv[1], "r");  
    //fileout = fopen(argv[2],"wb");  
    char str[80];  
    char str2[80];  
    char sumaddstr[80];  
    char sumandstr[80]; 
    char offsetadd[80]; 
    char offsetand[80]; 
    char haltstr[80];
    char sumjumpstr[80]; 
    int dash = 1 << 5; 
    int emptyjump = 0 << 9; 
    while (fscanf (file, "%s %s", str,str2) != EOF){  
        printf("This is a string - %s-%s\n",str,str2);
		count = count + 1;
		printf("The count is %d",count);
        if (strcmp(str, ".orig") == 0){
			sscanf(str2, "x%x", &origpart5);
			printf("orig is %x",origpart5);
            
			//sscanf(str2 , "x%2x%2x",&orig,&orig2);  
            //printf("orig %x-%x\n", orig,orig2);  
            //fwrite(&orig,1,1,fileout);  
            //fwrite(&orig2,1,1,fileout);  
        }  
        if (strcmp(str, "add") == 0){ 
        	if (str2[6] == 35){ 
        		sscanf(str2,"r%d,r%d,#%d",&r6,&r7,&offset); 
        		//printf("REGISTERS are %d,%d,%d\n",r6,r7,offset); 
        		r6write = r6 << 9; 
        		r7write = r7 << 6; 
        		if (offset < 0){ 
            			offset = offset + 32; 
        		} 
        		offsetwrite = offset << 0; 
        		sumadd = add | r6write | r7write | dash |offsetwrite; 
        		printf("THE HEX SUM of add is  %x\n",sumadd); 
        		//sprintf(offsetadd,"%x",sumadd); 
        		//sscanf(offsetadd,"%2x%2x",&offsetaddpart1,&offsetaddpart2); 
        		//fwrite(&offsetaddpart1,1,1,fileout); 
        		//fwrite(&offsetaddpart2,1,1,fileout); 
         
        } 
        else{ 
        sscanf(str2,"r%d,r%d,r%d",&r1,&r2,&r3); 
       	    //printf("Registers are %d,%d,%d\n", r1,r2,r3);  
            r1write = r1 << 9;  
            r2write = r2 << 6;  
            r3write = r3 << 0;  
            sumadd = add | r1write | r2write | r3write;  
            //printf("Shifted registers are %d,%d,%d\n",r1write,r2write,r3write);  
            //printf("Whole thing is %d%d%d%d\n",add,r1write,r2write,r3write);  
            printf("The decimal sum is %x\n", sumadd); 
            //sprintf(sumaddstr, "%x", sumadd);    
            //sscanf(sumaddstr,"%2x%2x",&sumaddpart1,&sumaddpart2);   
            //fwrite(&sumaddpart1,1,1,fileout);  
            //fwrite(&sumaddpart2,1,1,fileout); 
        }   
        }  
        if (strcmp(str, "and") == 0){ 
        	if (str2[6] == 35){ 
        		sscanf(str2,"r%d,r%d,#%d",&r0,&r1,&offset); 
        		//printf("ReGiStErS are %d,%d,%d\n",r0,r1,offset); 
        		r0write = r0 << 9; 
        		r1write = r1 << 6; 
        		offsetwrite = offset << 0; 
        		sumand = and | r0write | r1write | dash | offsetwrite; 
        		printf("The HEX SUM of and is %x\n",sumand); 
        		//sprintf(offsetand,"%x",sumand); 
        		//sscanf(offsetand,"%2x%2x",&offsetandpart1,&offsetandpart2); 
        		//fwrite(&offsetandpart1,1,1,fileout); 
        		//fwrite(&offsetandpart2,1,1,fileout); 
         
        } 
        else{  
            sscanf(str2,"r%d,r%d,r%d",&r0,&r4,&r5);  
            //printf("Registers are %d,%d,%d\n",r0,r4,r5);  
            r0write = r0 << 9;  
            r4write = r4 << 6;  
            r5write = r5 << 0;  
            sumand = and | r0write | r4write | r5write;  
            printf("The decimal sum is %x\n", sumand);  
            //sprintf(sumandstr,"%x",sumand);  
            //sscanf(sumandstr,"%2x%2x",&sumandpart1,&sumandpart2); 
            //fwrite(&sumandpart1,1,1,fileout);  
            //fwrite(&sumandpart2,1,1,fileout);  
            }  
              
        }  
        if (strcmp(str,"jmp") == 0){
		sscanf(str2,"r%d",&r5);
		//printf("Jump register is %d\n",r5);
		r5write = r5 << 6;
		sumjump = jmp | emptyjump | r5write;
		printf("The hex jump is %x\n",sumjump);
		//sprintf(sumjumpstr,"%x",sumjump);
		//sscanf(sumjumpstr,"%2x%2x",&jumpart1,&jumpart2);
		//fwrite(&jumpart1,1,1,fileout);
		//fwrite(&jumpart2,1,1,fileout);
	}
		
	if (strcmp(str, "halt") == 0){  
            printf("Halt value is %x\n",halt);  
            //sprintf(haltstr, "%x", halt);  
            //sscanf(haltstr,"%2x%2x",&haltpart1,&haltpart2);  
            //fwrite(&haltpart1,1,1,fileout);  
            //fwrite(&haltpart2,1,1,fileout);  
        }      
               
           
          
    }  

    fclose(file);  
    //fclose(fileout);  
    return 0;  
} 

