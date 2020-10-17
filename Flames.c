#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
void delay(int seconds)
{
    int milli_seconds=1000*seconds;
    clock_t start_time=clock();
    while (clock()<start_time + milli_seconds)
        ;
}
void _NOT_A_(char not,char* first_name,char* second_name)
{
    delay(2);
    switch(not)
    {
    case 'F':
        printf("\n\t\t%s is NOT a FRIEND of %s\n",first_name,second_name);
        break;
    case 'L':
        printf("\n\t\t%s DON'T have a LOVE on %s.\n",first_name,second_name);
        break;
    case 'A':
        printf("\n\t\t%s DON'T have an AFFECTION on %s.\n",first_name,second_name);
        break;
    case 'M':
        printf("\n\t\t%s is NOT going to MARRY %s.\n",first_name,second_name);
        break;
    case 'E':
        printf("\n\t\t%s is NOT an ENEMY of %s.\n",first_name,second_name);
        break;
    case 'S':
        printf("\n\t\t%s and %s are NOT SIBLINGS.\n",first_name,second_name);
        break;
    }
}
void _FLAMES_()
{
    int length_of_first_name,length_of_second_name;

    int common_letters=0,unique_letters,space_bars=0;

    int m=6,o=1;

    char first_english_letter = 'A', last_english_letter = 'Z';

    char first_name[100],second_name[100];

    char duplicate_first_name[100],duplicate_second_name[100];

    char flames[6]="FLAMES";

    getchar();

    printf("\nEnter the first name :");
    gets(first_name);

    printf("\nEnter the second name :");
    gets(second_name);

    strcpy(duplicate_first_name,first_name);
    strcpy(duplicate_second_name,second_name);

    length_of_first_name=strlen(first_name);
    length_of_second_name=strlen(second_name);

    for(int i=0;i<length_of_first_name;i++)
        for(int j=0;j<length_of_second_name;j++){

                if(duplicate_first_name[i]>=first_english_letter && duplicate_first_name[i] <= last_english_letter)
                    duplicate_first_name[i]=tolower(duplicate_first_name[i]);

                if(duplicate_second_name[j]>=first_english_letter &&duplicate_second_name[j]<= last_english_letter)
                    duplicate_second_name[j]=tolower(duplicate_second_name[j]);

                if(duplicate_first_name[i]==' '){
                    duplicate_first_name[i]='*';
                    space_bars++;  }

                if(duplicate_second_name[j]==' '){
                    duplicate_second_name[j]='#';
                    space_bars++;   }

                if(duplicate_first_name[i]==duplicate_second_name[j])
                 {
                    common_letters=common_letters+2;
                    duplicate_second_name[j]='#';
                    break;
                 }}

    unique_letters=length_of_first_name+length_of_second_name-common_letters-space_bars;
    printf("\n");

    for(int l=0;l<4;++l)
    {
        o=(unique_letters+o-1)%m;
        if(o==0)
            o=m;
        _NOT_A_(flames[o-1],first_name,second_name);
        for(int k=o-1;k<m;k++)
            flames[k]=flames[k+1];
        m--;
    }
    if((unique_letters+o+1)%2==1){
        char temp;
        temp=flames[0];
        flames[0]=flames[1];
        flames[1]=temp;}

    delay(1);
    _NOT_A_(flames[1],first_name,second_name);

    delay(2);
    printf("\n\t\t--------------------------------------------------");
    switch(flames[0])
    {
    case 'F':
        printf("\n\t\t\t%s is a FRIEND of %s\n",first_name,second_name);
        break;
    case 'L':
        printf("\n\t\t\t%s have a LOVE on %s.\n",first_name,second_name);
        break;
    case 'A':
        printf("\n\t\t\t%s have an AFFECTION on %s.\n",first_name,second_name);
        break;
    case 'M':
        printf("\n\t\t\t%s is going to MARRY %s.\n",first_name,second_name);
        break;
    case 'E':
        printf("\n\t\t\t%s is an ENEMY of %s.\n",first_name,second_name);
        break;
    case 'S':
        printf("\n\t\t\t%s and %s are SIBLINGS.\n",first_name,second_name);
        break;
    }
    printf("\t\t--------------------------------------------------");
}
void main()
{
    char ch='y';
    printf("------------------ FLAMES ------------------\n");
    printf("\nPress Enter to Start:");
    while(ch=='y')
    {
        _FLAMES_();
        printf("\nDo you want to put FLAMES again [y/n]:");
        scanf("%c",&ch);
    }
}
