#include <stdio.h>
#include <stdlib.h>
 
int find_if(char s[])       //chaar s[] in C
{
    int i = 0;
    while(s[i] == ' ' || s[i] == '\t')
        i++;
 
    if(s[i] == 'i' && s[i+1] == 'f') {
        int j = 0;
        while(s[j] != ')'){
            j++;
        }
 
        j++;
 
        while(s[j] != ';') {
            if(s[j] != ' ')
                break;
            j++;
        }
 
        if(s[j] == ';') {
            printf("%s\n", s);
            return 1;
        }
 
         
    }
 
    return 0;
}
 
int find_scanf(char s[])       //chaar s[] in C
{
    //printf("Enter scanf\n");
 
    int i = 0;
    while(s[i] == ' ' || s[i] == '\t')
        i++;
 
     if( (s[i]=='s') && (s[i+1]=='c') && (s[i+2]=='a') && (s[i+3]=='n') && (s[i+4]=='f') ) {
 
        int j = i+5;     // j = '('
 
        while((s[j] != '&') && (s[j] != ';')) {
            j++;
        }
 
        if(s[j] == ';') {
            printf("%s\n", s);
            return 1;
        }
 
    }
 
    //printf("returned 0");
    return 0;
}
 
int find_case(char s[])
{
 
    int i = 0;
    while(s[i] == ' ' || s[i] == '\t')
        i++;
 
     if( (s[i]=='c') && (s[i+1]=='a') && (s[i+2]=='s') && (s[i+3]=='e') ) {
        return 1;
    }
 
    //printf("returned 0");
    return 0;
}
 
int find_break(char s[])
{
    int i = 0;
    while(s[i] == ' ' || s[i] == '\t')
        i++;
 
     if( (s[i]=='b') && (s[i+1]=='r') && (s[i+2]=='e') && (s[i+3]=='a') && (s[i+4] == 'k')) {
        return 1;
    }
    //printf("returned 0");
    return 0;
}
 
 
int main(void)
{
    FILE *fp = fopen("text.c", "r");
    int c;
    char s[100];
    int i = 0;
    int flag = 0;
    while((c=getc(fp)) != EOF) {
        if(c == '\n') {          //when a line ends
 
            s[i] = '\0';
            i = 0;
 
            if (find_if(s) > 0)
                printf("%s\n", "Warning: placement of ';' after if\n");
 
            if(find_scanf(s) > 0)
                printf("%s\n", "Warning: you missed an & in scanf()\n");
 
            if(find_break(s)>0) {
                flag = 0;
            }
            if(find_case(s) > 0) {
                if(flag > 0) {
                    printf("Warning: you missed a break statement after switch\n");
                }
                flag = find_case(s);
            }
        }
        else s[i++] = c;
    }
 
    fclose(fp);
}
