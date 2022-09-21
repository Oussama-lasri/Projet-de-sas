#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
typedef struct{
    int jour;
    int mois;
    int annee;
    }date;


typedef struct{
    int code ;
    char nom[20];
    int quantite ;
    float prix ;
    float prixTTC ;
    }produit;


    typedef struct{
    int  code;
    int quantite ;
    float prixTTC ;
    date date_Achat;
    float TV ;
    }produitAchter;

// Les fonctions
void AjouterProduit(produit *medi,int Taille);
void AjouterPlusieursProduit(produit *medi,int NbP,int Taille);
void affichage(produit *medi , int Taille);
void OrdreAlpha(produit * medi,int Taille);
void TriPrix(produit * medi,int Taille);
void RechercherParCode(produit * medi,int Taille);
int RechercheCode(produit * medi,int Taille,int valeurRechercherCode);
void RechercherParQuantite(produit * medi,int Taille,int valeurRechercherQuantite);
void  AchterProduit(produit * medi ,int Taille,int codeProduitAch,int Quantite,produitAchter * medicamentAchter ,int TaillePA );
void affichageEtat(produit *medi , int Taille);
void AlimenterStock(produit *medi , int Taille,int QuantiteAjouter,int CodeReturn);
double TotalPrixProduiTVendusJC(produitAchter* mediAch ,int TaillePA,int J,int M,int A);
double MoyennePrixProduiTVendusJC(produitAchter* mediAch ,int TaillePA,int J,int M,int A,double total);
void MaxProduitVendusJC(produitAchter* mediAch ,int TaillePA,int J,int M,int A);
void MinProduitVendusJC(produitAchter* mediAch ,int TaillePA,int J,int M,int A);




int main()
{
    produit *medicament ;
    int choixTri ,choixRech ;
    int choix ;
    int NbP;
    int Taille ;
    int valeurRechercherCode;
    int valeurRechercherQuantite;
    int TaillePA = 0 ;
    Taille = 0;

    medicament = calloc (Taille,sizeof(produit));
    produitAchter *medicamentAchter = calloc((TaillePA+1),sizeof(produit));
    int fermer = 1 ;
    while(fermer == 1){
    // le menu
    printf("                ****************************gestion de pharmacie******************\n\n");
    printf("                                            ***Menu principal***\n\n");
    printf("                                        1-Ajouter un nouveau produit\n\n");
    printf("                                        2-Ajouter plusieurs nouveaux produits\n\n");
    printf("                                        3-Liste de tous les produits\n\n");
    printf("                                        4-Acheter produit\n\n");
    printf("                                        5-Rechercher a les produits\n\n");
    printf("                                        6-Etat du stock\n\n");
    printf("                                        7-Alimenter le stock\n\n");
    printf("                                        8-Supprimer les produits\n\n");
    printf("                                        9-Statistique de vente\n\n");
    printf("                                        10-Quitter le programme\n\n");
    printf("                *****************************************************************\n");
    do{
           printf("\t-> votre choix : ") ;
            scanf("%d",&choix);
            if(choix>10 || choix<0){
                printf("le choix entre 1 et 9 \n");
            }
    }while(choix>10 || choix<0);

system("cls");

    switch(choix){
            case 1 : {
                printf("\n\t\t**********Ajouter un nouveau produit**********\n");
                medicament = realloc(medicament,(Taille+1)*sizeof(produit));
                AjouterProduit(medicament,Taille);
                Taille++;
                printf("\t*****************\n");
                printf("\nclick entrer....");
                getch();
                break ;
            }
            case 2 : {
                printf("\n\n\t\t\t**********Ajouter des nouveaux produits**********\n\n");
                printf("\tveuillez saisir un le nombre de medicament ajouter : ");
                scanf("%d",&NbP);
                medicament = realloc(medicament,(Taille+NbP)*sizeof(produit));
                AjouterPlusieursProduit(medicament , NbP,Taille);
                Taille +=NbP ;
                printf("\nclick entrer....");
                getch();
                break ;
            }
            case 3 : {
                    printf("\t\t************liste de tri************\n");
                    printf("\t        1-Ordre alphabitique :\n");
                    printf("\t        2-tri avec le prix \n\n\n");
                    printf("\t           -> Votre choix : ");
                    scanf("%d",&choixTri);
                    switch(choixTri){
                case 1 : {
                    OrdreAlpha(medicament,Taille);

                    break;
                    }
                case 2 : {
                    TriPrix(medicament,Taille);
                    break;
                    }
                    }
                    printf("\nclick entrer....");
                    getch();
                break ;
            }
            case 4 : {
                //affichage de liste de medicament
                affichage(medicament ,Taille);
                //acheter un produit
                int codeProduitAch,Quantite;

                printf("\n\n\t\tsaisir le code de Medicament qui tu veux acheter : ");
                scanf("%d",&codeProduitAch);
                printf("\t\tsaisir la quantite de Medicament qui tu veux acheter : ");
                scanf("%d",&Quantite);
                AchterProduit(medicament,Taille,codeProduitAch,Quantite,medicamentAchter,TaillePA);
                TaillePA++;
                medicamentAchter = realloc(medicamentAchter,(TaillePA +1)*sizeof(produit));
                printf("\nclick entrer....");
                getch();
                break ;
            }
            //le recherche

            case 5 : {
                printf("\n\n\t\t*****************Le recherche*****************\n\n");
                printf("\n\n\t    1-recherche par le code \n");
                printf("\n\t      2-recherche par la quanitite \n");
                printf("\n\n\n\n\t\t    choisir un recherche -> ");
                scanf("%d",&choixRech);
                switch(choixRech){
                    case 1 :
                        RechercherParCode(medicament,Taille);
                        printf("\nclick entrer....");
                        getch();
                        break ;
                    case 2 :
                        printf("saisir le quantitte de produit qui tu veux rechercher : ");
                        scanf("%d",&valeurRechercherQuantite);
                        RechercherParQuantite(medicament,Taille,valeurRechercherQuantite);
                        printf("\nclick entrer....");
                        getch();
                        break;
                    }
                break ;
            }

            //affichage de etat de stock
            case 6 : {
                printf("\n\n\t\t\t************ les produits dont la quantite est inferieure a 3 ************\n");
                //affichage de etat de stock
                affichageEtat(medicament , Taille);
                printf("\nclick entrer....");
                getch();


                break ;
            }
             //ajoute de la quantite
            case 7 : {
                 //affichage
                affichage(medicament ,Taille);
                int QuantiteAjoute;
                int valeurRechercherCode;
                printf("         -> saisir le code de valeur qui tu recherche : ");
                scanf("%d",&valeurRechercherCode);
                int returnCode = RechercheCode( medicament, Taille,valeurRechercherCode);
                if(returnCode == -1){
                    printf("le code de produit n'existe pas");
                    printf("\nclick entrer....");
                    getch();
                    break;
                }
                else{
                printf("\n\n           -> entrer la quantite qui tu veux ajoute");
                scanf("%d",&QuantiteAjoute);
                AlimenterStock(medicament,Taille,QuantiteAjoute,returnCode);
                }
                printf("\nclick entrer....");
                getch();

                break ;
            }
            case 8 : {
                printf("\t\t************liste des Produits************\n");
                int CodeProduitSupprimer;
                OrdreAlpha(medicament,Taille);
                printf("\n\n \t\ Veuillez saisir le code de produit supprimer : ");
                scanf("%d",&CodeProduitSupprimer);
                int returnRCS = RechercheCode( medicament, Taille,CodeProduitSupprimer);
            if(returnRCS == -1){
                printf("le code n'existe pas dans la liste");

            }
            else
                {
                    for (int i = returnRCS; i < Taille; i++){
                    medicament[i] = medicament[i+1];}
                    printf("\n\n\t\tla suppresion succes\n\n");
                    Taille--;
                    printf("**************** Apres la suppression****************");
                    affichage(medicament,Taille);
                }

                printf("\nclick entrer....");
                getch();

                break ;
            }
            case 9 : {
                    int choixStat ;
                 printf("**************** Apres la suppression****************\n");
                 printf("\t\t1-Afficher le total des prix des produits vendus\n");
                 printf("\t\t2-Afficher la moyenne des prix des produits vendus\n");
                 printf("\t\t3-Afficher le Max des prix des produits vendus\n");
                 printf("\t\t4-Afficher le Min des prix des produits vendus\n");
                printf("\t\t\tchoisir un affichage -> ");
                scanf("%d",&choixStat);
                switch(choixStat){
                        case 1 : {
                            int J , M ,A ;
                        printf("saisir la date d'aujourdhui Ex : JJ/MM/AAAA");
                        scanf("%d %d %d",&J,&M,&A);
                        float Total ;
                        Total = TotalPrixProduiTVendusJC( medicamentAchter , TaillePA,J,M,A);
                        printf("\n\n\t\t\t le total des prix des produits vendus %.2f",Total);
                        printf("\nclick entrer....");
                        getch();

                        break;}
                        case 2 : {
                            int J , M ,A ;
                            float Moyenne,total;
                            printf("saisir la date d'aujourdhui Ex : JJ/MM/AAAA : ");
                            scanf("%d %d %d",&J,&M,&A);
                            total = TotalPrixProduiTVendusJC(medicamentAchter,TaillePA,J,M,A);

                            Moyenne = MoyennePrixProduiTVendusJC(medicamentAchter , TaillePA,J,M,A,total);
                            printf("\n\n\t\t\t La moyenne des prix des produits vendus %.2f",Moyenne);
                            printf("\nclick entrer....");
                            getch();
                            break;
                        }
                        case 3 : {
                        int J , M ,A ;
                            printf("saisir la date d'aujourdhui Ex : JJ/MM/AAAA : ");
                            scanf("%d %d %d",&J,&M,&A);
                        printf("\t\t\t\n *********** le Max des prix des produits vendus en journée courante ************\n");
                        MaxProduitVendusJC(medicamentAchter ,TaillePA, J, M, A);
                        printf("\nclick entrer....");
                        getch();
                        break;
                        }

                        case 4 : {
                                int J , M ,A ;
                            printf("saisir la date d'aujourdhui Ex : JJ/MM/AAAA : ");
                            scanf("%d %d %d",&J,&M,&A);
                            printf("\t\t\t\n *********** le Min des prix des produits vendus en journée courante ************\n");
                             MinProduitVendusJC(medicamentAchter ,TaillePA, J, M, A);
                             printf("\nclick entrer....");
                            getch();
                            break;
                        }
                        }

                break ;
            }
            case 10 : {
                fermer = 0 ;
                break ;
            }
            }
system("cls");
    }



    return 0;
}
// fonction d'ajouter un produit
void AjouterProduit(produit * medi,int Taille){
        printf("\t\n\nveuillez entrer les information d'un medicament\n ");
        printf("\t\tsaisir le code de medicament :");
        scanf("%d",&medi[Taille].code);
        printf("\t\tsaisir le nom de medicament :");
        scanf("%s",&medi[Taille].nom);
        printf("\t\tsaisir la quantite de medicament :");
        scanf("%d",&medi[Taille].quantite);
        printf("\t\tsaisir le prix de medicament :");
        scanf("%f",&medi[Taille].prix);
        medi[Taille].prixTTC = medi[Taille].prix + (medi[Taille].prix*0.15) ;
        }

// fonction d'ajouter plusieurs produits
void AjouterPlusieursProduit(produit *medi ,int NbP,int Taille){
        for(int i = Taille ; i<NbP+Taille ; i++){
        printf("\n\n\tVeuillez entrer les information medicament %d\n ",i+1);
        printf("\t\tsaisir le code de medicament :");
        scanf("%d",&medi[i].code);
        printf("\t\tsaisir le nom de medicament :");
        scanf("%s",medi[i].nom);
        printf("\t\tsaisir la quantite de medicament :");
        scanf("%d",&medi[i].quantite);
        printf("\t\tsaisir le prix de medicament :");
        scanf("%f",&medi[i].prix);
        printf("l'ajoute est valide");
        medi[i].prixTTC = medi[i].prix + (medi[i].prix*0.15) ;
        }
        }
//affichage
void affichage(produit *medi , int Taille){
         for(int k = 0 ; k<Taille ; k++){
        printf("\t\n\n Medicaments %d\n ",k+1);
        printf("\t\t Le code de medicament : %d\n",medi[k].code);
        printf("\t\t Le nom de medicament : %s\n",medi[k].nom);
        printf("\t\t La quantite de medicament : %d\n",medi[k].quantite);
        printf("\t\t le prix de medicament : %.2f\n",medi[k].prix);
        printf("\t\t Le prix TTC de medicament : %.2f\n",medi[k].prixTTC);
}        }


void OrdreAlpha(produit * medi,int Taille){
    for(int i = 0 ; i<Taille-1 ; i++){
            for(int j = i+1 ; j<Taille ; j++ ){
        if((strcmp(medi[i].nom,medi[j].nom))==1){
            produit ech = medi[i] ;
            medi[i] = medi[j];
            medi[j] = ech ;
        }
        }
    }
        //affichage
        affichage(medi ,Taille);


}

void TriPrix(produit * medi,int Taille){
    for(int i = 0 ; i<Taille-1 ; i++){
            for(int j = i+1 ; j<Taille ; j++ ){
        if(medi[i].prix<medi[j].prix){
            produit ech = medi[i] ;
            medi[i] = medi[j];
            medi[j] = ech ;
        }
        }
    }
    //affichage
    affichage(medi ,Taille);
}


void RechercherParCode(produit * medi,int Taille ){
                int valeurRechercherCode;
                printf("saisir le code de valeur qui tu recherche : ");
                scanf("%d",&valeurRechercherCode);
                int returnR = RechercheCode( medi, Taille,valeurRechercherCode);

            if(returnR == -1){
                    printf("le code de produit n'existe pas");

            }
            else{
                    printf("\t\t ***************** le Resultat ***************** \n");
                    printf("\t\t le code de medicament : %d\n",medi[returnR].code);
                    printf("\t\t le nom de medicament : %s\n",medi[returnR].nom);
                    printf("\t\t la quantite de medicament : %d\n",medi[returnR].quantite);
                    printf("\t\t le prix de medicament : %.2f\n",medi[returnR].prix);
                    printf("\t\t le prix TTC de medicament : %.2f\n",medi[returnR].prixTTC);

            }
    }



int RechercheCode(produit * medi,int Taille,int valeurRechercherCode){
    for(int i = 0 ; i<Taille ; i++){
        if(medi[i].code == valeurRechercherCode)
                   return i ;
        }
        return -1;
    }
// Recherche par quantite

void RechercherParQuantite(produit * medi,int Taille,int valeurRechercherQuantite){

    for(int i = 0 ; i<Taille ; i++){
        if(medi[i].quantite == valeurRechercherQuantite){
                  printf("\t\t ***************** le Resultat ***************** \n");
                    printf("\t\t le code de medicament : %d\n",medi[i].code);
                    printf("\t\t le nom de medicament : %s\n",medi[i].nom);
                    printf("\t\t la quantite de medicament : %d\n",medi[i].quantite);
                    printf("\t\t le prix de medicament : %.2f\n",medi[i].prix);
                    printf("\t\t le prix TTC de medicament : %.2f\n",medi[i].prixTTC);
        }
}

}


//acheter un medicament
void  AchterProduit(produit * medi ,int Taille,int codeProduitAch,int Quantite,produitAchter * medicamentAchter ,int TaillePA){



            int returnR = RechercheCode(medi,Taille,codeProduitAch);
            if(returnR == -1)
                printf("le code n'existe pas ");
            else{
                    if(Quantite>medi[returnR].quantite){
                            printf("la quantite est insuffisante");

                            }
                    else
                        {
                            medi[returnR].quantite -= Quantite ;
                            medicamentAchter[TaillePA].prixTTC= medi[returnR].prixTTC;
                            medicamentAchter[TaillePA].quantite= Quantite;
                            medicamentAchter[TaillePA].code= medi[returnR].code;
                            printf("entrer la date d'achat\n");
                            printf("\t-> Le jour : ");
                            scanf("%d",&medicamentAchter[TaillePA].date_Achat.jour);
                            printf("\t-> Le mois : ");
                            scanf("%d",&medicamentAchter[TaillePA].date_Achat.mois);
                            printf("\t-> L'annee : ");
                            scanf("%d",&medicamentAchter[TaillePA].date_Achat.annee);




                    printf("\t\t ***************** le Resultat de produit acheter ***************** \n");
                    printf("\t\t le code de medicament : %d\n",medicamentAchter[TaillePA].code);
                    printf("\t\t la quantite de medicament : %d\n",medicamentAchter[TaillePA].quantite);
                    printf("\t\t le prix TTC de medicament : %.2f\n",medicamentAchter[TaillePA].prixTTC);
                    printf("\t\t La date d'achat : %d/%d/%d \n",medicamentAchter[TaillePA].date_Achat.jour,medicamentAchter[TaillePA].date_Achat.mois,medicamentAchter[TaillePA].date_Achat.annee);

                    printf("\t\t *****************  liste apres l'achat***************** \n");
                    printf("\t\t le code de medicament : %d\n",medi[returnR].code);
                    printf("\t\t le nom de medicament : %s\n",medi[returnR].nom);
                    printf("\t\t la quantite de medicament : %d\n",medi[returnR].quantite);
                    printf("\t\t le prix de medicament : %.2f\n",medi[returnR].prix);
                    printf("\t\t le prix TTC de medicament : %.2f\n",medi[returnR].prixTTC);


                    }


            }


}
//affichage de etat de stock
void affichageEtat(produit *medi , int Taille){
         for(int k = 0 ; k<Taille ; k++){
                if(medi[k].quantite<3){
        printf("\t\n\n Medicaments %d\n ",k+1);
        printf("\t\t Le code de medicament : %d\n",medi[k].code);
        printf("\t\t Le nom de medicament : %s\n",medi[k].nom);
        printf("\t\t La quantite de medicament : %d\n",medi[k].quantite);
        printf("\t\t le prix de medicament : %.2f\n",medi[k].prix);
        printf("\t\t Le prix TTC de medicament : %.2f\n",medi[k].prixTTC);
        }
}}

//Alimenter le stock
void AlimenterStock(produit *medi , int Taille,int QuantiteAjouter,int CodeReturn){

            medi[CodeReturn].quantite+=QuantiteAjouter ;
             printf("\t\n\n Medicaments %d\n ",CodeReturn+1);
        printf("\t\t Le code de medicament : %d\n",medi[CodeReturn].code);
        printf("\t\t Le nom de medicament : %s\n",medi[CodeReturn].nom);
        printf("\t\t La quantite de medicament : %d\n",medi[CodeReturn].quantite);
    printf("\n\n\t\t\tl'ajoute de la quantite est effectue");


            }
//satatistique de vente
//---> affichage produits vendus en journée courante
double TotalPrixProduiTVendusJC(produitAchter* mediAch ,int TaillePA,int J,int M,int A){

        for(int i = 0 ; i<TaillePA;i++){

             if(J == mediAch[i].date_Achat.jour && M == mediAch[i].date_Achat.mois && A == mediAch[i].date_Achat.annee){
            printf("Le code de medicament  : %d \n",mediAch[i].code);
            printf("Le prix TTC %.2f \n",mediAch[i].prixTTC);
            printf("Qantite :  %d \n",mediAch[i].quantite);


            }}
            float Total ;
            for(int i = 0 ; i<TaillePA ; i++){
            if(J == mediAch[i].date_Achat.jour && M == mediAch[i].date_Achat.mois && A == mediAch[i].date_Achat.annee){
                Total = Total+(mediAch[i].prixTTC * mediAch[i].quantite) ;
            }}
            return Total ;


}
// Calcul la moyenne des produits achte en jour courante
double MoyennePrixProduiTVendusJC(produitAchter* mediAch ,int TaillePA,int J,int M,int A,double total){
        int Cont = 0 ;
        for(int i = 0 ; i<TaillePA;i++){
             if(J == mediAch[i].date_Achat.jour && M == mediAch[i].date_Achat.mois && A == mediAch[i].date_Achat.annee){
                    Cont++;
             }}

        float Moyenne;
        if( Cont != 0)
            Moyenne = total / Cont ;
        else
            Moyenne = 0 ;
            return Moyenne ;


}
// le Max des prix des produits vendus en journée courante

void MaxProduitVendusJC(produitAchter* mediAch ,int TaillePA,int J,int M,int A){
    for(int i = 0 ; i<TaillePA;i++){
        mediAch[i].TV = mediAch[i].prixTTC * mediAch[i].quantite ;
                                    }
    float MAX ;
    int IndexMAX ;
    MAX = mediAch[0].TV;
    for(int i = 0 ; i<TaillePA;i++){
            if(J == mediAch[i].date_Achat.jour && M == mediAch[i].date_Achat.mois && A == mediAch[i].date_Achat.annee){
                    if(MAX<mediAch[i].TV){
                               MAX = mediAch[i].TV ;
                               IndexMAX = i ;

                        }
            }
    }
            printf("               Le code de medicament  : %d \n",mediAch[IndexMAX].code);
            printf("               Le prix TTC %.2f \n",mediAch[IndexMAX].prixTTC);
            printf("               Qantite :  %d \n",mediAch[IndexMAX].quantite);
}

// le Min des prix des produits vendus en journée courante


void MinProduitVendusJC(produitAchter* mediAch ,int TaillePA,int J,int M,int A){
    for(int i = 0 ; i<TaillePA;i++){
        mediAch[i].TV = mediAch[i].prixTTC * mediAch[i].quantite ;
                                    }
    float MIN ;
    int IndexMIN ;
    MIN = mediAch[0].TV;
    for(int i = 0 ; i<TaillePA;i++){
            if(J == mediAch[i].date_Achat.jour && M == mediAch[i].date_Achat.mois && A == mediAch[i].date_Achat.annee){
                    if(MIN>mediAch[i].TV){
                               MIN = mediAch[i].TV ;
                               IndexMIN = i ;

                        }
            }
    }
            printf("\n\n               Le code de medicament  : %d \n",mediAch[IndexMIN].code);
            printf("               Le prix TTC %.2f \n",mediAch[IndexMIN].prixTTC);
            printf("               Qantite :  %d \n",mediAch[IndexMIN].quantite);
}





















