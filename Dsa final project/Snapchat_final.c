#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 10
struct friends
{
    char name[50];
    char username[50];
    char dob[50];
};
typedef struct friends F;
struct contacts
{
    char cname[50];
    char userid[50];
};
typedef struct contacts C;
char m[100];
int i=0;
struct node
{
    char data[50];
    struct node *next;
};
typedef struct node *NODE;
NODE head=NULL;


F frns[200];
C cncts[200];

F search_result[200];
int global_count = 0;
int global_count1 = 0;

void print()
{
    printf("\nYOUR FRIENDS:\n");
    printf("  NAME\t\t\tUSERNAME\n");
    for(int i=0;i<global_count;i++)
    {
        printf("%d.%s\t\t\t%s\n",i+1,frns[i].name,frns[i].username);
    }
}
void printcontacts()
{
    printf("\nYOUR contacts:\n");
    printf("  NAME\t\t\t\t\tUSERNAME\n");
    for(int i=0;i<global_count1;i++)
    {
        printf("%d.%s\t\t\t%s\n",i+1,cncts[i].cname,cncts[i].userid);
    }
}
int streak(char name[])
{
    int streak=0;
    int a,b;
    while(1)
    {
        printf("\n\nnew day!\n\n");
        printf("If yes enter 1 else 0\nEnter 3 to exit streaks.\n");
        printf("Did you send snap today?\n");
        scanf("%d",&a);
        if(a==3)
        {
            printf("Exited from streaks.\n");
            return 0;
        }
        else
        {
        printf("did %s send snap today?\n",name);
        scanf("%d",&b);
        if(a==1&&b==1)
        {
            streak++;
            if(streak>=3)
                printf("****%s %d FIREEEEE****\n",name,streak);
        }
        else if ((a==1&&b==0)||(a==0&&b==1)||a==0&&b==0)
        {
            printf("streaks broke\n");
            break;
        }
        }
    }
}

void load()
{
    FILE *fp;
    fp = fopen("SnapFriends.txt", "r+");

    if (fp == NULL)
    {
        printf("File Not found\n");
        return;
    }


    while(!feof(fp))
    {
        fscanf(fp,"%s%s%s", frns[global_count].name, frns[global_count].username,
        frns[global_count].dob);

        global_count++;
    }

    fclose(fp);
}
void load_contacts()
{
    FILE *fp;
    fp = fopen("contacts.txt", "r+");
    if (fp == NULL)
    {
        printf("File Not found\n");
        return;
    }

    while(!feof(fp))
    {
        fscanf(fp,"%s%s", cncts[global_count1].cname, cncts[global_count1].userid);
        global_count1++;
    }
        fclose(fp);
}

int check(char nm[20])
{
    int flag=0;
    for(int i=0;i<global_count;i++)
    {
        if(strcmp(nm,frns[i].username)==0)
        {
            flag=1;
            break;
        }
    }
    return flag;

}

NODE getnode()
{
    NODE newnode;
    newnode=malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("memory is not allocated \n");
    }

    //scanf("%s",newnode->data);
    strcpy(newnode->data,frns[i].name);
    newnode->next=NULL;
    i++;
    return newnode;
}

void display(NODE head)
{
    if(head==NULL)
    {
        printf("List is empty \n");
        return;
    }
    NODE temp=head;
    while(temp!=NULL)
    {
        printf("%s\n",temp->data);
        temp=temp->next;
    }
}

NODE delete_position(NODE head)
{
    char sname[100],msg[100];
    int d;
    printf("Enter the name to chat with:\n");
    scanf("%s",sname);
    printf("Type the message\n");
    scanf("%s",msg);
    if(head==NULL)
    {
        printf("cannot delete \n");
        return head;
    }
        NODE cur=head,prev=NULL;
        if(cur==head&&strcmp(cur->data,sname)==0)
        {
            return head;
        }
    while(strcmp(cur->data,sname)!=0&&cur!=NULL)
    {
        prev=cur;
        cur=cur->next;
    }
    if(cur==NULL)
    {
        printf("person not in friend list\n");
        return head;
    }
    prev->next=cur->next;
        NODE temp2=cur;
        NODE newnode=malloc(sizeof(struct node));
        strcpy(newnode->data,temp2->data);
        newnode->next=head;
        head=newnode;
        return head;
}

NODE insert_front(NODE head)
{
    NODE Newnode=getnode();
    if(head==NULL)
    {
        head=Newnode;
        return head;
    }
    else
    {
        Newnode->next=head;
        head=Newnode;

        return head;
    }

}

NODE delete_specific(NODE head)
{
    char sname[100],msg[100];
    printf("Remove friend:\n");
    scanf("%s",sname);
    if(head==NULL)
    {
        printf("cannot delete \n");
        return head;
    }
        NODE cur=head,prev=NULL;
        if(cur==head&&strcmp(cur->data,sname)==0)
        {
            return head;
        }
    while(strcmp(cur->data,sname)!=0&&cur!=NULL)
    {
        prev=cur;
        cur=cur->next;
    }
    if(cur==NULL)
    {
        printf("person not in friend list\n");
        return head;
    }
    prev->next=cur->next;
    return head;
}


void bubblesort()
{
    char temp[200];
    for(int i=0;i<=global_count-2;i++)
    {
        for(int j=0;j<=global_count-2-i;j++)
        {
            if(strcmp(frns[j].name,frns[j+1].name)>0)
            {
                strcpy(temp,frns[j].name);
                strcpy(frns[j].name,frns[j+1].name);
                strcpy(frns[j+1].name,temp);
            }
        }
    }
    for(int i=0;i<global_count;i++)
    {
        printf("%s\n",frns[i].name);
    }
}

void print2()
{
    for(int i=0;i<global_count;i++)
    {
        printf("%s\n",frns[i].name);
    }
}


 int main()
{
     load();
    load_contacts();
    printf("data loaded.\n\n");
    printf("Contacts loaded\n\n");
    printf("\n");
    for(int i=0;i<10;i++)
    {
        head=insert_front(head);
    }
    for(int i=0;i<85;i++)
    {
        printf("-");
    }
    printf("\n");
    printf("                                     LOGIN\n");
    for(int i=0;i<85;i++)
    {
        printf("-");
    }
    printf("\n");
    printf("To login enter 1 else 0\n");
    int y;
    scanf("%d",&y);
    if(y==1)
       {
           int t;
           char sir[20];
           int num;
          printf( "login using\n 1. username\n 2. phone number\n");
          printf("(Enter 1 to login using username, 2 to login using phone number)\n");
          printf("your choice?\n");
          scanf("%d",&t);
          if( t==1)
            {
                printf("enter username:\n");
                scanf("%s",sir);
                if(strcmp("gogi17",sir)!=0)
                 {
                     printf("invalid username.");
                     return 0;
                 }

            }
        if (t==2)
        {
            int phno;
            printf("enter phone number:\n");
            scanf("%d",&phno);
            if(phno!=8660253)
               {
                   printf("invalid phone number");
                   return 0;
               }
        }
        char pass[40];
        printf("enter ur password:\n");
        scanf("%s",pass);
        if(strcmp("gforgogi",pass)!=0)
            {
                printf("wrong password");
                return 0;
            }

       }
       else
        return 0;
        printf("\n***********************************||||HAPPY SNAPPING||||************************\n");
    int c;
    while(1)
    {
        printf("                                       **************\n                                           MENU\n                                       **************\n");
        for(int l=0;l<85;l++)
        {
            printf("-");
        }
        printf("\n");
        printf("                                ||  1.Display friends      ||\n");
        printf("                                ||  2.Streaks              ||\n");
        printf("                                ||  3.Search               ||\n");
        printf("                                ||  4.Display contacts     ||\n");
        printf("                                ||  5.Send message         ||\n");
        printf("                                ||  6.Remove a friend      ||\n");
        printf("                                ||  7.Sort by Name         ||\n");
        printf("                                ||  8.Logout               ||\n");
        for(int l=0;l<85;l++)
        {
            printf("-");
        }
        printf("\n");
        printf("enter choice:\n");
        scanf("%d",&c);

        switch(c)
        {
            case 1:
                    print();
                    break;
            case 2:
                {
                    char nm[20];
                    printf("enter the username \n");
                    scanf("%s",nm);
                    int flag=check(nm);
                    if(flag==0)
                    {
                        printf("No friends with that username:(\n");
                    }
                    else
                        streak(nm);
                    break;
                    }
            
            case 3:{
                    int r;
                    char s[20];
                    printf("Search based on username\n");
                                    printf("Enter the username to search \n");
                                    scanf("%s",s);
                                        int flag=0,n,m,i,j,k,l,z=0;
                                            for(i=0;i<global_count;i++)
                                            {
                                                n=strlen(frns[i].username);
                                                m=strlen(s);
                                                for(j=0;j<=n-m;j++)
                                                {
                                                    k=0;
                                                    while((k<m)&&(s[k]==(frns[i].username)[j+k]))
                                                    k++;
                                                    if(k==m)
                                                    {
                                                        strcpy(search_result[z].name,frns[i].name);
                                                        strcpy(search_result[z].username,frns[i].username);
                                                        z++;
                                                        break;
                                                    }
                                                }
                                            }
                                            z--;
                                            printf("\nRESULTS\nFriends whose username matches with %s:\n",s);
                                            for(i=0;i<=z;i++)
                                            {
                                                printf("%s\t%s\n",search_result[i].name,search_result[i].username);
                                            }
                                            if(z==-1)
                                            {
                                                printf("\n NOT FOUND\n");
                                            }

                     } break;
            case 4:
                    {
                        printcontacts();
                    }
                   break;
                        
            case 5:printf("Friends to chat with:\n");
                print();
                head=delete_position(head);
                {
                    if(head==NULL)
                    {
                        printf("List is empty \n");
                        break;
                    }
                    NODE temp=head;
                    while(temp!=NULL)
                    {
                        printf("%s\n",temp->data);
                        temp=temp->next;
                    }
                 }
                break;

            case 6:
                {
                    head=delete_specific(head);
                    printf("\n");
                    printf("Friends:\n");
                    display(head);
                }
                break;

            case 7:{
                    
                      bubblesort();
                    }   
                     break;
            case 8:{
                int n;
                printf("Are you sure you want to logout?\n1 for YES, 0 for NO\n");
                scanf("%d",&n);
                if(n==1)
                {
                    printf("LOGGED OUT SUCCESSFULLY.\n");
                    exit(0);
                }
                else
                {
                    printf("Keep snapping :)\n");
                }
                    break;
            }

            default:printf("invalid choice\n");
        }
    }
    return 0;
}
