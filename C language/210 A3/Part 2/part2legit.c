
#include <stdio.h> 
#include <string.h>  

int main(int argc, char **argv){ 
    FILE *file; 
    FILE *fileout; 
    int r0; 
    int r1; 
    int r2; 
    int r3;  
    int r4; 
    int r5; 
    int r6; 
    int r7; 
    int add = 1 << 12; 
    int and = 5 << 12; 
    int orig; 
    int orig2; 
    int halt = 0xf025; 
    int r0write; 
    int r1write; 
    int r2write; 
    int r3write; 
    int r4write; 
    int r5write; 
    int r6write; 
    int r7write; 
    int sumand; 
    int sumadd; 
    int sumaddpart1; 
    int sumaddpart2; 
    int sumandpart1; 
    int sumandpart2; 
    int haltpart1; 
    int haltpart2; 
    file = fopen(argv[1], "r"); 
    fileout = fopen(argv[2],"wb"); 
    char str[80]; 
    char str2[80]; 
    char sumaddstr[80]; 
    char sumandstr[80]; 
    char haltstr[80]; 
    while (fscanf (file, "%s %s", str,str2) != EOF){ 
        //printf("This is a string - %s-%s\n",str,str2); 
        if (strcmp(str, ".orig") == 0){ 
            sscanf(str2 , "x%2x%2x",&orig,&orig2); 
            //printf("orig %x-%x\n", orig,orig2); 
            fwrite(&orig,1,1,fileout); 
            fwrite(&orig2,1,1,fileout); 
             
        } 
        if (strcmp(str, "add") == 0){ 
            sscanf(str2,"r%d,r%d,r%d",&r1,&r2,&r3); 
            //printf("Registers are %d,%d,%d\n", r1,r2,r3); 
            r1write = r1 << 9; 
            r2write = r2 << 6; 
            r3write = r3 << 0; 
            sumadd = add | r1write | r2write | r3write; 
            //printf("Shifted registers are %d,%d,%d\n",r1write,r2write,r3write); 
            //printf("Whole thing is %d%d%d%d\n",add,r1write,r2write,r3write); 
            //printf("The decimal sum is %x\n", sumadd); 
            sprintf(sumaddstr, "%x", sumadd); 
            //printf("String of sumadd is %s\n",sumaddstr); 
            sscanf(sumaddstr,"%2x%2x",&sumaddpart1,&sumaddpart2); 
            //printf("Two parts are %x-%x\n",sumaddpart1,sumaddpart2); 
            //fwrite(&sumadd,2,1,fileout); 
            fwrite(&sumaddpart1,1,1,fileout); 
            fwrite(&sumaddpart2,1,1,fileout); 
        } 
        if (strcmp(str, "and") == 0){ 
            sscanf(str2,"r%d,r%d,r%d",&r0,&r4,&r5); 
            //printf("Registers are %d,%d,%d\n",r0,r4,r5); 
            r0write = r0 << 9; 
            r4write = r4 << 6; 
            r5write = r5 << 0; 
            sumand = and | r0write | r4write | r5write; 
            //printf("Shifted registers are %d,%d,%d\n", r0,r4,r5); 
            //printf("Whole thing is %d%d%d%d\n",and,r0write,r4write,r5write); 
            //printf("The decimal sum is %x\n", sumand); 
            //fwrite(&sumand,2,1,fileout); 
            sprintf(sumandstr,"%x",sumand); 
            sscanf(sumandstr,"%2x%2x",&sumandpart1,&sumandpart2); 
            fwrite(&sumandpart1,1,1,fileout); 
            fwrite(&sumandpart2,1,1,fileout); 
             
             
        } 
        if (strcmp(str, "halt") == 0){ 
            //printf("Halt value is %x\n",halt); 
            sprintf(haltstr, "%x", halt); 
            sscanf(haltstr,"%2x%2x",&haltpart1,&haltpart2); 
            fwrite(&haltpart1,1,1,fileout); 
            fwrite(&haltpart2,1,1,fileout); 
        }     
              
          
         
    } 

    fclose(file); 
    fclose(fileout); 
    return 0; 
} 
         