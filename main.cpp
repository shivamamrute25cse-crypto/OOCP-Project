#include "BookStore.h"
#include "FileManager.h"
#include <iostream>
#include <limits>
#include <string>
#include <stdexcept>

namespace {
int readInt(const std::string& prompt){int x;for(;;){std::cout<<prompt;if(std::cin>>x){std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');return x;}std::cout<<"Please enter a valid whole number.\n";std::cin.clear();std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');}}
double readDouble(const std::string& prompt){double x;for(;;){std::cout<<prompt;if(std::cin>>x&&x>=0){std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');return x;}std::cout<<"Please enter a valid non-negative number.\n";std::cin.clear();std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');}}
std::string readText(const std::string& prompt){std::string x;std::cout<<prompt;std::getline(std::cin,x);return x;}
void addBook(BookStore&s){int id=readInt("Book ID: ");auto title=readText("Title: ");auto author=readText("Author: ");double price=readDouble("Price (Rs.): ");int stock=readInt("Stock quantity: ");if(s.addBook(Book(id,title,author,price,stock)))std::cout<<"Book added.\n";else std::cout<<"Could not add book. Check ID, title, price, stock and duplicate IDs.\n";}
void addCustomer(BookStore&s){int id=readInt("Customer ID: ");auto name=readText("Customer name: ");auto phone=readText("Phone: ");if(s.addCustomer(Customer(id,name,phone)))std::cout<<"Customer added.\n";else std::cout<<"Could not add customer. Check ID/name and duplicate IDs.\n";}
void searchBook(BookStore&s){int id=readInt("Enter book ID: ");const Book*b=s.findBook(id);if(b)b->display();else std::cout<<"Book not found.\n";}
void updateBook(BookStore&s){int id=readInt("Book ID to update: ");if(!s.findBook(id)){std::cout<<"Book not found.\n";return;}auto title=readText("New title: ");auto author=readText("New author: ");double price=readDouble("New price: ");int stock=readInt("New stock: ");if(s.updateBook(id,title,author,price,stock))std::cout<<"Book updated.\n";else std::cout<<"Update failed.\n";}
void deleteBook(BookStore&s){int id=readInt("Book ID to delete: ");std::cout<<(s.deleteBook(id)?"Book deleted.\n":"Book not found.\n");}
void sell(BookStore&s){int bid=readInt("Book ID: "),cid=readInt("Customer ID: "),q=readInt("Quantity: ");double total=0;if(s.sellBook(bid,cid,q,total))std::cout<<"Sale successful. Total = Rs. "<<total<<"\n";else std::cout<<"Sale failed: check book/customer IDs, quantity and available stock.\n";}
void showMenu(){std::cout<<"\n===== BOOK STORE MANAGEMENT =====\n1. Add Record (Book)\n2. Display Records\n3. Search Record\n4. Update Record\n5. Delete Record\n6. Main Transaction (Sell Book)\n7. Report\n8. Save / Load\n9. Add Customer\n10. Display Customers\n11. Display Sales\n12. Exit\n";}
}
int main(){BookStore store;FileManager files("Data");if(files.load(store))std::cout<<"Existing data loaded.\n";else std::cout<<"Could not load data files.\n";bool running=true;while(running){showMenu();int choice=readInt("Choose an option: ");switch(choice){case 1:addBook(store);break;case 2:store.displayBooks();break;case 3:searchBook(store);break;case 4:updateBook(store);break;case 5:deleteBook(store);break;case 6:sell(store);break;case 7:store.printReport();store.displaySales();break;case 8:{int action=readInt("1=Save, 2=Load: ");if(action==1)std::cout<<(files.save(store)?"Data saved.\n":"Save failed.\n");else if(action==2)std::cout<<(files.load(store)?"Data loaded.\n":"Load failed.\n");else std::cout<<"Invalid action.\n";break;}case 9:addCustomer(store);break;case 10:store.displayCustomers();break;case 11:store.displaySales();break;case 12:if(files.save(store))std::cout<<"Data saved. ";else std::cout<<"Warning: data could not be saved. ";std::cout<<"Goodbye.\n";running=false;break;default:std::cout<<"Invalid menu choice. Please choose 1-12.\n";}}return 0;}
