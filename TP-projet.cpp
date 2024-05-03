#include <iostream>
#include <vector>
#include <string>


using namespace std;

class Plat {
private:
    string NomP;
    string DescriptionP;
    float PrixP;

public:
    Plat(string nom, string description, float prix)  : NomP(nom), DescriptionP(description), PrixP(prix) {}
    void afficherDetails() const {
        cout << " Nom: " << NomP << endl; 
        cout << " Description: " << DescriptionP << endl;
        cout << " Prix: " << PrixP << " Dh" << endl;
        
    }
    
    
    float getPrixPlat() const {
        return PrixP;
    }
    
    string getNomPlat() const {
        return NomP;
    }
    void Modifierplat( string nom,string description,float prix){
            NomP = nom;
            DescriptionP = description;
            PrixP = prix;
        }
    
};


class Boisson {
private:
    string NomB;
    string DescriptionB;
    float PrixB;
    
public:
    Boisson(string nom, string description, float prix) : NomB(nom), DescriptionB(description), PrixB(prix){}
    void afficherDetails() const {
        
        cout << " Nom: " << NomB << endl;
        cout << " Description: " << DescriptionB << endl;
        cout << " Prix: " << PrixB << " Dh" << endl;
    }
    
    float getPrixBoisson() const {
        return PrixB;
    }
    string getNomBoisson() const {
        return NomB;
    }
    void Modifierboisson( string nom,string description,float prix){
            NomB = nom;
            DescriptionB = description;
            PrixB = prix;
        }
    
};


class Menu {
private:
    vector<Plat> Listplats;
    vector<Boisson> Listboissons;
public:

Menu(){ 
}

    const vector<Plat>& getListPlats() const {
        return Listplats;
    }
    const vector<Boisson>& getListBoisson() const {
        return Listboissons;
    }
    void ajouterPlat(const Plat &plat) {
        Listplats.push_back(plat);
    }
    void ajouterBoisson(const Boisson &boisson) {
        Listboissons.push_back(boisson);
    }
    void afficherMenu() const {
        cout << "----- Menu -----" << endl;
        cout << " Plats :" << endl;
        for (const auto& plat : Listplats) {
            plat.afficherDetails();
            cout << endl;
        }
        cout << " Boissons :" << endl;
        for (const auto& boisson : Listboissons) {
            boisson.afficherDetails();
            cout << endl;
        }
    }
    void ModifierP() {
    cout << "Entrer le nom du Plat a  modifier : ";
    string choix;
    cin.ignore();
    getline(cin, choix);

    // Recherche du plat à modifier
    for (auto it = Listplats.begin(); it != Listplats.end(); ++it) {
        if (it->getNomPlat() == choix) {
            cout << "|=============== | Modification Plat |===============|" << endl;
            cout << "| - Nouveau Nom : ";
            string NouveauNom, DescriptionP;
            float PrixP;
            getline(cin, NouveauNom);
            cout << "| - Nouvelle Description : ";
            getline(cin, DescriptionP);
            cout << "| - Nouveau Prix : ";
            cin >> PrixP;
            cout << "|==================================================|" << endl;

            // Modifier le plat existant
            it->Modifierplat(NouveauNom, DescriptionP, PrixP);
            cout << "Plat modifie avec succes !!" << endl;
            return; // Sortir de la fonction après la modification
        }
    }

    // Si aucun plat portant le nom spécifié n'est trouvé
    cout << "Plat non trouve !!" << endl;
}
    void ModifierB() {
    cout << "Entrer le nom du boisson a modifier : ";
    string choix;
    cin.ignore();
    getline(cin, choix);

    // Recherche du plat à modifier
    for (auto it = Listboissons.begin(); it != Listboissons.end(); ++it) {
        if (it->getNomBoisson() == choix) {
            cout << "|=============== | Modification Plat |===============|" << endl;
            cout << "| - Nouveau Nom : ";
            string NouveauNom, DescriptionB;
            float PrixB;
            getline(cin, NouveauNom);
            cout << "| - Nouvelle Description : ";
            getline(cin, DescriptionB);
            cout << "| - Nouveau Prix : ";
            cin >> PrixB;
            cout << "|==================================================|" << endl;

            // Modifier le boisson existant
            it->Modifierboisson(NouveauNom, DescriptionB, PrixB);
            cout << "Boisson modifie avec succes !!" << endl;
            return; // Sortir de la fonction après la modification
        }
    }

    // Si aucun boisson portant le nom spécifié n'est trouvé
    cout << "Boisson non trouve !!" << endl;
}

};

class Reservation {
private:
    string Date; 
    string Heure;
    int NbrDePersonnes;
    string Statut;
    string NumTelephone;
public:
    Reservation( string date, string heure, int nombreDePersonnes, string stat, string numTelephone) : Date(date), Heure(heure), NbrDePersonnes(nombreDePersonnes), Statut(stat), NumTelephone(numTelephone) {}
    
    string getDate(){
        return Date;
    }
    string getHeure(){

        return Heure;
    }
    void confirmerReservation() {
        Statut = " Confirmee ";
    }
    void annulerReservation() {
        cout << " Reservation annuler !!" << endl;
        Statut = "Annulee";
    }
    void EnattenteReservation() {
        Statut = " En attente ";
    }
    string getStatut() const {
        return Statut;
        
    }
    void setStatut(string S){
        Statut = S;
    }

    void afficherDetails() const {
        cout << endl;
        cout << " ----------- Details de la reservation ----------- " <<endl;
        cout << "   Date : " << Date <<endl;
        cout << "   Heure : " << Heure << endl;
        cout << "   Nombre de personnes : " << NbrDePersonnes << endl;
        cout << "   Statut : " << Statut << endl; 
        cout << "   Numero de telephone : " << NumTelephone << endl;
        cout << "----------------------------------------------------" << endl;
        
    }

};

class Client {
private:
    string Nom;
    string NumTelephone;
public:
    string getNom() const {
        return Nom;
    }

    string getNumTelephone() const {
        return NumTelephone;
    }

    vector<Reservation> reservations;

    Client(string nom, string numeroTelephone) : Nom(nom), NumTelephone(numeroTelephone) {}

    void reserverTable(string nom, string date, string heure, int nombreDePersonnes,string stat,  string numTelephone) {
        NumTelephone = numTelephone;
        Reservation reservation(date, heure, nombreDePersonnes, stat, numTelephone);
        reservations.push_back(reservation);
        cout << "Reservation confrimee pour le client " << nom << "." << endl;
    }
    
void annulerReservation(string date, string heure) {
    bool reservationTrouvee = false;
    for (auto it = reservations.begin(); it != reservations.end(); ++it) {
        if (it->getDate() == date && it->getHeure() == heure) {
            it = reservations.erase(it); // Supprimer la réservation
            reservationTrouvee = true;
            cout << "Reservation pour le client annulee." << endl;
            break;
        }
    }
    if (!reservationTrouvee) {
        cout << "Aucune reservation " << endl;
    }
}




    void afficherDetails() const {
        cout << " Nom: " << Nom << endl;
        cout << " Numero de telephone: " << NumTelephone << endl;
        cout << " Reservations :" << endl;
    }
};

class Commande{
private:
    vector<Plat> ListPlatsCommandes;
    vector<Boisson> ListBoissonsCommandes;
    const Menu& m; 
public:

    Commande(const Menu& menu) : m(menu) {}
    
    void ajouterPlat(const string& plat) {
    bool platExiste = false;
    for (const Plat& p : m.getListPlats()) {
        if (p.getNomPlat() == plat) {
            ListPlatsCommandes.push_back(p);
            platExiste = true;
            cout << " Plat ajoute a la commande : " << plat << endl;
            break; // Sortir de la boucle dès qu'on trouve le plat
        }
    }
    if (!platExiste) {
        cout << " Plat non trouve !!" << endl;
    }
}

    void ajouterBoisson(const string& boisson) {
    bool boissonExiste = false;
    for (const Boisson& b : m.getListBoisson()) {
        if (b.getNomBoisson() == boisson) {
            ListBoissonsCommandes.push_back(b);
            boissonExiste = true;
            cout << " Boisson ajoute a la commande : " << boisson << endl;
            break; 
        }
    }
    if (!boissonExiste) {
        cout << " Boisson non trouve !!" << endl;
    }
}
    
    void calculerTotal(string p,string b) const{
        float total = 0.0;
        if(b.empty()){
        for(auto& pl : m.getListPlats()){
            if(p == pl.getNomPlat()){
                total += pl.getPrixPlat();
                cout << " Le total de la commande est : " << total << " DH" << endl;
                    break;
                }
            
            }
        }else if(p.empty()){
            for(auto& boi : m.getListBoisson()){
            if(b == boi.getNomBoisson()){
                    total += boi.getPrixBoisson();
                    cout << " Le total de votre commande est : " << total << "DH" << endl;
                    break;
            }   
            }
        }else{
            for(auto& pl : m.getListPlats()){
                if(p == pl.getNomPlat()){
                    total += pl.getPrixPlat();
                }
            }for(auto& boi : m.getListBoisson()){
                if(b == boi.getNomBoisson()){
                    total += boi.getPrixBoisson();
                }
        }
            cout << " Le total de votre commande est  : " << total << " DH" << endl;
        }
    }
};

class GestionnaireDeStocks{

    vector<int>NbrPlat;
    vector<int>NbrBoisson;
    static int totalPlat;
    static int totalBoisson;
    const Menu& menu;

public:
    GestionnaireDeStocks(const Menu& m): menu(m) {};

    vector<int> getNbrPlat(){
        return NbrPlat;
    }
    vector<int> getNbrBoisson(){
        return NbrBoisson;
    }
    void ajouteringredientsPlat(){
        totalPlat += 1;
        NbrPlat.push_back(totalPlat);
    
}
void ajouteringredientsBoisson(){
        totalBoisson += 1;
        NbrBoisson.push_back(totalBoisson);
    }
    
void miseajouringredientPlat(){
        totalPlat -= 1;
        NbrPlat.pop_back();
}
    
void miseajouringredientBoisson(){
        totalBoisson -= 1;
        NbrBoisson.pop_back();
}

    void verifierDisponibilitePlat(string plat)const {
        bool dispo = false;
        for(const auto palt : menu.getListPlats()){
            if(plat == palt.getNomPlat()){
                dispo = true;
                break;
            }
        }
            if(!dispo){
                cout << "********************" << endl;
                cout << "  PLat non disponible !! " << endl;
                cout << "********************" << endl;
            }
        
        }
        


void verifierDisponibiliteBoisson(string boisson)const {
    bool dispo = false;
    for(const auto b : menu.getListBoisson()){
        if(boisson == b.getNomBoisson()){
            dispo = true;
        }
    }
        if(!dispo){
            cout << "********************" << endl;
            cout << " Boisson non disponible !!" << endl;
            cout << "********************" << endl;
        }
    
}
};

int GestionnaireDeStocks::totalPlat = 2;
int GestionnaireDeStocks::totalBoisson = 2; 

int main(){
    TEST:
    // Ajoutez les plats et les boissons ici
    Plat p1("Salade", "vous pouvez personnaliser ton salade", 40);
    Plat p2("Pizza Alfredo ", "Poulet,sauce alfredo, fromage,", 70);
    Boisson b1("jus", "orange", 35);
    Boisson b2("Coca-Cola", " Boisson gazeuse", 15);
    Menu M;
    Commande C(M);
    vector<string> Listclients;
    vector<Reservation> Listreservation;
    vector<int> StockPlat(2);
    vector<int> StockBoisson(2);
    M.ajouterPlat(p1);
    M.ajouterPlat(p2);
    M.ajouterBoisson(b1);
    M.ajouterBoisson(b2);
    GestionnaireDeStocks gestion(M);
    

    int user;
    do{   
        
        cout << " " << endl;
        cout << "________________________________________________ " << endl;
        cout << "|**                                           **|" << endl;
        cout << "|***********************************************|" << endl;
        cout << "|**     1. Acceder au menu Client             **|" << endl;
        cout << "|**     2. Acceder au menu Serveur            **|" << endl;
        cout << "|**     3. Quitter                            **|" << endl;
        cout << "|**                                           **|" << endl;
        cout << "|***********************************************|" << endl;
        cout << "|_______________________________________________| " << endl;
        cout << " " << endl;
        cout << "Votre choix : ";
        cin >> user;
        if (user == 1){
            int Ch1;
        
                cout << " " << endl;
                cout << "___________________________________________________ " << endl;
                cout << "|*************************************************|" << endl;
                cout << "|**                                             **|" << endl;
                cout << "|**           The good Taste                    **|" << endl;
                cout << "|**                                             **|" << endl;
                cout << "|*************************************************|" << endl;
                cout << "|**     1. Afficher le Menu                     **|" << endl;
                cout << "|**     2. Passer une commande                  **|" << endl;
                cout << "|**     3. Reserver une table                   **|" << endl;
                cout << "|**     4. Annuler la reservation               **|" << endl;
                cout << "|**     5. Retour                               **|" << endl;
                cout << "|*************************************************|" << endl;
                cout << "|_________________________________________________| " << endl;
                cout << " " << endl;
                cout << "votre choix : ";
                cin >> Ch1;
                //*Partie Client*//
            switch(Ch1){ 
                case 1:  //afficher menu
                M.afficherMenu();
                break;
            
                case 2:{  //passer une cmd
                    string choix;
                    cout << "=================================" << endl;
                    cout << "| Passer une Commande            |" << endl;
                    cout << "| - PLat + Boisson (M)           |"<< endl;
                    cout << "| - Plat (P)                     |"<< endl;
                    cout << "| - Boisson (B)                  |"<< endl;
                    cout << "================================ "<< endl;
                    cout << " Votre Choix : ";
                    cin >> choix;
                    if (choix == "M") {
                        cout << " Entrer le nom du Plat a commander " ;
                        string cmdplat;
                        cin >> cmdplat;
                        cout << " Entrer le nom du boisson a commander " ;
                        string cmdboisson;
                        cin >> cmdboisson;
                        C.ajouterPlat(cmdplat);
                        C.ajouterBoisson(cmdboisson);
                        C.calculerTotal(cmdplat,cmdboisson);
                        gestion.miseajouringredientPlat();
                        gestion.miseajouringredientBoisson();
                        StockPlat.pop_back();
                        StockBoisson.pop_back();
                    }else if(choix == "P"){
                        cout << " Entrer un plat"<<endl;
                        string cmdplat;
                        cin >> cmdplat;
                        C.ajouterPlat(cmdplat);
                        C.calculerTotal(cmdplat,"");
                        gestion.miseajouringredientPlat();
                        StockPlat.pop_back();
                    }else if(choix == "B") {
                        cout << " Entrer une boisson"<<endl;
                        string cmdboisson;
                        cin >> cmdboisson;
                        C.ajouterBoisson(cmdboisson);
                        C.calculerTotal("",cmdboisson);
                        gestion.miseajouringredientBoisson();
                        StockBoisson.pop_back();
                    }else {
                        cout <<"********** Choix invalide **********"<<endl;
                    }


                    break;
                }
                case 3:{    // Reserver une table
                    string Nom;
                    string NumTelephone;
                    int NbrDePersonnes;
                    string Date; 
                    string Heure;
                    if(Listreservation.size() < 5){
                            cout << " Entrer le nom du client : ";
                            cin >> Nom;
                            cout << " Entrer le num  de Telephone : ";
                            cin >> NumTelephone;
                            cout << " Entrer le nombre de personne : ";
                            cin >> NbrDePersonnes;
                            cout << " Entrer la date de reservation : ";
                            cin >> Date;
                            cout << " Entrer l'heure de reservation : ";
                            cin >> Heure;
                            Client Cl(Nom ,NumTelephone);
                            Listclients.push_back(Nom);
                            Reservation Res(Date, Heure, NbrDePersonnes,"En attante ",NumTelephone );
                            Cl.reserverTable(Nom,Date, Heure, NbrDePersonnes,"En attente",NumTelephone);
                            Listreservation.push_back(Res);
                            Cl.reservations.push_back(Res);
                    }else{
                        cout << "La liste des reservations est pleine"<<endl;
                    }
                break;
                }case 4:{   
                    string NomCl;
                    cout << "Entrer le nom: ";
                    cin >> NomCl;
                    cout << "Entrer La Date : ";
                    string date;
                    cin >> date;
                    cout << "Entrer l'heure : ";
                    string heure;
                    cin >> heure;

                    if(Listreservation.size() == 0){
                        cout << "Aucune reservation annuler" << endl;
                        break;
                    }else{
                        for(auto r : Listreservation){
                            if(r.getDate() == date && r.getHeure() == heure){
                                r.annulerReservation();
                                break;
                            }
                        }
                    }
                    for(auto it = Listreservation.begin() ; it != Listreservation.end(); ++it){
                        if(it->getDate() == date && it->getHeure() == heure){
                            Listreservation.erase(it);
                            break;
                        }
                    }
                    break;
                }
                

                case 5:{
                        // cout <<"//////////////////////////"<<endl;
                        // cout <<       " Have fun ! "         << endl; 
                        // cout <<"//////////////////////////"<<endl;
                        goto TEST;
                    break;
                }
                default:
                cout <<"********** Choix invalide**********"<<endl;
            }   

            
        

            
        }else if (user == 2){ 
            int Ch2;
                MENU_GESTION:
                cout << " " << endl;
                cout << "______________________________________________________ " << endl;
                cout << "|*****************************************************|" << endl;
                cout << "|**                                                 **|" << endl;
                cout << "|**               Gestion des Taches                **|" << endl;
                cout << "|**                                                 **|" << endl;
                cout << "|**     1. Ajouter des Plats                        **|" << endl;
                cout << "|**     2. Ajouter des Boissons                     **|" << endl;
                cout << "|**     3. Modification de Menu                     **|" << endl;
                cout << "|**     4. Afficher Menu                            **|" << endl;                     
                cout << "|**     5. Afficher details Client                  **|" << endl;
                cout << "|**     6. Reservation                              **|" << endl;
                cout << "|**     7. Afficher le Stock                        **|" <<endl;
                cout << "|**     8. Retour                                   **|" << endl;
                cout << "|*****************************************************|" << endl;
                cout << "|_____________________________________________________| " << endl;
                cout << " " << endl;
                cout << "votre choix : ";
                cin >> Ch2;

                switch (Ch2){
                    case 1: {
                        string NomP, DescriptionP;
                        float PrixP;
                        cout << " Entrer le nom du plat : ";
                        cin >> NomP;
                        cout << " Entrer la description du plat : ";
                        cin >> DescriptionP;
                        cout << " Entrer le prix du plat : ";
                        cin >> PrixP;
                        Plat nouveauPlat(NomP, DescriptionP, PrixP);
                        M.ajouterPlat(nouveauPlat);
                        cout << " Plat ajoute avec succes !" << endl;
                        gestion.ajouteringredientsPlat();
                        StockPlat.push_back(1);
                        goto MENU_GESTION;
                    break;
                    }   
                    case 2: {
                        string NomB, DescriptionB;
                        float PrixB;
                        cout << " Entrer le nom de la boisson : ";
                        cin >> NomB;
                        cout << " Entrer la description de la boisson : ";
                        cin >> DescriptionB;
                        cout << " Entrer le prix de la boisson : ";
                        cin >> PrixB;
                        Boisson nouvelleBoisson(NomB, DescriptionB, PrixB);
                        M.ajouterBoisson(nouvelleBoisson);
                        cout << " Boisson ajoutee avec succes !" << endl;
                        gestion.ajouteringredientsBoisson();
                        StockBoisson.push_back(1);
                        goto MENU_GESTION;
                        break;    
                    }
                    case 3:{
                    //void ModifierElement(Menu& menu) {
                    int choix;
                    cout << " Choisissez ce que vous voulez modifier :" << endl;
                    cout << "1. Plat" << endl;
                    cout << "2. Boisson" << endl;
                    cout << "Votre choix : ";
                    cin >> choix;

                    if (choix == 1) {
                        M.ModifierP();
                        goto MENU_GESTION;
                        break;
                    } else if (choix == 2) {
                        M.ModifierB();
                        goto MENU_GESTION;
                        break;
                    } else {
                        cout << "Choix invalide !" << endl;
                        goto MENU_GESTION;
                            break;
                    }

                        break;
                     }case 4:  //afficher menu
                        M.afficherMenu();
                        goto MENU_GESTION;
                        break;
                    case 5: {
                        cout << endl;
                        cout << "|--------- Client Reserver -----------|" << endl;
                        for(auto cl : Listclients){
                            cout << "| - " << cl << endl;
                            cout << "|-------------------------------------|" << endl;
                            
                        }
                        break;
                    }
                    case 6 :{ 
                        cout << endl;
                        cout << "--------------- RESERVATION --------------|" << endl;
                        cout << " |1| - Affichage detail En attente.       |"<<endl;
                        cout << " |2| - Confirmation de la reservation.    |"<<endl;
                        cout << " |3| - Annulation de la reservation       |"<<endl;
                        cout << "------------------------------------------|" << endl;
                        int Ch4;
                        cin >> Ch4;
                        if (Ch4 == 1){
                            if(Listreservation.size() == 0){
                        cout << "Aucune reservation trouvee."<<endl;
                                break;
                            }else{
                                for(auto res : Listreservation){
                                    res.afficherDetails();
                                    break;
                                } 
                            }
                            
                            
                        }else if(Ch4 == 2) {
                            cout << "Entrer l'heure de Confirmation : ";
                            string heure;
                            cin >> heure;
                            
                            for(auto res : Listreservation){
                                    if(res.getHeure() == heure){
                                        res.setStatut("Confirmer");
                                        res.afficherDetails();
                                        for(auto i = Listreservation.begin(); i != Listreservation.end(); ++i){
                                            if(i->getHeure() == heure){
                                                Listreservation.erase(i);
                                                break;
                                            }
                                        }
                                        break;
                                    }else{
                                        cout << "error" << endl;
                                    }
                                } 
                        }else if(Ch4 == 3){
                            cout << "Entrer l'heure de Confirmation : ";
                            string heure;
                            cin >> heure;
                            
                            for(auto res : Listreservation){
                                    if(res.getHeure() == heure){
                                        res.setStatut("Annuler");
                                        res.afficherDetails();
                                        for(auto i = Listreservation.begin(); i != Listreservation.end(); ++i){
                                            if(i->getHeure() == heure){
                                                Listreservation.erase(i);
                                                break;
                                            }
                                        }
                                        break;
                                    }else{
                                        cout << "error" << endl;
                                    }
                                } 
                        }else{
                            cout<<"Choix invalide"<<endl;
                            break;
                        }
                        break; 
                    }case 7:{
                        cout << endl;
                        cout << "------------------ Stock Resetaurant ------------------" << endl;
                        cout << " - Stock Plat -> " << StockPlat.size() << endl;
                        cout << " - Stock Boisson -> " << StockBoisson.size() << endl;
                        cout << "-------------------------------------------------------" << endl;
                        if(StockPlat.size() <=  5 && StockBoisson.size() <= 5){
                            cout << "Veuillez Remplir Votre Stock " << endl;
                        }
                        
                        
                        goto MENU_GESTION;
                        break;
                    }case 8: {
                        goto MENU_GESTION;
                    }
                    default:{
                            cout << "Choix Invalid" << endl;
                            break;
                        }
                }
                
        }else{
                cout << "___________________________________________________ " << endl;
                cout << "|*************************************************|" << endl;
                cout << "|**              The good Taste                 **|" << endl;
                cout << "|*************************************************|" << endl;
                cout << "|----------------- Au REVOIR ---------------------|" << endl;
                cout << endl;
        }
    }while(user != 3);
}
