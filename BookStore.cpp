#include "BookStore.h"
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <utility>
static void displayEntity(const Entity& entity){ entity.display(); }
BookStore::BookStore():books(new Book[10]),customers(new Customer[10]),sales(new Sale[10]),bookCount(0),customerCount(0),saleCount(0),bookCapacity(10),customerCapacity(10),saleCapacity(10),nextSaleId(1){}
BookStore::~BookStore(){delete[] books;delete[] customers;delete[] sales;}
void BookStore::growBooks(){int n=bookCapacity*2;Book* p=new Book[n];for(int i=0;i<bookCount;++i)p[i]=books[i];delete[] books;books=p;bookCapacity=n;}
void BookStore::growCustomers(){int n=customerCapacity*2;Customer* p=new Customer[n];for(int i=0;i<customerCount;++i)p[i]=customers[i];delete[] customers;customers=p;customerCapacity=n;}
void BookStore::growSales(){int n=saleCapacity*2;Sale* p=new Sale[n];for(int i=0;i<saleCount;++i)p[i]=sales[i];delete[] sales;sales=p;saleCapacity=n;}
int BookStore::getBookCount()const{return bookCount;} int BookStore::getCustomerCount()const{return customerCount;} int BookStore::getSaleCount()const{return saleCount;}
const Book* BookStore::getBookAt(int i)const{return i>=0&&i<bookCount?&books[i]:nullptr;} const Customer* BookStore::getCustomerAt(int i)const{return i>=0&&i<customerCount?&customers[i]:nullptr;} const Sale* BookStore::getSaleAt(int i)const{return i>=0&&i<saleCount?&sales[i]:nullptr;}
Book* BookStore::findBook(int id){for(int i=0;i<bookCount;++i)if(books[i].getId()==id)return &books[i];return nullptr;} const Book* BookStore::findBook(int id)const{for(int i=0;i<bookCount;++i)if(books[i].getId()==id)return &books[i];return nullptr;}
Customer* BookStore::findCustomer(int id){for(int i=0;i<customerCount;++i)if(customers[i].getId()==id)return &customers[i];return nullptr;} const Customer* BookStore::findCustomer(int id)const{for(int i=0;i<customerCount;++i)if(customers[i].getId()==id)return &customers[i];return nullptr;}
bool BookStore::addBook(const Book& b){if(b.getId()<=0||b.getTitle().empty()||b.getPrice()<0||b.getStock()<0||findBook(b.getId()))return false;if(bookCount==bookCapacity)growBooks();books[bookCount++]=b;return true;}
bool BookStore::addCustomer(const Customer& c){if(c.getId()<=0||c.getName().empty()||findCustomer(c.getId()))return false;if(customerCount==customerCapacity)growCustomers();customers[customerCount++]=c;return true;}
bool BookStore::updateBook(int id,const std::string&t,const std::string&a,double p,int s){Book*b=findBook(id);if(!b||t.empty()||p<0||s<0)return false;b->setDetails(t,a,p,s);return true;}
bool BookStore::deleteBook(int id){for(int i=0;i<bookCount;++i)if(books[i].getId()==id){for(int j=i;j<bookCount-1;++j)books[j]=books[j+1];--bookCount;return true;}return false;}
void BookStore::displayBooks()const{if(!bookCount){std::cout<<"No books found.\n";return;}std::cout<<std::left<<std::setw(7)<<"ID"<<std::setw(27)<<"Title"<<std::setw(22)<<"Author"<<std::setw(10)<<"Price"<<"Stock\n";for(int i=0;i<bookCount;++i)displayEntity(books[i]);}
void BookStore::displayCustomers()const{if(!customerCount){std::cout<<"No customers found.\n";return;}for(int i=0;i<customerCount;++i)displayEntity(customers[i]);}
void BookStore::displaySales()const{if(!saleCount){std::cout<<"No sales recorded.\n";return;}for(int i=0;i<saleCount;++i)displayEntity(sales[i]);}
bool BookStore::sellBook(int bid,int cid,int q,double& totalOut){Book*b=findBook(bid);if(!b||!findCustomer(cid)||q<=0||b->getStock()<q)return false;if(saleCount==saleCapacity)growSales();totalOut=b->getPrice()*q;b->updateStock(-q);sales[saleCount++]=Sale(nextSaleId++,bid,cid,q,totalOut);return true;}
void BookStore::printReport()const{double revenue=0;for(int i=0;i<saleCount;++i)revenue+=sales[i].getTotal();std::cout<<"\n--- STORE REPORT ---\nBooks: "<<bookCount<<"\nCustomers: "<<customerCount<<"\nTransactions: "<<saleCount<<"\nTotal revenue: Rs. "<<std::fixed<<std::setprecision(2)<<revenue<<"\n";}
void BookStore::clearData(){bookCount=customerCount=saleCount=0;nextSaleId=1;}
