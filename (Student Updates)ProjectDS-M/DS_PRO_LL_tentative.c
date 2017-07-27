#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct placement{
	char company_name[30];
	char description[100];
	float salary;
	char skill[100];
	int placements_req;
	struct placement *next;
	};
struct placement *p;
struct internship{
	char company_name[30];
	char description[100];
	float stipend;
	char skill[100];
	char duration[20];
	struct internship *next;
};	
struct internship *i;
struct project{
	char project_name[20];
	char description[200];
	char platform[20];
	char advantages[100];
	char limitations[100];
	char branch[20];
	char doneby[20];
	char problems[100];
	struct project *next;
};
struct project *pro;
struct classinfo{
	char classname[10];
	char branchname[10];
	int date;
	int month;
	int year;
	char status[100];
	struct classinfo *next;
};
struct classinfo *c;
struct campusinfo{
	char activity[100];
	struct campusinfo *next;
};
struct campusinfo *campus;

struct placement* placementinfo(struct placement*);
struct placement* placementdisplay(struct placement*);
struct project* projectinfo(struct project*);
struct project* projectdisplay(struct project*);
struct classinfo* classinformation(struct classinfo*);
struct classinfo* classdisplay(struct classinfo*);
struct internship* internshipinfo(struct internship*);
struct internship* internshipdisplay(struct internship*);
struct campusinfo* campusinformation(struct campusinfo*);
struct campusinfo* campusdisplay(struct campusinfo*);
struct placement *placementstart=NULL;
struct internship *internshipstart=NULL;
struct project *projectstart=NULL;
struct classinfo *classinfostart=NULL;
struct campusinfo *campusinfostart=NULL;
void menu(void);
void menu2(void);
void menu3(void);
void placementupdate(struct placement*);
void internshipupdate(struct internship*);
void projectupdate(struct project*);
void classinfoupdate(struct classinfo*);
void campusinfoupdate(struct campusinfo*);
struct placement *placementretrieve(struct placement *);
struct placement *link_form_placement(struct placement *,struct placement *);
struct internship *internshipretrieve(struct internship *);
struct internship *link_form_internship(struct internship *,struct internship *);
struct project *projectretrieve(struct project *);
struct project *link_form_project(struct project *,struct project *);
struct classinfo *classinforetrieve(struct classinfo *);
struct classinfo*link_form_classinfo(struct classinfo *,struct classinfo *);
struct campusinfo *campusinforetrieve(struct campusinfo *);
struct campusinfo *link_form_campusinfo(struct campusinfo *,struct campusinfo *);
struct placement* placementsearchbysalary(struct placement*);
struct placement* placementsearchbycompany(struct placement*);
struct internship* internshipsearchbycompany(struct internship*);
struct internship* internshipsearchbystipend(struct internship*);
struct project* projectsearchbybranch(struct project*);
struct classinfo* classinfosearchbyclass(struct classinfo*);
int a,b,c1,d,e,f,g,h,i1;
void updateall(void)
{
	placementupdate(placementstart);
	internshipupdate(internshipstart);
	projectupdate(projectstart);
	classinfoupdate(classinfostart);
	campusinfoupdate(campusinfostart);
}
void retrieveall(void)
{
	placementstart=placementretrieve(placementstart);
	internshipstart=internshipretrieve(internshipstart);
	projectstart=projectretrieve(projectstart);
	classinfostart=classinforetrieve(classinfostart);
	campusinfostart=campusinforetrieve(campusinfostart);
}
int main()
{
	retrieveall();
	printf("\n \n");
	printf("	          *-*-*-*-*-* WELCOME TO HYPHEN*M *-*-*-*-*-*\n");
	printf("\n \n");
	menu();
	return 0;
}
	void menu(void)
	{
	printf("	    	            TELL US YOUR CATEGORY\n");
	printf("\n");
	printf("				   1.ADMIN \n");
	printf("				   2.USER\n");
	printf("			   	   3.EXIT (U can be Quit) \n");
	printf("\n");
	printf("-------------------------------------------------------------------------\n");
	scanf("%d",&a);
	getchar();
	switch(a)
	{
	case 1:
	{   
		char admin[10]="iknow";
		char password[10];
		printf("ENTER THE PASSWORD::");
		gets(password);
		if(strcmp(admin,password)==0)
		{
		printf("			   1.KNOW THE INFORMATION\n");
		printf("			   2.UPDATE THE INFORMATION\n");
		printf("			   3.EXIT\n");
		printf("\n");
		printf("-------------------------------------------------------------------------\n");
		scanf("%d",&b);
		getchar();
		switch(b)
		{
			case 1:
			{
				menu3();
				break;
			
			}
			case 2:
			{
			printf("			1.PLACEMENT INFORMATION\n");
			printf("			2.INTERNSHIP INFORMATION\n");
			printf("			3.PROJECT INFORMATION\n");
			printf("			4.CLASS INFORMATION\n");
			printf("			5.CAMPUS & ACTIVITY INFORMATION\n");
			printf("			6.EXIT \n");
			printf("\n");
			printf("-------------------------------------------------------------------------\n");
			printf("ENTER YOUR CHOICE TO UPDATE THE INFO::");
			printf("\n");
			printf("\n");
			scanf("%d",&d);
			getchar();
			switch(d)
			{
				case 1:
						placementstart=placementinfo(placementstart);
						menu3();
					break;
				case 2:
						internshipstart=internshipinfo(internshipstart);
						menu3();
					break;
				case 3:
						projectstart=projectinfo(projectstart);
						menu3();
					break;
				case 4:
						classinfostart=classinformation(classinfostart);
						menu3();
					break;
				case 5:
						campusinfostart=campusinformation(campusinfostart);
						menu3();
					break;	
					case 6:
					menu2();
					break;
				}
				}
				break;
			case 3:
			menu();
			break;
			default:
				do{
				printf("				INCORRECT CHOICE! TRY AGAIN\n");
				printf("\n");
				menu2();
				 }while(b>3||b<1);
		}
	}
else
{
	printf("			WROGLY ENTERED PASSWORD! ENTER AGAIN\n");
	menu();
}
}
break;
	case 2:
		{
		menu3();
		}
		break;
		case 3:
		printf("			UPDATING DATABASE\n");
		updateall();
			exit(1);
			break;
			default:
				printf("	   		  INCORRECT CHOICE! TRY AGAIN\n");
				printf("\n");
				menu();
				break;
}
}

struct placement* placementinfo(struct placement* placementstart )
{
struct placement *new_node,*p;
char cname[30];
char des[100];
float sal;
char ski[100];
int pla;
printf("	ENTER UNDERSCORE(_) IN PLACE OF A SPACE-- EX: I_AM_AN_INDIAN\n");
printf("ENTER THE NAME OF THE COMPANY::");
gets(cname);
	new_node=(struct placement*)malloc(sizeof(struct placement));
	strcpy(new_node->company_name,cname);
		printf("\n");
			printf("\n");
	printf("ENTER THE DESCRIPTION OF THE COMPANY::");
	gets(des);
	strcpy(new_node->description,des);
		printf("\n");
			printf("\n");
	printf("ENTER THE SALARY OFFERED::");
	scanf("%f",&sal);
	getchar();
	new_node->salary=sal;
		printf("\n");
			printf("\n");
	printf("ENTER THE SKILLS REQUIRED FOR THE COMPANY::");
	gets(ski);
	strcpy(new_node->skill,ski);
		printf("\n");
			printf("\n");
	printf("ENTER THE NUMBER OF PLACEMENTS OFFERED::");
	scanf("%d",&pla);
	new_node->placements_req=pla;
	if(placementstart==NULL){
		new_node->next=NULL;
		placementstart=new_node;
	}
	else {
		p=placementstart;
		while(p->next!=NULL){
			p=p->next;
		}
		p->next=new_node;
		new_node->next=NULL;
	}
	
	return placementstart;
}
struct internship* internshipinfo(struct internship* internshipstart )
{
struct internship *new_node,*i;
char cname[30];
char des[100];
float sti;
char ski[100];
char dur[20];
	printf("\n");
			printf("\n");
printf("	ENTER UNDERSCORE(_) IN PLACE OF A SPACE-- EX: I_AM_AN_INDIAN\n");
printf("ENTER THE NAME OF THE COMPANY::");
gets(cname);
	new_node=(struct internship*)malloc(sizeof(struct internship));
	strcpy(new_node->company_name,cname);
		printf("\n");
			printf("\n");
	printf("ENTER THE DESCRIPTION OF THE COMPANY::");
	gets(des);
	strcpy(new_node->description,des);
		printf("\n");
			printf("\n");
	printf("ENTER THE STIPEND OFFERED::");
	scanf("%f",&sti);
	getchar();
	new_node->stipend=sti;
		printf("\n");
			printf("\n");
	printf("ENTER THE SKILLS REQUIRED FOR THE INTERNSHIP::");
	gets(ski);
	strcpy(new_node->skill,ski);
		printf("\n");
			printf("\n");
	printf("ENTER THE DURATION OF THE INTERNSHIP::");
	gets(dur);
	strcpy(new_node->duration,dur);
	if(internshipstart==NULL){
		new_node->next=NULL;
		internshipstart=new_node;
	}
	else {
		i=internshipstart;
		while(i->next!=NULL){
			i=i->next;
		}
		i->next=new_node;
		new_node->next=NULL;
	}
	
	return internshipstart;
}
struct project* projectinfo(struct project* projectstart)
{
struct project *new_node,*pro;
char pname[20];
char des[200];
char plat[20];
char ad[100];
char lim[100];
char branch[20];
char doneby[20];
char probs[100];
	printf("\n");
			printf("\n");
printf("	ENTER UNDERSCORE(_) IN PLACE OF A SPACE-- EX: I_AM_AN_INDIAN\n");
printf("ENTER NAME OF THE PROJECT::");
gets(pname);
	new_node=(struct project*)malloc(sizeof(struct project));
	strcpy(new_node->project_name,pname);
		printf("\n");
			printf("\n");
	printf("ENTER THE DESCRIPTION OF THE PROJECT::");
	gets(des);
	strcpy(new_node->description,des);
		printf("\n");
			printf("\n");
	printf("ENTER THE PLATFORM ON WHICH THE PROJECT IS BEING DONE::");
	gets(plat);
	strcpy(new_node->platform,plat);
		printf("\n");
			printf("\n");
	printf("ENTER THE ADVANTAGES OF THE PROJECT::");
	gets(ad);
	strcpy(new_node->advantages,ad);
		printf("\n");
			printf("\n");
	printf("ENTER THE LIMITATIONS OF THE PROJECT::");
	gets(lim);
	strcpy(new_node->limitations,lim);
		printf("\n");
			printf("\n");
	printf("ENTER THE NAME OF THE BRANCH THAT THE PROJECT BELONGS TO::");
	gets(branch);
	strcpy(new_node->branch,branch);
		printf("\n");
			printf("\n");
	printf("WHO HAVE DONE THIS PROJECT::");
	gets(doneby);
	strcpy(new_node->doneby,lim);
		printf("\n");
			printf("\n");
	printf("ENTER THE PROBLEMS FACED WHILE DOING THE PROJECT::");
	gets(probs);
	strcpy(new_node->problems,probs);
	if(projectstart==NULL){
		new_node->next=NULL;
		projectstart=new_node;
	}
	else {
		pro=projectstart;
		while(pro->next!=NULL){
			pro=pro->next;
		}
		pro->next=new_node;
		new_node->next=NULL;
	}
	
	return projectstart;
}
struct classinfo* classinformation(struct classinfo* classinfostart)
{
struct classinfo *new_node,*c;
char cname[10];
char bname[10];
static int date,month,year,tdate,tmonth,tyear;
char status[100];
	printf("\n");
			printf("\n");
	printf("	ENTER UNDERSCORE(_) IN PLACE OF A SPACE-- EX: I_AM_AN_INDIAN\n");
	printf("ENTER CLASS NAME::");
	gets(cname);
	new_node=(struct classinfo*)malloc(sizeof(struct classinfo));
	strcpy(new_node->classname,cname);
		printf("\n");
			printf("\n");
	printf("ENTER BRANCH NAME::");
	gets(bname);
	strcpy(new_node->branchname,bname);
do
{
	printf("\n");
printf("		-------ENTER THE TODAY ACCURATE DATE-------\n");
printf("\n");
do{
printf("ENTER YEAR::");
scanf("%d",&tyear);
}while(tyear<65&&tyear>122);
do{
printf("ENTER VALID MONTH::");
scanf("%d",&tmonth);
}while(tmonth>12||tmonth<1);
do
{
	if(tmonth==2&&tyear%4==0)
	{
		do{
	printf("ENTER VALID DATE::");
	scanf("%d",&tdate);
		}while(tdate>29||tdate<1);
	}
	else if(tmonth==2)
	{
		do{
	printf("ENTER VALID DATE::");
	scanf("%d",&tdate);
		}while(tdate>28||tdate<1);
	}
	else if(tmonth==1||tmonth==3||tmonth==5||tmonth==7||tmonth==8||tmonth==10||tmonth==12)
	{
			do{
	printf("ENTER VALID DATE::");
	scanf("%d",&tdate);
		}while(tdate>31||tdate<1);
	}
	else
	{
		do{
		printf("ENTER VALID DATE::");
	scanf("%d",&tdate);
	getchar();
		}while(tdate>30||tdate<1);
	}
}while(tdate<1||tdate>31);
printf("\n");
printf("-----------YOU ARE ALLOWED TO ENTER AFTER %d ONLY-----------\n",tyear-1);
printf("	------ENTER THE DATE OF THE STATUS------\n");
printf("\n");
do{
printf("ENTER YEAR::");
scanf("%d",&year);
}while(tyear<65&&tyear>122);
do{
printf("ENTER VALID MONTH::");
scanf("%d",&month);
}while(month>12||month<1);
do
{
	if(month==2&&year%4==0)
	{
		do{
	printf("ENTER VALID DATE::");
	scanf("%d",&date);
		}while(date>29||date<1);
	}
	else if(month==2)
	{
		do{
	printf("ENTER VALID DATE::");
	scanf("%d",&date);
		}while(date>28||date<1);
	}
	else if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
	{
			do{
	printf("ENTER VALID DATE::");
	scanf("%d",&date);
		}while(date>31||date<1);
	}
	else
	{
		do{
		printf("ENTER VALID DATE::");
	scanf("%d",&date);
	getchar();
		}while(date>30||date<1);
	}
}while(date<1||date>31);
if((tyear-year==0||tyear-year==1)&&month<=tmonth&&date<=tdate)
{
	 new_node->date=date;
	 new_node->month=month;
	 new_node->year=year;
}
else{
	printf("\n");
	printf("			WRONGLY ENTERED DATE!! PLEASE TRY AGAIN\n");
	printf("\n");
    }
}while(((year>tyear)||((year>=tyear)&&(month>tmonth)))||((year>=tyear)&&(month>=tmonth)&&(date>tdate))&&((tyear-year!=1)||(tyear-year!=0)));
	printf("\n");
			printf("\n");
printf("	ENTER UNDERSCORE(_) IN PLACE OF A SPACE-- EX: I_AM_AN_INDIAN\n");			
printf("ENTER THE INFORMATION OF THE CLASS - %s  OF BRANCH - %s::\n",cname,bname);
gets(status);
strcpy(new_node->status,status);

	if(classinfostart==NULL){
		new_node->next=NULL;
		classinfostart=new_node;
	}
	else {
		c=classinfostart;
		while(c->next!=NULL){
			c=c->next;
		}
		c->next=new_node;
		new_node->next=NULL;
	}
	
	return classinfostart;
}
struct campusinfo* campusinformation(struct campusinfo* campusinfostart )
{
struct campusinfo *new_node,*campus;
char act[100];
	printf("\n");
			printf("\n");
printf("	ENTER UNDERSCORE(_) IN PLACE OF A SPACE-- EX: I_AM_AN_INDIAN\n");
printf("ENTER CAMPUS TOPIC::");
gets(act);
	new_node=(struct campusinfo*)malloc(sizeof(struct campusinfo));
	strcpy(new_node->activity,act);
	if(campusinfostart==NULL){
		new_node->next=NULL;
		campusinfostart=new_node;
	}
	else {
		campus=campusinfostart;
		while(campus->next!=NULL){
			campus=campus->next;
		}
		campus->next=new_node;
		new_node->next=NULL;
	}
	
	return campusinfostart;
}
	void menu3(void)
				{
			printf("		  		 1.PLACEMENT INFORMATION\n");
			printf("		  		 2.INTERNSHIP INFORMATION\n");
			printf("		   	   	 3.PROJECT INFORMATION\n");
			printf("		   		 4.CLASS INFORMATION\n");
			printf("		  		 5.CAMPUS & ACTIVITY INFORMATION\n");
			printf("		  		 6.EXIT\n");
			printf("\n");
			printf("-------------------------------------------------------------------------\n");
			printf("ENTER YOUR CHOICE TO KNOW THE INFO::");
			scanf("%d",&c1);
			getchar();
			switch(c1)
			{
				case 1:
						{
					printf("		1.SEARCH BY SALARY\n");
					printf("		2.SEARCH BY COMPANY\n");
					printf("		3.DISPLAY WHOLE INFORMATION\n");
					scanf("%d",&f);
					getchar();
					switch(f)
					{
						
						case 1:
								placementstart=placementsearchbysalary(placementstart);
								menu3();
							break;
							case 2:
									placementstart=placementsearchbycompany(placementstart);
								menu3();
								break;
								case 3:
										placementstart=placementdisplay(placementstart);
										menu3();
									break;
									default:
										printf("INCORRECT CHOICE! TRY AGAIN\n");
										menu3();
										break;
					}
					}
					break;
				case 2:
						{
					printf("		1.SEARCH BY STIPEND\n");
					printf("		2.SEARCH BY COMPANY\n");
					printf("		3.DISPLAY WHOLE INFORMATION\n");
					scanf("%d",&g);
					getchar();
					switch(g)
					{
						
						case 1:
								internshipstart=internshipsearchbystipend(internshipstart);
								menu3();
							break;
							case 2:
							   	internshipstart=internshipsearchbycompany(internshipstart);
								menu3();
								break;
								case 3:
										internshipstart=internshipdisplay(internshipstart);
										menu3();
									break;
									default:
										printf("INCORRECT CHOICE! TRY AGAIN\n");
										menu3();
										break;
					}
					
						}
					break;
				case 3:
						{
					printf("		1.SEARCH BY BRANCH\n");
					printf("		2.DISPLAY WHOLE INFORMATION\n");
					scanf("%d",&h);
					getchar();
					switch(h)
					{
						
						case 1:
								projectstart=projectsearchbybranch(projectstart);
								menu3();
							break;
								case 2:
									projectstart=projectdisplay(projectstart);
									menu3();
									break;
									default:
										printf("INCORRECT CHOICE! TRY AGAIN\n");
								        menu3();
										break;
					}
						}
				
					break;
				case 4:
						{
					printf("		1.SEARCH BY CLASS\n");
					printf("		2.DISPLAY WHOLE INFORMATION\n");
					scanf("%d",&i1);
					getchar();
					switch(i1)
					{
						
						case 1:
							classinfostart=classinfosearchbyclass(classinfostart);
								menu3();
							break;
							case 2:
								classinfostart=classdisplay(classinfostart);
								menu3();
								break;
									default:
										printf("INCORRECT CHOICE! TRY AGAIN\n");
										menu3();
										break;
					}
						}
					
					break;
				case 5:
					campusinfostart=campusdisplay(campusinfostart);
					break;	
					case 6:
					menu();
					break;
				}
			}
				void menu2(void)
		{
		printf("			   1.KNOW THE INFORMATION\n");
		printf("			   2.UPDATE THE INFORMATION\n");
		printf("			   3.EXIT\n");
		printf("\n");
		printf("-------------------------------------------------------------------------\n");
		scanf("%d",&b);
		getchar();
		}
		struct placement* placementdisplay(struct placement *placementstart)
		{
		struct placement *p;
		p=placementstart;
		if(p==NULL)
		{
			printf("			THERE IS NOTHING \n");
		}
		else
		{
		while (p!=NULL)
		{	
		printf("COMPANY NAME   ::");
		puts(p->company_name);
			printf("\n");
		printf("DESCRIPTION    ::");
		puts(p->description);
		printf("\n");
		printf("SALARY		   ::%f\n",p->salary);
		printf("\n");
		printf("SKILL REQ	   ::");
		puts(p->skill);
		printf("\n");
		printf("PLACEMENTS REQ ::%d\n",p->placements_req);
		p=p->next;
		printf("\n");
		printf("\n");
		}
		}
		return placementstart;		
		}
	struct internship* internshipdisplay(struct internship *internshipstart)
		{
		struct internship *i;
		i=internshipstart;
		if(i==NULL)
		{
			printf("			THERE IS NOTHING \n");
		}
		else
		{
		while (i!=NULL)
		{	
		printf("COMPANY NAME   :: %s\n",i->company_name);
		printf("\n");
		printf("DESCRIPTION    :: %s\n",i->description);
		printf("\n");
		printf("STIPEND		   :: %f\n",i->stipend);
		printf("\n");
		printf("SKILL REQ	   :: %s\n",i->skill);
		printf("\n");
		printf("DURATION	   :: %s\n",i->duration);
		i=i->next;
		printf("\n");
		printf("\n");
		}
		}
		return internshipstart;		
		}
		struct project* projectdisplay(struct project *projectstart)
		{
		struct project *pro;
		pro=projectstart;
		if(pro==NULL)
		{
			printf("			THERE IS NOTHING \n");
		}
		else
		{
		while (pro!=NULL)
		{	
		printf("PROJECT NAME   :: %s\n",pro->project_name);
		printf("\n");
		printf("DESCRIPTION    :: %s\n",pro->description);
		printf("\n");
		printf("FLATFORM	   :: %s\n",pro->platform);
		printf("\n");
		printf("ADVANTAGES	   :: %s\n",pro->advantages);
		printf("\n");
		printf("LIMITATIONS	   :: %s\n",pro->limitations);
		printf("\n");
		printf("PROBLEMS FACED :: %s\n",pro->problems);
		printf("\n");
		printf("BELONGS TO	   :: %s\n",pro->branch);
		printf("\n");
		printf("PROJECT DONE BY:: %s\n",pro->doneby);
		pro=pro->next;
		printf("\n");
		printf("\n");
		}
		}
		return projectstart;		
		}
		struct classinfo* classdisplay(struct classinfo *classinfostart)
		{
		struct classinfo *c;
		c=classinfostart;
		if(c==NULL)
		{
			printf("			THERE IS NOTHING \n");
		}
		else
		{
		while (c!=NULL)
		{	
		printf("ON DATE %d/%d/%d\n",c->date,c->month,c->year);
		printf("\n");
		printf("CLASS NAME       :: %s\n",c->classname);
		printf("\n");
		printf("BRANCH NAME      :: %s\n",c->branchname);
		printf("\n");
		printf("INFORMATION	     :: %s\n",c->status);
		c=c->next;
		printf("\n");
		printf("\n");
		}
		}
		return classinfostart;		
		}
		struct campusinfo* campusdisplay(struct campusinfo *campusinfostart)
		{
		struct campusinfo *campus;
		campus=campusinfostart;
		if(campus==NULL)
		{
			printf("			THERE IS NOTHING \n");
		}
		else
		{
		while (campus!=NULL)
		{	
			printf("\n");
		printf("CAMPUS TOPIC    :: %s\n",campus->activity);
		campus=campus->next;
		printf("\n");
		printf("\n");
		}
		}
		return campusinfostart;		
		}
void placementupdate(struct placement* placementstart)
{
	struct placement *p=placementstart;
	FILE *fp;
	fp=fopen("placement.txt","a");
	if(fp==NULL)
	{
		printf("File couldn't be opened.\n");
		exit(1);
	}
	if(p==NULL)
	{
		printf("There is nothing to be updated in placement info.\n");
	}
	else
	{
		while(p!=NULL)
		{
			fprintf(fp,"%s\t\t%s\t\t%s\t\t%f\t\t%d\n",p->company_name,p->description,p->skill,p->salary,p->placements_req);
			p=p->next;
		}
	}fclose(fp);
	}
void internshipupdate(struct internship* internshipstart)
{
	struct internship *i=internshipstart;
	FILE *fp;
	fp=fopen("internship.txt","a");
	if(fp==NULL)
	{
		printf("File couldn't be opened.\n");
		exit(1);
	}
	if(i==NULL)
	{
		printf("There is nothing to be updated internship info.\n");
	}
	else
	{
		while(i!=NULL)
		{
			fprintf(fp,"%s\t\t%s\t\t%s\t\t%f\t\t%s\n",i->company_name,i->description,i->skill,i->stipend,i->duration);
			i=i->next;
		}
	}fclose(fp);
	}
void projectupdate(struct project* projectstart)
{
	struct project *pro=projectstart;
	FILE *fp;
	fp=fopen("project.txt","a");
	if(fp==NULL)
	{
		printf("File couldn't be opened.\n");
		exit(1);
	}
	if(pro==NULL)
	{
		printf("There is nothing to be updated in project info.\n");
	}
	else
	{
		while(pro!=NULL)
		{
			fprintf(fp,"%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n",pro->project_name,pro->description,pro->platform,pro->advantages,pro->limitations,pro->branch,pro->problems,pro->doneby);
			pro=pro->next;
		}
	}fclose(fp);
	}
void classinfoupdate(struct classinfo* classinfostart)
{
	struct classinfo *c=classinfostart;
	FILE *fp;
	fp=fopen("classinfo.txt","a");
	if(fp==NULL)
	{
		printf("File couldn't be opened.\n");
		exit(1);
	}
	if(c==NULL)
	{
		printf("There is nothing to be updated in class info.\n");
	}
	else
	{
		while(c!=NULL)
		{
			fprintf(fp,"%s\t\t%s\t\t%d\t\t%d\t\t%d\n",c->classname,c->branchname,c->year,c->month,c->date);
			c=c->next;
		}
	}fclose(fp);
	}
void campusinfoupdate(struct campusinfo* campusinfostart)
{
	struct campusinfo *campus=campusinfostart;
	FILE *fp;
	fp=fopen("campusinfo.txt","a");
	if(fp==NULL)
	{
		printf("File couldn't be opened.\n");
		exit(1);
	}
	if(campus==NULL)
	{
		printf("There is nothing to be updated in campus info.\n");
	}
	else
	{
		while(campus!=NULL)
		{
			fprintf(fp,"%s\n",campus->activity);
			campus=campus->next;
		}
	}fclose(fp);
	}
	
struct placement *placementretrieve(struct placement *placementstart)
{
	struct placement *p;
	FILE *fp;
	fp=fopen("placement.txt","r");
	if(fp==NULL)
	{
		printf("Placement File couldn't be opened.\n");
		exit(1);
	}
	printf("    PLACEMENT");
	p=(struct placement *)malloc(sizeof(struct placement *));
	while(fscanf(fp,"%s\t\t%s\t\t%s\t\t%f\t\t%d\n",p->company_name,p->description,p->skill,&p->salary,&p->placements_req)!=EOF)
{
		placementstart=link_form_placement(p,placementstart);
		p=(struct placement *)malloc(sizeof(struct placement *));
}
return placementstart;
fclose(fp);
}
struct placement *link_form_placement(struct placement *p,struct placement *placementstart)
{
	struct placement *preptr1=placementstart;
	if(placementstart==NULL)
	{
		placementstart=p;
		p->next=NULL;
	}
	else
	{
		while(preptr1->next!=NULL)
		preptr1=preptr1->next;
		preptr1->next=p;
		p->next=NULL;
	}
	return placementstart;
}
struct internship *internshipretrieve(struct internship *internshipstart)
{
	struct internship *i;
	FILE *fp;
	fp=fopen("internship.txt","r");
	if(fp==NULL)
	{
		printf("File couldn't be opened.\n");
		exit(1);
	}
	printf("--INTERNSHIP");
	i=(struct internship *)malloc(sizeof(struct internship *));
	while(fscanf(fp,"%s\t\t%s\t\t%s\t\t%f\t\t%s\n",i->company_name,i->description,i->skill,&i->stipend,i->duration)!=EOF)
{
		internshipstart=link_form_internship(i,internshipstart);
		i=(struct internship *)malloc(sizeof(struct internship *));
}
return internshipstart;
fclose(fp);
}
struct internship *link_form_internship(struct internship *i,struct internship *internshipstart)
{
	struct internship *preptr2=internshipstart;
	if(internshipstart==NULL)
	{
		internshipstart=i;
		i->next=NULL;
	}
	else
	{
		while(preptr2->next!=NULL)
		preptr2=preptr2->next;
		preptr2->next=i;
		i->next=NULL;
	}
	return internshipstart;
}
struct project *projectretrieve(struct project *projectstart)
{
	struct project *pro;
	FILE *fp;
	fp=fopen("project.txt","r");
	if(fp==NULL)
	{
		printf("File couldn't be opened.\n");
		exit(1);
	}
	printf("--PROJECT");
	pro=(struct project *)malloc(sizeof(struct project*));
	while(fscanf(fp,"%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n",pro->project_name,pro->description,pro->platform,pro->advantages,pro->limitations,pro->branch,pro->problems,pro->doneby)!=EOF)
{
		projectstart=link_form_project(pro,projectstart);
		pro=(struct project *)malloc(sizeof(struct project *));
}
return projectstart;
fclose(fp);
}
struct project *link_form_project(struct project*pro,struct project *projectstart)
{
	struct project *preptr3=projectstart;
	if(projectstart==NULL)
	{
		projectstart=pro;
		pro->next=NULL;
	}
	else
	{
		while(preptr3->next!=NULL)
		preptr3=preptr3->next;
		preptr3->next=pro;
		pro->next=NULL;
	}
	return projectstart;
}
struct classinfo *classinforetrieve(struct classinfo *classinfostart)
{
	struct classinfo *c;
	FILE *fp;
	fp=fopen("classinfo.txt","r");
	if(fp==NULL)
	{
		printf("File couldn't be opened.\n");
		exit(1);
	}
	printf("--CLASSINFO");
	c=(struct classinfo *)malloc(sizeof(struct classinfo*));
	while(fscanf(fp,"%s\t\t%s\t\t%d\t\t%d\t\t%d\n",c->classname,c->branchname,&c->year,&c->month,&c->date)!=EOF)
{
		classinfostart=link_form_classinfo(c,classinfostart);
		c=(struct classinfo *)malloc(sizeof(struct classinfo*));
}
return classinfostart;
fclose(fp);
}
struct classinfo *link_form_classinfo(struct classinfo*c,struct classinfo *classinfostart)
{
	struct classinfo *preptr4=classinfostart;
	if(classinfostart==NULL)
	{
		classinfostart=c;
		c->next=NULL;
	}
	else
	{
		while(preptr4->next!=NULL)
		preptr4=preptr4->next;
		preptr4->next=c;
		c->next=NULL;
	}
	return classinfostart;
}
struct campusinfo *campusinforetrieve(struct campusinfo *campusinfostart)
{
	struct campusinfo *campus;
	FILE *fp;
	fp=fopen("campusinfo.txt","r");
	if(fp==NULL)
	{
		printf("File couldn't be opened.\n");
		exit(1);
	}
	printf("--CAMPUSINFO DATAS ARE RETRIVED");
	campus=(struct campusinfo *)malloc(sizeof(struct campusinfo*));
	while(fscanf(fp,"%s\n",campus->activity)!=EOF)
{
		campusinfostart=link_form_campusinfo(campus,campusinfostart);
		campus=(struct campusinfo *)malloc(sizeof(struct campusinfo*));
}
return campusinfostart;
fclose(fp);
}
struct campusinfo *link_form_campusinfo(struct campusinfo*campus,struct campusinfo *campusinfostart)
{
	struct campusinfo *preptr5=campusinfostart;
	if(campusinfostart==NULL)
	{
		campusinfostart=campus;
		campus->next=NULL;
	}
	else
	{
		while(preptr5->next!=NULL)
		preptr5=preptr5->next;
		preptr5->next=campus;
		campus->next=NULL;
	}
	return campusinfostart;
}
struct placement* placementsearchbysalary(struct placement* placementstart)
{
	int dcount=0;
	struct placement *p;
	p=placementstart;
	float sal;
	printf("ENTER SALARY::");
	scanf("%f",&sal);
	printf("\n");
while(p!=NULL)
{
	if(p->salary==sal)
		{
			dcount++;
				printf("COMPANY NAME   ::");
		puts(p->company_name);
			printf("\n");
		printf("DESCRIPTION    ::");
		puts(p->description);
		printf("\n");
		printf("SALARY		   ::%f\n",p->salary);
		printf("\n");
		printf("SKILL REQ	   ::");
		puts(p->skill);
		printf("\n");
		printf("PLACEMENTS REQ ::%d\n",p->placements_req);
		p=p->next;
		printf("\n");
		printf("\n");

		}
		p=p->next;
	}
if(dcount==0)
printf("\nNO PLACEMENTS ON SALARY %f\n",sal);
	return placementstart;
}
struct placement* placementsearchbycompany(struct placement* placementstart)
{
	int dcount=0;
	struct placement *p;
	p=placementstart;
	char company[30];
	printf("ENTER COMPANY NAME::");
	gets(company);
	printf("\n");
while(p!=NULL)
{
	if(strcmp(p->company_name,company)==0)
		{
			dcount++;
				printf("COMPANY NAME   ::");
		puts(p->company_name);
			printf("\n");
		printf("DESCRIPTION    ::");
		puts(p->description);
		printf("\n");
		printf("SALARY		   ::%f\n",p->salary);
		printf("\n");
		printf("SKILL REQ	   ::");
		puts(p->skill);
		printf("\n");
		printf("PLACEMENTS REQ ::%d\n",p->placements_req);
		p=p->next;
		printf("\n");
		printf("\n");

		}
		p=p->next;
}
if(dcount==0)
printf("\nNO PLACEMENTS ON THE NAME %s\n",company);
	return placementstart;
}
struct internship* internshipsearchbycompany(struct internship* internshipstart)
{
	int dcount=0;
	struct internship *i;
	i=internshipstart;
	char company[20];
	printf("ENTER COMPANY::");
	gets(company);
	printf("\n");
while(i!=NULL)
{
	if(strcmp(i->company_name,company)==0)
		{
			dcount++;
		printf("COMPANY NAME   :: %s\n",i->company_name);
		printf("\n");
		printf("DESCRIPTION    :: %s\n",i->description);
		printf("\n");
		printf("STIPEND		   :: %f\n",i->stipend);
		printf("\n");
		printf("SKILL REQ	   :: %s\n",i->skill);
		printf("\n");
		printf("DURATION	   :: %s\n",i->duration);
		i=i->next;
		printf("\n");
		printf("\n");
		}
i=i->next;	
}
if(dcount==0)
printf("\nNO PLACEMENTS ON COMPANY %s\n",company);
	return internshipstart;
}
struct internship* internshipsearchbystipend(struct internship* internshipstart)
{
	int dcount=0;
	struct internship *i;
	i=internshipstart;
	float stipend;
	printf("ENTER STIPEND::");
	scanf("%f",&stipend);
	printf("\n");
while(i!=NULL)
{
	if(i->stipend==stipend)
		{
			dcount++;
		printf("COMPANY NAME   :: %s\n",i->company_name);
		printf("\n");
		printf("DESCRIPTION    :: %s\n",i->description);
		printf("\n");
		printf("STIPEND		   :: %f\n",i->stipend);
		printf("\n");
		printf("SKILL REQ	   :: %s\n",i->skill);
		printf("\n");
		printf("DURATION	   :: %s\n",i->duration);
		i=i->next;
		printf("\n");
		printf("\n");
		}
		i=i->next;
	}

if(dcount==0)
printf("\nNO PLACEMENTS ON STIPEND %f\n",stipend);
	return internshipstart;
}
struct project* projectsearchbybranch(struct project* projectstart)
{
	int dcount=0;
	struct project *pro;
	pro=projectstart;
	char branch[30];
	printf("ENTER BRANCH::");
	gets(branch);
	printf("\n");
while(pro!=NULL)
{
	if(strcmp(pro->branch,branch)==0)
		{
			dcount++;
		printf("PROJECT NAME   :: %s\n",pro->project_name);
		printf("\n");
		printf("DESCRIPTION    :: %s\n",pro->description);
		printf("\n");
		printf("FLATFORM	   :: %s\n",pro->platform);
		printf("\n");
		printf("ADVANTAGES	   :: %s\n",pro->advantages);
		printf("\n");
		printf("LIMITATIONS	   :: %s\n",pro->limitations);
		printf("\n");
		printf("PROBLEMS FACED :: %s\n",pro->problems);
		printf("\n");
		printf("BELONGS TO	   :: %s\n",pro->branch);
		printf("\n");
		printf("PROJECT DONE BY:: %s\n",pro->doneby);
		pro=pro->next;
		printf("\n");
		printf("\n");
		}
		pro=pro->next;
	}
if(dcount==0)
printf("\nNO PROJECTS HAVE BEEN UPDATED OF BRANCH %s\n",branch);
	return projectstart;
}
struct classinfo* classinfosearchbyclass(struct classinfo* classinfostart)
{
	int dcount=0;
	struct classinfo *c;
	c=classinfostart;
	char classname[30];
	printf("ENTER CLASS::");
	gets(classname);
	printf("\n");
while(c!=NULL)
{
	if(strcmp(c->classname,classname)==0)
		{
			dcount++;
		printf("ON DATE %d/%d/%d\n",c->date,c->month,c->year);
		printf("\n");
		printf("CLASS NAME       :: %s\n",c->classname);
		printf("\n");
		printf("BRANCH NAME      :: %s\n",c->branchname);
		printf("\n");
		printf("INFORMATION	     :: %s\n",c->status);
		c=c->next;
		printf("\n");
		printf("\n");
		}
		c=c->next;
	}
if(dcount==0)
printf("\nNO UPDATE REGARDING CLASS %s\n",classname);
	return classinfostart;
}
