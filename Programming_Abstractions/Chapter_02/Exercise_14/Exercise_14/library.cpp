#include <iostream>
#include <string>

using namespace std;

const int MAX_AUTHORS = 5;
const int MAX_BOOKS = 1000;
const int MAX_HEADINGS = 5;


struct book_t {
    string title;
    string authors[MAX_AUTHORS];
    int catalog_number;
    string subject_headings[MAX_HEADINGS];
    string publisher;
    int year_of_publication;
    bool is_circulating;
};

struct library_t {
    int number_of_books;
    book_t books[MAX_BOOKS];
};

int main(void) {
    library_t library_data = { 3,
    {
        {
            {
                "Jakis tytul",
                { "Andrzej", "Michal" },
                190293,
                { "Heading uno" },
                "Wydawnictwo",
                2010,
                true
            }
        },
        {
            {
                "Jakis tytul 2",
                { "Pojedynczy" },
                234,
                { "Heading uno", "Jakies drugie heading" },
                "Era",
                2000,
                false
            }
        },
        {
            {
                "Jakis tytul 3",
                { "Grzesio", "Anna", "Janek" },
                66668,
                { "Naglowek?" },
                "Greg",
                2018,
                true
            }
        }
    }
    };


    return 0;
}
