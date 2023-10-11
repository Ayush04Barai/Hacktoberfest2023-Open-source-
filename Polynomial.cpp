#include <iostream>

struct Term {
    int coefficient;
    int exponent;
    Term* next;

    Term(int coeff, int exp) : coefficient(coeff), exponent(exp), next(nullptr) {}
};

class Polynomial {
public:
    Polynomial() : head(nullptr) {}

    // Function to add a term to the polynomial
    void addTerm(int coeff, int exp) {
        Term* newTerm = new Term(coeff, exp);
        if (!head) {
            head = newTerm;
        } else {
            Term* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newTerm;
        }
    }

    // Function to display the polynomial
    void display() {
        Term* current = head;
        while (current) {
            std::cout << current->coefficient << "x^" << current->exponent;
            if (current->next) {
                std::cout << " + ";
            }
            current = current->next;
        }
        std::cout << std::endl;
    }

private:
    Term* head;
};

int main() {
    Polynomial poly;

    // Adding terms to the polynomial
    poly.addTerm(3, 4);
    poly.addTerm(-2, 2);
    poly.addTerm(5, 1);
    poly.addTerm(7, 0);

    // Displaying the polynomial
    std::cout << "Polynomial: ";
    poly.display();

    return 0;
}
