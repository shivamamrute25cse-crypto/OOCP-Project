#include "Entity.h"
#include <iomanip>
#include <utility>
Book::Book(int id, std::string t, std::string a, double p, int s): bookId(id), title(std::move(t)), author(std::move(a)), price(p), stock(s) {}
int Book::getId() const{return bookId;} const std::string& Book::getTitle() const{return title;} const std::string& Book::getAuthor() const{return author;}
double Book::getPrice() const{return price;} int Book::getStock() const{return stock;}
void Book::setDetails(std::string t,std::string a,double p,int s){title=std::move(t);author=std::move(a);price=p;stock=s;}
bool Book::updateStock(int change){if(stock+change<0)return false;stock+=change;return true;}
void Book::display() const{std::cout<<std::left<<std::setw(7)<<bookId<<std::setw(27)<<title<<std::setw(22)<<author<<std::setw(10)<<std::fixed<<std::setprecision(2)<<price<<stock<<'\n';}
Author::Author(int id,std::string n,std::string g):authorId(id),name(std::move(n)),genre(std::move(g)){}
void Author::display() const{std::cout<<"Author ID: "<<authorId<<" | Name: "<<name<<" | Genre: "<<genre<<'\n';}
Customer::Customer(int id,std::string n,std::string p):customerId(id),name(std::move(n)),phone(std::move(p)){}
int Customer::getId()const{return customerId;} const std::string& Customer::getName()const{return name;} const std::string& Customer::getPhone()const{return phone;}
void Customer::display()const{std::cout<<"Customer ID: "<<customerId<<" | Name: "<<name<<" | Phone: "<<phone<<'\n';}
Sale::Sale(int sid,int bid,int cid,int q,double t):saleId(sid),bookId(bid),customerId(cid),quantity(q),total(t){}
int Sale::getId()const{return saleId;} int Sale::getBookId()const{return bookId;} int Sale::getCustomerId()const{return customerId;} int Sale::getQuantity()const{return quantity;} double Sale::getTotal()const{return total;}
double Sale::calculateTotal(double unitPrice)const{return unitPrice*quantity;}
void Sale::display()const{std::cout<<"Sale ID: "<<saleId<<" | Book ID: "<<bookId<<" | Customer ID: "<<customerId<<" | Qty: "<<quantity<<" | Total: "<<std::fixed<<std::setprecision(2)<<total<<'\n';}
