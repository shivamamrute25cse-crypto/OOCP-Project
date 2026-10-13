#ifndef ENTITY_H
#define ENTITY_H
#include <iostream>
#include <string>

class Entity {
public:
    virtual ~Entity() = default;
    virtual void display() const = 0;
};

class Book : public Entity {
private:
    int bookId{};
    std::string title, author;
    double price{};
    int stock{};
public:
    Book() = default;
    Book(int id, std::string t, std::string a, double p, int s);
    int getId() const; const std::string& getTitle() const; const std::string& getAuthor() const;
    double getPrice() const; int getStock() const;
    void setDetails(std::string t, std::string a, double p, int s);
    bool updateStock(int change);
    void display() const override;
};

class Author : public Entity {
private:
    int authorId{}; std::string name, genre;
public:
    Author() = default;
    Author(int id, std::string n, std::string g);
    void display() const override;
};

class Customer : public Entity {
private:
    int customerId{}; std::string name, phone;
public:
    Customer() = default;
    Customer(int id, std::string n, std::string p);
    int getId() const; const std::string& getName() const; const std::string& getPhone() const;
    void display() const override;
};

class Sale : public Entity {
private:
    int saleId{}, bookId{}, customerId{}, quantity{}; double total{};
public:
    Sale() = default;
    Sale(int sid, int bid, int cid, int q, double t);
    int getId() const; int getBookId() const; int getCustomerId() const; int getQuantity() const; double getTotal() const;
    double calculateTotal(double unitPrice) const;
    void display() const override;
};
#endif
