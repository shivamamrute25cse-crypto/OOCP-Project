#ifndef BOOK_STORE_H
#define BOOK_STORE_H
#include "Entity.h"
#include <string>
class FileManager;
class BookStore {
private:
    Book* books; Customer* customers; Sale* sales;
    int bookCount, customerCount, saleCount;
    int bookCapacity, customerCapacity, saleCapacity;
    int nextSaleId;
    void growBooks(); void growCustomers(); void growSales();
public:
    BookStore(); ~BookStore();
    BookStore(const BookStore&) = delete; BookStore& operator=(const BookStore&) = delete;
    int getBookCount() const; int getCustomerCount() const; int getSaleCount() const;
    const Book* getBookAt(int i) const; const Customer* getCustomerAt(int i) const; const Sale* getSaleAt(int i) const;
    Book* findBook(int id); const Book* findBook(int id) const; Customer* findCustomer(int id); const Customer* findCustomer(int id) const;
    bool addBook(const Book& b); bool addCustomer(const Customer& c);
    bool updateBook(int id, const std::string& title, const std::string& author, double price, int stock);
    bool deleteBook(int id); void displayBooks() const; void displayCustomers() const; void displaySales() const;
    bool sellBook(int bookId, int customerId, int quantity, double& totalOut);
    void printReport() const;
    void clearData();
    friend class FileManager;
};
#endif
