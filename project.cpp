#include <iostream>
#include <cstring>

using namespace std;

class Person{
protected:
     char personName[20];
     char personAddress[20];
     int personAge;
     char personEmail[20];
     int personContact;

public:
Person(char name[],char address[],int age,char mail[],int no){
  strcpy(personName,name);
  strcpy(personAddress,address);
  personAge = age;
  strcpy(personEmail,mail);
  personContact = no;
}
void setPersonDetails(char name[],char address[],int age,char mail[],int no){
  strcpy(personName,name);
  strcpy(personAddress,address);
  personAge = age;
  strcpy(personEmail,mail);
  personContact = no;
}
void displayDetails(){
  cout<<"name = "<< personName << endl; 
  cout<<"address = "<< personAddress << endl;
  cout<<"age = "<< personAge << endl;
  cout<<"mail = "<< personEmail << endl;
  cout<<"number = "<< personContact << endl;
}
};


class User : public Person{
protected :
      int userid;
      char accountType[10];
      Order *order[2];
      Cart *cart;
      int packageCost;
      int orderno;
      int vehicleDue;
      int locationid;

public:
User(char name[],char address[],int age,char mail[],int no,int id,char type[],Cart *c) : Person(name,address,age,mail,no){
  userid = id;
  strcpy(accountType,type);
  cart = c;
  orderno = 0;
}
void setUserDetails(char name[],char address[],int age,char mail[],int no,int id,char type[],Cart *c){
  strcpy(personName,name);
  strcpy(personAddress,address);
  personAge = age;
  strcpy(personEmail,mail);
  personContact = no;
  userid = id;
  strcpy(accountType,type);
  cart = c;
  orderno = 0;
}
void addOrder(Order *o){
  if(orderno < 2){
    order[orderno] = o;
    orderno++;
  }
}
void addPackage(int qut, Package *p){
  packageCost = qut * p->getPackagePrice;
}
void addVehicle(int days,Vehicle *v){
  vehicleDue = days * v->calcVehicleCost;
}
void addLocation( SafariLoc *l){
  locationid = l->getLocID;
}
void displaydetails(){
  cout<<"name = "<< personName << endl; 
  cout<<"address = "<< personAddress << endl;
  cout<<"age = "<< personAge << endl;
  cout<<"mail = "<< personEmail << endl;
  cout<<"number = "<< personContact << endl;
  cout<<"id = "<< userid << endl;
  cout<<"type = "<< accountType << endl;
  cart->DisplayDetails();
  for(int i=0;i<2;i=i+1){
    order[i]->displayOrderPrice();
  cout <<"Package cost = " << packageCost << endl;
  cout <<"Vehicle cost = " << vehicleDue << endl;  
  cout <<"Location Id = " << locationid << endl;
}
};


class Vehicle {
private:
char vehicleNo[7];
char vehicleName[10];
int vehicleCharge;
int vehicleMileage;

public:
Vehicle(char no[],char name[],int charge,int mileage){
  strcpy(vehicleNo,no);
  strcpy(vehicleName,name);
  vehicleCharge = charge;
  vehicleMileage = mileage;
}
void setVehicleDetails(char no[],char name[],int charge,int mileage){
  strcpy(vehicleNo,no);
  strcpy(vehicleName,name);
  vehicleCharge = charge;
  vehicleMileage = mileage;
}
void displayVehicleDetails(){
  cout << "Vehicle No = " << vehicleNo << endl;
  cout << "Vehicle Name = " << vehicleName << endl;
  cout << "Vehicle Charge = " << vehicleCharge << endl;
  cout << "Vehicle Mileage = " << vehicleMileage << endl;
}
int calcVehicleCost(){
  return vehicleMileage * vehicleCharge;
}
~Vehicle();
};

int main(){
Cart  *c= new Cart(10,"item1",20000.00);
Person p1("vihitha","colombo",25,"mail.com",0112222222);
User u1("vihitha","colombo",25,"mail.com",0112222222,1001,"normal",c);
Vehicle *v1= new Vehicle("nb0001","toyota",100,150);

  
  return 0;  
}
