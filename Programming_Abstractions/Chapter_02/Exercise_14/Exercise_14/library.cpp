#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int MAX_AUTHORS = 5;
const int MAX_BOOKS = 1000;
const int MAX_HEADINGS = 5;


struct book_t {
    string title;
    int authors_count;
    string authors[MAX_AUTHORS];
    int catalog_number;
    int subject_count;
    string subject_headings[MAX_HEADINGS];
    string publisher;
    int year_of_publication;
    bool is_circulating;
};

struct library_t {
    int number_of_books;
    book_t books[MAX_BOOKS];
};

void search_by_subject(library_t library_data, string subject);

int main(void) {
    library_t library_data = { 3,
        {
            {
                "Jakis tytul",
                2,
                { "Andrzej", "Michal" },
                190293,
                1,
                { "Heading" },
                "Wydawnictwo",
                2010,
                true
            },
            {
                "Jakis tytul 2",
                1,
                { "Pojedynczy" },
                234,
                2,
                { "Heading uno", "Heading" },
                "Era",
                2000,
                false
            },
            {
                "Jakis tytul 3",
                3,
                { "Grzesio", "Anna", "Janek" },
                66668,
                1,
                { "Naglowek?" },
                "Greg",
                2018,
                true
            }
        }
    };

    search_by_subject(library_data, "Heading");

    cin.get();
    return 0;
}

void search_by_subject(library_t library_data, string subject) {
    for (int i = 0; i < library_data.number_of_books; i++) {
        for (int j = 0; j < library_data.books[i].subject_count; j++) {
            if (library_data.books[i].subject_headings[j].compare(subject) == 0) {
                cout << setw(30) << library_data.books[i].title;
                cout << setw(20) << library_data.books[i].authors[0];
                cout << setw(10) << library_data.books[i].catalog_number << endl;
                break;
            }
        }
    }
}
