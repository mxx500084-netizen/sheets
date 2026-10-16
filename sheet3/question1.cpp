#include <iostream>
#include <string>

using namespace std;

class Product {
    private:
       string Name;
       int ID;
       float Price;
       float Tax;
       int Quantity;
       float Discount;
       float N_Price;
       
    public:
    Product() {
        Name = "";
        ID = 0;
        Price = 0.0;
        Tax = 0.0;
        Quantity = 0;
        Discount = 0.0;
        N_Price = 0.0;
    }
    
    Product(string name, int id, float price, float tax, int quantity, float discount) {
        Name = name;
        ID = id;
        Price = price;
        Tax = tax;
        Quantity = quantity;
        Discount = discount;
        N_Price = calculateNetPrice();
    }

    Product(const Product &p) { // ده pass by reference عشان يعمل access لل object من غير ما يعمل copy
        Name = p.Name;
        ID = p.ID;
        Price = p.Price;
        Tax = p.Tax;
        Quantity = p.Quantity;
        Discount = p.Discount;
        N_Price = p.N_Price;
    }

    float calculateNetPrice() {
        float totalPrice = Price * Quantity;
        float taxAmount = totalPrice * (Tax / 100.0);
        float discountAmount = totalPrice * (Discount / 100.0);
        return totalPrice + taxAmount - discountAmount;
    }

    void displayProductDetails() {
        cout << "Product Name: " << Name << endl;
        cout << "Product ID: " << ID << endl;
        cout << "Price: $" << Price << endl;
        cout << "Tax: " << Tax << "%" << endl;
        cout << "Quantity: " << Quantity << endl;
        cout << "Discount: " << Discount << "%" << endl;
        cout << "Net Price: $" << N_Price << endl;
    }
};

int main() {
    cout << "\n--- Product Class Demo ---\n";
    Product product1("Laptop", 101, 1000.0, 10.0, 2, 5.0);
    product1.displayProductDetails();
    
    Product product2 = product1;
    cout << "\nCopied Product Details:" << endl;
    product2.displayProductDetails();

    return 0;
}
