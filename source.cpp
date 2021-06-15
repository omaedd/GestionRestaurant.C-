#include<iostream>
#include<fstream>
#include<windows.h>
#include<dos.h>
#include<stdio.h>
#include<cstdlib>
#include<string>
#include<conio.h>
using namespace std;
COORD coord={0,0};
void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
int snackspr,maggipr,sdpr;
int snacksqty,maggiqty,sdqty;
void billpage();
void empjump();
void billjump();
void handlecust();
class login;
class store;

class order;
class billing;
class store
{
    public:
        string item;
        string name;
        int amt;
        int ch;
        int rate;
        int qty=0;
        void mnginvt();
        void storepageswitch();
        void price();
        void viewinvt();
        void quantity();
        void storepage()
        {
            storepageswitch();
        }
};
void store::storepageswitch()
{
    system("CLS");
    gotoxy(40,1);cout<<"RESTAURANT ROMA2";
    gotoxy(40,2);cout<<"-----------------"<<endl<<endl;
    cout<<"     VEUILLEZ METTRE A JOUR LE PRIX ET LA QUANTITE DANS"<<endl;
    cout<<"     --GERER LE STOCK ALIMENTAIRE-- AVANT DE PROCEDER"<<endl<<endl;
    cout<<"     1. GERER STOCK ALIMENTAIRE"<<endl;
    cout<<"     2. CONSULTER STOCK ALIMENTAIRE"<<endl;
    cout<<"     3. LANCER UNE COMMANDE"<<endl;
    cout<<"     4. VOIR LES ENREGISTREMENTS DE COMMANDES"<<endl;
    cout<<"     5. QUITTER"<<endl<<endl;
    cout<<"     SAISIR VOTRE CHOIX"<<endl;
    cout<<"     ";cin>>ch;
    while(ch!=1||ch!=2||ch!=3)
    {
        switch(ch)
        {
            case 1:
                mnginvt();
                break;
            case 2:
                viewinvt();
                break;
            case 3:
                handlecust();
                break;
            case 4:
                billjump();
                break;
            case 5:
                exit(0);
            default:
                cout<<endl<<"    CHOIX INVALIDE"<<endl<<endl;
                cout<<"     SAISIR VOTRE CHOIX"<<endl<<endl;
                cout<<"     ";cin>>ch;
        }
    }
}
void store::mnginvt()
{
    system("CLS");
    gotoxy(40,1);cout<<"RESTAURANT ROMA2";
    gotoxy(40,2);cout<<"-----------------"<<endl<<endl;
    cout<<"     1. MODIFIER LE PRIX"<<endl;
    cout<<"     2. SAISIR LA QUANTITE"<<endl<<endl;
    cout<<"     SAISIR VOTRE CHOIX"<<endl;
    cout<<"     ";cin>>ch;
    while(ch!=1||ch!=2)
    {
        switch(ch)
        {
            case 1:
                price();
                break;
            case 2:
                quantity();
                break;
            default:
                cout<<endl<<"    CHOIX INVALIDE"<<endl<<endl;
                cout<<"     SAISIR VOTRE CHOIX"<<endl<<endl;
                cout<<"     ";cin>>ch;
        }
    }
}
void store::price()
{
    system("CLS");
    gotoxy(40,1);cout<<"RESTAURANT ROMA2";
    gotoxy(40,2);cout<<"-----------------"<<endl<<endl;
    cout<<"     LE STOCK ALIMENTAIRE ACTUEL"<<endl;
    ifstream currprice("PRICE.txt");
    cout<<"     "<<"ELEMENT"<<" - "<<"PRIX"<<endl;
    cout<<"     ------------"<<endl;
    while(currprice>>item>>rate)
    {
        cout<<"     "<<item<<" - "<<rate<<endl;
    }
    currprice.close();
    remove("PRICE.txt");
    fstream editprice("PRICE.txt",ios::app);
    cout<<endl<<"     SAISIR LE PRIX DE SANDWICH"<<endl;
    cout<<"     ";cin>>snackspr;cout<<endl;
    editprice<<"SANDWICH"<<' '<<snackspr<<endl;
    cout<<"     SAISIR LE PRIX DU SALADE"<<endl;
    cout<<"     ";cin>>maggipr;cout<<endl;
    editprice<<"SALADE"<<' '<<maggipr<<endl;
    cout<<"     SAISIR LE PRIX DU BOISSION"<<endl;
    cout<<"     ";cin>>sdpr;cout<<endl;
    editprice<<"BOISSON"<<' '<<sdpr<<endl;;
    editprice.close();

    system("CLS");cout<<endl;
    gotoxy(40,0);cout<<"RESTAURANT ROMA2";
    gotoxy(40,2);cout<<"-----------------"<<endl<<endl;
    cout<<"     NOUVEAU STOCK ALIMENTAIRE"<<endl;
    ifstream viewprice("PRICE.txt");
    cout<<"     "<<"ELEMNET"<<" - "<<"PRIX"<<endl;
    cout<<"     ------------"<<endl;
    while(viewprice>>item>>rate)
    {
        cout<<"     "<<item<<" - "<<rate<<endl;
    }
    viewprice.close();
    cout<<endl<<"     APPUYEZ SUR UNE TOUCHE POUR CONTINUER"<<endl;
    cout<<"     ";getch();
    storepage();
}
void store::quantity()
{
    system("CLS");
    gotoxy(40,1);cout<<"RESTAURANT ROMA2";
    gotoxy(40,2);cout<<"-----------------"<<endl<<endl;
    cout<<"     LE STOCK ALIMENTAIRE ACTUEL"<<endl;
    ifstream currqty("QUANTITY.txt");
    cout<<"     "<<"ELEMENT"<<" - "<<"QUANTITE"<<endl;
    cout<<"     ---------------"<<endl;
    while(currqty>>item>>qty)
    {
        cout<<"     "<<item<<" - "<<qty<<endl;
    }
    currqty.close();
    remove("QUANTITY.txt");
    fstream editqty("QUANTITY.txt",ios::app);
    cout<<endl<<"     SAISIR LA QUANTITE DE SANDWICH"<<endl;
    cout<<"     ";cin>>snacksqty;cout<<endl;
    editqty<<"SANDWICH"<<' '<<snacksqty<<endl;
    cout<<"    SAISIR LA QUANTITE DE SALADE"<<endl;
    cout<<"     ";cin>>maggiqty;cout<<endl;
    editqty<<"SALADE"<<' '<<maggiqty<<endl;
    cout<<"     SAISIR LA QUANTITE DE BOISSON"<<endl;
    cout<<"     ";cin>>sdqty;cout<<endl;
    editqty<<"BOISSON"<<' '<<sdqty<<endl;
    editqty.close();
    system("CLS");
    gotoxy(40,1);cout<<"RESTAURANT ROMA2";
    gotoxy(40,2);cout<<"-----------------"<<endl<<endl;
    cout<<"     NOUVEL STOCK ALIMENTAIRE"<<endl;
    cout<<"     "<<"ELEMENT"<<" - "<<"QUANTITE"<<endl;
    cout<<"     --------------------"<<endl;
    ifstream viewqty("QUANTITY.txt");
    while(viewqty>>item>>qty)
    {
        cout<<"     ";cout<<item<<" - "<<qty<<endl;
    }
    viewqty.close();
    cout<<endl<<"     APPUYEZ SUR UNE TOUCHE POUR CONTINUER"<<endl;
    cout<<"     ";getch();
    storepage();
}
void store::viewinvt()
{
    system("CLS");
    gotoxy(40,1);cout<<"RESTAURANT ROMA2";
    gotoxy(40,2);cout<<"-----------------"<<endl<<endl;
    cout<<"     PRIX DES ELEMENTS DANS LE RESTAURANT"<<endl;
    cout<<"     ELEMENT - PRIX"<<endl;
    cout<<"     ------------"<<endl;
    ifstream vwpr("PRICE.txt");
    while(vwpr>>item>>rate)
    {
        cout<<"     ";cout<<item<<" - "<<rate<<endl;
    }
    vwpr.close();
    cout<<endl<<"     QUANTITE DES ELEMENTS DANS LE RESTAURANT"<<endl;
    cout<<"     ELEMENT - QUANTITE"<<endl;
    cout<<"     ---------------"<<endl;
    ifstream vwqt("QUANTITY.txt");
    while(vwqt>>item>>rate)
    {
        cout<<"     ";cout<<item<<" - "<<rate<<endl;
    }
    vwqt.close();
    cout<<endl<<"     APPUYEZ SUR UNE TOUCHE POUR CONTINUER"<<endl;
    cout<<"     ";getch();
    storepage();
}
class billing
{
    public:
        string name;
        int cost1,cost2,cost3,qty,totalcost;
        store s;
        int amt;
        char dec;
        void viewstat();
        void clearstat();
        billing()
        {
            cost1=0;
            cost2=0;
            cost3=0;
        }
        void bill1(int qty)
        {
            cost1=0;
            cost1=snackspr*qty;
        }
        void bill2(int qty)
        {
            cost2=0;
            cost2=maggipr*qty;
        }
        void bill3(int qty)
        {
            cost3=0;
            cost3=sdpr*qty;
        }
        void bill()
        {
            system("CLS");
            gotoxy(40,1);cout<<"RESTAURANT ROMA2";
            gotoxy(40,2);cout<<"-----------------"<<endl<<endl;
            totalcost=cost1+cost2+cost3;
            cout<<"     SAISIR LE NOM DU CLIENT "<<endl;
            cout<<"     ";cin>>name;cout<<endl;
            system("CLS");
            gotoxy(40,1);cout<<"RESTAURANT ROMA2";
            gotoxy(40,2);cout<<"-----------------"<<endl<<endl;
            cout<<"     FACTURE  : PAYER LE MONTANT SUIVANT "<<endl;
            cout<<"     NOM DU CLIENT : "<<name<<endl;
            cout<<"     COUT TOTAL EST : "<<totalcost<<" DH."<<endl;
            cout<<"     ------------------------------------------"<<endl;
            cout<<"     MERCI POUR LA VISITE. A BIENTOT DANS ROMA2"<<endl;
            cout<<"     ------------------------------------------"<<endl;
            fstream billmod("SALESRECORD.txt",ios::app);
            billmod<<name<<' '<<totalcost<<endl;
            billmod.close();
            cout<<endl<<"     APPUYEZ SUR UNE TOUCHE POUR CONTINUER"<<endl;
            cout<<"     ";getch();
            billpage();
        }
};
void billing::viewstat()
{
    system("CLS");
    gotoxy(40,1);cout<<"RESTAURANT ROMA2";
    gotoxy(40,2);cout<<"-----------------"<<endl<<endl;
    ifstream viewsr("SALESRECORD.txt");
    cout<<"     NOM - MONTANT"<<endl;
    cout<<"     -------------"<<endl;
    while(viewsr>>name>>amt)
    {
        cout<<"     "<<name<<" - "<<amt<<" DH."<<endl;
    }
    viewsr.close();
    cout<<endl<<"     APPUYEZ SUR UNE TOUCHE POUR CONTINUER"<<endl;
    cout<<"     ";getch();
    s.storepage();
}
void billing::clearstat()
{
    system("CLS");
    gotoxy(40,1);cout<<"RESTAURANT ROMA2";
    gotoxy(40,2);cout<<"-----------------"<<endl<<endl;
    cout<<"     VIDER L'ENREGISTREMENT DE COMMANDES [Y]"<<endl;
    cout<<"     ";cin>>dec;
    if(dec=='Y')
    {
        remove("SALESRECORD.txt");
        cout<<endl<<"     ENREGISTREMENT DE COMMANDES VIDE"<<endl;
        cout<<endl<<"     APPUYEZ SUR UNE TOUCHE POUR CONTINUER"<<endl;
        cout<<"     ";getch();
        remove("EMPLOYEE.txt");
        ifstream newsr("EMPLOYEE.txt");
        newsr.close();
        empjump();
    }
    else
    {
        cout<<endl<<"     ENREGISTREMENT DE COMMANDES NON VIDE"<<endl;
        cout<<endl<<"     APPUYEZ SUR UNE TOUCHE POUR CONTINUER"<<endl;
        cout<<"     ";getch();
        empjump();

    }
}
class order
{
    public:
        int tqty;
        string titem;
        billing b;
        int invtqty;
        string invtitem;
        char dec;
        int ch;
        int qty;
        void orderitem1();
        void orderitem2();
        void orderitem3();
        void orderpageswitch();
        void orderpage()
        {
            system("CLS");
            gotoxy(40,1);cout<<"RESTAURANT ROMA2";
            gotoxy(40,2);cout<<"-----------------"<<endl<<endl;
            cout<<"     1. SANDWICH"<<endl;
            cout<<"     2. SALADE"<<endl;
            cout<<"     3. BOISSON"<<endl;
            cout<<"     4. QUITTER"<<endl<<endl;
            cout<<"     SAISIR UN ELEMENT A COMMANDER"<<endl;
            cout<<"     ";cin>>ch;
            orderpageswitch();
        }
};
void order::orderpageswitch()
{
    while(ch!=1||ch!=2||ch!=3||ch!=4)
    {
        switch(ch)
        {
            case 1:
                orderitem1();
                break;
            case 2:
                orderitem2();
                break;
            case 3:
                orderitem3();
                break;
            case 4:
                exit(0);
                break;
            default:
                cout<<endl<<"    CHOIX INVALIDE"<<endl;
                cout<<"     SAISIR VOTRE CHOIX"<<endl;
                cout<<"     ";cin>>ch;
        }
    }
}
void order::orderitem1()
{
    cout<<"     SAISIR LA QUANTITE"<<endl;
    cout<<"     ";cin>>qty;cout<<endl;
    if(snacksqty>=qty)
    {
        snacksqty=snacksqty-qty;
        ofstream temp1("temp1.txt");
        ifstream snackorder("QUANTITY.txt");
        while(snackorder>>titem>>tqty)
        {
            if(titem!="SANDWICH")
            {
                temp1<<titem<<' '<<tqty<<endl;
            }
            else
            {
                temp1<<"SANDWICH"<<' '<<snacksqty<<endl;
            }
        }
        temp1.close();
        snackorder.close();
        remove("QUANTITY.TXT");
        rename("temp1.txt","QUANTITY.txt");
        b.bill1(qty);
        cout<<"     COMMANDER UN AUTRE ELEMENT [Y]"<<endl;
        cout<<"     ";cin>>dec;
        if(dec=='Y')
        {
            orderpage();
        }
        else
        {
            b.bill();
        }
    }
    else
    {
        cout<<endl<<"     INDISPONIBLE"<<endl;
        cout<<"     CHOISIR UN AUTRE ELEMENT"<<endl;
        cout<<endl<<"     APPUYEZ SUR UNE TOUCHE POUR CONTINUER"<<endl;
        cout<<"     ";getch();
        system("CLS");
        gotoxy(40,1);cout<<"RESTAURANT ROMA2";
        gotoxy(40,2);cout<<"-----------------"<<endl<<endl;
        ifstream orderout("QUANTITY.txt");
        cout<<"     ELEMENT - QUANTITE"<<endl;
        cout<<"     ---------------"<<endl;
        while(orderout>>invtitem>>invtqty)
        {
            cout<<"     "<<invtitem<<" - "<<invtqty<<endl;
        }
        orderout.close();
        cout<<endl<<"     APPUYEZ SUR UNE TOUCHE POUR UNE NOUVELLE COMMANDE"<<endl;
        cout<<"     ";getch();
        orderpage();
    }
}
void order::orderitem2()
{
    cout<<"     SAISIR LA QUANTITE"<<endl;
    cout<<"     ";cin>>qty;cout<<endl;
    if(maggiqty>=qty)
    {
        maggiqty=maggiqty-qty;
        ofstream temp2("temp2.txt");
        ifstream maggiorder("QUANTITY.txt");
        while(maggiorder>>titem>>tqty)
        {
            if(titem!="SALADE")
            {
                temp2<<titem<<' '<<tqty<<endl;
            }
            else
            {
                temp2<<"SALADE"<<' '<<maggiqty<<endl;
            }
        }
        temp2.close();
        maggiorder.close();
        remove("QUANTITY.TXT");
        rename("temp2.txt","QUANTITY.txt");
        b.bill2(qty);
        cout<<"     COMMANDER UN AUTRE ELEMENT [Y]"<<endl;
        cout<<"     ";cin>>dec;
        if(dec=='Y')
        {
            orderpage();
        }
        else
        {
            b.bill();
        }
    }
    else
    {
        cout<<endl<<"     NOT AVAILABLE"<<endl;
        cout<<"     SELECT ANOTHER ITEM"<<endl;
        cout<<endl<<"     APPUYEZ SUR UNE TOUCHE POUR CONTINUER"<<endl;
        cout<<"     ";getch();
        system("CLS");
        gotoxy(40,1);cout<<"RESTAURANT ROMA2";
        gotoxy(40,2);cout<<"-----------------"<<endl<<endl;
        ifstream orderout("QUANTITY.txt");
        cout<<"     ELEMENT - QUANTITE"<<endl;
        cout<<"     ---------------"<<endl;
        while(orderout>>invtitem>>invtqty)
        {
            cout<<"     "<<invtitem<<" - "<<invtqty<<endl;
        }
        orderout.close();
        cout<<endl<<"     APPUYER SUR UNE TOUCHE POUR UNE NOUVELLE COMMANDE"<<endl;
        cout<<"     ";getch();
        orderpage();
    }
}
void order::orderitem3()
{
    cout<<"     SAISIR LA QUANTITE"<<endl;
    cout<<"     ";cin>>qty;cout<<endl;
    if(sdqty>=qty)
    {
        sdqty=sdqty-qty;
        ofstream temp3("temp3.txt");
        ifstream sdorder("QUANTITY.txt");
        while(sdorder>>titem>>tqty)
        {
            if(titem!="BOISSON")
            {
                temp3<<titem<<' '<<tqty<<endl;
            }
            else
            {
                temp3<<"BOISSON"<<' '<<sdqty<<endl;
            }
        }
        temp3.close();
        sdorder.close();
        remove("QUANTITY.TXT");
        rename("temp3.txt","QUANTITY.txt");
        b.bill3(qty);
        cout<<"     COMMANDER UN AUTRE ELEMENT [Y]"<<endl;
        cout<<"     ";cin>>dec;
        if(dec=='Y')
        {
            orderpage();
        }
        else
        {
            b.bill();
        }
    }
    else
    {
        cout<<endl<<"     INDISPONIBLE"<<endl;
        cout<<"     CHOISIR UN AUTRE ELEMENT"<<endl;
        cout<<endl<<"     APPUYEZ SUR UNE TOUCHE POUR CONTINUER"<<endl;
        cout<<"     ";getch();
        system("CLS");
        gotoxy(40,1);cout<<"RESTAURANT ROMA2";
        gotoxy(40,2);cout<<"-----------------"<<endl<<endl;
        ifstream orderout("QUANTITY.txt");
        cout<<"     ELEMENT - QUANTITE"<<endl;
        cout<<"     ---------------"<<endl;
        while(orderout>>invtitem>>invtqty)
        {
            cout<<"     "<<invtitem<<" - "<<invtqty<<endl;
        }
        orderout.close();
        cout<<endl<<"     APPUYER SUR UNE TOUCHE POUR UNE NOUVELLE COMMANDE"<<endl;
        cout<<"     ";getch();
        orderpage();
    }
}
class employee
{
    public:
        int ch,age;
        char name[50];
        long int sal;
        void addemp();
        void displayemp();
        void removeemp();
        void editemp();
        void emppageswitch();
        void emppage()
        {
            system("CLS");
            gotoxy(40,1);cout<<"RESTAURANT ROMA2";
            gotoxy(40,2);cout<<"-----------------"<<endl<<endl;
            cout<<"     1. AFFICHER TOUS  LES EMPLOYES"<<endl;
            cout<<"     2. AJOUTER UN EMPLOYE"<<endl;
            cout<<"     3. SUPPRIMER UN EMPLOYE"<<endl;
            cout<<"     4. CONSULTER L'ENREGISTREMENT DE COMMANDES"<<endl;
            cout<<"     5. VIDER L'ENREGISTREMENT DE COMMANDES"<<endl;
            cout<<"     6. STOCK ALIMENTAIRE"<<endl;
            cout<<"     7. QUITTER"<<endl<<endl;
            cout<<"     SAISIR VOTRE CHOIX"<<endl;
            cout<<"     ";cin>>ch;
            emppageswitch();
        }
};
void employee::emppageswitch()
{
    while(ch!=1||ch!=2||ch!=3||ch!=4||ch!=5)
    {
        switch(ch)
        {
            case 1:
                displayemp();
                break;
            case 2:
                addemp();
                break;
            case 3:
                removeemp();
                break;
            case 4:
                {
                    billing b1;
                    b1.viewstat();
                }
                break;
            case 5:
                {
                    billing b2;
                    b2.clearstat();
                }
            case 6:
                {
                    store s;
                    s.storepage();
                }
                break;
            case 7:
                exit(0);
                break;
            default:
                cout<<endl<<"    CHOIX INVALIDE"<<endl;
                cout<<"     SAISIR VOTRE CHOIX"<<endl;
                cout<<"     ";cin>>ch;
        }
    }
}
void employee::addemp()
{
    system("CLS");
    gotoxy(40,1);cout<<"RESTAURANT ROMA2";
    gotoxy(40,2);cout<<"-----------------"<<endl<<endl;
    ofstream newemployee("EMPLOYEE.txt",ios::app);
    cout<<"     SAISIR LE NOM DE L'EMPLOYE"<<endl;
    cout<<"     ";cin>>name;
    cin.sync();
    cout<<"     SAISIR L'AGE DE L'EMPLOYE"<<endl;
    cout<<"     ";cin>>age;
    cout<<"     SAISIR LE SALAIRE DE L'EMPLOYE"<<endl;
    cout<<"     ";cin>>sal;
    newemployee<<name<<' '<<age<<' '<<sal<<endl;
    newemployee.close();
    cout<<endl<<"     EMPLOYE AJOUTE"<<endl;
    cout<<endl<<"     APPUYEZ SUR UNE TOUCHE POUR CONTINUER";
    cout<<"     ";getch();
    emppage();
}
void employee::displayemp()
{
    system("CLS");
    gotoxy(40,1);cout<<"RESTAURANT ROMA2";
    gotoxy(40,2);cout<<"-----------------"<<endl<<endl;
    ifstream employee("EMPLOYEE.txt");
    cout<<"     EMPLOYE - AGE - SALAIRE"<<endl;
    cout<<"     -----------------------"<<endl;
    while (employee>>name>>age>>sal)
    {
        cout<<"     "<<name<<" - "<<age<<" - "<<sal<<endl ;
    }
    employee.close();
    cout<<endl<<"     APPUYEZ SUR UNE TOUCHE POUR CONTINUER"<<endl;
    cout<<"     ";getch();
    emppage();
}
void employee::removeemp()
{
    system("CLS");
    gotoxy(40,1);cout<<"RESTAURANT ROMA2";
    gotoxy(40,2);cout<<"-----------------"<<endl<<endl;
    char tname[50];
    ifstream emp1("EMPLOYEE.txt");
    ofstream emp2("temp.txt");
    cout<<"     SAISIR LE NOM DE L'EMPLOYE A SUPPRIMER"<<endl;
    cout<<"     ";cin>>tname;
    while(emp1>>name>>age>>sal)
    {
        if(strcmp(name,tname)!=0)
        {
            emp2<<name<<' '<<age<<' '<<sal<<endl;
        }
    }
    emp1.close();
    emp2.close();
    remove("EMPLOYEE.txt");
    rename("temp.txt","EMPLOYEE.txt");
    cout<<endl<<"     EMPLOYE SUPPRIME"<<endl;
    cout<<endl<<"     APPUYEZ SUR UNE TOUCHE POUR CONTINUER"<<endl;
    cout<<"     ";getch();
    emppage();
}
class login
{
  public:
      string pass="";
      int ch;
      char c;
      void loginpageswitch();
      void homepageswitch();
      void employeelogin();
      void ownerlogin();
      void emp();
      void own();
      void homepage()
      {
          system("CLS");
          gotoxy(40,1);cout<<"BIENVENUE AU SYSTEME DE GESTION DU RESTAURANT ROMA2";
          gotoxy(40,2);cout<<"---------------------------------------------------"<<endl<<endl;
          cout<<"     1. S'AUTHENTIFIER"<<endl;
          cout<<"     2. QUITTER"<<endl<<endl;
          cout<<"     SAISIR VOTRE CHOIX"<<endl;
          cout<<"     ";cin>>ch;
          homepageswitch();
      }
      void loginpage()
      {
          system("CLS");
          gotoxy(40,1);cout<<"RESTAURANT ROMA2";
          gotoxy(40,2);cout<<"-----------------"<<endl<<endl;
          cout<<"     1. AUTHENTIFICATION: Mode ADMIN"<<endl;
          cout<<"     2. AUTHENTIFICATION: Mode EMPLOYE"<<endl;
          cout<<"     3. QUITTER"<<endl<<endl;
          cout<<"     SAISIR VOTRE CHOIX"<<endl;
          cout<<"     ";cin>>ch;
          loginpageswitch();
      }
};
void login::homepageswitch()
{
    while(ch!=1||ch!=2)
    {
        switch(ch)
        {
        case 1:
            loginpage();
            break;
        case 2:
            exit(0);
            break;
        default:
            cout<<endl<<"     CHOIX INVALIDE"<<endl;
            cout<<"     SAISIR VOTRE CHOIX"<<endl;
            cout<<"     ";cin>>ch;
        }
    }
}
void login::loginpageswitch()
{
    while(ch!=1||ch!=2||ch!=3)
    {
        switch(ch)
        {
            case 1:
                ownerlogin();
                break;
            case 2:
                employeelogin();
                break;
            case 3:
                exit(0);
                break;
            default:
                cout<<endl<<"     CHOIX INVALIDE"<<endl;
                cout<<"     SAISIR VOTRE CHOIX"<<endl;
                cout<<"     ";cin>>ch;
        }
    }
}
void login::ownerlogin()
{
    while(pass!="ROMA2")
    {
        pass="";
        cout<<endl<<"     ENTRER LE MOT DE PASSE ADMIN  ---exemple: admin---"<<endl;
        cout<<"     ";c=_getch();
        while(c!=13)
        {
            pass.push_back(c);
            cout<<"*";
            c=getch();
        }
        if(pass=="admin")
         {
             cout<<endl<<"     FELICITATIONS! ACCES ADMIN ACCORDE."<<endl;
             cout<<endl<<"     APPUYEZ SUR UNE TOUCHE POUR CONTINUER"<<endl;
             cout<<"     ";getch();
             own();
         }
        else
        {
            cout<<endl<<"     MOT DE PASSE INVALIDE"<<endl;
        }
    }
}
void login::employeelogin()
{
    while(pass!="employe")
    {
        pass="";
        cout<<"     ENTRER LE MOT DE PASSE EMPLOYE  ---exemple: employe---"<<endl;
        cout<<"     ";c=_getch();
        while(c!=13)
        {
            pass.push_back(c);
            cout<<"*";
            c=getch();
        }
        if(pass=="employe")
        {
            cout<<endl<<"     FELICITATIONS! ACCES EMPLOYE ACCORDE."<<endl;
            cout<<endl<<"     APPUYEZ SUR UNE TOUCHE POUR CONTINUER"<<endl;
            cout<<"     ";getch();
            emp();
        }
        else
        {
            cout<<endl<<"     MOT DE PASSE INVALIDE"<<endl;
        }
    }
}
void login::emp()
{
    store s;
    s.storepage();
}
void login::own()
{
    employee e;
    e.emppage();
}
void billpage()
{
    int ch;
    system("CLS");
    gotoxy(40,1);cout<<"RESTAURANT ROMA2";
    gotoxy(40,2);cout<<"-----------------"<<endl<<endl;
    cout<<"     1. NOUVELLE COMMANDE"<<endl;
    cout<<"     2. QUITTER"<<endl<<endl;
    cout<<"     SAISIR VOTRE CHOIX"<<endl;
    cout<<"     ";cin>>ch;
    while(ch!=1||ch!=2)
    {
        switch(ch)
        {
            case 1:
                {
                    order o;
                    o.orderpage();
                }
                break;
            case 2:
                exit(0);
                break;
            default:
                cout<<endl<<"    CHOIX INVALIDE"<<endl;
                cout<<"     SAISIR VOTRE CHOIX"<<endl;
                cout<<"     ";cin>>ch;
        }
    }
}
void handlecust()
{
    order o;
    o.orderpage();
}
void billjump()
{
    billing b;
    b.viewstat();
}
void empjump()
{
    employee e;
    e.emppage();
}
int main()
{
    system("title SYSTEME RESTAURANT ROMA2");
    system("color 90");
    login l;
    l.homepage();
    return 0;
}
