#include "Transaction.h"

#include <cassert>
#include <cstdint>
#include <string>

int main() {
    Transaction salary{
        Transaction::Kind::income,
        120000,
        "salary",
        "November"
    };

    assert(salary.kind() == Transaction::Kind::income);
    assert(salary.amount() == 120000);
    assert(salary.category() == "salary");
    assert(salary.note() == "November");
    assert(salary.signed_amount() == 120000);

    Transaction coffee{
        Transaction::Kind::expense,
        350,
        "food",
        "Coffee"
    };

    assert(coffee.signed_amount() == -350);

    Transaction same_coffee{
        Transaction::Kind::expense,
        350,
        "food",
        "Coffee"
    };
    assert(coffee == same_coffee);

    Transaction different_note{
        Transaction::Kind::expense,
        350,
        "food",
        "Tea"
    };
    assert(!(coffee == different_note));

    Transaction no_note{
        Transaction::Kind::income,
        1,
        "gift",
        ""
    };
    assert(no_note.note().empty());
    assert(no_note.signed_amount() == 1);

    Transaction copy = salary;
    assert(copy == salary);

    copy = coffee;
    assert(copy == coffee);
    assert(salary.category() == "salary"); // копии независимы
}