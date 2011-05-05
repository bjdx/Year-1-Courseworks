#include <stdio.h>
#include <ctype.h>
#include <string.h>

int encode(char *name){
  int i=1;
  int codenum = 1;
  char code[5];
  code[0] = name[0];


  while (name[i]!='\0') {
    if (codenum <4){
	
	if (name[i]== 'b'||name[i]=='p'||name[i]=='f'||name[i]=='v') {
	  code[codenum]='1';
	  codenum = codenum +1;
	}else{
	  if (name[i]== 'c'||name[i]=='s'||name[i]=='k'||name[i]=='g'||name[i]=='j'||name[i]=='q'||name[i]=='x'||name[i]=='z') {
	    code[codenum]='2';
	    codenum = codenum +1;
	  }else{
	    if (name[i]== 'd'||name[i]=='t'){
	      code[codenum]='3';
	      codenum = codenum +1;
	    }else{
	      if (name[i]== 'l'){
		code[codenum]='4';
		codenum = codenum +1;
	      }else{
		if (name[i]== 'm'||name[i]=='n'){
		  code[codenum]='5';
		  codenum = codenum +1;
		}else{
		  if (name[i]== 'r'){
		    code[codenum]='6';
		    codenum = codenum +1;
		  }
		}
	      }
	    }
	  }
	}
    }
    i=i+1;
  }
  

  while (codenum<4) {
    code[codenum] = '0';
    codenum = codenum +1;
  }

  //printf("%s\n", code);

  i=0;
  while (i<4) {
    name[i] = code [i];
    i++;
      }
  name[i] = '\0';

  //printf("%s\n", name);
  return 0;

}

int vowels(char *name){
  int i = 0; 

  while (name[i]!='\0') {
    if (name[i]=='a'||name[i]=='e'||name[i]=='i'||name[i]=='o'||name[i]=='u'||name[i]=='w'||name[i]=='y'||name[i]=='h'){
      name[i] = '0';

    }
      i = i + 1;
    }
 

 return encode(name);
}


int doubles(char *name){
  int i=1;

  while (name[i]!='\0') {
   name[i] = tolower(name[i]);
   i = i + 1;
  }

 i=1;

  while (name[i]!='\0') {
    if (name[i]==name[i+1]){
      name[i] = '0';
    }

      i = i + 1;
    }
  return vowels(name);
}

int main(){
  
  char name[20] ;
  printf("Max length 19 characters. \n");
  scanf("%19[a-zA-Z -]s", name);
  name[0] = toupper(name[0]);
  doubles( name );
  printf("Code = %s\n", name);
  return 0;
}
