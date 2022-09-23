#include <stdio.h>
#include<stdlib.h>
#include <time.h>
int productNB = 0;
int counter = 0;
int counter1 = 0;
typedef struct{

char nom[14];
int qty;
float price;
float price_TTC;

}infos;
typedef struct{

int id;
infos inf;

}products;
typedef struct{

int day;
int mounth;
int year;

}operation_date;
typedef struct{


char name[20];
int qty;
float price;
float Total_TTC;
operation_date da;

}informations;
typedef struct{ ///sales

int id;
informations info;

}sales;
typedef struct{

int day;
int mounth;
int year;

}operation1_date;
typedef struct{


char name[20];
int qty;
float price;
float Total_TTC;
operation_date datee;

}informations1;
typedef struct{ ///buy

int id;
informations1 infor;

}buuy;



products s[100];
sales t[100];
buuy t1[100];
int choice;
char check[90];
					// function that add products
void addproduct(){

						int n;

						printf("please enter number of products you want to add: ");
						scanf("%d", &n);



						printf("please enter products infos: ");
						int box = productNB;
						 for(int i=box; i< box + n; i++){

							printf("\n please enter information of products %d: \n", i+1);
                            night:
						    printf("please enter code of product:");
						    scanf(" %d", &s[i].id);
						    fflush(stdin);
						    for(int j=0 ;j<productNB;j++)
							if(s[i].id == s[j].id){
                            printf("code already existed\n");
                            goto night;
							}


							printf("please enter name of product: ");
						    scanf("%s",&s[i].inf.nom);

						    printf("please enter Quantity of product:");
						    scanf("%d",&s[i].inf.qty);
						    fflush(stdin);

						    printf("please enter price of product: ");
						    scanf("%f",&s[i].inf.price);
						    fflush(stdin);

						    s[i].inf.price_TTC = s[i].inf.price*1.15;


						    productNB++;

						    printf("\n--------------------------product was saved-------------------------\n");
						 }

						 printf("---------------------your new list-----------------------: \n");
                        for (int j=0; j<productNB;j++)
                        printf("\n%d \t %s \t %d \t %f \t %f \n",s[j].id,s[j].inf.nom,s[j].inf.qty,s[j].inf.price,s[j].inf.price_TTC);



						}
                    //function that display products
void view_productlist(){

					for(int i=0 ; i<productNB;i++)
					printf("%d    \t %s  \t %d \t %f  \t %f \n" ,  s[i].id,s[i].inf.nom,s[i].inf.qty,s[i].inf.price,s[i].inf.price_TTC);
				}
                    //function that delete products
void delete_product(){
int del_code;
int index = -1;
int n;
printf("************************delete products************************\n\n ");
printf("enter number of products you want to delete: ");
scanf("%d", &n);

for(int i=0; i<n; i++){
printf("enter the ID of the product you want to delete n %d: ",i+1);
    scanf("%d",&del_code);fflush(stdin);
 for (int j=0; j<productNB;j++){

    if(s[j].id == del_code){
            index=j;
    }
        if(index != -1){
    for(int j=index; j<productNB;j++){
        s[j]= s[j+1];
        productNB--;
        }
}

    printf("..................your product was deleted..................\n\n");
    }

}

}
                    //function that display descending by price
void Descending_by_price(){

for(int j=0; j<productNB-1;j++){
    for(int i=j+1; i<productNB;i++){
        if(s[j].inf.price < s[i].inf.price){
            products temp = s[i];
                     s[i] = s[j];
                     s[j] = temp;
    }
    }
}
printf("your new list :: \n\n");
printf("Code \t Name \t Qty \t Price HT \t  Price TTC");
for (int x = 0; x < productNB;x++)
    printf("\n%d \t %s \t %d \t %f \t %f\n",s[x].id,s[x].inf.nom,s[x].inf.qty,s[x].inf.price,s[x].inf.price_TTC);

}
                    //function that display ascending by name
void Ascending_by_name(){

for(int j=0; j<productNB-1;j++){
    for(int i=j+1; i<productNB;i++){
        if(strcmp(s[j].inf.nom , s[i].inf.nom)==1){
            products temp = s[i];
                     s[i] = s[j];
                     s[j] = temp;
        }
    }
}
printf("this is your new list: \n\n");
printf("Code\tNom\tQte\tPrice HT\t  Price TTC");
for (int z=0; z<productNB;z++)
    printf("\n%d \t %s \t %d \t %f \t %f\n",s[z].id,s[z].inf.nom,s[z].inf.qty,s[z].inf.price,s[z].inf.price_TTC);

}
                     //function that saves sales
void save_sales(){

int id_code ,qty_sales ,index;
int n;
printf("*****************save sales operations***************\n\n ");
printf("please type number of products: ");
scanf("%d", &n);

for(int i=0; i<n; i++){
    printf("please enter ID of product %d: ",i+1);
    scanf("%d",&id_code);fflush(stdin);
    printf("please enter quantity you want to subtract: ");
    scanf("%d",&qty_sales);fflush(stdin);

        for(int a = 0; a <productNB;a++)
            if(s[a].id == id_code){
                index = a;
            }
        s[index].inf.qty -= qty_sales;
        t[counter].id = s[index].id;
        strcmp(t[counter].info.name,s[index].inf.nom);
        t[counter].info.qty = qty_sales;
        t[counter].info.price = s[index].inf.price;
        t[counter].info.Total_TTC = s[index].inf.price*qty_sales*1.15;
        time_t h = time(NULL);
        struct tm timee = *localtime(&h);
        t[counter].info.da.day = timee.tm_mday;
        t[counter].info.da.mounth = timee.tm_mon + 1;
        t[counter].info.da.year = timee.tm_year + 1900;
        counter++;



    printf("..................operation was saved..................\n\n");
}
}
                    //function that saves buy products
void save_buys(){
int id_code1 ,qty_buy1 ,index1;
int n;
printf("*****************save buy operations***************\n\n ");
printf("please type number of products: ");
scanf("%d", &n);

for(int i=0; i<n; i++){
    printf("please enter ID of product number %d: ",i+1);
    scanf("%d",&id_code1);fflush(stdin);
    printf("please enter quantity you want to add: ");
    scanf("%d",&qty_buy1);fflush(stdin);

        for(int a = 0; a <productNB;a++)
            if(s[a].id == id_code1){
                index1 = a;
            }
        s[index1].inf.qty += qty_buy1;
        t1[counter1].id = s[index1].id;
        strcmp(t1[counter1].infor.name,s[index1].inf.nom);
        t1[counter1].infor.qty = qty_buy1;
        t1[counter1].infor.price = s[index1].inf.price;
        t1[counter1].infor.Total_TTC = s[index1].inf.price*qty_buy1*1.15;
        time_t h = time(NULL);
        struct tm time2 = *localtime(&h);
        t1[counter].infor.datee.day = time2.tm_mday;
        t1[counter].infor.datee.mounth = time2.tm_mon + 1;
        t1[counter].infor.datee.year = time2.tm_year + 1900;
        counter++;
        printf("..................operation was saved..................\n\n");
}
}
                    //function that alert you when stock less than 3
void stock_alert(){

    printf("welcome to your stock alert");
    for(int i=0;i<productNB;i++){
        if(s[i].inf.qty <3)
        printf("\n%d \t %s \t %d \t %f \t %f\n",s[i].id,s[i].inf.nom,s[i].inf.qty,s[i].inf.price,s[i].inf.price_TTC);
        }

}

void stats_sales(){

    float total_daily_price = 0;
    time_t h2 = time(NULL);
    struct tm tm = *localtime(&h2);
    //daily total earned
    for(int i=0; i<counter; i++){
        if(t[i].info.da.day == tm.tm_mday && t[i].info.da.mounth == tm.tm_mon + 1 && (t[i].info.da.year == tm.tm_year + 1900)){
            total_daily_price += t[i].info.Total_TTC;}
    }
    //average price
    float average_price;
    average_price = total_daily_price/counter;

    float max_p;
    int index = 0;
    max_p= t[0].info.Total_TTC;
    for (int i=1 ; i<counter ; i++){
        if(t[i].info.da.day==tm.tm_mday && t[i].info.da.mounth==tm.tm_mon + 1 && t[i].info.da.year==tm.tm_year + 1900){
            if(t[i].info.Total_TTC > max_p){
                max_p = t[i].info.Total_TTC;
                index = i;
            }
        }

    }
    float min_p;
    int index1 = 0;
    min_p = t[0].info.Total_TTC;

    for (int i=1 ; i<counter ; i++){
        if(t[i].info.da.day==tm.tm_mday && t[i].info.da.mounth==tm.tm_mon + 1 && t[i].info.da.year==tm.tm_year + 1900){
            if(t[i].info.Total_TTC < min_p){
                min_p = t[i].info.Total_TTC;
                index1 = i;
            }
        }

    }

    printf(" total daily sales: %f Dh\n\n average daily price: %f Dh\n\n", total_daily_price,average_price);
    printf("The product with the highest total sales:\n");

    printf("\n%d\t%s\t%f Dh\t%d/%d/%d\n\n",t[index].id,t[index].info.name,t[index].info.Total_TTC,t[index].info.da.day,t[index].info.da.mounth,t[index].info.da.year);
    printf("The product with the lowest total sales:\n");

    printf("\n%d\t%s\t%f Dh\t%d/%d/%d\n\n",t[index1].id,t[index1].info.name,t[index1].info.Total_TTC,t[index1].info.da.day,t[index1].info.da.mounth,t[index1].info.da.year);
}




int main () {
	menu:
    menu1:

	printf("-----------------------------------------<welcome to your system>-------------------------------------------\n\n");
    printf("------------------------------------<pharmacy management application>-------------------------------------------\n");
	begin:
    list:
    menu4:
	printf("----------------------------------------please choose an operation-------------------------------------------\n\n");


                                printf("#-------------------------------#1 ADD NEW PRODUCTS      #-----------------------------#\n\n"
                                       "#-------------------------------#2 DISPLAY PRODUCTS      #-----------------------------#\n\n"
                                       "#-------------------------------#3 DELETE PRODUCTS       #-----------------------------#\n\n"
                                       "#-------------------------------#4 STOCK MANAGEMENT      #-----------------------------#\n\n"
                                       "#-------------------------------#5 SEARCH BY ID && QTY   #-----------------------------#\n\n"
                                       "#-------------------------------#6 SALES STATISTICS      #-----------------------------#\n\n"
                                       "#-------------------------------#7 LEAVE THE APPLICATION #-----------------------------#\n\n");

	scanf("%d",&choice);


	while ((choice < 1 || choice > 7) ||  (sscanf(check, "%d", &choice)==1)){
        fgets(check, 90, stdin);
        system("cls");
        printf("invalid entry ! \n please enter a valid choice.\n ");
        goto begin;
        }



	switch(choice){

		case 1:
			addproduct();
           printf("\n  1. Back to main menu \n");
            scanf("%d",&choice);
            system("cls");
						switch(choice){


						case 1:
								goto menu;

									}
		case 2:
		    list1:
            list3:
            printf("\n1. products list\n");
            printf("\n2. descending by price\n");
            printf("\n3. ascending by name\n");
            printf("\n4. Back to main menu \n");
            scanf("%d", &choice);
            system("cls");



						switch(choice){

							case 1:
							    system("cls");
                                view_productlist();
                                goto list;
                                break;
							case 2:
                                    Descending_by_price();
                                    printf("\n  1. Back to main menu \n");
                                    scanf("%d",&choice);
                                    system("cls");
                                    goto list1;


                            case 3:
                                    Ascending_by_name();
                                    printf("\n  1. Back to main menu \n");
                                    scanf("%d",&choice);
                                    system("cls");
                                    goto list3;
                            case 4:

                                goto menu;

						}

        case 3:
            delete_product();
            printf("\n  1. Back to main menu \n");
            scanf("%d",&choice);
            system("cls");
            goto menu;

        case 4:
           //stock generator
           stock:
            printf("\n1. sales registery\n");
            printf("\n2. purcheses registery\n");
            printf("\n3. stock alert\n");
            printf("\n4. Back to main menu \n");
            scanf("%d", &choice);
            system("cls");

                        switch(choice){
                            case 1:
                                        save_sales();
                                        printf("\n  1. Back to main menu \n");
                                        scanf("%d",&choice);
                                        system("cls");
                                        goto stock;
							case 2:
                                        save_buys();
                                        printf("\n  1. Back to main menu \n");
                                        scanf("%d",&choice);
                                        system("cls");
                                        goto stock;
                            case 3:
                                        stock_alert();
                                        printf("\n  1. Back to main menu \n");
                                        scanf("%d",&choice);
                                        system("cls");
                            default:
                                        goto menu1;
                        }
        case 5:
            search:
            printf("\n1. search by qty\n");
            printf("\n2. search by ID\n");
            printf("\n3. Back to main menu \n");
            scanf("%d", &choice);
            system("cls");
                            switch(choice){
                            case 1:
                                   //search with qty
                                   printf("enter qty :");
                                    scanf("%d",&choice);
                                    int exist = 0;
                                    for(int i = 0;i < productNB;i++){
                                        if(s[i].inf.qty == choice){
                                            printf("\nCode :%d \n",s[i].id);
                                            printf("\nName :%s \n",s[i].inf.nom);
                                            printf("\nQuantity :%d \n",s[i].inf.qty);
                                            printf("\nPrice :%.2f \n",s[i].inf.price);
                                            exist = 1;
                                            break;
                                        }
                                    }
                                    if(exist == 0)
                                    {
                                        printf("quantity does not exist !! \n");
                                    }
                                        goto search;


                                case 2:
                                //search with ID
                                printf("enter ID of product :");
                                scanf("%d",&choice);
                                int exist2 = 0;
                                for(int i = 0;i < productNB;i++){
                                if(s[i].id == choice){
                                printf("\nCode :%d \n",s[i].id);
                                printf("\nName :%s \n",s[i].inf.nom);
                                printf("\nQuantity :%d \n",s[i].inf.qty);
                                printf("\nPrice :%.2f \n",s[i].inf.price);
                                exist = 1;
                                break;
                                    }
                                }
                                if(exist2 == 0)
                                {
                                printf("product does not exist !! \n");
                                }
                                goto search;

                        default :
                                    goto menu1;
                            }

        case 6:
                stats_sales();
                printf("\n  1. Back to main menu \n");
                scanf("%d",&choice);
                system("cls");
                goto menu1;
        case 7:
                printf(".....................................................................................\n"
                   "                                  ||  see you soon  ||                                  \n"
                   ".....................................................................................\n");
            system("exit");
	}

return 0;
}
