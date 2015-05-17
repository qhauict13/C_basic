char *atostr(int n)
{
	char* a = (char*)malloc(9*sizeof(char));
	int i=0,j,m=1,k;
	 if(n==0)
	{
		a[0]='0';a[1]='\0';
		return a;
	}
	if(n<0) {m=-1;n=-n;}
	
	while (n!=0)
	{
		j=n%10;
		a[i]=j+48;i++;
		n=(n-j)/10;
	}
	a[i]='\0';
	swap(a);
	if(m==-1) 
	{
		k=strlen(a);
		a[k]= ' ';
		a[k+1]='\0';
		k=strlen(a);
		for(i=k-1;i>0;i--) a[i] = a[i-1];
		a[0]='-';
	}
	return a;
}
int discriminate(char *a)
{
	if(!strcmp(a,"+")) return 1;
	if(!strcmp(a,"-")) return 1;
	if(!strcmp(a,"*")) return 1;
	if(!strcmp(a,"/")) return 1;
	if(!strcmp(a,"%")) return 1;
	if(!strcmp(a,"(")) return 1;
	if(!strcmp(a,")")) return 1;
	return 0;
}
int discriminatenew(char a)
{
	if(a=='-') return 1;
	if(a=='+') return 1;
	if(a=='*') return 1;
	if(a=='/') return 1;
	if(a=='%') return 1;
	return 0;
}

int check(char *a){
  int i = 0;
  if (discriminatenew(a[strlen(a)-2])) return 0;
  if (discriminatenew(a[0])) return 0;
  for (i=0;i<strlen(a)-2;i++) if(a[i]=='('&&a[i+2]==')') return 0;
  return 1;
}
char *transform(char *a)
{
	int i,j,k;
	for (i=0;i<strlen(a);i++) 
	if (a[i]=='+'||a[i]=='-'||a[i]=='*'||a[i]=='/'||a[i]=='%'||a[i]=='('||a[i]==')')
	{
		if(a[i-1]!= ' ') 
		{ 
		k=strlen(a);a[k]=' ';a[k+1]='\0'; k=strlen(a);
		for(j=k-1;j>i;j--) a[j]=a[j-1];  a[i]=' ';
		i++;
		}
		
		if(a[i+1]!= ' ') 
		{ 
		k=strlen(a);a[k]=' ';a[k+1]='\0'; k=strlen(a);
		for(j=k-1;j>i+1;j--) a[j]=a[j-1];  a[i+1]=' ';
		}
	}
	
	while(a[0]==' ') for(i=0;i<strlen(a);i++) a[i]=a[i+1]; 
 	while(a[strlen(a)-1]==' ') a[strlen(a)-1]='\0';  
	for(i=1;i<strlen(a)-1;i++)
	{
		if(a[i]==' '&&a[i+1]==' ') 
		{
			for(j=i+1;j<strlen(a);j++)
			a[j]=a[j+1];
			i--;
		}		
	}
	k=strlen(a);a[k]=' ';a[k+1]='\0';
	return a;
}
char *partcut(char *ex)
{
	int i=0,j,k;
	if(strlen(ex)==0) return NULL;
	while( ex[i]!=' ' && i<strlen(ex) && ex[i]!='\n')  i++;
	char* b = (char*)malloc(i*sizeof(char));
	for(j=0;j<i;j++)
		b[j]=ex[j];
	b[i]='\0';
	for(k=0;k<=i;k++)
	for(j=0;j<strlen(ex);j++) ex[j]=ex[j+1];
	return b;	
}
stringnode *postfix(char *ex)
{
	char *part=NULL;
	stringnode *mediate=NULL;
	stringnode *output=NULL;
	while(1)
	{		
		part = partcut(ex);
		if (part==NULL) 
		{
			while(mediate!=NULL)
			{
				output = stringpush(output,mediate->data);
				mediate = stringpop (mediate);
			}
			break;
		}
		if (!discriminate(part))
			output = stringpush(output,part);
		else if (!strcmp(part,"(")) 
		{
			mediate = stringpush(mediate,part);
		}				
	 	else if (!strcmp(part,")"))
			{
				while(strcmp(mediate->data,"(")) 
				{
					output = stringpush(output,mediate->data);
					mediate = stringpop(mediate);
				}
				mediate = stringpop(mediate);
			}
		else if (discriminate(part))
		{
			while (mediate!=NULL&&discriminate(mediate->data) && strcmp(mediate->data,part)&&strcmp(mediate->data,"("))
			{
				output = stringpush(output,mediate->data); 
				mediate = stringpop (mediate);
			}
			mediate = stringpush(mediate,part);
		}
	}
	output = stringlist_reverse(output);
	return output;	
}
