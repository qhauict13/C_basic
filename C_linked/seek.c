#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
 
enum {SUCCESS, FAIL, MAX=20};
 
typedef struct phoneBook{
    char name[MAX];
    char number[MAX];
    char email[MAX];
} contact;
 
//contact myContact[100];
 
int main(int argc, char *argv[]){
     
    int reval;
    FILE *filein;   
     
    contact *myContact;
     
    //check for file access
    if((filein= fopen("contact.txt", "r+"))== NULL) {
        perror("ERROR");
        return FAIL;
    } 
    else{   
        int i, from, to;
        //access data from... to...
        printf("Access contact from: "); scanf("%d", &from);
        printf("to: "); scanf("%d", &to);
        printf("\n");
         
        //Allocate memory
        myContact= (contact*)malloc((to-from+1)*sizeof(contact));
        if(myContact==NULL){
            printf("Allcate memory failed!");
            return FAIL;
        }
         
        fseek(filein, (from-1)*sizeof(contact) , SEEK_SET); //now, seeking to access
        printf("\nnow seeking to bit: **%d**\n", ftell(filein));
        // print data
        for(i=0; i< (to- from+ 1); i++){
            fscanf(filein, "%s%s%s", myContact[i].name, myContact[i].number, myContact[i].email);
            printf("%s- %s- %s\n", myContact[i].name, myContact[i].number, myContact[i].email);
        }
         
        //modify contact
        strcpy(myContact[0].name, "HauPQ");
        strcpy(myContact[0].number, "01697511095");
        strcpy(myContact[0].email, "qhauict13@gmail.com"); 
         
        fseek(filein, (from-1)*sizeof(contact) , SEEK_SET); //first, seek to postion to modify
        //fprintf(filein, "%s-%s-%s", myContact[0].name, myContact[0].number, myContact[0].email);
        int irc=fwrite(myContact, sizeof(contact), to-from+1, filein); //now, writing to file
         
        //print output
        printf("fwrite return code %d\n%s %s %s", irc, myContact[0].name, myContact[0].number, myContact[0].email);
        printf("\n");
        fclose(filein);
    }   
     
    return reval;
}